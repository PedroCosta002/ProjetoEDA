#include "pecas.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

/**
 * Esta função recebe um array de peças e introduz o número de serie para cada elemento do array.
 * @param Vpecas: recebe um array de pecas
 */
void introduz_n_serie(pecas* const Vpecas,int tamanho){
    srand(time(NULL));
    for (int indice=0;indice<tamanho;indice++){
        Vpecas[indice].n_serie=rand()%9000+1000;
    }
}


/**
 * Esta função recebe um array de peças e introduz o preço para cada elemento do array.
 * É utilizada a função rand para gerar um número aleatório entre 2 e 180 que depois é multiplicado por 5.
 * [2*5,5*180]=[10,900]
 * @param Vpecas: recebe um array de pecas
 */
void introduz_preco(pecas* const Vpecas,int tamanho) {
    srand(time(NULL));
    for (int indice = 0; indice < tamanho; indice++) {
        Vpecas[indice].preco = (rand() % 179 + 2) * 5;
    }
}
/**
 * Esta função recebe um array de peças e introduz a probabilidade de venda para cada elemento do array.
 * É utilizada a função rand para gerar um número aleatório entre 5 e 50 que depois é dividido por 100.
 * [0.05,0.5]
 * @param Vpecas : recebe um array de pecas
 */
void introduz_prob_venda(pecas* const Vpecas,int tamanho){
    srand(time(NULL));
    for (int indice = 0; indice < tamanho; indice++) {
        Vpecas[indice].prob_venda = static_cast<float>(rand() % 46+5)/100;
    }
}

/**
 * Esta função conta o número de linhas que um ficheiro possui através de um ciclo while.
 * É utilizado o ifstream para ler os dados do ficheiro.
 * @param nome_fich : Recebe o endereço do ficheiro.
 * @return Retorna o número de linhas que o ficheiro possui.
 */
int n_linhas(const string &nome_fich){
    ifstream ficheiro(nome_fich);

    string linhas;
    int num_linhas=0;
    if(ficheiro.is_open()){
        while(getline(ficheiro,linhas)){
            num_linhas++;
        }
    }else{
        cout<<"Nao foi possivel abrir o ficheiro";
    }ficheiro.close();

    return num_linhas;
}

/**
 * Esta função cria um array com todos os nomes do ficheiro, usando um ciclo for
 * e posteriormente o getline para guardar cada um dos nomes.
 *
 * @param nome_fich : Recebe o endereço do ficheiro.
 * @return  Retorna o endereço do array com os nomes.
 */
string* criarraydenomes(const string &nome_fich){
    ifstream ficheiro(nome_fich);
    int num_linhas= n_linhas(nome_fich);
    string* nomes=new string[num_linhas];
    if(ficheiro.is_open()){
        for(int i=0;i<num_linhas;i++){
            getline(ficheiro,nomes[i]);
        }
    }else{
        cout<<"Nao foi possivel abrir o ficheiro";

    }ficheiro.close();
    return nomes;
}


/**
 * Esta função introduz um nome aleatório de uma marca para cada elemento do array
 * @param Vpecas : Recebe um array de pecas.
 * @param tamanho : Recebe o tamanho do array.
 * @param nome_fich : Recebe o nome do ficheiro.
 */
void introduz_marca(pecas* const Vpecas,int tamanho,const string &nome_fich){
    srand(time(NULL));
    string* nome_marca= criarraydenomes(nome_fich);
    int num_linhas= n_linhas(nome_fich);
    for (int indice = 0; indice < tamanho; indice++) {
        Vpecas[indice].marca = nome_marca[rand()%num_linhas];
    }
    delete[] nome_marca;
}

/**
 * Esta função introduz um nome aleatório de uma categoria para cada elemento do array
 * @param Vpecas : Recebe um array de pecas.
 * @param tamanho : Recebe o tamanho do array.
 * @param nome_fich : Recebe o nome do ficheiro.
 */
void introduz_categoria(pecas* const Vpecas,int tamanho,const string &nome_fich){
    srand(time(NULL));
    string* nome_categoria= criarraydenomes(nome_fich);
    int num_linhas= n_linhas(nome_fich);
    for (int indice = 0; indice < tamanho; indice++) {
        Vpecas[indice].categoria = nome_categoria[rand()%num_linhas];
    }
    delete[] nome_categoria;
}

/**
 * Esta função mostra cada peça
 * @param Vpecas : Recebe um array de pecas.
 * @param tamanho : Recebe o tamanho do array.
 */
void mostra(pecas* const Vpecas,const int tamanho){
    for (int indice = 0; indice < tamanho; indice++) {
        cout<<Vpecas[indice].n_serie<<"/"<<Vpecas[indice].preco<<"/"<<Vpecas[indice].prob_venda<<"/"<<Vpecas[indice].marca<<"/"<<Vpecas[indice].categoria<<endl;
    }
}

/**
 * Esta função utiliza todas as funções criadas para introduzir cada categoria de uma peça
 * assim criando a peça.
 * @param Vpecas : Recebe um array de pecas.
 * @param tamanho : Recebe o tamanho do array.
 * @param f_marcas : Recebe o ficheiro "marcas.txt"
 * @param f_cat : Recebe o ficheiro "categorias.txt"
 */
void cria_peca(pecas * const Vpecas,int tamanho, string &f_marcas, string &f_cat){
     introduz_n_serie(Vpecas,tamanho);
     introduz_preco(Vpecas,tamanho);
     introduz_prob_venda(Vpecas,tamanho);
     introduz_marca(Vpecas,tamanho,f_marcas);
     introduz_categoria(Vpecas,tamanho,f_cat);
     mostra(Vpecas,tamanho);
}


