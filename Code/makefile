ARGS :=
TARGET := pmgr
FILES := $(shell cd ./src; find * -name "*.cpp") $(shell cd ./src; find * -name "*.c")
CPP := g++ -Wall -std=c++17
C := gcc -Wall



all: $(TARGET) debug

$(TARGET): build/$(TARGET)

build/$(TARGET): $(addprefix build/obj/, $(addsuffix .o,$(FILES)))
	@echo "Linking $@..."
	@$(CPP) $^ -o build/$(TARGET)

build/obj/%.cpp.o: src/%.cpp
	@echo "Assembling $@..."
	@mkdir -p $(dir $@)
	@$(CPP) -c $< -o $@

build/obj/%.c.o: src/%.c
	@echo "Assembling $@..."
	@mkdir -p $(dir $@)
	@$(C) -c $< -o $@


debug: debug/debug

debug/debug: $(addprefix debug/obj/, $(addsuffix .o,$(FILES)))
	@echo "Linking $@..."
	@$(CPP) -ggdb $^ -o debug/debug

debug/obj/%.cpp.o: src/%.cpp
	@echo "Assembling $@..."
	@mkdir -p $(dir $@)
	@$(CPP) -ggdb -c $< -o $@

debug/obj/%.c.o: src/%.c
	@echo "Assembling $@..."
	@mkdir -p $(dir $@)
	@$(C) -ggdb -c $< -o $@



clean:
	rm -r build/* debug/*

run: $(TARGET)
	@./build/$(TARGET) $(ARGS)