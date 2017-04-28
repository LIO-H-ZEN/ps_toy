/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-28 01:11
# Email        : lio_h_zen@163.com
# Filename     : HashFunction.h
# Description  : 
******************************************************/

#ifndef LZC_HASHFUNCTION_H
#define LZC_HASHFUNCTION_H

#include "common.h"

namespace lzc {

inline uint64 get_hash_code(uint64 x) {
   // copy from MurmurHash3
   x ^= x >> 33;
   x *= 0xff51afd7ed558ccd;
   x ^= x >> 33;
   x *= 0xc4ceb9fe1a85ec53;
   x ^= x >> 33;
   return x;
}

}; // end namespace swift_snails

#endif
