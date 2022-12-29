#pragma once
#include <iostream>
using namespace std;

template <class T>
class Arrays
{
private:
	int count;
	int currentMemorySize;
	T* buffer;
public:
	Arrays();
	~Arrays();

	bool PushFront(T data);
	bool PushBack(T data);

	bool PopFront(T* out);
	bool PopBack(T* out);

	bool Clear();
	bool IsEmpty();
	bool IsFull();

	bool Insert(int pos, T data);
	bool Remove(int pos, T* out);
	void PrintAll();

	int Count() const;
	T& operator [] (const int& idx);
private:
	void Print(T* contents, int count);
};

template<class T>
Arrays<T>::Arrays()
{
	count = 0;
	currentMemorySize = 16;
	buffer = new T[currentMemorySize];
	memset(buffer, 0, currentMemorySize);
}

template<class T>
Arrays<T>::~Arrays()
{
	Clear();
	delete[] buffer;
}

template<class T>
inline bool Arrays<T>::PushFront(T data)
{
	if (IsFull())
	{
		currentMemorySize *= 2;
		T* exBuffer = new T[currentMemorySize];
		memcpy(exBuffer, buffer, sizeof(T) * count);
		delete[] buffer;	// 메모리를 털어버린다
		buffer = exBuffer;	// 주소를 바꾼다.
	}
	memcpy(buffer + 1, buffer, sizeof(T) * count);
	buffer[0] = data;

	count++;
	return true;
}

template<class T>
inline bool Arrays<T>::PushBack(T data)
{
	if (IsFull())
	{
		currentMemorySize *= 2;
		T* exBuffer = new T[currentMemorySize];
		memcpy(exBuffer, buffer, sizeof(T) * count);
		delete[] buffer;	// 메모리를 털어버린다
		buffer = exBuffer;	// 주소를 바꾼다.
	}
	buffer[count] = data;

	count++;
	return true;
}

template<class T>
inline bool Arrays<T>::PopFront(T* out)
{
	if (IsEmpty())
	{
		return false;
	}

	*out = buffer[0];

	count--;
	T* exBuffer = new T[currentMemorySize];
	memcpy(exBuffer, buffer + 1, sizeof(T) * count);
	delete[] buffer;
	buffer = exBuffer;
	return true;
}

template<class T>
inline bool Arrays<T>::PopBack(T* out)	//readBack
{
	/**
	 * 컴퓨터공학적 삭제의 본질은 [은닉]이다.
	 **/
	if (IsEmpty())
	{
		return false;
	}

	*out = buffer[count - 1];
	count--;
	/*
	T* exBuffer = new char[currentMemorySize];

	for (int i = 0; i < count; i++)
	{
		exBuffer[i] = buffer[i];
	}

	delete[] buffer;
	buffer = exBuffer;
	*/
	return true;
}

template<class T>
inline bool Arrays<T>::Clear()
{
	return false;
}

template<class T>
inline bool Arrays<T>::IsEmpty()
{
	return count == 0;
}

template<class T>
inline bool Arrays<T>::IsFull()
{
	return count == currentMemorySize - 1;
}

template<class T>
inline bool Arrays<T>::Insert(int pos, T data)
{
	if (IsFull())
	{
		currentMemorySize *= 2;
		T* exBuffer = new T[currentMemorySize];
		memcpy(exBuffer, buffer, sizeof(T) * count);
		delete[] buffer;	// 메모리를 털어버린다
		buffer = exBuffer;	// 주소를 바꾼다.
	}

	memcpy(buffer + pos + 1, buffer + pos, sizeof(T) * count);
	buffer[pos] = data;

	count++;

	return true;
}

template<class T>
inline bool Arrays<T>::Remove(int pos, T* out)
{
	if (IsEmpty())
	{
		return false;
	}

	if (count < pos + 1)
	{
		return false;
	}

	*out = buffer[pos];
	count--;
	memcpy(buffer + pos, buffer + pos + 1, sizeof(T) * count);//total-1
	return true;
}

template<class T>
inline int Arrays<T>::Count() const
{
	return count;
}

template<class T>
inline T& Arrays<T>::operator[](const int& idx)
{
	return buffer[idx];
}

template<class T>
inline void Arrays<T>::Print(T* contents, int count)
{
	cout << "[";
	for (int i = 0; i < count; i++)
	{
		cout << " " << contents[i];
	}
	cout << " ] - count : " << count << endl;
}

template<class T>
inline void Arrays<T>::PrintAll()
{
	cout << "[";
	for (int i = 0; i < count; i++)
	{
		cout << " " << buffer[i];
	}
	cout << " ] - count : " << count << endl;
}