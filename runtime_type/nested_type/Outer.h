#ifndef OUTER_H
#define OUTER_H

    class Outer;

    class Outer
    {
    public:
        struct Inner1
        {
            void process(const Outer&);
            // Inner2 val;      /* Error: Outer::Inner2 not in the scope */
        };
        class Inner2
        {
        public:
            Inner2(int i = 0) : val(i) {}
            void process(const Outer& out)
            {
                out.handle();
            }
        private:
            int val;
        };
        void handle() const;
    };


#endif  /* OUTER_H */
