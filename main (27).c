#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "functions.h"



int main() {
    Produto* listaprodutos = NULL;
    int opcao;

    do {
        printf("Estoque de Produtos:\n");
        printf("------------------------\n");
        printf("1 - Cadastrar produto...\n");
        printf("2 - Listar produtos...\n");
        printf("3 - Pesquisar produto...\n");
        printf("4 - Remover produto...\n");
        printf("0. Sair.\n");
        scanf("%d", &opcao);
        printf("\033c");
        switch (opcao) {
            case 1: {
                char codigo[50], descricao[200];
                int qtd;
                float valor;
                printf("Digite o código do produto:\t");
                scanf(" %[^\n]s", codigo);
                printf("Digite a descrição do produto:\t");
                scanf(" %[^\n]s", descricao);
                printf("Digite a quantidade do produto:\t");
                scanf("%d", &qtd);
                printf("Digite o valor do produto:\t");
                scanf("%f", &valor);      
                Produto* nproduto = cadastrarproduto(codigo, descricao, qtd, valor);
                adicionar(&listaprodutos, nproduto);
                printf("\n");
                printf("Produto cadastrado!\n\n");
                sleep(2);
                printf("\033c");
                break;
            }
            case 2:
                listarprodutos(listaprodutos);
                break;
            case 3: {
                char codigo[50];
                printf("Digite o código do produto: ");
                scanf(" %[^\n]s", codigo);
                Produto* produto = pesquisarproduto(listaprodutos, codigo);
                if (produto != NULL) {
                    printf("\033c");
                    printf("Produto encontrado!\n");
                    printf("\n");
                    printf("Código: %s\n", produto->codigo);
                    printf("Descrição: %s\n", produto->descricao);
                    printf("Quantidade: %d\n", produto->qtd);
                    printf("Valor: %.2f\n", produto->valor);
                } else {
                    printf("\033c");
                    printf("Produto não encontrado!\n");
                    printf("\n");
                }   
              printf("\n");
              printf("Aperte qualquer tecla para continuar\n");
              flush_stdin();
              getchar();
              printf("\033c");
                break;
            }
            case 4: {
                char codigo[50];
                printf("Digite o código do produto a ser removido: ");
                scanf(" %[^\n]s", codigo);
                removerproduto(&listaprodutos, codigo);
                break;
            }
            case 0:
                printf("\033c");
                printf("Até a próxima!\n");
                sleep(2);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n\n");
                sleep(2);
                break;
        }
    } while (opcao != 0);

    return 0;
}
