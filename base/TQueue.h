#pragma once
#define MaxMemSize   100 // размер памяти по умолчанию

using namespace std;
template <class New>
class Queue
{
	int begin; // Индекс элемента массива, в котором хранится первый элемент очереди
	int end;// Индекс элемента массива, в котором хранится последний элемент очереди
	int DataCounter; // Количетсво элементов в очереди
	int MemSize;
	New* pMem;
public:
	Queue(int _size)
	{
		MemSize = _size;
		if (MemSize > MaxMemSize)
			throw "error";
		else
		{
			if (MemSize < 1)
				throw "error";
			DataCounter = 0;
			begin = 0;
			end = 0;
			pMem = new New[MemSize];
		}
	}
	~Queue()
	{
		delete[]pMem;
	}
	int GetNextIndex(int index)
	{
		return (++index%MemSize);
	}
	int IsEmpty()
	{
		return (DataCounter == 0);
	}
	int IsFull()
	{
		return (DataCounter == MemSize);
	}
	void Put(New elem)
	{
		if (!IsFull())
		{
			pMem[end++] = elem;
			DataCounter++;
			if (end > MemSize - 1)
				end = 0;
		}
		else
		{
			throw "error";
		}
	}
	New Get()
	{
		if (IsEmpty())
			throw "error";
		New res = pMem[begin];
		begin += 1;
		if (begin > MemSize - 1)
			begin = 0;
		DataCounter -= 1;
		return res;
	}
	New Check()
	{
		if (!IsEmpty())
		{
			return pMem[begin];
		}
		else
			throw "error";
	}
	int Size()
	{
		return DataCounter;
	}
};
