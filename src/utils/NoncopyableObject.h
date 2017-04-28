/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-26 12:37
# Email        : lio_h_zen@163.com
# Filename     : NoncopyableObject.h
# Description  : 
******************************************************/
#ifndef LZC_NONCOPYABLEOBJECT_H
#define LZC_NONCOPYABLEOBJECT_H 

namespace lzc {
class NoncopyableObject {
public:
    NoncopyableObject() = default;
    NoncopyableObject(const NoncopyableObject&) = delete;
    NoncopyableObject& operator=(const NoncopyableObject&) = delete;
    ~NoncopyableObject() = default;
};
} // namespace lzc 
#endif
