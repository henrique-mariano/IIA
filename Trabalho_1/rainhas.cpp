#include "rainhas.hpp"

void Tabuleiro::set_random_vector(){
    for(int i = 0; i < TAB_AREA; i++){
        this->random_vector.push_back(i);
    }
}

void Tabuleiro::Shuffle_random_vector(){
    this->set_seed();

    shuffle(this->random_vector.begin(), this->random_vector.end(), default_random_engine(this->seed));
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

void Tabuleiro::Print_queens(){
    cout << "\nRainhas: ";

    for(auto i : this->rainhas){
        cout << "(" << i.first << ", " << i.second << ") -> ";
    }
}

bool Tabuleiro::Check_queen_row_column(){
    if(this->linhas[this->linha] == 1 || this->colunas[this->coluna] == 1)
        return true;
    
    return false;
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

bool Tabuleiro::Queen_insertion_random(){

    for(int i = 0; i < TAB_AREA; i++){
        this->linha = this->tabela_posicao[this->random_vector[i]].first;
        this->coluna = this->tabela_posicao[this->random_vector[i]].second;

        if(i == 0)
            this->set_queen();

        if(this->Check_queen_row_column()) // verifica se linha == x e se coluna == y
            continue;

        if(this->Check_queen_diagonals()) //verifica se ha alguma rainha na diagonal
            this->set_queen();

        if(this->rainhas.size() == TAB_TAM){
            this->Print_queens();
            cout << endl << endl;
            cout << "Tabuleiro: " << endl;
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

bool Tabuleiro::Queen_insertion_left(){
    vector <int> pos; //[0 .. 7] randomizado
    pos.clear();
    this->colunas.clear();
    this->linhas.clear();
    this->set_linhas();
    this->set_colunas();
    this->rainhas.clear();
    this->linha = 0;
    this->coluna = 0;
    int max = 0;
    bool check;

    for(int k = 0; k < TAB_TAM; k++){
        pos.push_back(k);
    }

    this->set_seed();
    shuffle(pos.begin(), pos.end(), default_random_engine(this->seed));
    this->linha = pos[0];
    this->set_queen();

    for(int i = 1; i < TAB_TAM; i++){
        this->coluna = i;
        
        for(int j = 0; j < TAB_AREA; j++){
            this->set_seed();
            shuffle(pos.begin(), pos.end(), default_random_engine(this->seed));
            this->linha = pos[4];

            if(this->Check_queen_diagonals() && this->linhas[this->linha] == 0){
                this->set_queen();
                break;
            }
        }
    }

    if(this->rainhas.size() == TAB_TAM){
        this->Print_queens();
        cout << endl << endl;
        cout << "Tabuleiro: " << endl;
        this->Print_tab();
        return false;
    }

    this->Print_tab();
    return true;
}

void Tabuleiro::Eight_queen_game_random(){
    bool check;
    do {
        this->set_table();
        check = this->Queen_insertion_random();

    } while(check);

}

void Tabuleiro::Eight_queen_game_left(){
    bool check;
    do {
        this->set_table();
        check = this->Queen_insertion_left();

    } while(check);
}