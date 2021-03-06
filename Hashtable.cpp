#include "Hashtable.h"
#include "Entry.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

template <typename V>
Hashtable<V>::Hashtable () {
    size = 151;
    //theArray = vector<Entry <V> >();
    for (int i = 0; i < size; ++i) {
        theArray[i] = vector<Entry <V> >();
    }
}

template <typename V>
V Hashtable<V>::get(string k) {
    vector<Entry <V> > chain = theArray[hash(k)];
    for (int i = 0; i < (int) chain.size(); ++i) {
        if (k == chain[i].getKey()) {
            return chain[i].getValue();
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
        for (int i = 0; i < (int) chain.size(); ++i) {
            if (k == chain[i].getKey()) {
                chain[i].setValue(v);
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
    for (int i = 0; i < (int) chain.size(); ++i) {
        if (k == chain[i].getKey()) {
            chain.erase(chain.begin()+i);
        }
    }
}

template <typename V>
bool Hashtable<V>::contains(string k) {
    vector<Entry <V> > chain = theArray[hash(k)];
    for (int i = 0; i < (int) chain.size(); ++i) {
        if (k == chain[i].getKey()) {
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


template class Hashtable<int>;
template class Hashtable<double>;
template class Hashtable<string>;
