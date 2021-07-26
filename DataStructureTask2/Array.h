#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <math.h> 
#include "Heap.h"
using namespace std;

namespace ARRAY {
	class Array
	{
	public:
		Array(char* i_inFileName, int i_size, int i_k);
		Array(long int* i_arr, int i_size, int i_k);
		~Array();
		void kMergeAlgorithm();
		void myMerge(MINHEAP::minHeap i_heap);
		void checkAndInsertInputFromFile(char* i_inFileName);
		void copyArrayToFile(char* i_outFileName);

	private:
		long int* m_arr;
		int m_size;
		int m_k;
		int m_allocate;
	};
	void MYswap(long int& num1, long int& num2);
	int myPartition(long int* ArrForPart, int left, int right, int PivotIndex);
	void quickSort(long int* arr, int left, int right);
	int checkInputFromUser();
}

