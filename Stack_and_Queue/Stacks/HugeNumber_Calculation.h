#ifndef HUGHNUMBER_CALCULATION_H
#define HUGHNUMBER_CALCULATION_H

    #include <string>
    #include <stack>

    // #define DEBUG_INFO      1

    class HugeNumber_Calculation
    {
        friend HugeNumber_Calculation operator+(HugeNumber_Calculation hugenum1,
                                                HugeNumber_Calculation hugenum2);

        friend std::string operator-(HugeNumber_Calculation hugenum1,
                                     HugeNumber_Calculation hugenum2);

        friend bool operator<(HugeNumber_Calculation hugenum1,
                              HugeNumber_Calculation hugenum2);

        friend bool operator==(HugeNumber_Calculation hugenum1,
                               HugeNumber_Calculation hugenum2);

        friend HugeNumber_Calculation operator*(HugeNumber_Calculation hugenum1,
                                                HugeNumber_Calculation hugenum2);

        friend std::string print(HugeNumber_Calculation hugenum);
    public:
        explicit HugeNumber_Calculation(const std::string& numberInStringFormat);
        HugeNumber_Calculation(const HugeNumber_Calculation& orig);
        HugeNumber_Calculation& operator=(const HugeNumber_Calculation& orig);
        ~HugeNumber_Calculation();
    private:
        /* Define the default constructor under the private scope,
         * in order to prevent from calling default constructor to instantiate an object,
         * but it allows friend function to call.
         */
        HugeNumber_Calculation();
    public:
        size_t size() const;
    private:
        std::stack<int> hugenum_stack;
    };

#endif  /* HUGHNUMBER_CALCULATION_H */
