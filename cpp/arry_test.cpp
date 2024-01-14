#include <iostream>

int* funTest(){
    static int myArray[3] = {1, 2, 3};
    return myArray;
}

int main()
{
    int *array = funTest();
    std::cout << array[0] << " " << array[1] << " " << array[2] << std::endl;

    int *fakearray = new int(1);
    std::cout << fakearray[0] << " " << fakearray[1] << " " << fakearray[2] << std::endl;

    delete fakearray;
    return 0;
}