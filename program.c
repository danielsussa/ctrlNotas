#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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
		
		//Tela inicial com as opções
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
			
			//Itera o valor de i até um vetor vaziu
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
		else if(opt == 2){
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
				
				//Cadastro realizado com sucesso
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
		
		//Calcula média
		else if(opt == 3){
			int i = 0;
			//Itera o struct aluno até o ultimo cadastro
			while(aluno[i].ra != 0){
				//Calcula a média ponderada
				aluno[i].media = (aluno[i].nota[0] * 1 + aluno[i].nota[1] * 2 + aluno[i].nota[2] * 3 + aluno[i].nota[3] * 4) / 10;
				printf("\nAluno:%s || Média:%.2f\n",aluno[i].nome,aluno[i].media);
				i = i + 1;
			}
			system("pause");
			system("cls");							
		}
		
		//Calcula o desempenho geral da classe
		else if(opt == 4){
			int i = 0;
			float total = 0;
			while(aluno[i].ra != 0){
				//Soma a média de cada alune
				total += aluno[i].media;
				i = i + 1;
			}
			//divide a média total pela quantidade de alunos
			total = total / i;
			printf("\nTotal de alunos na classe: %d",i);
			printf("\nMédia total da classe: %.2f\n",total);
			system("pause");
			system("cls");
		}
		
		else{
			system("cls");
		}
	}
}

int checkNullRA(int ra){
	if(ra == 0){
		return 1;
	}else{
		return 0;
	}
}

int checkIfExistRA(int ra){
	int i;
	for(i = 0; i<20 ; i = i+1){
		if(aluno[i].ra == ra){
			return i;
		}
	}
	return -1;
}

