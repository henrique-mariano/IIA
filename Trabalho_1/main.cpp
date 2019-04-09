#include "rainhas.hpp"

using namespace std;

// bool check_row_colunms(vector<int> row, vector<int> colum);

int main(){
    // vector<int> v(64, 0);
    // vector<int> p(64);
    // int tab[8][8];
    // unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // map<int, pair<int, int>> m;
    
    // for(int i = 0; i < 64; i++){
    //     p[i] = i;
    // }

    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         tab[i][j] = 0;
    //     }
    // }

    // //traducao posicao-tabela
    // pair<int, int> l;
    // for(int i = 0; i < 64; i++){
    //    if(i == 0){
    //         l = make_pair(0,0);
    //         m[0] = l;
    //         continue;
    //    }

    //    if(i == 1){
    //        l = make_pair(0, 1);
    //        m[1] = l;
    //        continue;
    //    }

    //    if(l.first < 8 && l.second == 7){
    //        l.first++;
    //        l.second = 0;
    //        m[i] = l;
    //        continue;
    //    } else if(l.first == 7 && l.second == 7) {
    //        break;
    //    }

    //     l.second++;
    //     m[i] = l;

    // }

    // // for(auto& i : m){
    // //     cout << i.first << " = { (" << i.second.first << ", " << i.second.second << ") }"<< endl;
    // // }

    // shuffle(p.begin(), p.end(), default_random_engine(seed));

    // cout << endl << "Randomizada: " << endl;

    // for(vector<int>::iterator i = p.begin(); i != p.end(); ++i)
    //     cout << *i << ' ';
    
    // cout << endl;

    // vector<int> linhas(8, 0);
    // vector<int> colunas(8, 0);
    // vector<pair<int, int>> rainhas;

    // for(int i = 0; i < 64; i++){
    //     int linha = m[p[i]].first;
    //     int coluna = m[p[i]].second;

    //     if(linhas[linha] == 1 || colunas[coluna] == 1){ // verifica se linha == x e se coluna == y
    //         continue;
    //     }

    //     if(check_row_colunms(linhas, colunas)){
    //         rainhas.push_back(make_pair(linha, coluna));
    //         linhas[linha]++;
    //         colunas[coluna]++;
    //         tab[linha][coluna] = 1;
    //     }

    //     bool check = true;
    //     for(int k = 0; k < rainhas.size(); k++){
    //         if(abs(linha - rainhas[k].first) == abs(coluna - rainhas[k].second)){
    //             check = false;
    //             break;
    //         }
    //     }

    //     if(check){
    //         rainhas.push_back(make_pair(linha, coluna));
    //         linhas[linha]++;
    //         colunas[coluna]++;
    //         tab[linha][coluna] = 1;
    //     }
    // }

    // cout << endl << endl;

    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         cout << tab[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    Tabuleiro *tabuleiro = new Tabuleiro();

    tabuleiro->Eight_queen_game();

    return 0;
}

// bool check_row_colunms(vector<int> row, vector<int> colum){
//     bool resp = true;

//     for(int i = 0; i < row.size(); i++){
//         if(row[i] != 0){
//             resp = false;
//         }

//         if(colum[i] != 0){
//             resp = false;
//         }
//     }

//     return resp;
// }