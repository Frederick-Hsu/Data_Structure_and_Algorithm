#ifndef FILE_H
#define FILE_H

    typedef unsigned int Bit;

    class File
    {
    private:
        Bit mode : 2;
        Bit modified : 1;
        Bit prot_owner : 3;
        Bit prot_group : 3;
        Bit prot_world : 3;
    public:
        void write();
        void close();
        inline int isRead();
        inline int isWrite();
    };

    enum {READ = 01, WRITE = 02};       /* File modes */

    void access_bit_field(void);

    class Foo
    {
    public:
        Foo(const volatile Foo&);   /* copy from a volatile object */
        /* assign from a volatile object to a non-volatile object */
        Foo& operator=(volatile const Foo&);
        /* assign from a voltatile object to a volatile object */
        Foo& operator=(volatile const Foo&) volatile;
    };

#endif  /* FILE_H */
