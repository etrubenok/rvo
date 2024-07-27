//
// Created by etrubenok on 7/27/24.
//
#include <gtest/gtest.h>
#include "include/string_holder.h"

// No copying for str is happening here, so the data pointer should be the same as the original string
const void* print_string_internals(const std::string& str, const std::string& prefix) {
    // Print a pointer to the string
    std::cout << "--- " << prefix << "---: Pointer to the string: " << &str << std::endl;

    auto str_data_ptr = static_cast<const void*>(str.data());
    // Prints an address of the string data
    std::cout << "--- " << prefix << "---: Address of the string data: " << str_data_ptr << std::endl;
    // Prints size and capacity of the string
    std::cout << "--- " << prefix << "---: Size: " << str.size() << " Capacity: " << str.capacity() << std::endl;

    return str_data_ptr;
}

TEST(StringHolder, CopyTest) {
    std::string str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent sit amet tortor a justo efficitur vehicula. Curabitur vulputate nulla sed dui pharetra, ac interdum metus aliquam. Donec in purus ut turpis condimentum dapibus. Sed at felis arcu. Phasellus consectetur gravida.";
    auto str_data_ptr = static_cast<const void*>(str.data());
    auto str_data_ptr_from_func = print_string_internals(str, "str");
    ASSERT_EQ(str_data_ptr, str_data_ptr_from_func);

    StringHolder sh(str);

    str_data_ptr_from_func = print_string_internals(sh.str, "sh");
    auto sh_data_ptr = static_cast<const void*>(sh.str.data());
    ASSERT_EQ(sh_data_ptr, str_data_ptr_from_func);

    // Data pointer should be different from the original string, which proves that the string is copied
    ASSERT_NE(str_data_ptr, static_cast<const void*>(sh.str.data()));
}

TEST(StringHolder, MoveTest) {
    std::string str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent sit amet tortor a justo efficitur vehicula. Curabitur vulputate nulla sed dui pharetra, ac interdum metus aliquam. Donec in purus ut turpis condimentum dapibus. Sed at felis arcu. Phasellus consectetur gravida.";
    auto str_data_ptr = static_cast<const void*>(str.data());
    auto str_data_ptr_from_func = print_string_internals(str, "str");
    ASSERT_EQ(str_data_ptr, str_data_ptr_from_func);

    StringHolder sh(std::move(str));

    str_data_ptr_from_func = print_string_internals(sh.str, "sh");
    auto sh_data_ptr = static_cast<const void*>(sh.str.data());
    ASSERT_EQ(sh_data_ptr, str_data_ptr_from_func);

    // Data pointer should be the same as the original string, which proves that the string is moved
    ASSERT_EQ(str_data_ptr, static_cast<const void*>(sh.str.data()));
}

TEST(StringHolder, ShortMoveTest) {
    std::string str = "short";
    auto str_data_ptr = static_cast<const void*>(str.data());
    auto str_data_ptr_from_func = print_string_internals(str, "str");
    ASSERT_EQ(str_data_ptr, str_data_ptr_from_func);

    StringHolder sh(std::move(str));

    str_data_ptr_from_func = print_string_internals(sh.str, "sh");
    auto sh_data_ptr = static_cast<const void*>(sh.str.data());
    ASSERT_EQ(sh_data_ptr, str_data_ptr_from_func);

    // As it is the short string, the data was copied instead of moved, so the data pointer should be different
    ASSERT_NE(str_data_ptr, static_cast<const void*>(sh.str.data()));
}