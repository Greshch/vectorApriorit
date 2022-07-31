#include "Vector.h"

Vector::Vector() :
                    Vector(Vector::capasityDefault)
{

}

Vector::Vector(size_t capasity) :
                    m_capasity(capasity),
                    m_buffer(new int[m_capasity])
{

}

Vector::~Vector()
{
    Clear();
}

void Vector::Clear()
{
    delete[] m_buffer;
    m_buffer = nullptr;
    m_capasity = capasityDefault;
    m_size = 0;
}
