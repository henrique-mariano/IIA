#ifndef __REVERSE_LIST_HPP__
#define __REVERSE_LIST_HPP__

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

#define N 1000
using namespace std;
using namespace std::chrono;

void swap_list(list<int>&, size_t i, size_t j);
void reverse_list(list<int>&);
void reverse_vector(vector<int>&);
void reverse_array(unsigned int*);
void print_list(list<int>&);
void print_vector(vector<int>&);
void print_array(unsigned int *arr);
void reverse_list_recursive(list<int>&);
void run_list(void (* func)(list<int>&), list<int> &);

#endif