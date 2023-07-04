#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

typedef struct Produto {
    char codigo[50];
    char descricao[200];
    int qtd;
    float valor;
    struct Produto* proximo;
} Produto;

void flush_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

Produto* cadastrarproduto(const char* codigo, const char* descricao, int qtd, float valor) {
    Produto* nproduto = (Produto*)malloc(sizeof(Produto));
    strcpy(nproduto->codigo, codigo);
    strcpy(nproduto->descricao, descricao);
    nproduto->qtd = qtd;
    nproduto->valor = valor;
    nproduto->proximo = NULL;
    return nproduto;
}

void adicionar(Produto** lista, Produto* nproduto) {
    if (*lista == NULL) {
        *lista = nproduto;
    } else {
        Produto* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = nproduto;
    }
}

void listarprodutos(Produto* lista) {
    printf("Lista de Produtos:\n");
    printf("------------------\n");
    
    Produto* atual = lista;
    
    while (atual != NULL) {
        printf("Código do produto: %s\n", atual->codigo);
        printf("Descrição do produto: %s\n", atual->descricao);
        printf("Quantidade do produto: %d\n", atual->qtd);
        printf("Valor do produto: %.2f\n", atual->valor);
        printf("------------------\n");
        
        atual = atual->proximo;
      
    }
   printf("Aperte o espaço.\n");
   flush_stdin();
   getchar();
   printf("\033c");
}

Produto* pesquisarproduto(Produto* lista, const char* codigo) {
    Produto* atual = lista;
    
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigo) == 0) {
            return atual;
        }
        
        atual = atual->proximo;
    }
    
    return NULL;
}

void removerproduto(Produto** lista, const char* codigo) {
    Produto* anterior = NULL;
    Produto* atual = *lista;
    
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigo) == 0) {
            if (anterior == NULL) {

                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            
            free(atual);
            printf("\033c");
            printf("Produto removido!\n");
            sleep(2);
            printf("\033c");
            return;
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
    printf("\033c");
    printf("Produto não foi cadastrado, faça o cadastro.\n");
    sleep(2);
    printf("\033c");
}