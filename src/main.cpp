#include "Vector.h"



int main(int argc, char** argv) {
    int const length = 20;
    Vector vector;
    for (int i = 0; i < length; i++)
    {
        vector.PushBack(i);
    }
    
    vector.Print();
    return 0;
}