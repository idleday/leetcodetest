SRCS:=$(wildcard main.cpp)
SRCS+=$(wildcard leetcode/*.cpp)
SRCS+=$(wildcard utils/*.cpp)
OBJS := $(SRCS:%.c=%.o)
OBJS := $(OBJS:%.cpp=%.o)
CFLAGS += -g
CPPFLAGS += -Iinclude -g
EXE := a.out

all: $(OBJS)
	@echo objs: $(OBJS)
	$(CXX) -o $(EXE) ${OBJS}

clean:
	$(RM) $(OBJS) $(EXE)

%.o:%.cpp
	$(CXX) -o $@ -c $< $(CPPFLAGS)


