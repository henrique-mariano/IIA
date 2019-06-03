#include "../include/sum.hpp"

int main(void) {

    vector<int> v(N);
    list<llu> lista;
    unsigned int *arr, i;
    arr = (unsigned int *) malloc(sizeof(unsigned int) * N);
	for(i = 0; i < N; i++) arr[i] = i;

    for(llu i = 1; i < N; i++) {
        v.push_back(i);
        lista.push_back(i);
    }

    llu l_sum = 0;
    //int vec_sum = 0;
    //int arr_sum = 0;

    //arr_sum = array_sum(arr);

    //run_list_sum(list_sum, lista);

    run_list_rec_sum(list_rec_sum, lista, l_sum);

    //run_vector_rec_sum(vector_rec_sum, v, vec_sum);


    // print_vector(v);
    
    //cout << "Soma array: " << arr_sum << endl;

    //cout << "Soma vetor: " << vec_sum << endl;

    cout << "Soma lista: " << l_sum << endl;

    free(arr);

    return 0;
}

int vector_sum(vector<int> v) {
    int sum = 0;
    for (llu i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

int list_sum(list<int> lista) {
    int sum = 0;
    for(llu i = 0; i < lista.size(); i++) {
        sum += lista.front();
        lista.pop_front();
    }
    return sum;
}

int array_sum(unsigned int *arr) {
    int sum = 0;
    for(llu i = 0; i < N; i++)
        sum += arr[i];
    return sum;
}

void vector_rec_sum(vector<int> &vec, int &soma) {
    if (vec.size() == 0)
        return;
    soma += vec.back();
    vec.pop_back();
    vector_rec_sum(vec, soma);
}

void list_rec_sum(list<llu> &lista, llu &soma) {
    if(lista.size() == 0)
        return;

    soma += lista.front();
    lista.pop_front();
    list_rec_sum(lista, soma);

}