#include "Hashtable.h"
#include <iostream>

using namespace std;

int main() {
    
    Hashtable<int> h = Hashtable<int>();

    h.set("a", 1234);
    h.set("b", 567);

    cout << h.get("a") << endl;
    cout << h.get("b") << endl;

    return 0;
}
