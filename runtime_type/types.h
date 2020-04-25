#ifndef TYPES_H
#define TYPES_H

    class Base;
    class Derived;

    /*
    bool operator==(const Base&, const Base&);
    bool operator==(const Derived&, const Derived&);
    bool operator==(const Derived&, const Base&);
    bool operator==(const Base&, const Derived&);
     */

    class Base
    {
        friend bool operator==(const Base&, const Base&);
    public:
        Base();
        virtual ~Base();
    protected:
        virtual bool equal(const Base&) const;
    };

    class Derived : public Base
    {
        friend bool operator==(const Base&, const Base&);
    public:
        Derived();
        ~Derived();
    private:
        bool equal(const Base&) const;
    };

    void display_type_name(void);

#endif  /* TYPES_H */
