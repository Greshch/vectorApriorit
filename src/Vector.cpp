#include "Vector.h"
#include <iostream>

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
    if (m_size == m_capasity)
    {
        //It should think about realocation/ Now just double.
        Resize(m_capasity * 2);
    }

    m_buffer[m_size] = num;
    ++m_size;
}

void Vector::Insert(size_t pos, int val)
{
    if (pos > m_size)
    {
        std::cerr << "Errror!! It's just tried to insert by invalid index!..\n";
    }

    if (m_size == m_capasity)
    {
        //It should think about realocation/ Now just double.
        Resize(m_capasity * 2);
    }

    for (size_t i = m_size; i > pos; i--)
    {
        m_buffer[i] = m_buffer[i - 1];
    }
    m_buffer[pos] = val;
    ++m_size;
}

void Vector::Resize(size_t size)
{
    if (size > m_capasity)
    {
        Reserve(size);
        for (size_t i = m_size; i < size; i++)
        {
            m_buffer[i] = 0;
        }
    }
}

void Vector::Reserve(size_t newCapasity)
{
    if (newCapasity < m_capasity)
    {
        std::cerr << "It can't reduce capasity\n";
        return;
    }
    else if (newCapasity > m_capasity)
    {
        int* tmp = new int[newCapasity];
        for (size_t i = 0; i < m_size; i++) // copy data from old memeory
        {
            tmp[i] = m_buffer[i];
        }
        Clear(); // free old memory
        m_buffer = tmp; // link to new memory 
        m_capasity = newCapasity;
    }
}

int Vector::PopBack()
{
    if (Empty())
    {
        std::cerr << "Empty vector error!!..\n";
        exit(0);
    }
    --m_size;
    return m_buffer[m_size];
}

void Vector::Remove(int elId)
{
    if (elId >= m_size)
    {
        std::cerr << "Error!! It's just tried to remove by invalid index!..\n";
    }

    for (size_t i = elId; i < m_size - 1; i++)
    {
        m_buffer[i] = m_buffer[i + 1];
    }

    --m_size;
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