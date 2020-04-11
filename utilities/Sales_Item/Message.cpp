#include "Message.h"
#include "Folder.h"

Message::Message(const string& str) : contents(str)
{
}

Message::Message(const Message& orig) : contents(orig.contents), folders(orig.folders)
{
    put_Msg_in_Folders(folders);
}

void Message::put_Msg_in_Folders(const set<Folder *> &ptrfolders)

{
    for (set<Folder*>::const_iterator it = ptrfolders.begin(); it != ptrfolders.end(); ++it)
    {
        (*it)->addMsg(this);
    }
}

Message& Message::operator=(const Message &other)
{
    if (&other != this)
    {
        remove_Msg_from_Folders();
        contents = other.contents;
        folders = other.folders;
        put_Msg_in_Folders(other.folders);
    }
    return *this;
}

void Message::remove_Msg_from_Folders()
{
    /* remove this message from corresponding folders */
    for (set<Folder*>::const_iterator it = folders.begin(); it != folders.end(); ++it)
    {
        (*it)->remMsg(this);
    }
}

Message::~Message()
{
    remove_Msg_from_Folders();
}
