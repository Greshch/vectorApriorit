#include "Vector.h"

Vector::Vector() :
                    Vector(Vector::capasityDefault)
{

}

Vector::Vector(size_t capasity) :
                    m_capasity(capasity),
                    m_buffer(new int[capasity]) // ?? why m_buffer(new int[m_capasity]) is not work
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
}

size_t Vector::Size() const
{
    return m_size;
}

void Vector::PushBack(int num)
{
    if (m_size == m_capasity - 1) // if buffer is full - realocate memory and copy data
    {
        //std::cout << "#realloc m_size = " << m_size << "\n";
        // Allocate new memory for data
        m_capasity *= 2;
        int* tmp = new int[m_capasity];
        for (size_t i = 0; i < m_size; i++) // copy data from old memeory
        {
            tmp[i] = m_buffer[i];
        }
        
        Clear(); // free old memory

        m_buffer = tmp; // link to new memory
    }

    m_buffer[m_size++] = num;
}

void Vector::Print() const
{
    for (size_t i = 0; i < m_size; i++)
    {
        std::cout << m_buffer[i] << "\t";
        if ((i + 1) % 10 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\n";    
}