#ifndef CACHEDOBJ_H
#define CACHEDOBJ_H

    #include <cctype>
    #include <memory>
    #include <stdexcept>

    template<class elemType> class CachedObj;

    /* memory allocation class :
     * Pre-allocates objects and maintains a freelist of objects that are unused.
     * When an object is freed, it is put back on the freelist.
     * The memory is only returned back to OS when the program exits.
     */
    template<class elemType> class CachedObj
    {
    public:
        void* operator new(std::size_t);
        void  operator delete(void*, std::size_t);
        virtual ~CachedObj();
    protected:
        elemType* next;
    private:
        static void add_to_freelist(elemType*);
        static std::allocator<elemType> alloc_mem;
        static elemType* freeStore;
        // static const std::size_t chunk;
    };

/*================================================================================================*/

    template<class elemType> std::allocator<elemType> CachedObj<elemType>::alloc_mem;
    template<class elemType> elemType* CachedObj<elemType>::freeStore = 0;
    // template<class elemType> const std::size_t CachedObj<elemType>::chunk = 24;

    template<class elemType> CachedObj<elemType>::~CachedObj<elemType>()
    {
    }

    template<class elemType> void CachedObj<elemType>::add_to_freelist(elemType* p)
    {   /* puts object at head of freelist */
        p->CachedObj<elemType>::next = freeStore;
        freeStore = p;
    }

    template<class elemType> void* CachedObj<elemType>::operator new(std::size_t sz)
    {
        /* new should only be asked to build an "elemType", not an object derived from
         * "elemType"; check that right size is required.
         */
        if (sz != sizeof(elemType))
        {
            throw std::runtime_error("CachedObj: wrong size object in operator new");
        }

        std::size_t size = sz; // + 2 * sizeof(elemType);
        if (!freeStore)     /* the list is empty, grab a new chunk of memory */
        {
            /* allocate chunk number of objects of type "elemType" */
            elemType* array = alloc_mem.allocate(size);
            /* now set the next pointers for each object in the allocated memory */
            for (std::size_t i = 0; i != size; ++i)
            {
                add_to_freelist(&array[i]);
            }
        }
        elemType *p = freeStore;
        freeStore = freeStore->CachedObj<elemType>::next;
        return p;
    }

    template<class elemType> void CachedObj<elemType>::operator delete(void *p, std::size_t)
    {
        if (p != 0)
        {   /* put the "deleted" object back at head of freelist */
            add_to_freelist(static_cast<elemType*>(p));
        }
    }

#endif  /* CACHEDOBJ_H */
