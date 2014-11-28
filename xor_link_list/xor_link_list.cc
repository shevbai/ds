#include <iostream>
#include "xor_link_list.h"
using std::endl;
using std::cout;
using std::cin;
int main(int argc, char** argv) {
    XorLinkList<int> list;
    cout << list.size() << endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    cout << list.size() << endl;
    list.traverse();
    return 0;
}
