#pragma once
#include <iostream>
using namespace std;

namespace MINHEAP {
	typedef struct {
		int val;
		int sizeOfArr;
		int index;
		long int* arrayBelongs;
	}dataNode;

	class minHeap
	{
	public:
		minHeap(dataNode** data, int size);
		~minHeap();
		int DeleteMin();
		dataNode* Min() { return m_Heap[0]; }
		bool IsEmpty() { return heapSize == 0; }
		int getSize() { return heapSize; }

	private:
		dataNode** m_Heap;
		int maxSize;
		int heapSize;
		int allocated;
		static int Left(int node) { return (2 * node + 1); }
		static int Right(int node) { return 2 * node + 2; }
		static int Parent(int node) { return (node - 1) / 2; }
		void FixHeap(int node);
		void Insert(dataNode* node);
		void BuildHeap(dataNode** data, int size);
	};

	void MYswap(dataNode& num1, dataNode& num2);

}
