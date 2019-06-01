#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern const int N;

void run_list(void (* func)(list<int>&), list<int> &);
void run_list_recursive(void (* func)(list<int>&, list<int>&), list<int> &lista, list<int> &lista_resp);
void run_list_rec_sum(void (*func)(list<int>&, int&), list<int>&, int&);
void run_vector(void (*func)(vector<int>&), vector<int> &);
void run_vector_rec_sum(void (*func)(vector<int>&, int&), vector<int>&, int&);
void run_array(void (*func)(unsigned int*), unsigned int *arr);
void print_list(list<int>&);
void print_vector(vector<int>&);
void print_array(unsigned int *arr);

#endif