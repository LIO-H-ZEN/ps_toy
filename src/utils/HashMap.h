/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-28 02:26
# Email        : lio_h_zen@163.com
# Filename     : HashMap.h
# Description  : 
******************************************************/

#ifndef LZC_HASHMAP_H
#define LZC_HASHMAP_H

#include "common.h"
#include "sparsehash/sparse_hash_map"

using google::sparse_hash_map;
using google::dense_hash_map;

namespace lzc {

// space saving
template <typename KeyType, typename ValueType, typename CmpType>
class SparseHashMap : public NoncopyableObject {
public:
    explicit SparseHashMap(){}
    
private:
    sparse_hash_map<KeyType, ValueType, CmpType> _dict;
};

template <typename KeyType, typename ValueType, typename CmpType>
class DenseHashMap : public NoncopyableObject {
public:
    explicit DenseHashMap(){}

private:
    dense_hash_map<KeyType, ValueType, CmpType> _dict;
};

} // namespace lzc

#endif
