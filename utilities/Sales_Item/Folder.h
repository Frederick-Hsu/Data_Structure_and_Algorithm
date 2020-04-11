#ifndef FOLDER_H
#define FOLDER_H

    #include <set>
    using namespace std;

    class Message;

    class Folder
    {
    public:
        Folder();
        Folder(const Folder& orig);
        Folder& operator=(const Folder& orig);
        ~Folder();
    public:
        void addMsg(Message* msg);
        void remMsg(Message* msg);
    private:
        set<Message*> mesgs;
    };

#endif  /* FOLDER_H */
