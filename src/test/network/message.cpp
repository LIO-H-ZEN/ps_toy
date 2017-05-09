#include <iostream>
#include "../../network/Message.h"
#include "../../utils/Buffer.h"

using namespace lzc;
using namespace std;

void test_msg_1() {
    BinaryBuffer b1;
    int a = 77;
    double b = 7.7;
    bool c = true;
    b1 << a;
    b1 << b;
    b1 << c;
    Message msg(b1.buffer(), b1.size());
    
    BinaryBuffer b2; 
    b2.set(msg.buffer(), msg.size());
    int ao;
    double bo;
    bool co;
    b2 >> ao;
    b2 >> bo;
    b2 >> co;
    cout << ao << endl;
    cout << bo << endl;
    cout << co << endl;
}

void test_msg_2() {
    BinaryBuffer b1;
    int a = 77;
    double b = 7.7;
    bool c = true;
    b1 << a;
    b1 << b;
    b1 << c;

    Message msg(b1);
    BinaryBuffer b2; 
    b2.set(msg.buffer(), msg.size());

    int ao;
    double bo;
    bool co;
    b2 >> ao;
    b2 >> bo;
    b2 >> co;
    cout << ao << endl;
    cout << bo << endl;
    cout << co << endl;
}

int main() {
    test_msg_1();
    test_msg_2();
}
