#pragma once
#include "../../src/cp-template.hpp"

template < class T > using heap_min = std::priority_queue< T, std::vector< T >, std::greater< T > >;
template < class T > using heap_max = std::priority_queue< T, std::vector< T >, std::less< T > >;

