#ifndef SLLIST_H
#define SLLIST_H

    #include <cstdlib>
    #include <vector>
    #include <map>
    #include <stdexcept>
    #include <iostream>
    #include <algorithm>
    using namespace std;

    template<class Type> class SLListItem;
    template<class Type> class SLList;

    template<class Type> bool compare(const SLListItem<Type>* nodeA, const SLListItem<Type>* nodeB);
    template<class Type> SLListItem<Type>* checkIntersection(const SLList<Type>* lstA, const SLList<Type>* lstB);

    template<class Type>
    class SLListItem
    {
        friend class SLList<Type>;
        friend bool compare<Type>(const SLListItem<Type>* nodeA, const SLListItem<Type>* nodeB);
        friend SLListItem<Type>* checkIntersection<Type>(const SLList<Type>* lstA, const SLList<Type>* lstB);
    public:
        explicit SLListItem(const Type& elem);
        ~SLListItem();
    private:
        Type element;
        SLListItem* next;
    public:
        Type getElement() const;
    };

    template<class Type>
    class SLList
    {
        friend SLListItem<Type>* checkIntersection<Type>(const SLList<Type>* lstA, const SLList<Type>* lstB);
    public:
        SLList();
        SLList(const SLList& orig);
        SLList& operator=(const SLList& orig);
        ~SLList();
    private:
        SLListItem<Type>* head;
        SLListItem<Type>* tail;
    public:
        void append(Type elem);
        void append(SLListItem<Type>* oneNode);
        bool isEmpty() const;
        void destroy();
        size_t size();
        void insertAfter(SLListItem<Type>* node, int pos) throw (std::runtime_error);
        void displayNodeAddress();
        void rectify();
    private:
        /* Why need to define the 2 containers?
         * Considering the scenario(1) that 2 different list objects owned the common nodes,
         * when they intersected. How to manage those nodes?
         *
         * Scenario(2): One list object goes to end-of-life, but another list object goes alive,
         * How to free the common nodes, when calling the destructor?
         *
         * Scenario(3): How to retain the nodes-list for each independent list object, if 2 objects
         * intersected, and could have more than 1 common nodes?
         *
         * Purpose: store the common nodes, which are shared by different list objects
         */
        static map<SLListItem<Type>*, int> nodes_map;
        /* Purpose: store all the nodes, which are owned individually by current list object */
        vector<SLListItem<Type>*> nodes_vec;
    };

    /*============================================================================================*/

    #include "SLList.cpp"

#endif  /* SLLIST_H */

