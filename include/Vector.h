#pragma

class Vector {
public:
    Vector();
    Vector(size_t capasity);
    Vector(int val, size_t size);
    Vector(Vector const& origin);
    void PushBack(int num);
    int PopBack();
    size_t Size() const;
    bool Empty() const;
    void Clear();
    void Resize(size_t size);
    void Reserve(size_t n);
    void Insert(size_t pos, int val);
    void Remove(int elId);
    ~Vector();
    void Print() const;

private:
    int* m_buffer = nullptr;
    size_t m_size = 0;
    size_t m_capasity;
    static const size_t capasityDefault = 10;
};

