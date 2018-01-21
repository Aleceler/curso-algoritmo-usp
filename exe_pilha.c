
#include <stdio.h>
#include <stdbool.h>
#define MAXPILHA 6

struct pilha {
    int topo;
    int item[MAXPILHA];
};

int topo(struct pilha *p) {
    return p->topo;
};

int esvaziaPilha(struct pilha *p) {
    while (p->topo > -1) {
    p->item[p->topo] = NULL;
    p->topo = p->topo -1;
    }
    return false;
};

_Bool pilhaCheia(struct pilha *p) {
    if(p->topo+1 == MAXPILHA)
    return true;
    else
    return false;
};

_Bool pilhaVazia(struct pilha *p) {
    if(p->topo == -1)
    return true;
    else
    return false;
};

int empilha(int d, struct pilha *p) {
    if(pilhaCheia(p) == false) {
    p->item[p->topo+1] = d;
    p->topo = p->topo +1;
    }
    else{
        return false;
        // printf("nao vai dar para empilhar o elemento: %d \n\n\n", d );   
    }
};

int desempilha(struct pilha *p){
    if(pilhaVazia(p) == false) {
    p->item[p->topo] = NULL;
    p->topo = p->topo -1;
    }
    return false;
};
    

int desempilhaItem(int d, struct pilha *p, struct pilha *p2){
    int posicao_elem_provisorio;
    int b;
    for( b = p->topo; b >= -1; b--){
        if (d == p->item[b]){
            posicao_elem_provisorio = b;
            break;
        }
        else if(b == -1){
            printf("erro");
            return false;
        }
    };
    int a;
    for(a = p->topo; a > posicao_elem_provisorio; a--){
        empilha(p->item[a], p2);
        desempilha(p);
    };
    desempilha(p);
    while (p2->topo > -1){
        empilha(p2->item[p2->topo], p);
        desempilha(p2);
    }
};



int main()
{   
    struct pilha p2;
    p2.topo = -1;
    
    struct pilha p;
    p.topo = -1;
    
    int minha_lista[] = {12,24,36,48,60,72};
    
    empilha(minha_lista[0], &p);
    empilha(minha_lista[1], &p);
    empilha(minha_lista[2], &p);
    empilha(minha_lista[3], &p);
    empilha(minha_lista[4], &p);
    empilha(minha_lista[5], &p);

    
    // printf("%d", p->item[5]);
    
    //desempilhando o elemento 36 da nossa pilha !!!
    //o algoritmo está desempilhando da nossa pilha principal e empilhando em uma pilha secundária
    //após achar o numero a ser removido ele remove-o e volta na ordem em que foi colocado na nossa pilha secundária
    
    desempilhaItem(36, &p, &p2);
    
    // printf("resultado final de p \n\n\n\n");
    // printf("%d \n", p.item[0]);
    // printf("%d \n", p.item[1]);
    // printf("%d \n", p.item[2]);
    // printf("%d \n" ,p.item[3]);
    // printf("%d \n" ,p.item[4]);
    // printf("%d \n", p.item[5]);
    
    
}
