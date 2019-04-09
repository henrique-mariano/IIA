#include "rainhas.hpp"

void Tabuleiro::set_random_vector(){
    for(int i = 0; i < TAB_AREA; i++){
        this->random_vector.push_back(i);
    }
}

void Tabuleiro::Shuffle_random_vector(){
    this->set_seed();

    shuffle(this->random_vector.begin(), this->random_vector.end(), default_random_engine(seed));
}

void Tabuleiro::set_table(){
    for(int i = 0; i < TAB_TAM; i++){
        for(int j = 0; j < TAB_TAM; j++){
            this->tab[i][j] = 0;
        }
    }
}

void Tabuleiro::set_traduction(){
    pair<int, int> l;

    for(int i = 0; i < TAB_AREA; i++){
        if(i == 0){
            l = make_pair(0,0);
            this->tabela_posicao[0] = l;
                continue;
        }

        if(i == 1){
            l = make_pair(0, 1);
            this->tabela_posicao[1] = l;
            continue;
        }

        if(l.first < TAB_TAM && l.second == TAB_TAM - 1){
            l.first++;
            l.second = 0;
            this->tabela_posicao[i] = l;
            continue;
        } else if(l.first == TAB_TAM - 1 && l.second == TAB_TAM - 1) {
            break;
        }

        l.second++;
        this->tabela_posicao[i] = l;

    }
}

void Tabuleiro::Print_tab(){
    cout << endl << endl;
    for(int i = 0; i < TAB_TAM; i++){
        for(int j = 0; j < TAB_TAM; j++){
            cout << this->tab[i][j] << ' ';
        }
        cout << endl;
    }
}

void Tabuleiro::Print_random_vector(){
    cout << endl << "Randomizada: " << endl;
    for(vector<int>::iterator i = this->random_vector.begin(); i != this->random_vector.end(); ++i)
        cout << *i << ' ';
            
    cout << endl;
}

bool Tabuleiro::Check_row_colunms(){
    bool resp = true;

    for(int i = 0; i < this->linhas.size(); i++){
        if(this->linhas[i] != 0){
            resp = false;
        }

        if(this->colunas[i] != 0){
            resp = false;
        }
    }

    return resp;
}

bool Tabuleiro::Check_queen_diagonals(){
    bool check = true;
    for(int k = 0; k < this->rainhas.size(); k++){
        if(abs(this->linha - rainhas[k].first) == abs(this->coluna - rainhas[k].second)){
            check = false;
            return check;
            break;
        }
    }

    return check;
}

void Tabuleiro::set_queen(){
    this->rainhas.push_back(make_pair(this->linha, this->coluna));
    this->linhas[this->linha]++;
    this->colunas[this->coluna]++;
    this->tab[this->linha][this->coluna] = 1;
}

bool Tabuleiro::Queen_insertion(){

    for(int i = 0; i < TAB_AREA; i++){
        this->linha = this->tabela_posicao[this->random_vector[i]].first;
        this->coluna = this->tabela_posicao[this->random_vector[i]].second;

        if(this->linhas[this->linha] == 1 || this->colunas[this->coluna] == 1){ // verifica se linha == x e se coluna == y
            continue;
        }

        if(this->Check_row_colunms()){
            this->set_queen();
        }

        bool check = this->Check_queen_diagonals();

        if(check){
            this->set_queen();
        }

        if(this->rainhas.size() == TAB_TAM){

            for(auto i : this->rainhas){
                cout << "(" << i.first << ", " << i.second << ") -> ";
            }
            cout << endl << endl;
            this->Print_tab();
            return false;
        }
    }

    this->Print_tab();

    this->colunas.clear();
    this->linhas.clear();
    this->rainhas.clear();
    this->set_linhas();
    this->set_colunas();
    this->Shuffle_random_vector();

    return true;
}

void Tabuleiro::Eight_queen_game(){
    bool check;
    do {
        this->set_table();
        check = this->Queen_insertion();

    } while(check);

}