#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "pecas.h"
#include <string>


using namespace std;
int main() {
    //começa com 10 peças
    int num_pecas=10;
    pecas* peca= new pecas[num_pecas];
    string ficheiroM="../marcas.txt";
    string ficheiroC="../categorias.txt";

    cria_peca(peca,num_pecas,ficheiroM,ficheiroC);
    delete[] peca;
    return 0;
}
