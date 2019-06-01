#ifndef __SUM_HPP__
#define __SUM_HPP__

#include <iostream>
#include <list>
#include <vector>
#include "utils.hpp"

using namespace std;

const int N = 1001;

void list_sum(list<int>&);
void list_rec_sum(list<int>&, int&);
int vector_sum(vector<int>);
void vector_rec_sum(vector<int> &vec, int &soma);
void array_sum(size_t *arr);
#endif