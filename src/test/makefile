CXX=g++
CC=gcc
BIN=./bin
BASE=../..
CXXFLAGS= -std=c++11 -pthread -Wall -g 
THIRD_INCPATH=-I../../third/local/glog/include \
	-I../../third/local/zeromq/include

THIRD_LIB=../../third/local/glog/lib/libglog.a $(BASE)/third/local/zeromq/lib/libzmq.a 

.PHONY:all clean test

all: $(BIN)/utils_string.out \
	 $(BIN)/utils_configparser.out \
	 $(BIN)/utils_hashfunction.out \
	 $(BIN)/utils_buffer.out \
	 $(BIN)/utils_queue_push.out \
	 $(BIN)/utils_queue.out \
	 $(BIN)/network_message.out 

$(BIN)/utils_string.out : utils/string.cpp ../utils/string.h
	$(CXX) utils/string.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/utils_string.out 

$(BIN)/utils_configparser.out : utils/configparser.cpp ../utils/ConfigParser.h
	$(CXX) utils/configparser.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/utils_configparser.out 

$(BIN)/utils_hashfunction.out : utils/hashfunction.cpp ../utils/HashFunction.h
	$(CXX) utils/hashfunction.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/utils_hashfunction.out 

# -Wno-reorder ignore order
$(BIN)/utils_buffer.out : utils/buffer.cpp ../utils/Buffer.h
	$(CXX) utils/buffer.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/utils_buffer.out -Wno-reorder

$(BIN)/utils_queue_push.out : utils/queue_push.cpp ../utils/queue.h
	$(CXX) utils/queue_push.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/utils_queue_push.out -Wno-reorder

$(BIN)/utils_queue.out : utils/queue.cpp ../utils/queue.h
	$(CXX) utils/queue.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/utils_queue.out -Wno-reorder

$(BIN)/network_message.out : network/message.cpp ../network/Message.h
	$(CXX) network/message.cpp $(CXXFLAGS) $(THIRD_INCPATH) -Xlinker $(THIRD_LIB) -o $(BIN)/network_message.out -Wno-reorder
