#include<iostream>
#include<locale.h>
#include"questaoAVL.hpp"
#include"questaoHash.hpp"
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int op;

    do{
        cout << "01 - Questão AVL" << endl;
        cout << "02 - Questão Hash" << endl;
        cout << "00 - Sair" << endl;
        cin >> op;

        switch(op){
        case 1:
            questaoAVL();
            break;
        case 2:
            questaoHash();
            break;
        case 0:
            return 0;
        default:
            cout << "Opção invalida!" << endl;
        }
    }while(op != 0);

    return 0;
}
