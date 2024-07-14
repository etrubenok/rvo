//
// Created by Eugene Trubenok on 14/7/2024.
//

#include "bad_copy_buffer.h"
#include <iostream>

BadCopyBuffer::BadCopyBuffer(int size) : size(size) {
    _data = new int[size];
    std::cout << "BadCopyBuffer: constructor: " << this << " (_data: " << _data << ")" << std::endl;
}

BadCopyBuffer::~BadCopyBuffer() {
    std::cout << "BadCopyBuffer: destructor: " << this << " (_data: " << _data << ")" << std::endl;
    delete[] _data;
}

int BadCopyBuffer::getSize() const {
    return size;
}

