#include "io_stream_states.h"

void display(ostream& os)
{
    /* remember the current format state */
    ostream::fmtflags curr_fmt = os.flags();
    /* do output that uses manipulators to change the format state of ostream */
    os.flags(curr_fmt);     /* restore the original format state of ostream */
}

void control_ostream_format(void)
{
    cout << "default bool values: " << true << " " << false
         << "\nalpha bool values: " << boolalpha << true << " " << false
         << endl;

    bool boolval = true;
    cout << boolalpha       /* sets internal state of cout */
         << boolval
         << noboolalpha << endl     /* resets internal state to default formatting */
         << boolval << endl;

    const int ival = 15, jval = 1024;   /* const, so values never change */
    cout << "default: ival = " << ival << ", jval = " << jval << endl;
    cout << "printed in octal: ival = o" << oct << ival << ", jval = o" << jval << endl;
    cout << "printed in hexadecimal: ival = 0x" << hex << ival << ", jval = 0x" << jval << endl;
    cout << "printed in decimal: ival = " << dec << ival << ", jval = " << jval << endl;
}
