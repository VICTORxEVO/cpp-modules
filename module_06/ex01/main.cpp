#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.value = 42;
    data.name = "Hello";

    std::cout << "Original pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "Success: pointers match!" << std::endl;
    else
        std::cout << "Error: pointers do not match!" << std::endl;

    return 0;
}
