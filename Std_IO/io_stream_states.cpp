#include "io_stream_states.h"

#include <iomanip>
#include <sstream>
#include <fstream>

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

void specify_ostream_format_base(void)
{
    const int ival = 54943, jval = 6859;
    cout << showbase;       /* show base when printing integral values */
    cout << "default: ival = " << ival << ", jval = " << jval << endl;
    cout << "printed in octal: ival = " << oct << ival << ", jval = " << jval << endl;
    cout << "printed in hexadecimal: ival = " << hex << ival << ", jval = " << jval << endl;
    cout << "printed in decimal: ival = " << dec << ival << ", jval = " << jval << endl;
    cout << noshowbase;     /* reset state of the ostream */

    cout << uppercase << showbase << hex
        << "printed in hexadecimal: ival = " << ival << ", jval = " << jval
        << nouppercase << noshowbase << endl;
    cout << dec << endl;
}

void set_display_precison(void)
{
    cout << "Precision: " << cout.precision() << ", sqrt(2.0) = " << sqrt(2.0) << endl;
    /* cout.precison(12) asks that 12 digits of precison to be printed */
    cout.precision(12);
    cout << "Precision: " << cout.precision() << ", sqrt(2.0) = " << sqrt(2.0) << endl;
    /* alternative way to set precision using setprecision manipulator */
    cout << setprecision(4);
    cout << "Precision: " << cout.precision() << ", sqrt(2.0) = " << sqrt(2.0) << endl;
}

void control_float_notation(void)
{
    /* reset to default handling for notation */
    cout.unsetf(ostream::floatfield);

    cout << "sqrt(2.0) = " << sqrt(2.0) << endl;
    cout << "scientific: " << scientific << "sqrt(2.0) = " << sqrt(2.0) << endl
         << "fixed decimal: " << fixed << "sqrt(2.0) = " << sqrt(2.0) << endl;
    cout << uppercase
         << "scientific: " << scientific << setprecision(12) << "sqrt(2.0) = " << sqrt(2.0) << endl
         << "fixed decimal: " << fixed << setprecision(10) << "sqrt(2.0) = " << sqrt(2.0) << endl
         << nouppercase;
    cout.unsetf(ostream::floatfield);
    cout << "sqrt(2.0) = " << sqrt(2.0) << endl;
    cout << setprecision(6);

    /* control the decimal dot */
    cout << 10.0 << endl;
    cout << showpoint << 10.0
         << noshowpoint << endl;
}

void control_ostream_padding(void)
{
    int i = -16;
    double d = 3.14159;
    /* pad fist column to use minimum of 12 positions in the output */
    cout << "i: " << setw(12) << i << " next col" << endl
         << "d: " << setw(12) << d << " next col" << endl;
    /* pad forst column and left-justify all columns */
    cout << left
        << "i: " << setw(12) << i << " next col" << endl
        << "d: " << setw(12) << d << " next col" << endl;
    /* pad first column and right-justify all column */
    cout << right
        << "i: " << setw(12) << i << " next col" << endl
        << "d: " << setw(12) << d << " next col" << endl;
    /* pad first column, but put the passing internal to field */
    cout << internal
        << "i: " << setw(12) << i << " next col" << endl
        << "d: " << setw(12) << d << " next col" << endl;
    /* pad first column, using # as the pad character */
    cout << setfill('#')
        << "i: " << setw(12) << i << " next col" << endl
        << "d: " << setw(12) << d << " next col" << endl;

    int num1 = 0x7BD0A, num2 = 2020;
    cout << setfill('0')
        << "num1: " << showbase << hex << setw(16) << num1 << endl
        << "num2: 0x" << noshowbase << uppercase << hex << setw(16) << num2 << endl;
}

void control_istream_format(void)
{
    char ch;
    /*
    while (cin >> ch)
    {
        cout << ch;
    }
     */

    cin >> noskipws;    /* set cin, so that it reads whitespace */
    while (cin >> ch)
    {
        cout << ch;
    }
    cin >> skipws;      /* reset cin to default state, so that it discards whitespace */

    while (cin.get(ch))     /* read byte by byte */
    {
        cout.put(ch);
    }

    int char_of_file;       /* NOTE: int, not char!!!   using a char here invites disaster  */
    /* loop to read and write all the data in the input */
    while ((char_of_file = cin.get())   /* return from cin.get() is converted from int to char and then compared to an int */
        != EOF)
    {
        cout.put(char_of_file);
    }
}

int read_write_stream_file(void)
{
#if 0
    /* remember current write position in mark */
    ostringstream writeStr;     /* output stringstream */
    ostringstream::pos_type mark = writeStr.tellp();
#endif
    fstream inOut("copyOut", fstream::ate | fstream::in | fstream::out);
    if (!inOut)
    {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE;
    }
    /* inOu is opened in ate mode, so it starts out positioned at the end,
     * which we must remember as it is the original end-of-file position.
     */
    ifstream::pos_type end_mark = inOut.tellg();
    inOut.seekg(0, fstream::beg);   /* reposition to start of the file */
    int cnt = 0;                    /* accumulator for byte count */
    string line;                    /* hold each of input */
    /* while we haven't hit an error and we are still reading the original data,
     * and successfully read another line from the file. 
     */
    while (inOut && inOut.tellg() != end_mark && getline(inOut, line))
    {
        cnt += line.size() + 1;     /* add 1 to account for the newline */
        ifstream::pos_type mark = inOut.tellg();    /* remember current read marker */
        inOut.seekp(0, fstream::end);   /* set write marker to end */
        inOut << cnt;                   /* write the accumulated length */
        /* print separator if this is not the last line */
        if (mark != end_mark)
        {
            inOut << " ";
            inOut.seekg(mark);          /* restore read position */
        }
    }
    inOut.clear();                  /* clear flags in case we hit an error */
    inOut.seekp(0, fstream::end);   /* seek to end */
    inOut << "\n";                  /* write a newline at end of file */
    return 0;
}