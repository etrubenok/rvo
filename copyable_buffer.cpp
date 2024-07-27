//
// Created by Eugene Trubenok on 14/7/2024.
//

#include "include/copyable_buffer.h"
#include <iostream>

CopyableBuffer::CopyableBuffer(int size) : size(size) {
    _data = new int[size];
    std::cout << "CopyableBuffer: constructor: " << this << " (_data: " << _data << ")" << std::endl;
}

CopyableBuffer::CopyableBuffer(const CopyableBuffer& other) : size(other.size) {
    _data = new int[size];
    std::cout << "CopyableBuffer: copy constructor: " << this << " (_data: " << _data << ")" << std::endl;
    copyData(other);
}

CopyableBuffer& CopyableBuffer::operator=(const CopyableBuffer& other) {
    // We assign _old_data_ptr for printing the previous address of _data for the demo purpose.
    // cppcheck-suppress constVariablePointer
    auto _old_data_ptr = _data;
    if (this == &other) {
        return *this;
    }
    delete[] _data;
    size = other.size;
    _data = new int[size];
    std::cout << "CopyableBuffer: copy assignment operator: " << this << " (OLD _data: " << _old_data_ptr << ", NEW _data: " << _data << ")" << std::endl;
    copyData(other);
    return *this;
}

void CopyableBuffer::copyData(const CopyableBuffer& other) {
    std::cout << "Data copying... from " << &other << " to " << this << std::endl;
    for (int i = 0; i < size; i++) {
        _data[i] = other._data[i];
    }
}

CopyableBuffer::~CopyableBuffer() {
    std::cout << "CopyableBuffer: destructor: " << this << std::endl;
    delete[] _data;
}

int& CopyableBuffer::operator[](int index) {
    return _data[index];
}

int CopyableBuffer::operator[](int index) const {
    return _data[index];
}

int CopyableBuffer::getSize() const {
    return size;
}