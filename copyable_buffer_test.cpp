//
// Created by etrubenok on 7/27/24.
//

#include <gtest/gtest.h>
#include "include/copyable_buffer.h"

CopyableBuffer createCopyableBuffer(int size) {
    auto b = CopyableBuffer{size};
    return b;
}

TEST(CopyableBuffer, CopyableBuffer) {
    auto buf = createCopyableBuffer(1000);
    std::cout << "TEST: 'buf' size: " << buf.getSize() << " at address: " << &buf << std::endl;
    ASSERT_EQ(1000, buf.getSize());

    // Explicit execution of copy constructor
    auto buf_copied = CopyableBuffer{buf};
    std::cout << "TEST: 'buf_copied' size: " << buf_copied.getSize() << " at address: " << &buf_copied << std::endl;
    ASSERT_EQ(1000, buf_copied.getSize());

    // Assert that the objects are not the same
    ASSERT_NE(&buf, &buf_copied);

    // Assert that their _data pointers are not the same
    ASSERT_NE(buf._data, buf_copied._data);

    auto huge_buf = createCopyableBuffer(10000000);
    std::cout << "TEST: 'huge_buf' size: " << huge_buf.getSize() << " at address: " << &huge_buf << std::endl;
    ASSERT_EQ(10000000, huge_buf.getSize());

    // Should execute copy assignment operator
    buf_copied = huge_buf;
    std::cout << "TEST: 'buf_copied' size: " << buf_copied.getSize() << " at address: " << &buf_copied << std::endl;
    ASSERT_EQ(10000000, buf_copied.getSize());

    // Assert that the objects are not the same
    ASSERT_NE(&huge_buf, &buf_copied);

    // Assert that their _data pointers are not the same
    ASSERT_NE(huge_buf._data, buf_copied._data);
}