#include "Vector.h"

Vector::Vector() :
                    Vector( Vector::capasityDefault)
{

}

Vector::Vector(size_t capasity) :
                    m_capasity(capasity),
                    m_buffer(new int[m_capasity])
{

}
