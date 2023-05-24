#pragma once
template < class K, class V >
struct key_val {
    K key; V val;
    key_val() {}
    key_val(K key, V val) : key(key), val(val) {}
};