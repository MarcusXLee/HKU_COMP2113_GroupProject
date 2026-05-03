CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCS = $(wildcard FileIO/*.cpp UI/*.cpp combat_system/*.cpp enemy/*.cpp event/*.cpp player/*.cpp)

OBJS = $(SRCS:.cpp=.o)

TARGET = vengeful_adventurer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean