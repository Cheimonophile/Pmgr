files := $(shell cd ./src; find * -name "*.cpp")



all: passmgr

passmgr: build/passmgr

build/passmgr: $(addprefix build/out/, $(addsuffix .o,$(files)))
	g++ $^ -o build/passmgr

build/out/%.cpp.o: src/%.cpp
	@mkdir -p $(dir $@)
	g++ -c $< -o $@

clean:
	rm -r build/*

run: passmgr
	@./build/passmgr