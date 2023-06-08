#pragma once

#include <iostream>
#include <list>
#include <exception>
using namespace std;

template <typename T>
struct MyComparator {
	bool operator()(T a, T b) const {
		return a < b;
	}
};


// any templates?
template <typename T>
class PriorityQueue{
   
public:
    // You need to complete the implement : 
    void push(const T& element) {
        auto it = queue.begin();
        while (it != queue.end() && comparator(*it, element)) {
            ++it;
        }
        queue.insert(it, element);
    }
    T poll() {
        if (queue.empty()) {
            throw std::runtime_error("PriorityQueue is empty!");
        }
        T element = queue.front();
        queue.pop_front();
        return element;
    }

private:
	// add relevant data members
	list<T> queue;
	MyComparator<T> comparator;
};


