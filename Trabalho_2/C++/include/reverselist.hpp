#ifndef __REVERSE_LIST_HPP__
#define __REVERSE_LIST_HPP__

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

#include "utils.hpp"

using namespace std;
using namespace std::chrono;

const unsigned int N = 10000;

//Swap de dois elementos de uma lista
void swap_list(list<int>&, size_t i, size_t j);
void reverse_list(list<int>&);
void reverse_vector(vector<int>&);
void reverse_array(unsigned int*);
void reverse_list_recursive(list<int>&, list<int>&);

#endif