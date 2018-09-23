#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>
#include <vector>
#include <list>
#include <iostream>

#include "random_access_iterator_custom.h"
#include "my_iterator.h"

BOOST_AUTO_TEST_SUITE(test_suite_main)

template <typename T>
class UserContainer {
public:
    UserContainer() = default;


    T begin() {
        BOOST_CONCEPT_ASSERT((RandomAccessIteratorCustom<T>));
        return T();
    }

    T end() {
        BOOST_CONCEPT_ASSERT((RandomAccessIteratorCustom<T>));
        return T();
    }
};

BOOST_AUTO_TEST_CASE(check_vector_iterator)
{
    UserContainer<std::vector<int>::iterator> container;

    for(auto element: container)
        std::cout << element;
}

BOOST_AUTO_TEST_CASE(check_list_iterator)
{
    UserContainer<std::list<int>::iterator> container;

    for(auto element: container)
        std::cout << element;
}

BOOST_AUTO_TEST_CASE(check_filter_any_valid)
{
    UserContainer<SomeIterator> container;

    for(auto element: container)
        std::cout << element;
}

BOOST_AUTO_TEST_SUITE_END()
