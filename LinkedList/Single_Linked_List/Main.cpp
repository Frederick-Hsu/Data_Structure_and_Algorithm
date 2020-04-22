#include "SLList.h"

#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    SLListItem<int> *pnode1 = new SLListItem<int>(1),
                    *pnode2 = new SLListItem<int>(2),
                    *pnode3 = new SLListItem<int>(3),
                    *pnode4 = new SLListItem<int>(4),
                    *pnode5 = new SLListItem<int>(5),
                    *pnode6 = new SLListItem<int>(6),
                    *pnode7 = new SLListItem<int>(7),
                    *pnode8 = new SLListItem<int>(8),
                    *pnode9 = new SLListItem<int>(9),
                    *pnode10 = new SLListItem<int>(10),
                    *pnode12 = new SLListItem<int>(12),
                    *pnode15 = new SLListItem<int>(15),
                    *pnode19 = new SLListItem<int>(19),
                    *pnode20 = new SLListItem<int>(20),
                    *pnode25 = new SLListItem<int>(25),
                    *pnode39 = new SLListItem<int>(39);

    SLList<int> mylst;
    mylst.append(0);
    mylst.append(pnode1);
    mylst.append(pnode3);
    mylst.append(pnode5);
    mylst.append(pnode7);
    mylst.append(pnode8);
    mylst.insertAfter(pnode10, 4);
    mylst.append(pnode15);
    mylst.append(pnode19);
    mylst.append(pnode25);
    mylst.append(pnode39);
    cout << "The original 'mylst' is shown as below: " << endl;
    mylst.displayNodeAddress();

    cout << "\n" << endl;

    SLList<int> yourlst;
    yourlst.append(pnode2);
    yourlst.append(pnode4);
    yourlst.append(pnode5);
    yourlst.append(pnode6);
    yourlst.append(pnode8);
    yourlst.append(pnode9);
    yourlst.append(pnode12);
    yourlst.append(pnode20);
    cout << "The original 'yourlst' is shown as below: " << endl;
    yourlst.displayNodeAddress();

    cout << "The length of mylst is: " << mylst.size() << endl;
    cout << "The length of yourlst is: " << yourlst.size() << endl;

    SLListItem<int>* pnode = checkIntersection<int>(&mylst, &yourlst);
    cout << pnode << " : " << pnode->getElement() << endl;

    cout << "After the intersection, \n'mylst' becomes: " << endl;
    mylst.displayNodeAddress();
    cout << "'yourlst' becomes: " << endl;
    yourlst.displayNodeAddress();

    return 0;
}

