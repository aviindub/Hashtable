#include "Hashtable.h"
#include "Entry.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename V>
Hashtable<V>::Hashtable () {
    //size = 151;
    //theArray = vector<Entry <V> >[size];
    //for (int i = 0; i < size; ++i) {
    //    theArray[i] = vector<Entry <V> >;
    //}
}

template <typename V>
V Hashtable<V>::get(string k) {
    vector<Entry <V> > chain = theArray[hash(k)];
    for (int i = 0; i < chain.size(); ++i) {
        if (k == chain.at(i).getKey()) {
            return chain.at(i).getValue();
        }
    }
    return (V) 0;
}

template <typename V>
void Hashtable<V>::set(string k, V v) {
    int kHash = hash(k);
    vector<Entry <V> > chain = theArray[kHash];
    Entry<V> entry = Entry<V>(k, v);
    if (chain.empty()) {
        chain.push_back(entry);
    } else {
        bool exists = false;
        for (int i = 0; i < chain.size(); ++i) {
            if (k == chain.at(i).getKey()) {
                chain.at(i).setValue(v);
                exists = true;
            }
        }
        if (!exists) {
            chain.push_back(entry);
        }
    }
}


template <typename V>
void Hashtable<V>::remove(string k) {
    vector<Entry <V> > chain = theArray[hash(k)];
    for (int i = 0; i < chain.size(); ++i) {
        if (k == chain.at(i).getKey()) {
            chain.erase(i);
        }
    }
}

template <typename V>
bool Hashtable<V>::contains(string k) {
    vector<Entry <V> > chain = theArray[hash(k)];
    for (int i = 0; i < chain.size(); ++i) {
        if (k == chain.at(i).getKey()) {
            return true;
        }
    }
    return false;
}

template <typename V>
int Hashtable<V>::hash(string k) {
    int sum = 0;
    for (int i = 0; i < (int) k.size(); ++i) {
        sum += (int) k[i];
    }
    return sum % size;
}


template class Entry<int>;
template class Entry<double>;
template class Entry<string>;
