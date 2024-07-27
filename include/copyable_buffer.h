//
// Created by Eugene Trubenok on 14/7/2024.
//

#ifndef RTO_COPYABLEBUFFER_H
#define RTO_COPYABLEBUFFER_H

#ifdef UNIT_TEST
#include <gtest/gtest.h>
#endif

class CopyableBuffer {
public:
    explicit CopyableBuffer(int size);

    // Copy constructor
    CopyableBuffer(const CopyableBuffer& other);

    ~CopyableBuffer();

    // Copy assignment operator
    CopyableBuffer& operator=(const CopyableBuffer& other);

    int& operator[](int index);

    int operator[](int index) const;

    [[nodiscard]]
    int getSize() const;

private:
#ifdef UNIT_TEST
    // For testing purposes to access private members
    FRIEND_TEST(CopyableBuffer, CopyableBuffer);
#endif
    int* _data;
    int size;

    void copyData(const CopyableBuffer& other);
};


#endif //RTO_COPYABLEBUFFER_H
