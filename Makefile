SRCS:=$(wildcard main.cpp)
SRCS+=$(wildcard leetcode/*.cpp)
SRCS+=$(wildcard utils/*.cpp)
OBJS := $(SRCS:%.c=%.o)
OBJS := $(OBJS:%.cpp=%.o)

CPPFLAGS := -Iinclude

all: $(OBJS)
	@echo objs: $(OBJS)
	$(CXX) -o a.exe ${OBJS}

%.o:%.cpp
	$(CXX) -o $@ -c $< $(CPPFLAGS)


