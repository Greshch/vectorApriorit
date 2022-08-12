#include "Vector.h"
#include <iostream>



int main(int argc, char** argv) {
    int const length = 8;
    Vector vector;
    //vector.Print();
    for (size_t i = 0; i < length; i++)
    {
        vector.PushBack(i + 1);
    }
    vector.Print();
    std::cout << "Try to insert 777 to middle\n";
    vector.Insert(length / 2, 777);
    vector.Print();
    std::cout << "Try to remove 777\n";
    vector.Remove(length / 2);
    vector.Print();
    return 0;
}