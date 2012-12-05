#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <string>

using std::string;

template <typename V>
class Entry {
    private:
        string key;
        V value;

    public:
        Entry(string k, V v);
        string getKey();
        V getValue();
        void setValue(V v);
};

#endif
