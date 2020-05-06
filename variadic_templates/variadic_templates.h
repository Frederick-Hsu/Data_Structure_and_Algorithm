#ifndef VARIADIC_TEMPLATES_H
#define VARIADIC_TEMPLATES_H

    void Print() {}
    template<typename T, typename... Types> void Print(const T& firstarg, const Types&... args);

#endif  /* VARIADIC_TEMPLATES_H */
