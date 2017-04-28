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

typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned char byte_t;

#define REPEAT_MACRO1(X) REPEAT_PATTERN(X)
#define REPEAT_MACRO2(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO1(args)
#define REPEAT_MACRO3(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO2(args)
#define REPEAT_MACRO4(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO3(args)
#define REPEAT_MACRO5(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO4(args)
#define REPEAT_MACRO6(X, args...) REPEAT_PATTERN(X) REPEAT_MACRO5(args)

#endif
