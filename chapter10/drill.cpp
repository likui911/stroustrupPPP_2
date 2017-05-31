#include "drill.h"
#include "../std_lib_facilities.h"
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    using namespace std;
    cout << "Please input 7 pairs (x,y):" << endl;
    vector<Pointer> original_points{};
    for (int i = 0; i < 7; ++i)
    {
        char c;
        int x, y;
        cin >> c >> x >> c >> y >> c;
        original_points.push_back(Pointer{x, y});
    }

    ofstream ofs{"./chapter10/mydata.txt"};
    if (!ofs)
        error("can't open file");
    for (Pointer p : original_points)
    {
        ofs << "(" << p.x << "," << p.y << ")" << endl;
    }
    ofs.close();
    
    ifstream ifs{"./chapter10/mydata.txt"};
    vector<Pointer> provessed_points{};
    if (!ifs)
        error("can't open file");
    while (ifs)
    {
        char c;
        int x, y;
        ifs >> c >> x >> c >> y >> c;
        provessed_points.push_back(Pointer{x, y});
    }
    for (Pointer p : provessed_points)
    {
        cout << "(" << p.x << "," << p.y << ")" << endl;
    }
    ifs.close();
    
    return 0;
}