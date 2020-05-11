#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <iostream>
#include <sstream>
#include <array>
using namespace std;

class minMaxHeap {
	public:
		void insert(int value);
		bool deleteMin();
		bool deleteMax();
		int getMax();
		void printMax();
		void printMin();
		int getMin();
		void printHeap();
	//private:
		int array[1000000];
		int index=0;
		//int arraySize = 0;
		void percolateup(int index);
		int getLevel (int index);
		int getParentIndex(int index);
		bool isMinLevel(int level);
		void swap(int index1, int index2);
		void percolateup_max(int index);
		void percolateup_min(int index);
		void percolatedown_min(int rootindex);
		void percolatedown(int rootindex);
		void percolatedown_max(int rootindex);
		int getChilrenIndex(int rootindex);
		int getGrandChilrenIndex(int rootindex);
		};


#endif