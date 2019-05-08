#include <iostream>
#include <list>
#include <stdlib.h>

using namespace std;

void reverse_list(list<int>&);
void swap_list(list<int>&, size_t i, size_t j);
void print_list(list<int>&);

int main(void) {
    list<int> lista = {1,2,3,4,5};
    reverse_list(lista);
    print_list(lista);
    return 0;
}

void reverse_list(list<int>& lista) {
    for(size_t i = 0, j = lista.size() - 1; i < j; i++, j--){
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

void print_list(list<int>& lista) {
    cout << endl << "Lista:";
    for(auto i = lista.begin(); i != lista.end(); ++i){
        cout << " " << *i;
    }
}