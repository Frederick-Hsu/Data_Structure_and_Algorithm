#ifndef HASPTR_H
#define HASPTR_H

    #include <string>
    using namespace std;

    #define PLAIN_POINTER               1
    #define REF_COUNT_SMART_POINTER     2
    #define VALUE_SEMATICS_POINTER      3
    #define MANAGE_POINTER_MEMBER_BY    REF_COUNT_SMART_POINTER

    class HasPtr;
    class U_Ptr;

#if (MANAGE_POINTER_MEMBER_BY == PLAIN_POINTER)
    /* class that has a pointer member that behaves like a plain pointer */
    class HasPtr
    {
    public:
        HasPtr(int *p, int i);
        int* get_ptr() const;
        int get_int() const;
        void set_ptr(int* p);
        void set_int(int i);
        int get_ptr_val() const;
        void set_ptr_val(int val) const;
    private:
        int *ptr;
        int val;
    };
#elif (MANAGE_POINTER_MEMBER_BY == REF_COUNT_SMART_POINTER)
    class HasPtr
    /* smart pointer class: takes ownership of the dynamically allocated object to which it is bound.
     * User code must dynamically allocate an object to initialize a HasPtr,
     * and must not delete that object; the HasPtr class will delete it.
     */
    {
    public:
        HasPtr(int *p, int i);
        HasPtr(const HasPtr& orig);
        HasPtr& operator=(const HasPtr& other);
        ~HasPtr();
    public:
        int* get_ptr() const;
        int get_int() const;
        void set_ptr(int* p);
        void set_int(int i);
        int get_ptr_val() const;
        void set_ptr_val(int i);
    private:
        U_Ptr *ptr;     /* points to use-counted U_Ptr class */
        int val;
    };

    class U_Ptr     /* private class for use by HasPtr only */
    {
        friend class HasPtr;
    private:
        int *ip;
        size_t use;
    private:
        U_Ptr(int *p) : ip(p), use(1)
        {
        }
        ~U_Ptr()
        {
            delete ip;
        }
    };
#elif (MANAGE_POINTER_MEMBER_BY == VALUE_SEMATICS_POINTER)
    class HasPtr
    {
    public:
        HasPtr(const int& p, int i);
        HasPtr(const HasPtr& orig);
        HasPtr& operator=(const HasPtr& other);
        ~HasPtr();
    public:
        int get_ptr_val() const;
        int get_int() const;
        void set_ptr(int *p);
        void set_int(int i);
        int* get_ptr() const;
        void set_ptr_val(int p) const;
    private:
        int* ptr;
        int val;
    };
#endif

#endif  /* HASPTR_H */
