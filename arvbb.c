#include "arvbb.h"

Arv* abb_cria(void){
    Arv* arvore = NULL;
    return arvore;
}

void abb_imprime(Arv *a){
    printf("<");
    if (a != NULL){
        abb_imprime(a->esq);
        printf("%d", a->info);
        abb_imprime(a->dir);
    }
    printf(">");
}

Arv* abb_busca(Arv* r, int v){
    if (r != NULL){
        if (v < r->info) return abb_busca(r->esq, v);
        else {
            if (v > r->info) return abb_busca(r->dir, v);
            else return r;
        }
    }
    return NULL;
}

Arv* abb_insere(Arv* a, int v){
    if (a == NULL) {
        a = (Arv *)malloc(sizeof(Arv));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;

    } else {
        if (v < a->info) a->esq = abb_insere(a->esq, v);
        else a->dir = abb_insere(a->dir, v);
    }
    return a;
}

Arv* abb_retira(Arv* r, int v){
    if (r == NULL) return NULL;
    else {
        if (v < r->info) r->esq = abb_retira(r->esq, v);
        else {
            if (v > r->info) r->dir = abb_retira(r->dir, v);
            else {
                if (r->esq == NULL && r->dir == NULL) r = NULL;
                else {
                    if (r->esq == NULL) r = r->dir;
                    else {
                        if (r->dir == NULL) r = r->esq;
                        else {
                            Arv* p = r->esq;
                            while (p->dir != NULL) p = p->dir;
                            
                            r->info = p->info;
                            p->info = v;
                            r->esq = abb_retira(r->esq, v);
                        }
                    }
                }
            }
        }
    }
    return r;
}

void abb_imprimeDecrescente(Arv* a){
    printf("<");
    if (a != NULL){
        abb_imprimeDecrescente(a->dir);
        printf("%d", a->info);
        abb_imprimeDecrescente(a->esq);
    }
    printf(">");
}