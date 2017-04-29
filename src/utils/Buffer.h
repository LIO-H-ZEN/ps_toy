/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-28 05:11
# Email        : lio_h_zen@163.com
# Filename     : Buffer.h
# Description  : 
******************************************************/
#ifndef LZC_STRINGBUFFER_H
#define LZC_STRINGBUFFER_H

#include "common.h"

namespace lzc {

class BasicBuffer {
public:
    explicit BasicBuffer() {
        CHECK(capacity() > 0);
        _buffer = new char[capacity()];
        _writer = _reader = _buffer;
    }
    // Move constructor.
    explicit BasicBuffer(BasicBuffer&& other) :
    _capacity(other._capacity), _buffer(other._buffer), _reader(other._buffer), _writer(other._writer) {
        other.clear(); // 置空，礼貌性的行为 // other使用std::move()
    }

    ~BasicBuffer() {
        free_ori();
    }    

    size_t capacity() {
        return _capacity;
    }

    char* writer() {
        return _writer;
    }

    char* reader() {
        return _reader;
    }

    char* buffer() {
        return _buffer;
    }

    size_t size() {
        return writer() - buffer() - 1;
    }
    
    void update_cursor(size_t delta, int mode) {
        if (mode == 1) {
            _writer = _writer + delta + 1;
        } else {
            _reader = _reader + delta + 1;
        }
    }

    bool read_exceed(size_t lens) {
        return (_reader + lens > _writer)?true:false;
    }

    void reset_reader() {
        _reader = _buffer;
    }

    void clear() {
        _buffer = nullptr;
        _writer = nullptr;
        _reader = nullptr;
        _capacity = 0;
    }

    void free_ori() {
        if (_buffer) {
            delete _buffer;
            clear();
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
        _writer = _buffer + pre_size + 1; // 这点是不是要加1，还存疑。
        _capacity = lens; 
    }
private:
    size_t _capacity = 1024;
    char* _buffer = nullptr; 
    char* _writer = nullptr; 
    char* _reader = nullptr;
};

class BinaryBuffer : public BasicBuffer {
public:

#define REPEAT_PATTERN(T)                    \
    BasicBuffer& operator<<(const T& val) {  \
        write_raw(val);                      \
        return *this;                        \
    }                                        \
    BasicBuffer& operator>>(T& val) {        \
        read_raw(val);                       \
        return *this;                        \
    }
    REPEAT_MACRO6(int16_t, uint16_t, int32_t, uint32_t, int64_t, uint64_t) 
    REPEAT_MACRO2(double, float) 
    REPEAT_MACRO2(bool, byte_t) 
#undef REPEAT_PATTERN
    
protected:
    template <typename T>
    void write_raw(T& t) {
        size_t t_size = sizeof(T);
        if (size() + t_size > capacity()) {
            size_t newcp = (t_size > capacity())?2 * t_size:2 * capacity();
            reserve(newcp);
        }
        memcpy(writer(), &t, t_size); 
        update_cursor(t_size, 1);
    }
    
    template <typename T>
    void read_raw(T& t) {
        size_t t_size = sizeof(T);
        CHECK(!read_exceed(t_size));
        memcpy(&t, reader(), t_size);                
        update_cursor(t_size, 0);
    }
};

} // namepsace lzc
#endif
