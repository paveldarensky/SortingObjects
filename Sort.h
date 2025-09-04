#pragma once
#include <iostream>
#include <stdio.h>

template <class T>
class Sort
{
public:
	static int SortShell(T** Ptr, int n);
	static int SortBinHeap(T** Ptr, int n);

	static bool CheckSort(T** Ptr, int n);

};

template <class T>
void swap(T* a, T* b)
{
	T c;
	c = *a;
	*a = *b;
	*b = c;
}

template <class T>
int Sort<T>::SortShell(T** Ptr, int n)
{
	int i, j, h;
	int counter = 0;
	for (h = 1; h <= n / 9; h = h * 3 + 1);
	while (h >= 1)
	{
		for (i = h; i < n; i++)
			for (j = i - h; (j >= 0) && (*Ptr[j] < *Ptr[j + h]); j -= h, counter++)			// < - Decreasing, > - increasing. 
				swap(Ptr[j], Ptr[j + h]);
		h = (h - 1) / 3;
	}
	return counter;
}

template <class T>
void sift(T** Ptr, int i, int m, int& counter)
{
	int j = i, k = i * 2 + 1;	 // k - левый сын
	while (k <= m)
	{
		if ((k < m) && (*Ptr[k] < *Ptr[k + 1])) { k++; } // k - больший сын
		counter++;
		if (*Ptr[j] > *Ptr[k])														// > - Decreasing, < - increasing. 
		{
			swap(Ptr[j], Ptr[k]); j = k; k = k * 2 + 1;
			counter++;
		}
		else break;
	}
}

template <class T>
int Sort<T>::SortBinHeap(T** Ptr, int n)
{
	int i, m;
	int counter = 0;
	// построение пирамиды
	for (i = n / 2; i >= 0; i--)
		sift(Ptr, i, n - 1, counter);
	// сортировка массива
	for (m = n - 1; m >= 1; m--)
	{
		swap(Ptr[0], Ptr[m]);
		sift(Ptr, 0, m - 1, counter);
	}
	return counter;
}

template <class T>
bool Sort<T>::CheckSort(T** Ptr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (*Ptr[i] > *Ptr[i + 1])
		{
			return false;
		}
	}
	return true;
}
