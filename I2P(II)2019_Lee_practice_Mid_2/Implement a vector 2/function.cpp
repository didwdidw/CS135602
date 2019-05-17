#include "function.h"
#include <iostream>

oj::Vector::Vector() {
    begin_ = NULL;
    end_ = NULL;
    last_ = NULL;
}

std::size_t oj::Vector::capacity() const {
    return end_ - begin_;
}

std::size_t oj::Vector::size() const {
    return last_ - begin_;
}

void oj::Vector::pop_back() {
    if (size()) {
        last_ --;
    }
}

void oj::Vector::push_back(data_t val) {
    if (size() == capacity())
        reserve(std::max(capacity() + 1, capacity() * 3));

    *last_ = val;
    last_ ++;
}

void oj::Vector::insert(std::size_t pos,std::size_t count,data_t val) {
    int i;

    if (size() + count > capacity())
        reserve(std::max((size_t)(capacity()*1.5), capacity()+count));

    for (i = size()+count-1; i >= pos+count; i--){
        begin_[i] = begin_[i-count];
    }
    for (i = pos; i < pos+count; i++){
        begin_[i] = val;
    }

    last_ += count;
}

void oj::Vector::reserve(std::size_t new_capacity) {
    if (new_capacity > capacity()) {
        size_t oldcapacity = capacity();
        size_t oldsize = size();
        data_t* newbegin = new data_t[new_capacity];
        int i;
        for (i = 0; i < oldsize; i++){
            newbegin[i] = begin_[i];
        }
        delete [] begin_;
        begin_ = newbegin;
        last_ = begin_ + oldsize;
        end_ = begin_ + new_capacity;
    }
}

void oj::Vector::resize(std::size_t new_size) {
    int i;
    size_t oldcapacity = capacity();
    size_t oldsize = size();

    if (new_size > oldcapacity) {
        reserve(new_size);
        for (i = oldsize; i < new_size; i++)
            begin_[i] = 0;
        last_ = begin_ + new_size;
    }
    else if (new_size > oldsize) {
        for (i = oldsize; i < new_size; i++)
            begin_[i] = 0;
        last_ = begin_ + new_size;
    }
    else if (new_size < oldsize) {
        last_ = begin_ + new_size;
    }

}

oj::Vector::~Vector() {
    delete [] begin_;
}
