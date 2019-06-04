#ifndef __SUM_HPP__
#define __SUM_HPP__

#include <iostream>
#include <list>
#include <vector>
#include "utils.hpp"

using namespace std;

/*N que define o tamanho das estruturas de dados*/
const unsigned int N = 10001;

typedef long long unsigned int llu;

int list_sum(list<llu>);
void list_rec_sum(list<llu>&, llu&);
int vector_sum(vector<int>);
void vector_rec_sum(vector<int> &vec, int &soma);
int array_sum(unsigned int *arr);

#endif