#include "Vector.h"



int main(int argc, char** argv) {
    int const length = 8;
    Vector vector;
    //vector.Print();
    for (size_t i = 0; i < length; i++)
    {
        vector.PushBack(i + 1);
    }
    vector.Print();
    vector.Insert(length / 2, 777);
    vector.Print();
    return 0;
}