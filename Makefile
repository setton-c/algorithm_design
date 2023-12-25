
# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall

# Target executable
TARGET = graph

# Source files
SRCS = src/weighted_graph.cpp src/unweighted_graph.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Targets
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile unweighted_graph.cpp before main.cpp
weighted_graph.o: src/weighted_graph.cpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

unweighted_graph.o: src/unweighted_graph.cpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
