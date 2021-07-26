#include "Array.h"


namespace ARRAY {
	Array::Array(char* i_inFileName, int i_size, int i_k)
	{
		m_size = i_size;
		m_k = i_k;
		m_arr=new long int[m_size];
		m_allocate = 1;
		checkAndInsertInputFromFile(i_inFileName);
	}
	Array::Array(long int* i_arr, int i_size, int i_k)
	{
		m_size = i_size;
		m_k = i_k;
		m_arr = new long int[m_size];
		m_allocate = 0;
		m_arr = i_arr; //Same address
		
	}

	Array::~Array()
	{
		if (m_allocate) {
			delete[] m_arr;
		}
	}

	void Array::kMergeAlgorithm() 
	{
		if (m_size < m_k)
		{
			quickSort(m_arr, 0, (m_size - 1));
		}
		else
		{
			int currentIndex = 0;
			int sizeArr;
			int sumSize = 0;
			int countBigSubArrSize = m_size % m_k; //The nuber of arrays in size: ceil((double)m_size / m_k), if zero all arrays of this size
			bool biggerThanZero = true;
			if (countBigSubArrSize == 0) {
				biggerThanZero = false;
			}
			long int** arrOfArr = new long int* [m_k]; //Array of all sub-arrays
			MINHEAP::dataNode** arrForHeap = new MINHEAP::dataNode * [m_k]; //An array of all the types that will insert into the heap

			for (int i = 0; i < m_k; i++)
			{
				if (!biggerThanZero)
				{
					sizeArr = ceil((double)m_size / m_k);
				}
				else
				{
					if (countBigSubArrSize > 0) {
						sizeArr = ceil((double)m_size / m_k);
						countBigSubArrSize--;
					}
					else
					{
						sizeArr = floor((double)m_size / m_k);
					}
				}
				arrOfArr[i] = new long int[sizeArr];
				for (int j = 0; j < sizeArr; j++)
				{
					arrOfArr[i][j] = m_arr[currentIndex];
					currentIndex++;
					
				}
				Array tempArr(arrOfArr[i], sizeArr, m_k); //Insert the relevant sub-array into a class that holds arrays
				tempArr.kMergeAlgorithm(); //Recursive call
				MINHEAP::dataNode* tempNode = new MINHEAP::dataNode; //Create a type that will insert into the heap
				tempNode->index = 0;
				tempNode->arrayBelongs = arrOfArr[i];
				tempNode->val = arrOfArr[i][0];
				tempNode->sizeOfArr = sizeArr;
				arrForHeap[i] = tempNode; //Save in an array from which we will create the heap
			}
			MINHEAP::minHeap heapForSort(arrForHeap, m_k);
			this->myMerge(heapForSort); //Calling to the method that merges using an heap
			for (int i = 0; i < m_k; i++) {
				delete[] arrOfArr[i];
			}
			delete[] arrOfArr;
			delete[] arrForHeap;
		}
	}

	void Array::myMerge(MINHEAP::minHeap i_heap) 
	{
		int i = 0;
		while (i_heap.getSize() > 0)
		{
			m_arr[i] = i_heap.DeleteMin();
			i++;
		}
		cout << endl;
	}

	void MYswap(long int& num1, long int& num2) {
		double temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int myPartition(long int* ArrForPart, int left, int right, int PivotIndex)
	{
		double pivot = ArrForPart[PivotIndex];
		MYswap(ArrForPart[PivotIndex], ArrForPart[right]);
		PivotIndex = left;

		for (int i = left; i < right; i++)
		{
			if (ArrForPart[i] <= pivot)
			{
				MYswap(ArrForPart[i], ArrForPart[PivotIndex]);
				PivotIndex++;
			}
		}
		MYswap(ArrForPart[PivotIndex], ArrForPart[right]);
		return PivotIndex;
	}

	void quickSort(long int* arr, int left, int right) {

		if (left < right)
		{
			int PivotIndex = myPartition(arr, left, right, left);
			quickSort(arr, left, PivotIndex - 1);
			quickSort(arr, PivotIndex + 1, right);
		}
	}

	void Array::copyArrayToFile(char* i_outFileName)
	{
		ofstream outfile(i_outFileName);
		if (!outfile) {
			cout << "Error with outfile" << endl;
			exit(-1);
		}
		for (int i = 0; i < m_size; i++)
		{
			outfile << m_arr[i] << endl;
		}
		outfile.close();
	}

	void Array::checkAndInsertInputFromFile(char* i_inFileName)
	{
		bool negative = false;
		int tempNum = 0;
		char tempInput;
		int i;
		ifstream inFile(i_inFileName);
		if (!inFile) {
			cout << "Error with infile" << endl;
			exit(-1);
		}

		for ( i = 0; i < m_size; i++) {
			if (inFile.eof())
			{
				cout << "wrong input" << endl;
				exit(-1);
			}
			inFile.get(tempInput);
			tempNum = 0;
			if (tempInput == '-') {
				negative = true;
				inFile.get(tempInput);
			}
			else if (!(tempInput <= '9' && tempInput >= '0')) {
				cout << "wrong input" << endl;
				exit(-1);
			}
			while (tempInput != '\n' && !inFile.eof())
			{
				if (!(tempInput <= '9' && tempInput >= '0')) {
					cout << "wrong input" << endl;
					exit(-1);
				}
				tempNum *= 10;
				tempNum += (tempInput - '0');
				inFile.get(tempInput);
			}
			if (negative) {
				tempNum *= -1;
				negative = false;
			}

			m_arr[i] = tempNum;
		}

		if (!inFile.eof()) {
			cout << "wrong input" << endl;
			exit(-1);
		}

		inFile.close();
	}

	int checkInputFromUser()
	{
		char temp;
		int num = 0;
		while (1)
		{
			temp = getchar();
			if (temp == '\n') 
			{
				break;
			}
			if (temp <= '9' && temp >= '0')
			{
				num = num * 10 + (temp - '0');
			}
			else
			{
				cout << "wrong input" << endl;
				exit(-1);
			}
		}
		if (num == 0) {
			return num;
			cout << "wrong input" << endl;
			exit(-1);
		}
		return num;
	}
}