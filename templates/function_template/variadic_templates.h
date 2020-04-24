#ifndef VARIADIC_TEMPLATES_H
#define VARIADIC_TEMPLATES_H

    #include <iostream>

    void print_mutable_args();

    template<typename T, typename... Types>     /* 数量不定的模板参数 */
    void print_mutable_args(const T& firstArg, const Types&... args)
    {
        std::cout << "Total number of arguments: " << sizeof...(args) << std::endl;

        std::cout << firstArg << std::endl;
        print_mutable_args(args...);
    }

    void verify_how_variadic_templates_work(void);

#endif  /* VARIADIC_TEMPLATES_H */
