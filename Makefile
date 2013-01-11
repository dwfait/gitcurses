CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -Wall -Wextra -pedantic -std=c++11
LD_FLAGS := -lcurses
GXX := /usr/local/Cellar/gcc/4.7.2/bin/g++-4.7

bin/gitcurses: $(OBJ_FILES)
	$(GXX) -o $@ $^ $(LD_FLAGS)

obj/%.o: src/%.cpp
	$(GXX) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f obj/*.o bin/*
