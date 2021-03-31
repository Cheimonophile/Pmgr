TARGET := passmgr
FILES := $(shell cd ./src; find * -name "*.cpp") $(shell cd ./src; find * -name "*.c")
CPP := g++ -ggdb -Wall -std=c++17
C := gcc -Wall



all: $(TARGET)

$(TARGET): build/$(TARGET)

build/$(TARGET): $(addprefix build/out/, $(addsuffix .o,$(FILES)))
	$(CPP) $^ -o build/$(TARGET)

build/out/%.cpp.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) -c $< -o $@

build/out/%.c.o: src/%.c
	@mkdir -p $(dir $@)
	$(C) -c $< -o $@

clean:
	rm -r build/*

run: passmgr
	@./build/myAppStore database.db