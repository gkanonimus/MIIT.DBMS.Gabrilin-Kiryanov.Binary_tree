FILENAME = main

install:
	mkdir -p build
	g++ -g source/$(FILENAME).cpp -o build/$(FILENAME) -I source/
	g++ -g tests/test_node.cpp -o build/test_node -I source/  -lgtest -lpthread
	g++ -g tests/test_tree.cpp -o build/test_tree -I source/  -lgtest -lpthread
	build/test_node
	build/test_tree