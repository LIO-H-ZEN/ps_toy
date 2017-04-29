/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-29 08:18
# Email        : lio_h_zen@163.com
# Filename     : queue.cpp
# Description  : 
******************************************************/
#include "../../utils/queue.h"

using namespace lzc;
using namespace std;

threadsafe_queue<int> q;

void push_10000() {
    for (int i = 0; i < 10000; ++i)
        q.push(i); 
}

void wait_pop() {
    int j;
    for (int i = 0; i < 10000; ++i) {
        q.wait_pop(j);
        cout << j << endl;
    }
}

int main() {
    thread t2(wait_pop); 
    thread t1(push_10000);
    t1.join();
    t2.join();
}
