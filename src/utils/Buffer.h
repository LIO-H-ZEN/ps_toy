/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-28 05:11
# Email        : lio_h_zen@163.com
# Filename     : StringBuffer.h
# Description  : 
******************************************************/
#ifndef LZC_STRINGBUFFER_H
#define LZC_STRINGBUFFER_H

#include "common.h"

namespace lzc {

class BasicBuffer {
public:
    BasicBuffer(const BasicBuffer&) = delete;
    explicit BasicBuffer(BasicBuffer&& other) :
    _capacity(other._capacity), _buffer(other._buffer), _cursor(other._cursor) {
        other.clear(); // 置空，礼貌性的行为 // other使用std::move()
    }
    
    size_t capacity() {
        return _capacity;
    }

    char* cursor() {
        return _cursor;
    }

    char* buffer() {
        return _buffer;
    }

    size_t size() {
        return cursor() - buffer() + 1;
    }
    
    void clear() {
        _capacity = 0;
        _buffer = nullptr;
        _cursor = nullptr;
    }

    void free_ori() {
        if (_buffer) {
            delete _buffer;
            _buffer = nullptr;
            _cursor = nullptr;
            _capacity = 0;
        } 
    }

    void reserve(size_t lens) {
        CHECK(lens > 0);
        char* newbuf;
        newbuf = new char[lens];
        size_t pre_size = size();
        if (pre_size > 0) {
            memcpy(newbuf, _buffer, pre_size);
        }  
        free_ori(); // 把之前的free掉，用现在创建的这个 
        _buffer = newbuf;
        _cursor = _buffer + pre_size + 1; // 这点是不是要加1，还存疑。
        _capacity = lens; 
    }
private:
    size_t _capacity = 0;
    char* _buffer = nullptr; 
    char* _cursor = nullptr; 
};

class BinaryBuffer : public BasicBuffer {

    BasicBuffer& operator<<() {

    } 
    
};

} // namepsace lzc
#endif
