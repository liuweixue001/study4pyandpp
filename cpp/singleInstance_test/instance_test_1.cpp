#include <iostream>

class Test
{
public:
    static int a;
    static Test* get_instance()
    {
        a++;
        return test;
    }
    
    
private:
    Test(){};   
    static Test* test;
};

Test* Test::test = new Test;
int Test::a = 1;
int main()
{
    std::cout << Test::get_instance()->a << std::endl;
    std::cout << Test::get_instance()->a << std::endl;
    std::cout << Test::get_instance()->a << std::endl;
    std::cout << Test::get_instance()->a << std::endl;
    return 0;
}