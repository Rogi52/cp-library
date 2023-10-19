#pragma once
#include "../../src/cp-template.hpp"

namespace randnum {

static uint seed;
static std::mt19937 mt;
struct gen_seed {
    gen_seed() {
        seed = std::random_device()();
        mt = std::mt19937(seed);
    }
} gs;

// [L, R)
template < class T >
T gen_int(T L, T R) {
    return std::uniform_int_distribution< T >(L, R - 1)(mt);
}

template < class T >
T get_real(T L, T R) {
    return std::uniform_real_distribution< T >(L, R)(mt);
}

}