#include "../include/utils.hpp"

void run_list(void (* func)(list<int>&), list<int> &lista) {
    auto start = high_resolution_clock::now();
    func(lista);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Reversao de lista:" << endl;
    cout << "Tempo levado pela funcao: " << duration.count() << " nanosegundos" << endl;
    return;
}

void run_list_recursive(void (* func)(list<int>&, list<int>&), list<int> &lista, list<int> &lista_resp) {
    auto start = high_resolution_clock::now();
    func(lista, lista_resp);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Reversao recursiva de lista:" << endl;
    cout << "Tempo levado pela funcao: " << duration.count() << " nanosegundos" << endl;
    return;
}

void run_list_rec_sum(void (*func)(list<int>&, int&), list<int> &lista, int &soma) {
    auto start = high_resolution_clock::now();
    func(lista, soma);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Soma recursiva da lista:" << endl;
    cout << "Tempo levado pela funcao: " << duration.count() << " nanosegundos" << endl;
    return;
}

void run_vector(void (*func)(vector<int>&), vector<int> &vec) {
    auto start = high_resolution_clock::now();
    func(vec);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Reversao de vector:" << endl;
    cout << "Tempo levado pela funcao: " << duration.count() << " nanosegundos" << endl;
    return;
}

void run_vector_rec_sum(void (*func)(vector<int>&, int&), vector<int> &vec, int &soma) {
    auto start = high_resolution_clock::now();
    func(vec, soma);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Soma recursiva do vector:" << endl;
    cout << "Tempo levado pela funcao: " << duration.count() << " nanosegundos" << endl;
}

void run_array(void (*func)(unsigned int*), unsigned int *arr) {
    auto start = high_resolution_clock::now();
    func(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "Reversao de array:" << endl;
    cout << "Tempo levado pela funcao: " << duration.count() << " nanosegundos" << endl;
    return;
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

void print_array(unsigned int *arr) {
    unsigned int i;
    for(i = 0; i < N; i++) printf("%3d%s", arr[i], i % 20 == 19 ? "\n" : " ");
}