#ifndef CHAIN_H
#define CHAIN_H

    class A;
    class B;
    class C;

    class A
    {
    public:
        A();
        A(int m, int n);
        virtual ~A();
    public:
        virtual void vfunc1();
        virtual void vfunc2();
                void  func1();
                void  func2();
    private:
        int m_data1;
        int m_data2;
    };

    class B : public A
    {
    public:
        B();
        B(int m, int n, int u);
        virtual ~B() override;
    public:
        virtual void vfunc1() override;
                void  func2();
    private:
        int m_data3;
    };

    class C : public B
    {
    public:
        C();
        C(int m, int n, int u, int x, int y);
        virtual ~C() override;
    public:
        virtual void vfunc1() override;
                void  func1();
    private:
        int m_data1;
        int m_data4;
    };

    void validate_how_vptr_vtbl_work(void);

#endif  /* CHAIN_H */
