#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>

template <typename V>
class Entry {
    private:
        string key;
        V value;

    public:
        Entry(string k, V v);
        V getValue();
        void setValue();
}
