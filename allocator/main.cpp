#include <string>
#include <memory>
#include <cstdlib>
#include <iostream>

#include "sgi_defalloc.h"

class Object {
public:
    Object(int id) {
        _id = id;
        std::cout << "construct " << _id << std::endl;
    }
    ~Object() {
        std::cout << "destruct " << _id << std::endl;
    }

protected:
    int _id;
};

void test_std_alloc() {
    // std
    int size = 10;
    std::allocator<Object> alloc;
    Object* p = alloc.allocate(size);
    for (int i = 0; i < size; i++) {
        alloc.construct(&p[i], i);
        alloc.destroy(&p[i]);
    }
    alloc.deallocate(p, size);
}

void test_sgi_alloc() {
    int size = 10;
    sgi::allocator<Object> alloc;
    Object* p = alloc.allocate(size);
    std::cout << std::hex << p << std::endl;
    alloc.deallocate(p);
}

int main() {
    test_sgi_alloc();
    return 0;
}

