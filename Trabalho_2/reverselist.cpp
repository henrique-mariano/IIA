#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <chrono>

#define N 100000
using namespace std;
using namespace std::chrono;

void swap_list(list<int>&, size_t i, size_t j);
void reverse_list(list<int>&);
void reverse_vector(vector<int>&);
void reverse_array(unsigned int*);
void print_list(list<int>&);
void print_vector(vector<int>&);
void print_array(unsigned int *arr);

int main(void) {
    list<int> lista;
    vector<int> vec(N);
    unsigned int *arr, i;
    arr = (unsigned int *) malloc(sizeof(unsigned int) * N);
	for(i = 0; i < N; i++) arr[i] = i;

    for(size_t k = 1; k < N; k++) {
        vec.push_back(k);
        lista.push_back(k);
    }
    // cout << "Lista antes do reverse:" << endl;
    // print_list(lista);
    auto start = high_resolution_clock::now();
    // reverse_list(lista);
    // lista.reverse();
    //print_vector(vec);
    // reverse_vector(vec);
    reverse_array(arr);
    auto stop = high_resolution_clock::now();
    cout << "Lista apos o reverse:" << endl;
    // print_vector(vec);
    // print_list(lista);
    // print_array(arr);
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    free(arr);
    return 0;
}

void reverse_list(list<int>& lista) {
    for(size_t i = 0, j = lista.size() - 1; i < j; i++, j--) {
        swap_list(lista, i, j);
    }
    return;
}

//Swap de dois elementos de uma lista
void swap_list(list<int>& lista, size_t i, size_t j) {
    list<int> :: iterator it;
    list<int> :: iterator jt;
    size_t aux;
    it = lista.begin();
    jt = lista.begin();
    advance(it, i); //leva o iterator para a posicao i na lista
    advance(jt, j);
    aux = *it;
    *it = *jt;
    *jt = aux;
    return;
}

void reverse_vector(vector<int>& vec) {
    for(size_t i = 0, j = vec.size() - 1; i < j; i++, j--) {
        vec[i] += vec[j];
        vec[j] = vec[i] - vec[j];
        vec[i] -= vec[j];
    }
}

void print_list(list<int>& lista) {
    cout << "Lista:";
    for(auto i = lista.begin(); i != lista.end(); ++i) {
        printf(" %d", *i);
    }
    cout << endl;
}

void print_vector(vector<int>& vec) {
    cout << "Vector:";
    for(auto i = vec.begin(); i != vec.end(); ++i) {
        printf(" %d", *i);
    }
    cout << endl;
}

void reverse_array(unsigned int *arr) {
    unsigned int i;
    unsigned int j;
	for(i = 0, j = (N / 2) - 1; i < j; i++) {
		*(arr + i) += *(arr + N - 1 - i);
		*(arr + N - 1 - i) = *(arr + i) - *(arr + N - 1 - i);
		*(arr + i) -= *(arr + N - 1 - i);
	}
}

void print_array(unsigned int *arr) {
    unsigned int i;
    for(i = 0; i < N; i++) printf("%3d%s", arr[i], i % 20 == 19 ? "\n" : " ");
}