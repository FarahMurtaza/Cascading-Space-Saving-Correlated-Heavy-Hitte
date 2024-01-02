#ifndef PAIRHASH
#define PAIRHASH

#pragma once

#include <cstdint>
#include "xxhash.h"

class PairHash {
public:
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = XXH64(&p.first, sizeof(T1), 0);
        auto h2 = XXH64(&p.second, sizeof(T2), 0);
        return h1 ^ h2;
    }
};


#endif // PAIRHASH.h
