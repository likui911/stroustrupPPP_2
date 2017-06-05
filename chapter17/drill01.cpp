// 1.Allocate an array of ten ints on the free store using new
// 2.Print the values of the ten ints to cout
// 3.Deallocate the array (using delete[])
// 4.Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os
//5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
//6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values
//7. Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os
//8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
//9. Did you remember to delete the arrays? (If not, do it.)
//10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array()

#include <iostream>

using namespace std;

ostream &print_array(ostream &os, int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return os;
}

ostream &print_array10(ostream &os, int *a)
{
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return os;
}

int main()
{
    int *ints = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; ++i)
    {
        cout << ints[i] << " ";
    }
    cout << endl;
    delete[] ints;

    int *a = new int[10]{101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_array10(cout, a) << endl;

    int *b = new int[11]{101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};
    print_array10(cout, b) << endl;

    int *c = new int[11]{101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};
    print_array(cout, c, 11) << endl;

    return 0;
}