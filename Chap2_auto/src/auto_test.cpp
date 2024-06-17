#include "auto_test.hpp"

int main(int argc, char** argv)
{
    unordered_map<string , double> m;

    m["x"] = 1.0;
    m["y"] = 2.0;
    m["z"] = 3.0;

    // Too verbose...
    // for(const std::pair<const string, double>& p: m)
    // {
    //     print_key_values(p.first, p.second);
    // }

    // Use auto for simplicity!
    for(const auto& p:m)
    {
        print_key_values(p.first, p.second);
    }

    return EXIT_SUCCESS;
}