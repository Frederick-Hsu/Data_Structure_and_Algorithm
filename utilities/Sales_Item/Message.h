#ifndef MESSAGE_H
#define MESSAGE_H

    #include <string>
    #include <set>
    using namespace std;

    class Folder;

    class Message
    {
    public:
        explicit Message(const string& str = "");
        explicit Message(const Message&);
        Message& operator=(const Message&);
        ~Message();
    public:
        void save(Folder&);
        void remove(Folder&);
    private:
        string contents;        /* actual message text */
        set<Folder*> folders;   /* Folders that have this message */
    private:
        void put_Msg_in_Folders(const set<Folder*>&);
        void remove_Msg_from_Folders();
        void addFldr(Folder *fldr);
        void remFldr(Folder* fldr);
    };

#endif  /* MESSAGE_H */
