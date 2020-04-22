#ifndef VECTOR_H
#define VECTOR_H

    #include <memory>
    #include <algorithm>

    #define USE_ALLOCATOR_CLASS                 1
    #define USE_OPERATOR_NEW_DELETE             2
    #define MEM_ALLOCATE_DEALLOCATE_METHOD      USE_OPERATOR_NEW_DELETE

    template<class Type> class Vector;

    /* pseudo-implementation of memory allocation strategy for a vector-like class */
    template<class Type> class Vector
    {
    public:
        Vector();
        void push_back(const Type&);
    private:
        static std::allocator<Type> alloc;      /* object to get raw memory */
        void reallocate();                      /* get more space and copy existing elements */
        Type* elements;                         /* points to first element in the array */
        Type* first_free;                       /* pointer to first free element in the array */
        Type* end;                              /* pointer to one past the end of the array */
    };

/*================================================================================================*/

    template<class Type> std::allocator<Type> Vector<Type>::alloc = std::allocator<Type>();

    template<class Type> Vector<Type>::Vector() : elements(0), first_free(0), end(0)
    {
    }

    template<class Type> void Vector<Type>::push_back(const Type& t)
    {
        /* are we out of space? */
        if (first_free == end)
        {
            reallocate();       /* gets more space and copies existing elements to it */
        }
#if (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_ALLOCATOR_CLASS)
        alloc.construct(first_free, t);
#elif (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_OPERATOR_NEW_DELETE)
        /* copy t into element addressed by first_free */
        new (first_free) Type(t);
#endif
        ++first_free;
    }

    template<class Type> void Vector<Type>::reallocate()
    {
        /* compute size of current array and allocate space for twice as many elements */
        std::ptrdiff_t size = first_free - elements;
        std::ptrdiff_t newcapacity = 2 * std::max<std::ptrdiff_t>(size, 1);
#if (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_ALLOCATOR_CLASS)
        /* allocate space to hold newcapacity number of elements of Type */
        Type* newelements = alloc.allocate(newcapacity);
#elif (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_OPERATOR_NEW_DELETE)
        /* allocate unconstructed memory to hold newcapacity elements of Type */
        Type* newelements = static_cast<Type*>(operator new[](newcapacity * sizeof(Type)));
#endif

        /* construct copies of the existing elements in the new space */
        std::uninitialized_copy(elements, first_free, newelements);
        /* destroy the old elements in reverse order */
        for (Type* p = first_free; p != elements; /* empty */)
        {
#if (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_ALLOCATOR_CLASS)
            alloc.destroy(--p);
#elif (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_OPERATOR_NEW_DELETE)
            /* explicitly call the destructor, only clean the object itself,
             * DOES NOT free the memory space.
             */
            p->~Type();
#endif
        }

        /* deallocate cannot be called on a null pointer */
        if (elements)
        {
#if (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_ALLOCATOR_CLASS)
            /* return the memory that held the elements */
            alloc.deallocate(elements, end - elements);
#elif (MEM_ALLOCATE_DEALLOCATE_METHOD == USE_OPERATOR_NEW_DELETE)
            /* operator delete[]() function will not execute destructor,
             * it only free the memory space which elements specified.
             */
            operator delete[](elements);
#endif
        }
        /* make our data structure point to the new elements */
        elements = newelements;
        first_free = elements + size;
        end = elements + newcapacity;
    }

#endif  /* VECTOR_H */
