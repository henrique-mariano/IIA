#include "../include/reverselist.hpp"

int main(void) {
    list<int> lista, ans, lista_rec;
    vector<int> vec(N);
    unsigned int *arr, i;
    arr = (unsigned int *) malloc(sizeof(unsigned int) * N);
	for(i = 0; i < N; i++) arr[i] = i;

    for(size_t k = 1; k < N; k++) {
        vec.push_back(k);
        lista.push_back(k);
        lista_rec.push_back(k);
    }
    run_list(reverse_list, lista);
    run_vector(reverse_vector, vec);
    run_array(reverse_array, arr);
    run_list_recursive(reverse_list_recursive, lista_rec, ans);
    
    free(arr);
    return 0;
}

void reverse_list(list<int>& lista) {
    for(size_t i = 0, j = lista.size() - 1; i < j; i++, j--) {
        swap_list(lista, i, j);
    }
    return;
}

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

void reverse_array(unsigned int *arr) {
    unsigned int i;
    unsigned int j;
	for(i = 0, j = (N / 2) - 1; i < j; i++) {
		*(arr + i) += *(arr + N - 1 - i);
		*(arr + N - 1 - i) = *(arr + i) - *(arr + N - 1 - i);
		*(arr + i) -= *(arr + N - 1 - i);
	}
}

void reverse_list_recursive(list<int> &lista, list<int> &lista_result) {
    if(lista.size() == 0)
        return;

    lista_result.push_back(lista.front());
    lista.pop_front();
    reverse_list_recursive(lista, lista_result);
}
