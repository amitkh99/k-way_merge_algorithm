#include "Heap.h"

namespace MINHEAP 
{
	minHeap::minHeap(dataNode** data, int size)
	{
		BuildHeap(data, size);
		allocated = 0;
	}

	minHeap::~minHeap()
	{
		if (allocated)
			delete[] m_Heap;
		m_Heap = nullptr;
	}

	void minHeap::BuildHeap(dataNode** data, int size) {
		heapSize = maxSize = size;
		m_Heap = data;
		allocated = 0;
		int i;
		for (i = size / 2 - 1; i >= 0; i--) {
			FixHeap(i);
		}
	}

	void minHeap::FixHeap(int node)
	{
		int min = node;
		int left = Left(node);
		int right = Right(node);

		if (left < heapSize && (m_Heap[left]->val < m_Heap[min]->val)) {
			min = left;
		}
		if (right < heapSize && (m_Heap[right]->val < m_Heap[min]->val)) {
			min = right;
		}
		if (min != node) {
			MYswap(*m_Heap[node], *m_Heap[min]);
			FixHeap(min);
		}
	}

	int minHeap::DeleteMin() { //If the array relevant to the value that coming out from the heap is not done, insert the next value in the array into the heap instead of the output that came out and performs FixHeap
		if (heapSize < 1) {
			cout << "input invalid" << endl;
			exit(1);
		}
		int min = m_Heap[0]->val;
		m_Heap[0]->index++;
		if (m_Heap[0]->index == m_Heap[0]->sizeOfArr) 
		{
			heapSize--;
			m_Heap[0] = m_Heap[heapSize];
			m_Heap[heapSize] = nullptr;
		}
		else
		{
			m_Heap[0]->val = m_Heap[0]->arrayBelongs[m_Heap[0]->index];
		}
		FixHeap(0);
		return min;
	}

	void minHeap::Insert(dataNode* node) {
		if (heapSize == maxSize) {
			cout << "error" << endl;
			exit(1);
		}
		int i = heapSize;
		heapSize++;
		while ((i > 0) && ((m_Heap[Parent(i)]->val) > (node->val))) {
			m_Heap[i] = m_Heap[Parent(i)];
			i = Parent(i);
		}
		m_Heap[i] = node;
	}

	void MYswap(dataNode& num1, dataNode& num2)
	{
		dataNode temp = num1;
		num1 = num2;
		num2 = temp;
	}
}


