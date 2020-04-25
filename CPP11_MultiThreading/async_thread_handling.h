#ifndef ASYNC_THREAD_HANDLING_H
#define ASYNC_THREAD_HANDLING_H

    #include <string>
    using namespace std;

    string fetchDataFromDB(string recvData);
    string fetchDataFromFile(string recvData);

    void execute_single_thread(void);
    void async_execute_thread(void);
    void async_with_functor_or_lambda_callback(void);

    struct DataFetcher
    {
        string operator()(string recvData);
    };

#endif  /* ASYNC_THREAD_HANDLING_H */