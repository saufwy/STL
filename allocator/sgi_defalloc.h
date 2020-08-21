#ifndef _SGI_DEFALLOC_H_
#define _SGI_DEFALLOC_H_

#include <new>
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <algorithm>
#include <climits>

namespace sgi {

void _no_memory () {
    std::cout << "Failed to allocate memory!" << std::endl;
    exit (1);
}

template<typename T>
inline T* _allocate(ptrdiff_t size, T*) {
    std::set_new_handler(_no_memory);
    T* tmp = (T*)::operator new(size * sizeof(T));
    if (tmp == nullptr) {
        std::cout << "alllocte error" << std::endl;
        exit(0);
    }
    return tmp;
}

template<typename T>
inline void _deallocate(T* buffer) {
    ::operator delete(buffer);
}

template<typename T>
class allocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;

    pointer allocate(size_type n) {
        return _allocate(n, pointer(0));
    }
    void deallocate(pointer p) {
        _deallocate(p);
    }


    pointer address(reference x) {
        return &x;
    }

    const_pointer const_address(const_reference x) {
        return &x;
    }

    size_type init_page_size() {
        return std::max(size_type(1), size_type(4096/sizeof(T)));
    }
    size_type max_size() {
        return std::max(size_type(1), size_type(UINT_MAX/sizeof(T)));
    }
};

} // namespace sgi
#endif

