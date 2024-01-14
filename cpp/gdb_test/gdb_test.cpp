#include <iostream>

void gdb_test()
{
    std::cout << "in gdb_test func" << std::endl;
}


int main()
{
    std::cout << "come in gdb test" << std::endl;
    gdb_test();
    std::cout << "come out gdb test" << std::endl;
    return 0;
}