#include <iostream>


enum color {white, black=4, red, yellow, green};

enum class day:unsigned char {Monday=123, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

//auto white = 2; // error, color作用域为全局，重复定义,
auto Monday = 2;

int main()
{
    day today = day::Tuesday;
    std::cout << "Monday = " << Monday << std::endl;
    std::cout << "red = " << red << std::endl;
    std::cout << "today = " << static_cast<int>(today) << std::endl;

    if(white==0) std::cout << "white = 0" << std::endl;
    // if(day::Tuesday==0) std::cout << " white = 0" << std::endl; // error, 没有匹配的运算符
    if(static_cast<int>(day::Tuesday)==124) std::cout << "static_cast<int>(day::Tuesday)==124" << std::endl; // error
    return 0;
}