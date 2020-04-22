
template<class Type> SLListItem<Type>::SLListItem(const Type& elem) : element(elem), next(0)
{
}

template<class Type> SLListItem<Type>::~SLListItem()
{
    next = 0;
}

template<class Type> Type SLListItem<Type>::getElement() const
{
    return element;
}

template<class Type> map<SLListItem<Type>*, int> SLList<Type>::nodes_map;

template<class Type> SLList<Type>::SLList() : head(0), tail(0)
{
}

template<class Type> SLList<Type>::SLList(const SLList& orig) : head(0), tail(0)
{
    SLListItem<Type>* pnode = orig.head;
    while (pnode != 0)
    {
        append(pnode->element);
        pnode = pnode->next;
    }

    SLListItem<Type>* node = head;
    while (node)
    {
        nodes_map[node]++;
        nodes_vec.push_back(node);
        node = node->next;
    }
}

template<class Type> SLList<Type>& SLList<Type>::operator=(const SLList& orig)
{
    destroy();
    nodes_map.clear();
    nodes_vec.clear();

    SLListItem<Type>* pnode = orig.head;
    while (pnode != 0)
    {
        append(pnode->element);
        pnode = pnode->next;
    }

    SLListItem<Type>* node = head;
    while (node)
    {
        nodes_map[node]++;
        nodes_vec.push_back(node);
        node = node->next;
    }
    return *this;
}

template<class Type> SLList<Type>::~SLList()
{
    for (typename vector<SLListItem<Type>*>::iterator iter = nodes_vec.begin(); iter != nodes_vec.end(); ++iter)
    {
        if (nodes_map[*iter] - 1 == 0)      /* only free the nodes, which are exclusively belonged to myself list */
        {
            nodes_map[*iter]--;
            delete (*iter);
        }
        else                        // For the common nodes, decrement their use-count
        {                           // they will be revoked when another list object dies.
            nodes_map[*iter]--;
        }
    }
#if 0
    nodes_vec.clear();       // this nodes_vec does not need to clear(), because list object ends of life,
                             // synthesized destructor will automatically call ~vector<Type>() destructor to clean up.

    nodes_map.clear();       // likewise, synthesized destructor will automatically call ~map<Type>(), after all list objects
                             // which shared the static map<Type> object, terminates.
#endif
}

template<class Type> void SLList<Type>::destroy()
{
    for (typename vector<SLListItem<Type>*>::iterator iter = nodes_vec.begin(); iter != nodes_vec.end(); ++iter)
    {
        delete (*iter);
    }
    nodes_vec.clear();
    head = 0;
    tail = 0;
}

template<class Type> void SLList<Type>::append(Type elem)
{
    SLListItem<Type>* pNewNode = new SLListItem<Type>(elem);
    nodes_map[pNewNode]++;
    nodes_vec.push_back(pNewNode);

    if (isEmpty())
    {
        head = tail = pNewNode;
    }
    else
    {
        tail->next = pNewNode;
        tail = pNewNode;
    }
}

template<class Type> bool SLList<Type>::isEmpty() const
{
    if (head == 0)
        return true;
    else
        return false;
}

template<class Type> bool compare(const SLListItem<Type>* nodeA, const SLListItem<Type>* nodeB)
{
    if ((nodeA == nodeB) && (nodeA->element == nodeB->element))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class Type> SLListItem<Type>* checkIntersection(const SLList<Type>* lstA, const SLList<Type>* lstB)
{
#if 0   /* search the common node from nodes_map, but could not locate the first occurred common node. Because map is not a sequential container.
         * at this scenario, the time complexity is O(n).
         */
    for (typename map<SLListItem<Type>*, int>::iterator iter = SLList<Type>::nodes_map.begin(); iter != SLList<Type>::nodes_map.end(); ++iter)
    {
        if (iter->second == 2)
        {
            return iter->first;
        }
    }
    return NULL;
#else   /* search the first common node from 2 vector containers.
         * but at this scenario, the time complexity is O(n^2).   Obviously, it is much slower than the above algorithm.
         */
    for (int m = 0; m < lstA->nodes_vec.size(); ++m)
    {
        for (int n = 0; n < lstB->nodes_vec.size(); ++n)
        {
            if (compare(lstA->nodes_vec[m], lstB->nodes_vec[n]) == true)
            {
                return lstA->nodes_vec[m];
            }
        }
    }
    return NULL;
#endif
}

template<class Type> void SLList<Type>::append(SLListItem<Type>* oneNode)
{
    /* Add a new node each time, you should store the new node into map as a key,
     * and increment his value
     */
    nodes_map[oneNode]++;
    nodes_vec.push_back(oneNode);

    if (isEmpty())
    {
        head = tail = oneNode;
    }
    else
    {
        tail->next = oneNode;
        tail = oneNode;
    }
}

template<class Type> size_t SLList<Type>::size()
{
    return nodes_vec.size();
}

template<class Type> void SLList<Type>::insertAfter(SLListItem<Type>* node, int pos) throw (std::runtime_error)
{
    int count = 0;
    if (pos > size())
    {
        throw std::runtime_error("The position where you want to insert exceeds the max range.");
    }
    SLListItem<Type>* pnode = head;

    nodes_map[node]++;      /* same action as appending new node */
    typename vector<SLListItem<Type>*>::iterator it = nodes_vec.begin();
    while (pnode)
    {
        ++count;
        ++it;
        if (count == pos)
        {
            nodes_vec.insert(it, node);
            SLListItem<Type>* successor = pnode->next;
            pnode->next = node;
            node->next = successor;
            break;
        }
        pnode = pnode->next;
    }
}

template<class Type> void SLList<Type>::displayNodeAddress()
{
    cout << "[ ";
    int pos = 0;
    head = nodes_vec[pos];
    SLListItem<Type>* pnode = head;
    for (pos = 0; pos < nodes_vec.size(); ++pos)
    {
        pnode = nodes_vec[pos];
        pnode = pnode->next;

        cout << nodes_vec[pos] << " : " << (nodes_vec[pos])->element << ", ";
    }
    tail = nodes_vec[pos - 1];
    cout << "]" << endl;
}

template<class Type> void SLList<Type>::rectify()       /* rectify the nodes-list from nodes_vec */
{
    int pos = 0;
    head = nodes_vec[pos];
    SLListItem<Type>* pnode = head;
    for (pos = 0; pos < nodes_vec.size(); ++pos)
    {
        pnode = nodes_vec[pos];
        pnode = pnode->next;
    }
    tail = nodes_vec[pos - 1];
}
