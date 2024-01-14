#include <iostream>
#include <fstream>
#include <cstring>


int main()
{
    // 打开文件test.txt以读取方式
    std::ifstream inputFile("test.txt");
    if (!inputFile.is_open())
    {
        std::cout << "无法打开文件！" << std::endl;
        return 1;
    }
    inputFile.close(); // 关闭文件

    // 以写入和读取方式打开文件test.txt
    std::fstream file("test.txt", std::ios::in | std::ios::out | std::ios::app);
    if (!file.is_open())
    {
        std::cout << "无法打开文件！" << std::endl;
        return 1;
    }

    file.seekg(0, std::ios::beg);
    int num1, num2;
    file >> num1 >> num2;
    std::cout << "num1 = " << num1 << " num2 = " << num2 << std::endl;

    char str[100];
    while(file.getline(str, 100))
    {
        if(strlen(str)==0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    std::cout << "str = " << str << std::endl;

    int32_t data;
    // file.read(reinterpret_cast<char*>(&data), sizeof(int32_t)); # 二进制读取，不适用
    file >> data;
    std::cout << "data = " << data << std::endl;

    const char* str2 = "Hello, world!";
    file << str2; // 将字符串str写入文件中

    file.seekg(0, std::ios::end);

    long pos = file.tellg();
    std::cout << "lens = " << pos << std::endl;

    file.seekg(0, std::ios::beg);

    if (file.fail())
    {
        std::cout << "文件操作发生错误" << std::endl;
        file.clear();
    }

    // 关闭文件
    file.close();
    return 0;
}
