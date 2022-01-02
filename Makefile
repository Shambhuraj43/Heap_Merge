all: heapMerge
	g++ heapMerge.cpp -o heapMerge


run:
	./heapMerge

clean:
	rm -rf *.o
