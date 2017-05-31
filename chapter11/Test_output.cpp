#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int brith_year = 1986;
    int age = 30;
    cout << showbase << brith_year << "\tdecimal" << endl;
    cout << hex << brith_year << "\thexadecimal" << endl;
    cout << oct << brith_year << "\toctal" << endl;
    // output age
    cout << dec << age << endl;

    double d = 1234567.89;
    cout << d << '\n'
         << fixed << d << '\n'
         << scientific << d << endl;

    cout << setw(6) << "kui" //lase name
         << "|"
         << setw(6) << "li" //first name
         << "|"
         << setw(16) << 15601803990 //phnoe num
         << "|"
         << setw(18) << "likui@qilirj.com" << endl; //email
    return 0;
}