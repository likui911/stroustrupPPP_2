
/*
*Caculator Parser
*
*	caculation
*		statement
*		print
*		quit
*       help
*		caculation statement
*
*	print
*		;
*
*	quit
*		exit
*
*   help
*        help
*	
*	Statement
*		declaration
*		expression
*
*	declaration
*		"let" Name "=" Expression
*
*	expression
*		term
*		expression + term
*		expression - term
*
*	term
*		primary
*		term * primary
*		term / primary
*
*	primary
*		number
*		"-" primary
*		"+" primary
*		"("expression")"
*		sqrt "("expression")"
*       pow "(" expression "," expression ")"
*
*	number
*		float-pointing-literal
*/

#include "../std_lib_facilities.h"

struct Token
{
    char kind;
    double value;
    string name;
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, double val) : kind(ch), value(val) {}
    Token(char ch, string str) : kind(ch), name(str) {}
};

class Token_stream
{
    bool full;
    Token buffer;

  public:
    Token_stream() : full(0), buffer(0) {}

    Token get();
    void unget(Token t)
    {
        buffer = t;
        full = true;
    }

    void ignore(char);
};

const char QUIT = 'Q';
const char PRINT = ';';
const char NUMBER = '8';
const char NAME = 'a';
const char SQRT = 's';
const char POW = 'p';
const char CONST = 'c';
const char LET = 'L';
const char HELP = 'H';

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    //skip 'space' 'tab'
    while (cin >> noskipws >> ch)
    {
        if (!isspace(ch) || ch == '\n')
            break;
    }

    switch (ch)
    {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
    case ',':
        return Token(ch);
    case '\n':
        return Token(PRINT);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.unget();
        double val;
        cin >> val;
        return Token(NUMBER, val);
    }
    default:
        if (isgraph(ch))
        {
            string s;
            s = ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_'))
                s += ch;
            cin.unget();
            if (s == "help")
                return Token(HELP);
            // detect sqrt symbol
            if (s == "sqrt")
                return Token(SQRT);
            // detect pow symbol
            if (s == "pow")
                return Token(POW);
            if (s == "exit")
                return Token(QUIT);
            if (s == "let")
                return Token(LET);
            if (s == "const")
                return Token(CONST);
            // get the variable
            return Token(NAME, s);
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;

    char ch;
    if (!cin) //if cin's state is not io_base::good ,clear it.
        cin.clear();
    while (cin >> ch)
        if (ch == c)
            return;
}

struct Variable
{
    string name;
    double value;
    bool is_const;
    Variable(string n, double v, bool b) : name(n), value(v), is_const(b){};
};

struct Symbol_table
{
    vector<Variable> var_table;
    double get(string s);
    void set(string s, double d);
    bool is_declared(string s);
    void declare(string name, double value, bool is_const);
    Symbol_table() : var_table(){};
};

double Symbol_table::get(string s)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s)
            return var_table[i].value;
    error("get: undefined name ", s);
}

void Symbol_table::set(string s, double d)
{
    for (int i = 0; i <= var_table.size(); ++i)
        if (var_table[i].name == s)
        {
            if (var_table[i].is_const)
                error("set: variable const ", s);
            var_table[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].name == s)
            return true;
    return false;
}

void Symbol_table::declare(string name, double value, bool is_const)
{
    if (is_declared(name))
        error(name, " declared twice");
    var_table.push_back(Variable(name, value, is_const));
}

// define global variables
Token_stream ts;
Symbol_table tbl;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case POW:
    {
        t = ts.get();
        if (t.kind != '(')
            error("'(' expected");
        double left = expression();
        t = ts.get();
        if (t.kind != ',')
            error("')' expected");
        double right = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return pow(left, narrow_cast<int>(right));
    }
    case SQRT:
    {
        t = ts.get();
        if (t.kind != '(')
            error("'(' expected");
        double d = expression();
        if (d < 0)
            error("sqrt below zero");
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return sqrt(d);
    }
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
            error("')' expected");
        return d;
    }
    case '-':
        return -primary();
    case NUMBER:
        return t.value;
    case NAME:
        return tbl.get(t.name);
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0)
                error("Divide by zero");
            // using fmod to evaluate float module
            left = fmod(left, d);
            break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true)
    {
        Token t = ts.get();
        switch (t.kind)
        {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    bool is_const = false;
    if (t.kind == CONST)
    {
        is_const = true;
        t = ts.get();
    }
    if (t.kind != NAME)
        error("name expected in declaration");
    string name = t.name;
    Token t2 = ts.get();
    if (t2.kind != '=')
        error("= missing in declaration of ", name);
    double d = expression();
    if (tbl.is_declared(name))
        tbl.set(name, d);
    else
        tbl.declare(name, d, is_const);
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case LET:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(PRINT);
}

const string prompt = "> ";
const string result = "= ";

void help()
{
    cout << "welcome to caculator!\n";
    cout << "some help resource\n";
}

void calculate()
{
    while (true)
        try
        {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == PRINT)
                t = ts.get();
            if (t.kind == QUIT)
                return;
            if (t.kind == HELP)
            {
                help();
                continue;
            }
            ts.unget(t);
            cout << result << statement() << endl;
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            clean_up_mess();
        }
}

int main()
{
    try
    {
        //predifine names;
        tbl.declare("pi", 3.1415926535, true);
        tbl.declare("e", 2.7182818284, true);
        tbl.declare("k", 1000, true);

        // do calculation
        calculate();
        return 0;
    }
    catch (exception &e)
    {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c != ';')
            ;
        return 1;
    }
    catch (...)
    {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';')
            ;
        return 2;
    }
}