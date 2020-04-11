#include "HasPtr.h"

#if (MANAGE_POINTER_MEMBER_BY == PLAIN_POINTER)
    HasPtr::HasPtr(int* p, int i) : ptr(p), val(i)
    {
    }

    int* HasPtr::get_ptr() const
    {
        return ptr;
    }

    int HasPtr::get_int() const
    {
        return val;
    }

    void HasPtr::set_ptr(int *p)
    {
        ptr = p;
    }

    void HasPtr::set_int(int i)
    {
        val = i;
    }

    int HasPtr::get_ptr_val() const
    {
        return *ptr;
    }

    void HasPtr::set_ptr_val(int val) const
    {
        *ptr = val;
    }
#elif (MANAGE_POINTER_MEMBER_BY == REF_COUNT_SMART_POINTER)
    HasPtr::HasPtr(int *p, int i) : ptr(new U_Ptr(p)), val(i)
    /* HasPtr owns the pointer; p must have been dynamically allocated. */
    {
    }

    HasPtr::HasPtr(const HasPtr& orig) : ptr(orig.ptr), val(orig.val)
    /* copy members and increment the use count. */
    {
        ++ptr->use;
    }

    HasPtr& HasPtr::operator=(const HasPtr& other)
    {
        ++other.ptr->use;       /* increment use count on right operant */
        if (--ptr->use == 0)
        {
            delete ptr;     /* if use count goes to 0 on this object, delete it. */
        }
        ptr = other.ptr;
        val = other.val;
        return *this;
    }

    HasPtr::~HasPtr()
    {
        /* if use count decrease down to 0, delete the U_Ptr object. */
        if (--ptr->use == 0)
        {
            delete ptr;
        }
    }

    int* HasPtr::get_ptr() const
    {
        return ptr->ip;
    }

    int HasPtr::get_int() const
    {
        return val;
    }

    void HasPtr::set_ptr(int* p)
    {
        ptr->ip = p;
    }

    void HasPtr::set_int(int i)
    {
        val = i;
    }

    int HasPtr::get_ptr_val() const
    {
        return *(ptr->ip);
    }

    void HasPtr::set_ptr_val(int i)
    {
        *(ptr->ip) = i;
    }
#elif (MANAGE_POINTER_MEMBER_BY == VALUE_SEMATICS_POINTER)
    HasPtr::HasPtr(const int& p, int i) : ptr(new int(p)), val(i)
    {    
    }

    HasPtr::HasPtr(const HasPtr& orig) : ptr(new int(*(orig.ptr))), val(orig.val)
    {
    }

    HasPtr& HasPtr::operator=(const HasPtr &other)
    {
        *ptr = *other.ptr;
        val = other.val;
        return *this;
    }

    HasPtr::~HasPtr()
    {
        delete ptr;
    }

    int HasPtr::get_ptr_val() const
    {
        return *ptr;
    }

    int HasPtr::get_int() const
    {
        return val;
    }

    void HasPtr::set_ptr(int *p)
    {
        ptr = p;
    }

    void HasPtr::set_int(int i)
    {
        val = i;
    }

    int* HasPtr::get_ptr() const
    {
        return ptr;
    }

    void HasPtr::set_ptr_val(int p) const
    {
        *ptr = p;
    }
#endif
