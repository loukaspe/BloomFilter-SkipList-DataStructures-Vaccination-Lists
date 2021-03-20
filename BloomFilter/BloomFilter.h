/* IMPORTANT DISCLAIMER:

My classes BloomFilter and BitArray are copied from another university project, and
specifically from Operating Systems with A.Delis.
No changes were made since their use was exactly what I needed for here too. */

#ifndef UNTITLED_BLOOMFILTER_H
#define UNTITLED_BLOOMFILTER_H

#include "../BitArray/BitArray.h"
#include <cassert>

class BloomFilter {
public:
    BloomFilter(int);
    void add(char*);
    bool check(char*);
private:
    const static int NUMBER_OF_HASH_FUNCTIONS;
    int size;
    BitArray* bitArray;
    unsigned long firstHashFunction(char*);
    unsigned long secondHashFunction(char*);
    unsigned long* getHashDigests(char*);
};

#endif //UNTITLED_BLOOMFILTER_H