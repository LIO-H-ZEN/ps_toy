/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-27 21:11
# Email        : lio_h_zen@163.com
# Filename     : configparser.cpp
# Description  : 
******************************************************/
#include "../../utils/ConfigParser.h"

using namespace std;
using namespace lzc;

int main() {
    ConfigParser cp("conf1.txt");
    cout << cp.get_config("U").to_string() << endl; 
    cout << cp.get_config("I").to_string() << endl; 
    cout << cp.get_config("AI").to_int32() << endl; 
}

