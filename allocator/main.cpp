#include <string>
#include <memory>
#include <cstdlib>
#include <iostream>

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

int main() {
    int size = 10;
    std::allocator<Object> alloc;
    Object* p = alloc.allocate(size);
    for (int i = 0; i < size; i++) {
        alloc.construct(&p[i], i);
        alloc.destroy(&p[i]);
    }
    alloc.deallocate(p, size);
    return 0;
}

