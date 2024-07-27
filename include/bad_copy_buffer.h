//
// Created by Eugene Trubenok on 14/7/2024.
//

#ifndef RTO_BADCOPYBUFFER_H
#define RTO_BADCOPYBUFFER_H


class BadCopyBuffer {
public:
    explicit BadCopyBuffer(int size);

    // ERROR: Default copy constructor (as it is not defined here) will copy the pointer to the data but not the data itself.
    // This will lead to double deletion of the same memory block when the original object is destroyed. As the destructor implementation has `delete[] _data` operator.

    ~BadCopyBuffer();

    [[nodiscard]]
    int getSize() const;
private:
    int* _data;
    int size;
};


#endif //RTO_BADCOPYBUFFER_H
