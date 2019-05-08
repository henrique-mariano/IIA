#include <iostream>
#include <list>
#include <vector>

#define N 10e2 + 1
using namespace std;

void reverse_list(list<int>&);
void swap_list(list<int>&, size_t i, size_t j);
void print_list(list<int>&);
void reverse_vector(vector<int>&);
void print_vector(vector<int>&);

int main(void) {
    list<int> lista;
    //vector<int> vec(N);
    for(size_t k = 1; k < N; k++) {
        //vec.push_back(k);
        lista.push_back(k);
    }
    cout << "Lista antes do reverse:" << endl;
    print_list(lista);
    reverse_list(lista);
    //print_vector(vec);
    //reverse_vector(vec);
    cout << "Lista apos o reverse:" << endl;
    //print_vector(vec);
    print_list(lista);
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
