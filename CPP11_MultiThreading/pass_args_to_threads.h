#ifndef PASS_ARGS_TO_THREADS_H
#define PASS_ARGS_TO_THREADS_H

    #include <string>
    using namespace std;

    void threadCallback(int x, string str);
    void newThreadCallback(int* ptr);
    void startNewThread(void);
    void refThreadCallback(const int& x);

    void pass_simple_arguments_to_threads(void);
    void not_pass_pointer_argument_to_threads(void);
    void pass_reference_arguments_to_threads(void);
    void pass_memberFunction_arguments_to_threads(void);

#endif  /* PASS_ARGS_TO_THREADS_H */