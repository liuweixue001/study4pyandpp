#include <iostream>  

using namespace std;  

template<typename T1>  
class mypair  
{  
public:  
    T1 first;  
    mypair(T1 first_val): first(first_val)
    {   
        std::cout << "inner first_val1 " << &first_val << std::endl;
        std::cout << "inner first1 " << &first << std::endl;
    }  
};  

class myint
{
public:
    int value; 
};

int main()  
{  
    myint a{1};  
    mypair<int&> test(a.value); 
    return 0;  
}