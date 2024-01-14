#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <mutex>
#include <list>

struct data
{
    int length = 0;
    int width = 1;
    std::shared_ptr<int> data = std::make_shared<int>(996);

};

struct test
{
    data m_data = data();
    std::string m_str = "hello shared_ptr";
};


int main()
{
    std::list<test> test_list;
    {
        test A = test();
        test_list.push_back(A);
        std::cout << (A.m_data.data.get()) << std::endl;
    }
    
    test C;
    {
        test B = test_list.back();
        C.m_str = B.m_str;
        C.m_data = B.m_data;
        std::cout << (B.m_data.data.get()) << std::endl;
    }
    
    std::cout << (C.m_data.data.get()) << std::endl;
    std::cout << (C.m_data.data.use_count()) << std::endl;
    test_list.clear();
    std::cout << (C.m_data.data.use_count()) << std::endl;
    return 0;
}