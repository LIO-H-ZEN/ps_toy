#include <iostream>
#include "../../utils/Buffer.h"

using namespace std;
using namespace lzc;

void test_basicbuffer() {
    BasicBuffer bb;
}

void test_binarybuffer() {
    BinaryBuffer bb;
    int i = 99;
    double d = 7.98765;
    short s = 7;
    bb << i;
    bb << d;
    
    int io = -1;
    bb >> io;
    cout << io << endl;     
    double doo = -1;
    bb >> doo;
    cout << doo << endl;
    bb << s;
    short so = -1;
    bb >> so;
    cout << so << endl;
}

int main() {
    test_basicbuffer(); 
    test_binarybuffer(); 
}
