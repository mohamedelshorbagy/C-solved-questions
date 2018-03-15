all: 
	g++ prefixevaluator.cpp -o prefix -fpermissive -w -std=c++11 -std=c++0x -std=gnu++11
clean:
	rm -rf *o prefix