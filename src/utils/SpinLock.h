/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-26 13:04
# Email        : lio_h_zen@163.com
# Filename     : SpinLock.h
# Description  : 
******************************************************/
#ifndef LZC_SPINLOCK_H
#define LZC_SPINLOCK_H
#include "pthread.h"

namespace lzc {
class SpinLock : public NoncopyableObject {
public:
    SpinLock() {
        PCHECK(pthread_spin_init(&_spin, 0) == 0);
    }
    ~SpinLock() {
        PCHECK(pthread_spin_destroy(&_spin) == 0);
    }
    lock() {
        PCHECK(pthread_spin_lock(&_spin) == 0);
    }
    unlock() {
        PCHECK(pthread_spin_unlock(&_spin) == 0);
    }

private:
    pthread_spinlock_t _spin;
};

} // namespace lzc
#endif
