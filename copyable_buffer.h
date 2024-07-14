//
// Created by Eugene Trubenok on 14/7/2024.
//

#ifndef RTO_COPYABLEBUFFER_H
#define RTO_COPYABLEBUFFER_H


class CopyableBuffer {
public:
    CopyableBuffer(int size);

    // Copy constructor
    CopyableBuffer(const CopyableBuffer& other);

    ~CopyableBuffer();

    // Copy assignment operator
    CopyableBuffer& operator=(const CopyableBuffer& other);

    int& operator[](int index);

    int operator[](int index) const;

    int getSize() const;

private:
    int* _data;
    int size;

    void copyData(const CopyableBuffer& other);
};


#endif //RTO_COPYABLEBUFFER_H
