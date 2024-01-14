#include <map>
#include <iostream>

int main() {
    std::map<std::pair<int, int>, std::string> myMap;

    // 插入数据
    myMap[std::pair<int, int>{1, 2}] = "One Two";
    myMap[std::pair<int, int>{1, 2}] = "Three Four";
    myMap[std::pair<int, int>{1, 2}] = "Five Six";


    // 判断是否找到
    if (myMap.find(std::pair<int, int>{1, 2}) != myMap.end()) {
        std::cout << "Key found!" << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}