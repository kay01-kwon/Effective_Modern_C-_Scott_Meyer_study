#include "template_type_test.hpp"

int main(int argc, char** argv)
{
    int x = 27;
    const int const_x = x;
    const int& ref_x = x;
    const int *px = &x;


    cout<<"\nCase 1. Param Type - reference or pointer\n\n";

    // Reference
    cout<<"******************************************\n";
    cout<<"1.a int x = 27;\nf(T& param);\n";
    f_case1_ref(x);

    cout<<"1.b const int const_x = x;\nf(T& param);\n";
    f_case1_ref(const_x);

    cout<<"1.c const int& ref_x = x;\nf(T& param);\n";
    f_case1_ref(ref_x);

    cout<<"******************************************\n";

    // const reference
    cout<<"2.a int x = 27;\nf(const T& param);\n";
    f_case1_const_ref(x);

    cout<<"2.b const int const_x = x;\nf(const T& param);\n";
    f_case1_const_ref(const_x);

    cout<<"2.c const int& ref_x = x;\nf(const T& param);\n";
    f_case1_const_ref(ref_x);


    cout<<"******************************************\n";
    // pointer
    cout<<"3.a int x = 27;\nf(T* param);\n";
    f_case1_ptr(&x);

    cout<<"3.b const int const_x = x;\nf(T* param);\n";
    f_case1_ptr(&const_x);

    cout<<"3.c const int& ref_x = x;\nf(T* param);\n";
    f_case1_ptr(&ref_x);


    cout<<"\nCase 2. Param Type - universal reference\n\n";

    cout<<"******************************************\n";
    cout<<"1. int x = 27;\nf(T&& param);\n";
    f_case2(x);

    cout<<"2. const int const_x = x;\nf(T&& param);\n";
    f_case2(const_x);

    cout<<"3. const int& ref_x = x;\nf(T&& param);\n";
    f_case2(ref_x);

    cout<<"4. rvalue \nf(T&& param);\n";
    f_case2(27);

    auto fun1 = somefn;

    fun1(1,1.2);

    return EXIT_SUCCESS;

}