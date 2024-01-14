#include <stdio.h>
#include <iostream>

int main()
{
    // 打开文件test.txt以读取方式
    FILE *fp;
    fp = fopen("test.txt", "r");
    if (fp == nullptr)
    {
        std::cout << "无法打开文件！" << std::endl;
    }

    // 关闭文件
    fclose(fp);

    // 以写入方式打开文件test.txt
    fp = fopen("test.txt", "a+");
    if (fp == nullptr)
    {
        std::cout << "无法打开文件！" << std::endl;
    }

    fseek(fp, 0, SEEK_SET);
    int num1, num2;
    fscanf(fp, "%d %d", &num1, &num2); 
    std::cout << "num1 = " << num1 << " num2 = " << num2 << std::endl;

    char str[100];
    fgets(str, 100, fp);
    std::cout << "str = " << str << std::endl;

    int *data;
    fread(data, sizeof(int), 1, fp);
    std::cout << "data = " << *data << std::endl;

    char str2[] = "Hello, world!";
    fputs(str2, fp); // 将字符串str写入文件中，注意字符串结尾的'\0'不会被写入文件中。因此在使用fgets读取的时候需要注意字符串的长度。

    fseek(fp, 0, SEEK_SET); // SEEK_END

    long pos = ftell(fp);
    std::cout << "lens = " << pos << std::endl;

    rewind(fp);
    
    if (ferror(fp))
    {
        printf("文件操作发生错误\n");
        clearerr(fp);
    }

    // 关闭文件
    fclose(fp);
    return 0;
}
