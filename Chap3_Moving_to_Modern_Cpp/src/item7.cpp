#include <iostream>
#include <vector>
#include <class_item7.hpp>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv)
{
    // Initialization
    // 1. ()
    // 2. =
    // 3. {}
    int x(1);
    int y = 2;
    int z{3};

    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<"z: "<<z<<endl;

    // Braced initialization
    vector<int> v{4, 5, 6};

    cout<<"v: ";

    for(auto& vec:v)
    {
        cout<<vec<<", ";
    }

    cout<<endl;

    Item7 item7;

    item7 = Item7();

    item7.print_item();

    Test1 test1_1, test1_2, test1_3, test1_4;


    // Call the first constructor
    test1_1 = Test1(10, true);
    test1_2 = Test1{10, true};

    //  Call the second constructor
    test1_3 = Test1(10, 5.0);
    test1_4 = Test1{10, 5.0};

    Test2 test2_1, test2_2, test2_3, test2_4;

    // Call the first constructor
    test2_1 = Test2(10, true);
    test2_2 = Test2{10, true};  //std::initilizer_list<long double>

    //  Call the second constructor
    test2_3 = Test2(10, 5.0);
    test2_4 = Test2{10, 5.0};   //std::initilizer_list<long double>

    Test2 test2_5, test2_6;

    // Copy constructor
    test2_5 = Test2(test2_4);
    test2_6 = Test2{test2_4};


    return EXIT_SUCCESS;
}