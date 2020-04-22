#include "File.h"
#include <iostream>

void File::write()
{
    modified = 1;
}

void File::close()
{
    if (modified)
    {
        /* TODO */
    }
}

int File::isRead()
{
    return mode & READ;
}

int File::isWrite()
{
    return mode & WRITE;
}



void access_bit_field(void)
{
    File myFile;
    // myFile.mode |= READ;    /* set the READ bit */
    if (myFile.isRead()) /* if the READ bit is on */
    {
        std::cout << "myFile.mode READ is set." << std::endl;
    }
}
