#include "arvbb.c"

int main(void){
  setlocale(LC_ALL, "Portuguese");

  Arv* arvore1 = abb_cria();
  
  arvore1 = abb_insere(arvore1, 6);
  abb_insere(arvore1, 2);
  abb_insere(arvore1, 8);
  abb_insere(arvore1, 1);
  abb_insere(arvore1, 4);
  abb_insere(arvore1, 3);

  /*          ARVORE1

                 6
               /   \
              /     \ 
             2       8
            / \
           /   \    
          1     4 
               /
              /     
             3
  */

  /*  
  Como não há o número 5 em arvore1, deve 
  retornar uma árvore nula e imprimir 
  apenas "<>".  
  */
  Arv* arvore2 = abb_busca(arvore1, 5);
  printf("Impressão arvore2 (Ordem crescente)\n");
  abb_imprime(arvore2);


  printf("\n\nImpressão arvore1 (Ordem crescente)\n");
  abb_imprime(arvore1);
  printf("\n\nImpressão arvore1 (Ordem decrescente)\n");
  abb_imprimeDecrescente(arvore1);

  //Exemplo de remoção (Caso 1).
  arvore1 = abb_retira(arvore1, 1);

  //Exemplo de remoção (Caso 2).
  arvore1 = abb_retira(arvore1, 4);

  //Exemplo de remoção (Caso 3).
  arvore1 = abb_retira(arvore1, 6);
  
  /*          ARVORE1
                 3
               /   \
              /     \ 
             2       8 
  */

  printf("\n\nImpressão arvore1 (Ordem crescente)\n");
  abb_imprime(arvore1);
  printf("\n\nImpressão arvore1 (Ordem decrescente)\n");
  abb_imprimeDecrescente(arvore1);
  printf("\n");
}