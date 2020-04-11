#ifndef SCREENPTR_H
#define SCREENPTR_H

    #include <stddef.h>

    class Screen;
    class ScreenPtr;

    class ScrPtr
    {
        friend class ScreenPtr;
    private:
        Screen* sp;
        size_t use;
    private:
        ScrPtr(Screen* p);
        ~ScrPtr();
    };

    /* smart pointer: Users pass to a pointer to a dynamically allocated Screen,
     *                which is automatically destroyed when the last ScreenPtr goes away.
     */
    class ScreenPtr
    {
    public:
        /* no default constructor: ScreenPtr must be bound to an object. */
        ScreenPtr(Screen* p);
        ScreenPtr(const ScreenPtr& orig);
        ScreenPtr& operator=(const ScreenPtr& orig);
        ~ScreenPtr();
    public:
        Screen& operator*();
        Screen* operator->();
        const Screen& operator*() const;
        const Screen* operator->() const;
    private:
        ScrPtr* ptr;
    };

    /* smart pointer: Checks access to elements throw an out_of_range exception
     *                if attempt to access a nonexistent element.
     *                users allocate and free the array
     */
    class CheckedPtr
    {
    public:
        CheckedPtr(int *begin, int *end);
    public:
        /* prefix operators */
        CheckedPtr& operator++();
        CheckedPtr& operator--();
        /* postfix operators */
        CheckedPtr operator++(int);
        CheckedPtr operator--(int);
        int operator[](int index);
        int& operator*();
    private:
        int* beg;       /* pointer to beginning of the array */
        int* end;       /* one past the end of array */
        int* curr;      /* current position within the array */
    };

    struct AbsInt
    {
        unsigned int operator()(int val);
    };

#endif  /* SCREENPTR_H */
