#ifndef MISC_H
#define MISC_H

    #include <cstddef>

    #define ORDINARY_FRIEND             1
    #define ORDINARY_TEMPLATE_FRIEND    2
    #define SPECIFIC_TEMPLATE_FRIEND    3
    #define SAME_TYPE_TEMPLATE_FRIEND   4

    #define TEMPLATE_FRIEND_RELATIONSHIP    SAME_TYPE_TEMPLATE_FRIEND

    class FooBar;
    template<class Type> class Bar;
    template<class Type> class Foo1;
    template<class Type> class Foo2;
    template<class Type> class Foo3;

    void fnct(void);
    template<class Type> void templ_fnct1(const Type&);
    template<class Type> void templ_fnct2(const Type&);
    template<class Type> void templ_fnct3(const Type&);

    template<class Type>
    class Bar
    {
        #if (TEMPLATE_FRIEND_RELATIONSHIP == ORDINARY_FRIEND)
            /* grants access to ordinary, nontemplate class and function */
            friend class FooBar;
            friend void fnct();
        #elif (TEMPLATE_FRIEND_RELATIONSHIP == ORDINARY_TEMPLATE_FRIEND)
            /* grants access to Foo or temp_fnct() parameterized by any type */
            template<class T> friend class Foo1;
            template<class T> friend void temp_fnct(const T&);
        #elif (TEMPLATE_FRIEND_RELATIONSHIP == SPECIFIC_TEMPLATE_FRIEND)
            /* grants access to a single specific instance parameterized by char* */
            friend class Foo2<char*>;
            friend void templ_fnct2<char*>(char* const &);
        #elif (TEMPLATE_FRIEND_RELATIONSHIP == SAME_TYPE_TEMPLATE_FRIEND)
            /* each instantiation of Bar grants access to the version of
             * Foo3 or templ_fnct3() instantiated with the same type.
             */
            friend class Foo3<Type>;
            friend void templ_fnct3<Type>(const Type&);
        #endif
    public:
        Bar(const Type& mbr) : member(mbr) {}
    private:
        Type member;
    protected:
    };

    template<class Type> class Foo1
    {
    public:
        static std::size_t count()
        {
            return ctr;
        }
    private:
        static std::size_t ctr;
    };

    void instantiate_template_friend_objects(void);
    void access_class_template_static_member(void);

/*=================================================================================================*/

    template<class Type> std::size_t Foo1<Type>::ctr = 0;   /* define and initialize ctr */

#endif  /* MISC_H */