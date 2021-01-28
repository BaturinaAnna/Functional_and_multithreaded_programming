#include "task1.h"
#include "task2.h"
#include "task3.h"

//task1

void task1()
{
	vector<string> array_to_sort = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth" };
	vector<string> sorted_array;

	cout << "sort by first letter" << endl;
	sorted_array = bubble_sort(array_to_sort, [](string str1, string str2) {return str1[0] > str2[0]; });
	for (auto i : sorted_array)
		cout << i << " ";

	cout << endl;
	cout << endl;

	cout << "sort by last letter" << endl;
	sorted_array = bubble_sort(array_to_sort, [](string str1, string str2) {return str1[str1.size() - 1] > str2[str2.size() - 1]; });
	for (auto i : sorted_array)
		cout << i << " ";

	cout << endl;
	cout << endl;

	cout << "sort by size" << endl;
	sorted_array = bubble_sort(array_to_sort, [](string str1, string str2) {return str1.size() > str2.size(); });
	for (auto i : sorted_array)
		cout << i << " ";

	cout << endl;
	cout << endl;

	cout << "sort by h counter" << endl;
	sorted_array = bubble_sort(array_to_sort, [](string str1, string str2)
		{return count(str1.begin(), str1.end(), 'h') > count(str2.begin(), str2.end(), 'h'); });
	for (auto i : sorted_array)
		cout << i << " ";

	cout << endl;
	cout << endl;

	cout << "sort" << endl;
	sorted_array = bubble_sort(array_to_sort, [](string str1, string str2) {return str1 > str2; });
	for (auto i : sorted_array)
		cout << i << " ";
}


//task2

void task2()
{
	vector<string> array_to_sort = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth" };

	thread thread1(bubble_sort_thread, ref(array_to_sort), [](string str1, string str2) {return str1[0] > str2[0]; });
	while (!end_flag)
	{
		mutex1.lock();
		for (auto i : array_to_sort)
			cout << i << " ";
		cout << endl;
		iteration = false;
		mutex1.unlock();
	}
	thread1.join();
}


//task3

mutex mutex2;

void buy(queue<customer*> customers, int thread_number)
{
	while (!customers.empty())
	{
		customer* cust = customers.front();
		for (int i = 0; i < cust->get_products_len(); i++)
		{
			mutex2.lock();
			cout << "customer id " << cust->get_id() << "; product number" << i << "; thread " << thread_number << endl;
			mutex2.unlock();
			this_thread::sleep_for(1s);
		}
		customers.pop();
	}
}

void task3()
{
	queue<customer*> customers;
	vector<thread*> threads;
	for (int i = 1; i <= 20; i++)
	{
		customers.push(new customer(i));
		if (i % MAX_CUSTOMERS == 0)
		{
			threads.push_back(new thread(buy, customers, threads.size() + 1));
			while (!customers.empty())
				customers.pop();
		}
	}
	for (auto thr : threads)
		thr->join();
}

int main()
{
	//task1();
	//task2();
	task3();

	return 0;
}
