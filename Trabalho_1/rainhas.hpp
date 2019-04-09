#ifndef ___RAINHAS_HPP___
#define ___RAINHAS_HPP___

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>
#include <chrono>

#define TAB_TAM 8
#define TAB_AREA 64

using namespace std;

class Tabuleiro{
    private:
        vector<int> random_vector;
        int tab[TAB_TAM][TAB_TAM];
        unsigned seed;
        map<int, pair<int, int>> tabela_posicao;
        vector<int> linhas;
        vector<int> colunas;
        int linha;
        int coluna;
        vector<pair<int, int>> rainhas;

        void set_seed(){
            this->seed = chrono::system_clock::now().time_since_epoch().count();
        }

        void set_linhas(){
            this->linhas = vector<int>(TAB_TAM, 0);
        }

        void set_colunas(){
            this->colunas = vector<int>(TAB_TAM, 0);
        }

        void set_random_vector();

        void Shuffle_random_vector();

        void set_table();

        //Traducao posicao-tabela
        void set_traduction();

        void set_queen();

        bool Check_row_colunms();

        bool Check_queen_diagonals();

        bool Queen_insertion();

    public:

        void Print_tab();

        void Print_random_vector();

        void Eight_queen_game();


        Tabuleiro(){
            this->set_table();
            this->set_random_vector();
            this->Shuffle_random_vector();
            this->set_traduction();
            this->set_linhas();
            this->set_colunas();
        }

};




#endif