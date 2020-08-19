#ifndef _SGI_DEFALLOC_H_
#define _SGI_DEFALLOC_H_

#include <new>
#include <iostream>

namespace sgi {

template<typename T>
class allocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef ptrdiff_t difference_type;
};

} // namespace sgi
#endif

