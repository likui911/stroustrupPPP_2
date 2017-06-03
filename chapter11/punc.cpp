#include "./punc.h"

bool Punct_stream::is_whitespace(char c)
{
    for (char x : white)
        if (c == x)
            return true;
    return false;
}

Punct_stream &Punct_stream::operator>>(string &s)
{
    while (!(buffer >> s))
    {
        //if buffer is bad or source is not good return *this
        if (buffer.bad() || !source.good())
            return *this;
        buffer.clear();
        string line;
        getline(source, line);
        for (char &ch : line)
            if (is_whitespace(ch))
                ch = ' ';
            else if (!sensetive)
                ch = tolower(ch);
        buffer.str(line);
    }
    // if buffer not empty return *this
    return *this;
}

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}