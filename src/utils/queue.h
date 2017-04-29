/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-28 20:00
# Email        : lio_h_zen@163.com
# Filename     : queue.h
# Description  : 线程安全的queue
******************************************************/
#ifndef LZC_QUEUE_H
#define LZC_QUEUE_H

#include "common.h"

namespace lzc {

template <typename T>
class threadsafe_queue {
private:
    std::mutex m;
    std::condition_variable cv;
    std::queue<T> que; 
public:
    void push(T val) {
        std::lock_guard<std::mutex> lg(m);
        que.push(std::move(val)); 
        cv.notify_one(); 
    }  
    
    // 这里的try，意思是有多少是多少，不会因为empty而去等cond
    bool try_pop(T& val) {
        std::lock_guard<std::mutex> lg(m);
        if (que.empty())
            return false;
        val = std::move(que.front());
        que.pop();
        return true; 
    }

    void wait_pop(T& val) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [this]{return !que.empty();}); 
        val = std::move(que.front());
        que.pop();
    }
    
    bool empty() {
        std::lock_guard<std::mutex> lg(m);
        return que.empty(); 
    } 
    
    size_t size() {
        std::lock_guard<std::mutex> lg(m);
        return que.size();
    }
};

} // namespace lzc
#endif
