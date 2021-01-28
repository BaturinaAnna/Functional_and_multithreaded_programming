#include "task3.h"
#include <random>


customer::customer(int id)
{
	customer_id = id;
	for (int i = 0; i < rand() % MAX_PRODUCTS; i++)
		products.push_back("product");
}

int customer::get_id()
{
	return customer_id;
}

int customer::get_products_len()
{
	return products.size();
}