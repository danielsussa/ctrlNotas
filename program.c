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
		
		//Tela inicial com as op��es
		printf("Sistema de Cadastro de aluno e notas\n");
		printf("1 - Cadastrar novo aluno\n");
		printf("2 - Cadastrar nota\n");
		printf("3 - Calcula M�dia\n");
		printf("4 - Relat�rio de desempenho\n");
		printf("Digite um valor:");
		scanf("%d",&opt);
		
		//Cadastrar novo aluno
		if(opt == 1){
			system("cls");
			//Verifica em qual registro deveremos escrever na mem�ria
			int i = 0;
			
			//Itera o valor de i at� um vetor vaziu
			while(aluno[i].ra != 0){
				i = i + 1;
			}
			
			//Valores tempor�rios
			int inputRA = 0;
			char inputNome[50];
			
			//Escreve NOME aluno
			printf("Digite o nome do aluno:");
			scanf("%s",&inputNome);
			
			//Escreve RA aluno
			printf("Digite o RA do aluno:");
			scanf("%d",&inputRA);
			
			if(checkIfExistRA(inputRA) == -1 && checkNullRA(inputRA) == 1){
				//Se existir j� um RA ou for nulo
				printf("\nRA invalido ou j� existente!\n");
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
			//Valores tempor�rios
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
				printf("RA n�o cadastrado\n");
				system("pause");
				system("cls");
			}
		}
		
		//Calcula m�dia
		else if(opt == 3){
			int i = 0;
			//Itera o struct aluno at� o ultimo cadastro
			while(aluno[i].ra != 0){
				//Calcula a m�dia ponderada
				aluno[i].media = (aluno[i].nota[0] * 1 + aluno[i].nota[1] * 2 + aluno[i].nota[2] * 3 + aluno[i].nota[3] * 4) / 10;
				printf("\nAluno:%s || M�dia:%.2f\n",aluno[i].nome,aluno[i].media);
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
				//Soma a m�dia de cada alune
				total += aluno[i].media;
				i = i + 1;
			}
			//divide a m�dia total pela quantidade de alunos
			total = total / i;
			printf("\nTotal de alunos na classe: %d",i);
			printf("\nM�dia total da classe: %.2f\n",total);
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

