/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-29 02:32
# Email        : lio_h_zen@163.com
# Filename     : queue.cpp
# Description  : 
******************************************************/
#include "../../utils/queue.h"

using namespace lzc;
using namespace std;

string ss = "123";
threadsafe_queue<string> q;
queue<string> q2;

void push_10000() {
    for (int i = 0; i < 10000; ++i)
        q.push(ss); 
}

void push_10000_2() {
    for (int i = 0; i < 10000; ++i)
        q2.push(ss); 
}

int main() {
    thread ts[10];
    for (int i = 0; i < 10; ++i) {
        ts[i] = thread(push_10000);
    }
    for (int i = 0; i < 10; ++i)
        ts[i].join();
    cout << q.size() << endl;
    string s;
    q.wait_pop(s);
    cout << s << endl;

    thread ts2[10];
    for (int i = 0; i < 10; ++i) {
        ts2[i] = thread(push_10000_2);
    }
    for (int i = 0; i < 10; ++i)
        ts2[i].join();
    cout << q2.size() << endl;
    cout << q2.front() << endl;
}
