#ifndef TEMPLATE_PARAMETER_H
#define TEMPLATE_PARAMETER_H

    #include <list>
    #include <queue>
    using namespace std;

#if 0
    /* template template parameter */
    template<typename T, template<typename T> class SmartPtr>
    class XCls
    {
    private:
        SmartPtr<T> sp;
    public:
        XCls() : sp(new T) {}
    };

    template<typename T> using Lst = list<T, allocator<T>>;
#endif

/*================================================================================================*/

    template<class T, class Sequence> class Stack;

    template<class T, class Sequence> bool operator==(const Stack<T, Sequence>& a,
                                                      const Stack<T, Sequence>& b);
    template<class T, class Sequence> bool operator< (const Stack<T, Sequence>& a,
                                                      const Stack<T, Sequence>& b);

    template<class T, class Sequence = deque<T>>
    class Stack
    {
        friend bool operator==(const Stack<T, Sequence>& a, const Stack<T, Sequence>& b);
        friend bool operator< (const Stack<T, Sequence>& a, const Stack<T, Sequence>& b);
    protected:
        Sequence c;
    };

    void access_template_parameter(void);

#endif  /* TEMPLATE_PARAMETER_H */
