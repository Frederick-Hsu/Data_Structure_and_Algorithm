/**************************************************************************************************
 * Project name : templates
 * Description  : Study the generic programming techniques, how to utilize the templates in C++.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file will implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Sun.  29 March 2020
 * Copyright(C) 2020    All rights reserved.
 *
 **************************************************************************************************/

#include <iostream>

#include "testing.h"
#include "generic_handle/utilizing_handle.h"

int main(int argc, char* argv[])
{
    // instantiateClassTemplates();

    instantiate_object_from_other_iterators_range();

    how_generic_handle_works();

    instantiateSpecificFnctTemplate();

    call_specialized_class_template();

    verify_list_structure();

    return 0;
}
