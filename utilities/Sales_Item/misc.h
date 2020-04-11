#ifndef MISC_H
#define MISC_H

    #include <string>
    #include <utility>
    #include <vector>
    #include <iostream>
    using namespace std;

    class Record
    {
        typedef std::size_t size;
        Record();
        Record(size s);
        Record(std::string s);

        size byte_count;
        std::string name;
    public:
        size get_count() const;
        std::string get_name() const;
    };

    /*============================================================================================*/

    typedef double Money;
    class Account
    {
    public:
        void applyInterest();
        static double rate();
        static void rate(double);   /* sets a new rate */
        Money balance()
        {
            return bal;
        }
    private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initialRate();
        Money bal;
    private:
        static const int period = 30;   /* interest posted every 30 days */
        double daily_tbl[period];       /* OK: because period is constant expression */
    };

    /*============================================================================================*/

    class ConstRef
    {
    public:
        ConstRef(int num);
    private:
        int number;
        const int constNum;
        int& refNum;
    };

    /*============================================================================================*/

    struct NoName
    {
        NoName();
        NoName(const NoName& orig);
        ~NoName();
    private:
        std::string *pstring;
        int i;
        double d;
    };

    typedef struct NoName *PNoName;

    /*============================================================================================*/

    class Date
    {
    public:
        typedef enum Month
        {
            January = 1,
            February = 2,
            March = 3,
            April = 4,
            May = 5,
            June = 6,
            July = 7,
            August = 8,
            September = 9,
            October = 10,
            November = 11,
            December = 12
        } Month;
    public:
        Date(unsigned year, unsigned month, unsigned day);
        Date(const Date& date);
        Date& operator=(const Date& date);
    public:
        static Date currentDate();

        unsigned getYear();
        unsigned getMonth();
        unsigned getDay();
        void setYear(unsigned year);
        void setMonth(unsigned month);
        void setDay(unsigned day);
    private:
        unsigned year;
        Month month;
        unsigned day;
    };

    class CheckoutRecord
    {
        friend std::ostream& operator<<(std::ostream& out, const CheckoutRecord& record);
        friend std::istream& operator>>(std::istream& in, CheckoutRecord& record);
    public:
        CheckoutRecord();
        pair<string, string>* operator[](size_t index);
    private:
        double book_id;
        string title;
        Date date_borrowed;
        Date date_due;
        pair<string, string> borrower;
        vector< pair<string, string>* > wait_list;
    };

    /*============================================================================================*/

    class Foo
    {
    public:
        int& operator[](const std::size_t);
        const int& operator[](const std::size_t) const;
    private:
        vector<int> data;
    };

#endif  /* MISC_H */
