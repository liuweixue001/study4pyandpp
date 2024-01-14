#include <iostream>

void func(int&& x)
{
    std::cout << &x << std::endl;
    x = 10;
}

void func_(int& x)
{
    std::cout << &x << std::endl;
    x = 10;
}

struct Test
{
    int a;
    int b;
    float c;
    int *p;
};

int main()
{
    int a = 5;
    std::cout << &a << std::endl;
    func(std::move(a));
    func_(a);
    std::cout << &a << std::endl;
    std::cout << "value: " << a << std::endl;

    std::cout << "test below...." << std::endl;

    int array[10]{1,2,3,4,5,6,7,8,9,0};

    Test b = {3, 3, 2.2, array};
    Test c = std::move(b);

    b.p[2] = 996;
    c.p[2] = 996;
    b.p = nullptr; // 移动后将b的指针设为空指针,防止未定义行为, 在g++中, 移动后指针还是指向原先的位置
    std::cout << "b = " << &(b.p[2]) << " c = " << &(c.p[2]) << std::endl;
    std::cout << "b = " << &(b.p[2]) << " c = " << c.p[2] << std::endl;
    return 0;
}
