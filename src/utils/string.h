/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-27 05:10
# Email        : lio_h_zen@163.com
# Filename     : string.h
# Description  : 
******************************************************/
#ifndef LZC_STRING_H
#define LZC_STRING_H

#include "common.h"

namespace lzc {

void trim(std::string &ss) {
    if (!ss.empty()) {
        ss.erase(0, ss.find_first_not_of(" \t\n\r"));
        ss.erase(ss.find_last_not_of(" \t\n\r") + 1);
    } 
}

std::vector<std::string> split(std::string &ss, const std::string &seg) {
    std::vector<std::string> fs; 
    size_t se_search = std::string::npos;
    size_t last = 0;
    se_search = ss.find_first_of(seg, last);
    while (se_search != std::string::npos) {
        fs.push_back(ss.substr(last, se_search - last));
        last = se_search + 1;
        se_search = ss.find_first_of(seg, last);
    }
    fs.push_back(ss.substr(last));
    return fs;
}

std::pair<std::string, std::string> kv_split(std::string &ss, const std::string &seg) {
    size_t ind = ss.find_first_of(seg);
    auto ps = std::make_pair(ss.substr(0, ind), ss.substr(ind + 1));
    return ps;
}

bool starts_with(std::string &ss, const std::string &flag) {
    size_t lens = flag.size();
    return ss.substr(0, lens) == flag;
}

} // namespace lzc

#endif
