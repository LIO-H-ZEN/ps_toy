/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-05-09 11:41
# Email        : lio_h_zen@163.com
# Filename     : Message.h
# Description  : 
******************************************************/

#ifndef LZC_MESSAGE_H
#define LZC_MESSAGE_H

#include "../utils/Buffer.h"

namespace lzc {

class Message {
public:
    Message() {
        PCHECK(0 == zmq_msg_init(&_zmg));
    }

    Message(const Message&) = delete;

    Message& operator=(Message& other) {
        if (this != &other) {
            PCHECK(0 == zmq_msg_move(&_zmg, &(other._zmg)));
        }
        return *this;
    } 

    Message(char* buf, size_t size) {
        PCHECK(0 == zmq_msg_init_size(&_zmg, size));
        memcpy(buffer(), buf, size); 
    }

    Message(BasicBuffer& bb) {
        PCHECK(0 == zmq_msg_init_size(&_zmg, bb.size()));
        memcpy(buffer(), bb.buffer(), bb.size());
    }

    ~Message() {
        PCHECK(0 == zmq_msg_close(&_zmg)); 
    }

    void reset() {
        PCHECK(0 == zmq_msg_close(&_zmg));
        PCHECK(0 == zmq_msg_init(&_zmg));
    }

    char* buffer() {
        return (char *)zmq_msg_data(&_zmg);
    }

    size_t size() {
        return zmq_msg_size(&_zmg);
    } 

    void resize(size_t size) {
        PCHECK(0 == zmq_msg_close(&_zmg));
        PCHECK(0 == zmq_msg_init_size(&_zmg, size));
    }

    void assign(char* buf, size_t size) {
        resize(size); 
        memcpy(buffer(), buf, size);
    }

private:
    zmq_msg_t _zmg;
}; // class Message

} // namespace lzc

#endif
