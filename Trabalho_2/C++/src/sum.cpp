#include "../include/sum.hpp"

int main(void) {

    vector<int> v(N);
    list<int> lista;

    for(int i = 1; i < N; i++){
        v.push_back(i);
        lista.push_back(i);
    }

    int sum = 0;
    int vec_sum = 0;

    run_list_rec_sum(list_rec_sum, lista, sum);

    run_vector_rec_sum(vector_rec_sum, v, vec_sum);

    // print_vector(v);
    
    cout << "Soma vetor: " << vec_sum << endl;

    cout << "Soma lista: " << sum << endl;

    return 0;
}

int vector_sum(vector<int> v) {
    int sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

void vector_rec_sum(vector<int> &vec, int &soma) {
    if (vec.size() == 0)
        return;
    soma += vec.back();
    vec.pop_back();
    vector_rec_sum(vec, soma);
}
   


void list_rec_sum(list<int> &lista, int &soma) {
    if(lista.size() == 0)
        return;

    soma += lista.front();
    lista.pop_front();
    list_rec_sum(lista, soma);

}