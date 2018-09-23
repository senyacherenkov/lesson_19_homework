#pragma once
#include <vector>

struct SomeIterator {
    std::vector<int> m_data;
    std::size_t m_pointer = 0;

    SomeIterator() = default;
    SomeIterator(std::vector<int>& data):
        m_data(data),
        m_pointer(0)
    {}

    SomeIterator(std::vector<int>& data, std::size_t pointer):
        m_data(data),
        m_pointer(pointer)
    {}

    bool operator!=(const SomeIterator& other) { return !(*this == other); }
    bool operator==(const SomeIterator& other) { return m_pointer == other.m_pointer; }

    SomeIterator& operator+ (int n) {
        m_pointer += n;
        return *this;
    }

    SomeIterator& operator++() {
        m_pointer++;
        return *this;
    }

    SomeIterator operator++(int) {
        SomeIterator result(*this);
        ++(*this);
        return result;
    }

    int operator*() { return m_data.at(m_pointer); }
    int operator[] (int n) {return m_data.at(n); }
};
