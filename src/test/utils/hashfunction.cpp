/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-28 01:33
# Email        : lio_h_zen@163.com
# Filename     : hashfunction.cpp
# Description  : 
******************************************************/

#include "../../utils/HashFunction.h"

using namespace lzc;
using namespace std;

int main() {
    for (int i = 0; i < 1000; ++i)
        cout << get_hash_code(i) << endl;
}
