CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

SRCS := main.cpp Member.cpp Trainer.cpp Gym.cpp
OBJS := $(SRCS:.cpp=.o)

gym: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) gym gym.exe

.PHONY: clean
