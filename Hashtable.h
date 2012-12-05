#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>
#include <list>

template <typename V>
class Hashtable {
    private:
        list<Entry <V> > theArray;
        int hash(string k);
        int size;

    public:
        Hashtable(int size);
        V get(string k);
        void set(string k, V v);
        void remove(string k);
        bool contains(string k);
}

#endif
