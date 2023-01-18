FILENAME = main

install:
	mkdir -p build
	g++ -g source/main.cpp -o build/main -I source/
	g++ -g tests/test_tree.cpp -o build/test_tree -I source/  -lgtest -lpthread
	build/test_tree