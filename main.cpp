#include <iostream>
#include "copyable_buffer.h"
#include "bad_copy_buffer.h"


CopyableBuffer createCopyableBuffer(int size) {
    auto b = CopyableBuffer{size};
    return b;
}

BadCopyBuffer createBadCopyBuffer(int size) {
    auto b = BadCopyBuffer{size};
    return b;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto buf = createCopyableBuffer(1000);
    std::cout << "main: 'buf' size: " << buf.getSize() << " at address: " << &buf << std::endl;
    auto buf_copied = buf;
    std::cout << "main: 'buf_copied' size: " << buf_copied.getSize() << " at address: " << &buf_copied << std::endl;

    auto huge_buf = createCopyableBuffer(10000000);
    std::cout << "main: 'huge_buf' size: " << huge_buf.getSize() << " at address: " << &huge_buf << std::endl;

    // Should execute copy assignment operator
    buf_copied = huge_buf;
    std::cout << "main: 'buf_copied' size: " << buf_copied.getSize() << " at address: " << &buf_copied << std::endl;

    auto bad_copy_buf = createBadCopyBuffer(1000);
    std::cout << "main: 'bad_copy_buf' size: " << bad_copy_buf.getSize() << " at address: " << &bad_copy_buf << std::endl;

    // If the copy constructor is not defined, the code will compile but it will crash with double free error as the internal data pointer points to the same memory location.
    auto bad_copy_buf_copied = bad_copy_buf;

    return 0;
}
