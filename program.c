#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <stdbool.h>

struct Aluno{
	char *nome[50];
	int ra;
	float nota[4];
	float media;
};

struct Aluno aluno[20];

void main(){
	
	setlocale(LC_ALL, "Portuguese");
	int opt = 0;
	
	while(opt != -1){
		printf("Sistema de Cadastro de aluno e notas\n");
		printf("1 - Cadastrar novo aluno\n");
		printf("2 - Cadastrar nota\n");
		printf("3 - Calcula Média\n");
		printf("4 - Relatório de desempenho\n");
		printf("Digite um valor:");
		scanf("%d",&opt);
	}
		
		

}

