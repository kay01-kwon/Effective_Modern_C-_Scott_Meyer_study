#ifndef TEMPLATE_TYPE_TEST_HPP_
#define TEMPLATE_TYPE_TEST_HPP_
#include <iostream>
#include <boost/type_index.hpp>

using std::cout;
using std::endl;
using boost::typeindex::type_id_with_cvr;


/**
 * Case 1: param type is a reference or pointer, but not a universal reference
*/

// param type: Reference 
template <typename T>
void f_case1_ref(T& param)
{
    cout<<"T Types: ";
    cout<<type_id_with_cvr<T>().pretty_name()<<"\n";
    cout<<"Parameter Types: ";
    cout<<type_id_with_cvr<decltype(param)>().pretty_name()<<"\n\n";
}

template <typename T>
void f_case1_const_ref(const T& param)
{
    cout<<"T Types: ";
    cout<<type_id_with_cvr<T>().pretty_name()<<"\n";
    cout<<"Parameter Types: ";
    cout<<type_id_with_cvr<decltype(param)>().pretty_name()<<"\n\n";
}

template <typename T>
void f_case1_ptr(T* param)
{
    cout<<"T Types: ";
    cout<<type_id_with_cvr<T>().pretty_name()<<"\n";
    cout<<"Parameter Types: ";
    cout<<type_id_with_cvr<decltype(param)>().pretty_name()<<"\n\n";
}

/**
 * Case 2: param type is a Universal reference
*/
template <typename T>
void f_case2(T&& param)
{
    cout<<"T Types: ";
    cout<<type_id_with_cvr<T>().pretty_name()<<"\n";
    cout<<"Parameter Types: ";
    cout<<type_id_with_cvr<decltype(param)>().pretty_name()<<"\n\n";
}

#endif