#ifndef PROJETOEDA_PECAS_H
#define PROJETOEDA_PECAS_H
#include <string>
using namespace std;

struct pecas{
    int n_serie;
    int preco;
    float prob_venda;
    string marca;
    string categoria;
};

void introduz_n_serie( pecas* const Vpecas,int tamanho);

void introduz_preco( pecas* const Vpecas,int tamanho);

void introduz_prob_venda(pecas* const Vpecas,int tamanho);

void introduz_marca(pecas* const Vpecas,int tamanho,const string &nome_fich);

void introduz_categoria(pecas* const Vpecas,int tamanho,const string &nome_fich);

void mostra(pecas* const Vpecas, int tamanho);

void cria_peca(pecas * const Vpecas,int tamanho,string &f_marcas,string &f_cat);

#endif //PROJETOEDA_PECAS_H
