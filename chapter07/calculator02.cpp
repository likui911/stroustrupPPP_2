
/*
*Caculator Parser
*
*	caculation
*		statement
*		print
*		quit
*		caculation statement
*
*	print
*		;
*
*	quit
*		q
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

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
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
	case '#':
		return Token(ch);
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
		if (isalpha(ch))
		{
			string s;
			s = ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.unget();
			// detect sqrt symbol
			if (s == "sqrt")
				return Token(SQRT);
			// detect pow symbol
			if (s == "pow")
				return Token(POW);
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
	Variable(string n, double v) : name(n), value(v) {}
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
			return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s)
		{
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
			return true;
	return false;
}

Token_stream ts;

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
		return get_value(t.name);
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
	if (t.kind != NAME)
		error("name expected in declaration");
	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
	case '#':
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
			ts.unget(t);
			cout << result << statement() << endl;
		}
		catch (runtime_error &e)
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

void define_name(string name, double value)
{
	if (is_declared(name))
		error(name, " declared twice");
	names.push_back(Variable(name, value));
}

int main()
{
	try
	{
		//predifine names;
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);
		define_name("k", 1000);

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