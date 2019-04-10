#include "rainhas.hpp"

using namespace std;

int main(){

    Tabuleiro *tabuleiro = new Tabuleiro();

    int escolha = 0;

    cout << "\nInsira qual metodo utilizar: \n 1) Metodo A: rainhas em qualquer lugar.\n 2) Metodo B: rainhas sempre a esquerda.\n";
    
    do {
        cin >> escolha;
    } while(escolha < 1 || escolha > 2);

    switch (escolha){
        case 1:
            tabuleiro->Eight_queen_game_random();
            break;

        case 2:
            tabuleiro->Eight_queen_game_left();
            break;
        
        default:
            break;
    }

    delete tabuleiro;

    return 0;
}