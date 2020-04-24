#ifndef FOO_H
#define FOO_H

    #include <string>
    using namespace std;

    // #define TEST_PLACEMENT_NEW_THROW_EXCEPTION

    class Foo
    {
    public:
        Foo();
        Foo(int i);
        virtual ~Foo();
    private:
        int id;
        long data;
        string str;
    public:
        static void* operator new(size_t size);
        static void  operator delete(void *pdead, size_t size);
        static void* operator new[](size_t size);
        static void  operator delete[](void* pdead, size_t size);

        void* operator new(size_t size, void* start);
        void  operator delete(void*, void*);

        void* operator new(size_t size, long extra);    /* placement new(...) overload */
        void  operator delete(void*, long);

        void* operator new(size_t size, long extra, char init);
        // void* operator new(long extra, char init);  /* Error: placement 'operator new' must take 'size_t size' as the first parameter */
        void  operator delete(void*, long, char);


    };

    void investigate_how_operator_new_delete_work(void);
    void investigate_how_placement_new_work(void);

#endif  /* FOO_H */
