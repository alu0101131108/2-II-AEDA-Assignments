all:	dll_test vector_test queue_test stack_test
dll_test:	src/debug/dll_test.cpp
	g++ -o build/dll_test.o src/debug/dll_test.cpp
vector_test: src/debug/vector_test.cpp
	g++ -o build/vector_test.o src/debug/vector_test.cpp
queue_test: src/debug/queue_test.cpp
	g++ -o build/queue_test.o src/debug/queue_test.cpp
stack_test: src/debug/stack_test.cpp
	g++ -o build/stack_test.o src/debug/stack_test.cpp
clean:
	rm build/vector_test.o build/dll_test.o build/queue_test.o build/stack_test.o
