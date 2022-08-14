#include "Vector.h"
#include <iostream>



int main(int argc, char** argv) {
    int const length = 8;
    Vector v1;
    //vector.Print();
    for (size_t i = 0; i < length; i++)
    {
        v1.PushBack(i + 1);
    }
    Vector v2(v1);
    v1.Print();
    v2.Print();
    return 0;
}