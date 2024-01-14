#include <iostream>
using namespace std;

void func()
{
    std::cout << "This fucntion is in " << __func__ << std::endl;
    std::cout << "This fucntion is in " << __FUNCTION__ << std::endl;
    std::cout << "This file is in " << __FILE__ << std::endl;
    std::cout << "This LINE is in " << __LINE__ << std::endl;
    std::cout << "The Date is " << __DATE__ << std::endl;
    std::cout << "This Time is " << __TIME__ << std::endl;
}

int main()
{
    func();
    return 0;
}