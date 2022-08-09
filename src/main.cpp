#include "Vector.h"



int main(int argc, char** argv) {
    int const length = 2;
    Vector vector(0, length);
    vector.Print();
    for (size_t i = 0; i < 18; i++)
    {
        vector.PushBack(i + 1);
    }
    vector.Print();
    return 0;
}