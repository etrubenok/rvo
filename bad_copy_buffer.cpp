//
// Created by Eugene Trubenok on 14/7/2024.
//

#include "include/bad_copy_buffer.h"
#include <iostream>

BadCopyBuffer::BadCopyBuffer(int size) : size(size) {
    // We intentionally suppress these warnings here to demonstrate the buggy memory management implementation
    // cppcheck-suppress noCopyConstructor
    // cppcheck-suppress noOperatorEq
    _data = new int[size];
    std::cout << "BadCopyBuffer: constructor: " << this << " (_data: " << _data << ")" << std::endl;
}

BadCopyBuffer::~BadCopyBuffer() {
    std::cout << "BadCopyBuffer: destructor: " << this << " (_data: " << _data << ")" << std::endl;
    // As we do not implement copy constructor and assignment operator, the _data array will be deleted multiple times.
    // This will lead to a crash.
    delete[] _data;
}

int BadCopyBuffer::getSize() const {
    return size;
}

