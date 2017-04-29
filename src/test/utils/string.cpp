/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-27 03:20
# Email        : lio_h_zen@163.com
# Filename     : string.cpp
# Description  : 
******************************************************/

#include <iostream>
#include <vector>

#include "../../utils/string.h"

using namespace lzc;
using namespace std;

void test_trim() {
    LOG(INFO) << "<test trim>";
    string a = " hello world";
    trim(a);
    CHECK(a == "hello world");
    LOG(INFO) << "now a is:" << a;    
}

void test_split() {
    LOG(INFO) << "<test split>";
    string a = "input_path:xxx output_path:xxx";
    vector<string> list = split(a, " ");
    for (auto i : list)
        cout << i << endl;
    CHECK(list.size() == 2);
    LOG(INFO) << "original str is:" << a;
    for (auto p:list) 
        LOG(INFO) << "part\t" << p;
    CHECK(list[0] == "input_path:xxx");
    CHECK(list[1] == "output_path:xxx");
}


void test_kv_split() {
    LOG(INFO) << "<test kv split>";
    string a = "input_path:/root/input";
    pair<string, string> kv = std::move(kv_split(a, ":"));
    LOG(INFO) << "original str is:" << a;
    LOG(INFO) << "key:" << kv.first << " value:" << kv.second;
    CHECK(kv.first == "input_path");
    CHECK(kv.second == "/root/input"); 
}

void test_starts_with() {
    LOG(INFO) << "<test is comment>";
    string a = "# this is comment";
    bool ret = starts_with(a, "#");
    CHECK(ret == true);
    LOG(INFO) << "original str is:" << a;
    LOG(INFO) << "is comment?" << ret;
}

void test_format_string() {
    LOG(INFO) << "<test format string>";
    string ret = "1234";
    cout << ret << endl;
    format_string(ret, "56%s10", "789");
    cout << ret << endl;
    CHECK(ret.substr(0, 11) == "12345678910");
    LOG(INFO) << "test format string done";
}

int main() {
    test_trim();
    test_split();
    test_kv_split();
    test_starts_with();
    test_format_string();
}
