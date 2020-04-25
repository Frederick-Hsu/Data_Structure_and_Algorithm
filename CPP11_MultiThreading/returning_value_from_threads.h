#ifndef RETURNING_VALUE_FROM_THREADS_H
#define RETURNING_VALUE_FROM_THREADS_H

    #include <future>
    using namespace std;

    void initializer(promise<int> *promiseObj);
    void return_values_from_threads(void);

#endif  /* RETURNING_VALUE_FROM_THREADS_H */