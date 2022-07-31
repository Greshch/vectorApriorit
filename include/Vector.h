#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

class Vector {
public:
    Vector();
    Vector(size_t capasity);
    void PushBack(int num);
    int PopBack();
    void Clear();
    ~Vector();

private:
    int* m_buffer = nullptr;
    size_t m_size = 0;
    size_t m_capasity;
    static const size_t capasityDefault = 10;
};


#endif
