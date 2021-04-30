#include<stdio.h>
#include<stdlib.h>

typedef struct aluno
{
    char nome[20];
    int idade;
    struct aluno * proximo; 
} Aluno;


int main(){

    Aluno * ini_aluno;
    Aluno * proximo_aluno;
    int resp;

    ini_aluno = (Aluno *)malloc(sizeof(Aluno));
    proximo_aluno = ini_aluno;

    while (1)
    {
        printf("\n");
        fflush(stdin);
        printf("Digite o nome = ");
        fgets(proximo_aluno->nome, 20, stdin);

        fflush(stdin);
        printf("Digite a idade = ");
        scanf("%i", &proximo_aluno->idade);

        fflush(stdin);
        printf("Deseja continuar? <1>SIM <2>NAO: ");
        scanf("%i", &resp);

        if (resp == 1){
            proximo_aluno->proximo = (Aluno*)malloc(sizeof(Aluno));
            proximo_aluno = proximo_aluno->proximo;
        }else{
            break;
        }

    }
    proximo_aluno->proximo = NULL;
    printf("\n");

    proximo_aluno = ini_aluno;
    printf("\n");

    while (proximo_aluno != NULL)
    {
        printf("Nome: %sIdade: %i \n\n", proximo_aluno->nome, proximo_aluno->idade);
        proximo_aluno = proximo_aluno->proximo;
    }

    return 0;
}