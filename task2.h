#ifndef TASK2
#define TASK2
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex mutex1;
bool iteration = true;
bool end_flag = false;

void bubble_sort_thread(vector<string> &array, bool compare(string str1, string str2))
{
	for (int i = 0; i < array.size() - 1; i++)
	{
		for (int j = 1; j < array.size(); j++)
		{
			if (compare(array[j - 1], array[j]))
			{
				mutex1.lock();
				swap(array[j - 1], array[j]);
				iteration = true;
				mutex1.unlock();
			}
		}
	}
	end_flag = true;
}

#endif