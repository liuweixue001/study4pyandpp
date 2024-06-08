#include <iostream>
#include <tuple>
#include <vector>
#include <string>

int main()
{
    std::tuple<int, std::string, std::vector<int>> test;
    test = std::make_tuple(1, "hello tuple", std::vector<int>{1, 2, 3});

    int a;
    std::string b;
    std::vector<int> c;
    std::tie(a, b, c) = test;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    for (const auto& value: c)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    
    int a1 = std::get<0>(test);
    std::string b1 = std::get<1>(test);
    std::vector<int> c1 = std::get<2>(test);
    std::cout << a1 << std::endl;
    std::cout << b1 << std::endl;
    for (const auto& value: c1)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    return 0;
}