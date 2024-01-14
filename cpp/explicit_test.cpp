#include <iostream>

class Person{
public:
    explicit Person(int a):age(a){

    }
    Person(int& a):age(a){

    }
    ~Person(){

    }
    int getAge() const{
        counter++;
        return age;
    }
private:
    int age{18};
    mutable int counter{0};
};

int main()
{
    int a = 1;
    Person person{1};
    // Person person_a = a; 不允许隐式转换
    Person person_aa = a; // 可以隐式转换
    std::cout << person.getAge() << std::endl;
    std::cout << person_aa.getAge() << std::endl;
    return 0;
}