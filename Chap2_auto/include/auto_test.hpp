#ifndef AUTO_TEST_HPP_
#define AUTO_TEST_HPP_
#include <iostream>
#include <boost/type_index.hpp>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using boost::typeindex::type_id_with_cvr;
using std::unordered_map;
using std::string;

// Helper lambda function to print key-value pairs

auto print_key_values = [](const auto& key, const auto& value)
{
    cout << "Key: " << key << ", Value: " << value <<"\n\n";
};


#endif