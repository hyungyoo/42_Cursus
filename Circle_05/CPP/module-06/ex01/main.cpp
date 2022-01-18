#include <iostream>

struct Data
{
    int x;
    int y;
};

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data data;

    data.x = 123;
    data.y = 987;
    std::cout << "x: " << data.x << std::endl;
    std::cout << "y: " << data.y << std::endl;
    std::cout << "ptr: " << &data << std::endl;

    uintptr_t raw = serialize(&data);
    Data* ptr = deserialize(raw);

    std::cout << "x: " << ptr->x << std::endl;
    std::cout << "y: " << ptr->y << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
}