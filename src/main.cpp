#include "Vector.h"



int main(int argc, char** argv) {
    int const length = 20;
    std::cout << "###\n";
    Vector vector(777, length);
    vector.Print();
    return 0;
}