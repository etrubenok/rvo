//
// Created by etrubenok on 7/27/24.
//

#include <gtest/gtest.h>
#include "include/bad_copy_buffer.h"

BadCopyBuffer createBadBuffer(const int size) {
    auto b = BadCopyBuffer{size};
    return b;
}

// Demonstrates double free error.
TEST(BadCopyBuffer, DoubleFree) {
    EXPECT_DEATH({
        auto bad_buf = createBadBuffer(1000);
        // As the copy constructor is not defined, the code will compile, but it will crash with double free error as the internal data pointer points to the same memory location.
        // bad_buf._data points to the same memory location as the bad_copy_buf._data
        auto bad_buf_copied = bad_buf;
        }, ".*double free or corruption.*");
}