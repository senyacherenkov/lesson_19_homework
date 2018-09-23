#pragma once

#include <boost/concept_check.hpp>

template <typename T>
struct RandomAccessIteratorCustom {
        BOOST_CONCEPT_USAGE(RandomAccessIteratorCustom) {
            int n;
            //forward iterator requirements
            i++;    // required postincrement operator
            ++i;    // required preincrement operator
            //backward iterator requirements
            i--;    // required postdecrement operator
            --i;    // required preincrement operator
            //random access requirements
            r += n;     // required addition assignment operator, which returns T&
            i = a + n;  // required addition operator, which returns T
            i = n + a;  // required addition operator, which returns T
            r -= n;     // required substraction assignment operator, which returns T&
            a = i - n;  // required substraction operator, which returns T
            n = b - a;  // required substraction operator for T types, which returns integer difference
            i[n];       // required subscript operator, which returns value
            a < b;      // required less operator, which returns bool
            a > b;      // required greater operator, which returns bool
            a >= b;     // required not greater operator, which returns bool
            a <= b;     // required not less operator, which returns bool
        }

    private:
        T i, a, b;
        T& r, m;
};
