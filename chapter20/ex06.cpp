/*
 Write a find-and-replace operation for Documents based on §20.6.2
*/
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

using Line = vector<char>;

class Text_iterator
{ // keep track of line and character position within a line
    list<Line>::iterator ln;
    Line::iterator pos;

  public:
    // start the iterator at line ll’s character position pp:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        : ln{ll}, pos{pp} {}
    char &operator*() { return *pos; }
    Text_iterator &operator++();
    bool operator==(const Text_iterator &other) const
    {
        return ln == other.ln && pos == other.pos;
    }
    bool operator!=(const Text_iterator &other) const
    {
        return !(*this == other);
    }
};

Text_iterator &Text_iterator::operator++()
{
    ++pos; // proceed to next character
    if (pos == (*ln).end())
    {
        ++ln;                // proceed to next line
        pos = (*ln).begin(); // bad if ln==line.end(); so make sure it isn’t
    }
    return *this;
}

struct Document
{
    Document() { line.push_back(Line{}); }

    list<Line> line;
    Text_iterator begin() // first character of first line
    {
        return Text_iterator(line.begin(), (*line.begin()).begin());
    }
    Text_iterator end() // one beyond the last character of the last line
    {
        list<Line>::iterator last = line.end();
        --last; // we know that the document is not empty
        return Text_iterator(last, (*last).end());
    }
    void find_replace(const char *src, const char *dest);
};

istream &operator>>(istream &is, Document &d)
{
    for (char ch; is.get(ch);)
    {
        d.line.back().push_back(ch); // add the character
        if (ch == '\n')
            d.line.push_back(Line{}); // add another line
    }
    if (d.line.back().size())
        d.line.push_back(Line{}); // add final empty line
    return is;
}

void Document::find_replace(const char *src, const char *dest)
{
    int nSrc = strlen(src);
    int nDest = strlen(dest);
    for (Line &ln : line)
    {
        for (Line::iterator iter = ln.begin(); iter != ln.end(); ++iter)
        {
            if (*iter == src[0])
            {
                if (std::equal(iter, iter + nSrc, src))
                {
                    iter = ln.erase(iter, iter + nSrc);
                    iter = ln.insert(iter, dest, dest + nDest);
                    iter += nDest;
                }
            }
        }
    }
}

int main()
{
    ifstream fis("./chapter20/docu.txt");
    Document doc;
    fis >> doc;
    doc.find_replace("C++", "C");
    for (auto c : doc)
    {
        cout << c;
    }
    return 0;
}