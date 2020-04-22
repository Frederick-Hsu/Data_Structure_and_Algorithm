/* Fiel name    : program.cpp
 * Description  : This file implement the main() entry function for current project.
 *
 */

#include <iostream>

#include "join_detach_thread.h"
#include "ThreadRAII.h"
#include "pass_args_to_threads.h"
#include "race_conditions.h"
#include "event_handling.h"
#include "returning_value_from_threads.h"
#include "async_thread_handling.h"
#include "create_async_packaged_task.h"

int main(int argc, char* argv[])
{
    std::cout << "C++ standard no.: " << __cplusplus << std::endl;

    // join_threads();
    // detach_threads();
    // create_safe_thread();
    // pass_simple_arguments_to_threads();
    // not_pass_pointer_argument_to_threads();
    // pass_reference_arguments_to_threads();
    // pass_memberFunction_arguments_to_threads();
    // verifyMultiThreadConflict();
    // handle_event();
    // return_values_from_threads();
    // async_execute_thread();
    // async_with_functor_or_lambda_callback();
    execute_async_packaged_task();

    return 0;
}