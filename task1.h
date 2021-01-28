#ifndef TASK1
#define TASK1
#include <iostream>
#include <vector>

using namespace std;

vector <string> bubble_sort(vector<string> array, bool compare(string str1, string str2))
{
	for (int i = 0; i < array.size() - 1; i++)
	{
		for (int j = 1; j < array.size(); j++)
		{
			if (compare(array[j - 1], array[j]))
			{
				swap(array[j - 1], array[j]);
			}
		}
	}
	return array;
}

#endif