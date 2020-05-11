prog2.out: prog2.cpp minMaxHeap.cpp
	g++ -o prog2.out minMaxHeap.cpp prog2.cpp
clean: 
	rm -f  prog2.out minMaxHeap.o prog2.o