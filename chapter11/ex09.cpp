/*
Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text 
file into binary and one program that reads binary and converts it to text. Test these programs 
by comparing a text file with what you get by converting it to binary and back
*/
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
char *as_bytes(T &i) // needed for binary I/O
{
    void *addr = &i;                  // get the address of the first byte
                                      // of memory used to store the object
    return static_cast<char *>(addr); // treat that memory as bytes
}

vector<int> read_from_binary(const string &file)
{
    ifstream ifs{file, ios_base::binary};
    vector<int> vec;
    for (int x; ifs.read(as_bytes(x), sizeof(int));)
        vec.push_back(x);
    return vec;
}

void write_to_binary(const string &file, const vector<int> &vec)
{
    ofstream ofs{file, ios_base::binary};
    for (int i : vec)
        ofs.write(as_bytes(i), sizeof(int));
}

int main()
{
    write_to_binary("./chapter11/binary", {1, 2, 3, 4, 5});
    vector<int> vec = read_from_binary("./chapter11/binary");
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}