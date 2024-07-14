//
// Created by Eugene Trubenok on 14/7/2024.
//

#ifndef RTO_BADCOPYBUFFER_H
#define RTO_BADCOPYBUFFER_H


class BadCopyBuffer {
public:
    BadCopyBuffer(int size);

    // ERROR: Default copy constructor (as it is not defined here) will cause double free error

    ~BadCopyBuffer();

    int getSize() const;
private:
    int* _data;
    int size;
};


#endif //RTO_BADCOPYBUFFER_H
