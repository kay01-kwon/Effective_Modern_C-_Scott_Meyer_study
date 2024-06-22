#include "class_item7.hpp"

Item7::Item7()
{

}

void Item7::print_item()
{
    std::cout << "x: "<< x <<std::endl;
    std::cout << "y: "<< y <<std::endl;
}

Test1::Test1()
{
    // std::cout<<"Default constructor"<<std::endl;
}

Test1::Test1(int i, bool b)
{
    std::cout<<"Int: "<<i<<std::endl;
    std::cout<<"Bool: "<<b<<std::endl;
    
}

Test1::Test1(int i, double d)
{
    std::cout<<"Int: "<<i<<std::endl;
    std::cout<<"Double: "<<d<<std::endl;
}

Test2::Test2()
{

}

Test2::Test2(int i, bool b)
{
    std::cout<<"Int: "<<i<<std::endl;
    std::cout<<"Bool: "<<b<<std::endl;
}

Test2::Test2(int i, double d)
{
    std::cout<<"Int: "<<i<<std::endl;
    std::cout<<"Double: "<<d<<std::endl;
}

Test2::Test2(std::initializer_list<long double> il)
{
    std::cout<<"Call std::initializer_list<long double>"<<std::endl;
    for(auto& m: il)
    {
        std::cout<<m<<", ";
    }
    std::cout<<std::endl;
}
