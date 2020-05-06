#include <iostream>
#include "io_stream_states.h"

using namespace std;

int main()
{
    cout << "C++ standard no.: " << __cplusplus << endl;

    control_ostream_format();
    cout << "\n" << endl;
    
    specify_ostream_format_base();
    cout << "\n" << endl;

    set_display_precison();
    cout << "\n" << endl;

    control_float_notation();
    cout << "\n" << endl;

    control_ostream_padding();
    cout << "\n" << endl;

    control_istream_format();
    cout << "\n" << endl;
    return 0;
}
