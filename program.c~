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
		
		//Cadastrar novo aluno
		if(opt == 1){
			system("cls");
			//Verifica em qual registro deveremos escrever na memória
			int i = 0;
			while(aluno[i].ra != 0){
				i = i + 1;
			}
			
			//Valores temporários
			int inputRA = 0;
			char inputNome[50];
			
			//Escreve NOME aluno
			printf("Digite o nome do aluno:");
			scanf("%s",&inputNome);
			
			//Escreve RA aluno
			printf("Digite o RA do aluno:");
			scanf("%d",&inputRA);
			
			if(checkIfExistRA(inputRA) == -1 && checkNullRA(inputRA) == 1){
				//Se existir já um RA ou for nulo
				printf("\nRA invalido ou já existente!\n");
				system("pause");
				system("cls");
			}else{
				//Registra os valores
				strcpy(aluno[i].nome,inputNome);
				aluno[i].ra = inputRA;
				printf("\nCadastro realizado com sucesso!\n");
				system("pause");
				system("cls");
			}
		}
		
		//Cadastrar notas
		if(opt == 2){
			system("cls");
			//Valores temporários
			int inputRA = 0;
			
			//Escreve RA aluno
			printf("Digite o RA do aluno:");
			scanf("%d",&inputRA);
			
			int posRA = checkIfExistRA(inputRA);
			if(posRA != -1){
				//Caso exista o RA
				printf("\nNome do aluno:%s",aluno[posRA].nome);
				float menNota = 10;
				int menNotaPos = 0;
				int i;
				for(i = 0; i< 5 ; i = i+1){
					if(i < 4){
						//Computa as 4 notas
						printf("\nInsira a nota %d:",i+1);
						scanf("%f",&aluno[posRA].nota[i]);
						if(menNota > aluno[posRA].nota[i]){
							menNota = aluno[posRA].nota[i];
							menNotaPos = i;
						}
					}else{
						float sub;
						printf("\nNota da prova substitutiva:");
						scanf("%f",&sub);
						if(sub>menNota){
							//Atualiza a menor nota pela da SUB
							aluno[posRA].nota[menNotaPos] = menNota;
							printf("\nNota substitutiva sobrescreveu a nota da prova %d",menNotaPos+1);
						}			
					}
				}
				
				//
				printf("\nNotas cadastradas com sucesso!\n");
				system("pause");
				system("cls");				
			}else{
				//RA inexistente
				printf("RA não cadastrado\n");
				system("pause");
				system("cls");
			}
		}
	}
		
		

}

