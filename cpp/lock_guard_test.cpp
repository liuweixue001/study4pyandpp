#include <iostream>
#include <mutex>
#include <thread>
#include <string>

std::mutex myMutex;

void criticalSection(int& i, std::string name) {
    std::lock_guard<std::mutex> lock(myMutex);
    i++;
    std::cout << "in " << name << " i = " << i << std::endl;
} 

int main() {
    int i = 1;
    std::string name1 = "func1";
    std::string name2 = "func2";
    std::thread t1(criticalSection, std::ref(i), name1);
    std::thread t2(criticalSection, std::ref(i), name2);

    t1.join();
    t2.join();

    return 0;
}