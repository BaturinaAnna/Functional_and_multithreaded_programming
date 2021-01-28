#ifndef TASK3
#define TASK3

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>

using namespace std;

const int MAX_PRODUCTS = 20;
const int MAX_CUSTOMERS = 5;

class customer
{
private:
	int customer_id;
	vector<string> products;
public:
	customer(int);
	int get_id();
	int get_products_len();
};


#endif


