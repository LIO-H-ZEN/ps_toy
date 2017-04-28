/* ******************************************************
# Author       : liuzhaocheng
# Last modified: 2017-04-26 13:02
# Email        : lio_h_zen@163.com
# Filename     : common.h
# Description  : 
******************************************************/
#ifndef LZC_COMMON_H
#define LZC_COMMON_H

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cstring>

#include "NoncopyableObject.h"
#include "glog/logging.h"

typedef int int32;
typedef long int64;
typedef unsigned int uint32;
typedef unsigned long uint64;

#define REPEAT_MACRO1(X) REPEAT_PATTERN(X)
#define REPEAT_MACRO2(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO1(args)
#define REPEAT_MACRO3(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO2(args)
#define REPEAT_MACRO4(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO3(args)
#define REPEAT_MACRO5(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO4(args)
#define REPEAT_MACRO6(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO5(args)

#endif
