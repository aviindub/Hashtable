#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "Entry.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename V>
class Hashtable {
    private:
        vector< Entry <V> > theArray[151];
        int hash(string k);
        int size;

    public:
        Hashtable();
        V get(string k);
        void set(string k, V v);
        void remove(string k);
        bool contains(string k);
};

#endif
