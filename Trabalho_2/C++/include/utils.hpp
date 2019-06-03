#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long unsigned int llu;

extern const unsigned int N;

/*
As funções com o prefixo run recebem uma função e executam passando seus argumentos
e assim avaliando seu tempo de execução.
*/

void run_list(void (* func)(list<int>&), list<int> &);
void run_list_recursive(void (* func)(list<llu>&, list<llu>&), list<llu> &lista, list<llu> &lista_resp);
void run_list_rec_sum(void (*func)(list<int>&, int&), list<int>&, int&);
void run_list_sum(int (*func)(list<int>), list<int>);
void run_vector(void (*func)(vector<int>&), vector<int> &);
void run_list_rec_sum(void (*func)(list<llu>&, llu&), list<llu> &lista, llu &soma);
void run_array(void (*func)(unsigned int*), unsigned int *arr);
void print_list(list<int>&);
void print_vector(vector<int>&);
void print_array(unsigned int *arr);

#endif