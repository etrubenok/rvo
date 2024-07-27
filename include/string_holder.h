//
// Created by etrubenok on 7/27/24.
//

#ifndef RVO_STRING_HOLDER_H
#define RVO_STRING_HOLDER_H


#include <string>
#include <utility>
#ifdef UNIT_TEST
#include <gtest/gtest.h>
#endif

class StringHolder {
public:
    // Construct a StringHolder object with the given string.

    // Copy constructor
    explicit StringHolder(const std::string& str) : str(str) {}

    // Copy assignment operator
    StringHolder& operator=(const std::string& str) {
        this->str = str;
        return *this;
    }

    // Move constructor
    explicit StringHolder(std::string&& str) : str(std::move(str)) {}

    // Move assignment operator
    StringHolder& operator=(std::string&& str) {
        this->str = std::move(str);
        return *this;
    }

private:
#ifdef UNIT_TEST
    // For testing purposes to access private members
    FRIEND_TEST(StringHolder, CopyTest);
    FRIEND_TEST(StringHolder, MoveTest);
    FRIEND_TEST(StringHolder, ShortMoveTest);
#endif
    std::string str;
};


#endif //RVO_STRING_HOLDER_H
