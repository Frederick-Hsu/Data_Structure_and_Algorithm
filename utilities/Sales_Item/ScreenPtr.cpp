#include "ScreenPtr.h"
#include "Screen.h"

ScrPtr::ScrPtr(Screen* p) : sp(p), use(1)
{
}

ScrPtr::~ScrPtr()
{
    if (--use == 0)
    {
        delete sp;
    }
}

ScreenPtr::ScreenPtr(Screen* p) : ptr(new ScrPtr(p))
{
}

ScreenPtr::ScreenPtr(const ScreenPtr& orig) : ptr(orig.ptr)
{
    /* copy members and increment the use count */
    ++(ptr->use);
}

ScreenPtr& ScreenPtr::operator=(const ScreenPtr &orig)
{
    ++(orig.ptr->use);
    if (--(ptr->use) == 0)
    {
        delete ptr;
    }
    ptr = orig.ptr;
    return *this;
}

ScreenPtr::~ScreenPtr()
{
    /* if use count goes to zero, delete the ScrPtr* object */
    if (--(ptr->use) == 0)
    {
        delete ptr;
    }
}

Screen& ScreenPtr::operator*()
{
    return *(ptr->sp);
}

Screen* ScreenPtr::operator->()
{
    return ptr->sp;
}

const Screen& ScreenPtr::operator*() const
{
    return *(ptr->sp);
}

const Screen* ScreenPtr::operator->() const
{
    return ptr->sp;
}

CheckedPtr::CheckedPtr(int* b, int* e) : beg(b), end(e), curr(b)
{
}

CheckedPtr& CheckedPtr::operator++()
{
    if (curr == end)
    {
        throw out_of_range("increment past the end of CheckedPtr");
    }
    ++curr;
    return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
    if (curr == beg)
    {
        throw out_of_range("decrement past the beginning of CheckedPtr");
    }
    --curr;
    return *this;
}

CheckedPtr CheckedPtr::operator++(int)
{
    /* no check needed here, the call to prefix increment will do the check. */
    CheckedPtr ret(*this);      /* save current value */
    ++*this;                    /* advance one element, checking the increment */
    return ret;                 /* return saved state */
}

CheckedPtr CheckedPtr::operator--(int)
{
    CheckedPtr ret(*this);
    --*this;                    /* move backward one element and check */
    return ret;
}

int CheckedPtr::operator[](int index)
{
    int* ptr = beg;
    for (int n = 0; n < index; ++n)
    {
        if (ptr == end)
        {
            return *ptr;
        }
        ptr++;
    }
    return *ptr;
}

int& CheckedPtr::operator*()
{
    return *curr;
}

unsigned int AbsInt::operator()(int val)
{
    return ((val < 0) ? (-val) : (val));
}
