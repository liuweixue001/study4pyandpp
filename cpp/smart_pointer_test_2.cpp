#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

struct MyStruct {
    std::shared_ptr<int> ptr;
    std::string data;
};

std::vector<MyStruct> structList;
std::mutex mtx;

void printA() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        mtx.lock(); // 加锁
        if (structList.size() > 0) 
        {
            MyStruct A = structList.back(); // 获取A
            mtx.unlock(); // 释放锁

            if (A.ptr) {
                std::cout << "A's pointer data: " << *A.ptr << std::endl;
            } else {
                std::cout << "A's pointer is empty" << std::endl;
            }
        } 
        else 
        {
            mtx.unlock(); // 释放锁
            std::cout << "no data" << std::endl;
        }
    }
}

void clearList() {

    mtx.lock(); // 加锁
    structList.clear();
    mtx.unlock(); // 释放锁
    std::cout << "List cleared" << std::endl;

}

int main() {
    // 向列表中添加几个结构体
    structList.push_back({std::make_shared<int>(1), "One"});
    structList.push_back({std::make_shared<int>(2), "Two"});
    structList.push_back({std::make_shared<int>(3), "Three"});

    std::thread threadPrint(printA);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::thread threadClear(clearList);

    threadPrint.join();
    threadClear.join();

    return 0;
}
