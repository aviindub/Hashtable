#include "entry.h"

template <typename V>
Entry<V>::Entry(string k, V v) {
    key = k;
    value = v;
}

template <typename V>
Entry<V>::getKey() {
    return key;
}

template <typename V>
Entry<V>::getValue() {
    return value;
}

template <typename V>
Entry<V>::setValue(V v) {
    value = v;
}
