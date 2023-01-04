#include <iostream>
#include <conio.h>
#include <algorithm>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

void MergeSort(int *arr, size_t start, size_t end )
{
	if (end - start < 2)
	{
		return;
	}
	if (end - start == 2)
	{
		if (arr[start] > arr[start + 1])
		{
			swap(arr[start], arr[start + 1]);
			return;
		}
	}
	MergeSort(arr, start, start + (end - start) / 2); //поділили на одну половину
	MergeSort(arr, start + (end - start) / 2, end); //поділили на другу половину
	vector<int> B;
	size_t b1 = start; 
	size_t el = start + (end - start) / 2;
	size_t b2 = el;
	while (B.size() < end - start)
	{
		if (b1 >= el || (b2 < end && arr[b2] <= arr[b1]))
		{
			B.push_back(arr[b2]);
			++b2;
		}
		else
		{
			B.push_back(arr[b1]);
			++b1;
		}
	}
	for (size_t i = start; i < end; i++)
	{
		arr[i] = B[i - start];
	}
}

int main() {
	srand(time(0));
	int n; cin >> n;
	int* array = new int[n];
	ofstream file;
	file.open("input.txt");
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % 100;
		file << array[i] << " ";
	}
	file.close();
	MergeSort(array, 0, n);
	ofstream file2;
	file2.open("output.txt");
	for (int i = 0; i < n; i++)
	{
		file2 << array[i] << " ";
	}
	file2.close();
	return 0;
}