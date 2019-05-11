#include <iostream>
#include <list>
#include <vector>

using namespace std;

void list_sum(list<int>&);
size_t vector_sum(vector<int>);
void print_vector(vector<int>);
void array_sum(size_t *arr);

int main(void) {

    vector<int>v;

    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    size_t sum = vector_sum(v);

    print_vector(v);
    cout << "Soma: " << sum << endl;

    return 0;
}

size_t vector_sum(vector<int> v) {
    size_t sum = 0;
    for(size_t i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

void print_vector(vector<int> v) {
    cout << endl;
    cout << "Vector: ";
    for(size_t i = 0; i < v.size(); i++) {
        cout << "-> " << v[i];
    }
    cout << endl;
}