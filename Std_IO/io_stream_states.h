#ifndef IO_STREAM_STATES_H
#define IO_STREAM_STATES_H

    #include <iostream>
    using namespace std;

    void display(ostream& os);
    void control_ostream_format(void);
    void specify_ostream_format_base(void);
    void set_display_precison(void);
    void control_float_notation(void);
    void control_ostream_padding(void);

    void control_istream_format(void);
    int read_write_stream_file(void);

#endif  /* IO_STREAM_STATES_H */
