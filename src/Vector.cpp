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

Vector::Vector(int val, size_t size) :
        Vector(size)
{
    m_size = size;
    for (size_t i = 0; i < m_size; i++)
    {
        m_buffer[i] = val;
    }
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

bool Vector::Empty() const
{
    return m_size == 0;
}

void Vector::PushBack(int num)
{
    //if (m_size == m_capasity - 1) // if buffer is full - realocate memory and copy data
    //{
    //    //std::cout << "#realloc m_size = " << m_size << "\n";
    //    // Allocate new memory for data
    //    m_capasity *= 2;
    //    int* tmp = new int[m_capasity];
    //    for (size_t i = 0; i < m_size; i++) // copy data from old memeory
    //    {
    //        tmp[i] = m_buffer[i];
    //    }
    //    
    //    Clear(); // free old memory

    //    m_buffer = tmp; // link to new memory
    //}

    if (m_size >= m_capasity)
    {
        //It should think about realocation/ Now just double.
        Resize(m_capasity * 2);
    }

    m_buffer[m_size++] = num;
}

void Vector::Resize(size_t size)
{
    //m_capasity = size;
    Reserve(size);

    int* tmp = new int[m_capasity];
    for (size_t i = 0; i < m_capasity; i++) // copy data from old memeory
    {
        if (i < m_size) // copy old values
        {
            tmp[i] = m_buffer[i];
        }
        else // fill new reserves by 0.
        {
            tmp[i] = 0;
        }
    }
    Clear(); // free old memory
    m_buffer = tmp; // link to new memory  
}

void Vector::Reserve(size_t n)
{
    m_capasity = n;
}

int Vector::PopBack()
{
    if (Empty())
    {
        std::cerr << "Empty vector error!!..\n";
        exit(0);
    }
    return m_buffer[--m_size];
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