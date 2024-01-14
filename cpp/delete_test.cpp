#include <iostream>


int main()
{
    int *ptr1 = new int(3);
    int *ptr2 = ptr1;
    
    std::cout << "before delete ptr1 = " << ptr1 <<  " *ptr1 = " << *ptr1<< std::endl;

    delete ptr2;
    ptr2 = nullptr;

    std::cout << "after delete ptr1 = " << ptr1 <<  " *ptr1 = " << *ptr1<< std::endl;

    ptr1 = nullptr;

    std::cout << "after nullptr *ptr1 = " << *ptr1 << std::endl;

    return 0;
}