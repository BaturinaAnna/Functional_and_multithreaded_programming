# Functional and multithreaded programming

### Task 1.

> Write a function for sorting strings using the bubble method. Comparison of two adjacent elements in a function must be done using a lambda expression, which is passed to the function as a parameter. Build an example using sorting using 5 different comparator functions. 

### Задание 2.

> Write a program in which a separate thread is used to sort an array of strings from 1 task. Sorting occurs in the auxiliary thread, and the main thread outputs the contents of the array after each step of the algorithm. Threads must use mutexes to keep all synchronized. 

### Задание 3.

> Write a program that simulates customer service in a supermarket. The idea of ​​the problem is that customers come to the checkout counters at random times and with carts containing a random number of products. A queue is created to serve several customers (up to 5 people). Customers are placed at the end of the line. As soon as the queue is full for one checkout, a new checkout stream is created with its own queue. The checkout stream can complete execution if customers run out. The customer service process consists of iterating over all the products represented by integers in a vector with a slight delay. 