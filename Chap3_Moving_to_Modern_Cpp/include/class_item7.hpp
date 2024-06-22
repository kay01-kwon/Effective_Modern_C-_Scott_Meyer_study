#ifndef CLASS_ITEM7_HPP_
#define CLASS_ITEM7_HPP_
#include <iostream>

class Item7{

    public:

        Item7();

        void print_item();

    private:
        
        int x{7};

        int y = 8;

        // int z(0);
};

class Test1{

    public:

        Test1();

        Test1(int i, bool b);
        
        Test1(int i, double d);

};

class Test2{

    public:

        Test2();

        Test2(int i, bool b);
        
        Test2(int i, double d);

        Test2(std::initializer_list<long double> il);

        // operator float() const;

};

#endif