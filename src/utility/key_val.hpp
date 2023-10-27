#pragma once

template < class K, class V >
struct key_val {
    K key; V val;
    key_val() {}
    key_val(K key, V val) : key(key), val(val) {}
    template < std::size_t Index >
    std::tuple_element_t< Index, key_val >& get() {
        if constexpr (Index == 0) return key;
        if constexpr (Index == 1) return val;
    }
};

namespace std {

template < class K, class V > struct tuple_size < key_val< K, V > > : integral_constant< size_t, 2 > {};
template < class K, class V > struct tuple_element < 0, key_val< K, V > > { using type = K; };
template < class K, class V > struct tuple_element < 1, key_val< K, V > > { using type = V; };

}