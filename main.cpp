#include <iostream>
#include "include/copyable_buffer.h"
#include "include/bad_copy_buffer.h"


CopyableBuffer createCopyableBuffer(int size) {
    auto b = CopyableBuffer{size};
    return b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto buf = createCopyableBuffer(1000);
    buf.operator[](0) = 42;
    std::cout << buf.operator[](0) << std::endl;

    return 0;
}
