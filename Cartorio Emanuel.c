#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca para aloca��o de espa�o na memoria
#include <locale.h> //biblioteca de localiza��o de texto
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings
	
	printf("Digite o CPF que gostaria de cadastrar (apenas numeros): ");//coletando dados do usuario
	scanf("%s",cpf);//%s se refere a string
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores das strings
	
	FILE *file;//cria o arquivo no pc
	file = fopen(arquivo, "w");//cria o arquivo, "w" � para escrever
	fprintf(file,cpf);//salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//atualiza o arquivo, "a" � para atualizar
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome que gostaria de cadastrar (sem acentos): ");
	scanf("%s",nome);//comando para copiar a string nome no arquivo
	
	file = fopen(arquivo, "a");//atualiza o arquivo com nova informa��o
	fprintf(file,nome);//informa��o a ser atualizada
	fclose(file);
	
	file = fopen(arquivo, "a");//atualiza o arquivo com nova informa��o
	fprintf(file,", ");//adiciona a "," � linha de texto a ser salva
	fclose(file);
	
	printf("Digite o sobrenome que gostaria de cadastrar (apenas o �ltimo nome, sem acentos): ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo que gostaria de cadastrar: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()//Fun��o respons�vel pela consulta de usu�rios j� cadastrados
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF que gostaria de consultar (apenas numeros): ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Desculpe, CPF n�o encontrado.\nEstamos voltando ao menu, tente novamente.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}

int deletar()//Fun��o respons�vel por deletar usu�rios j� cadastrados
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que gostaria de deletar (apenas numeros): ");
	scanf("%s",cpf);
	
	remove(cpf);
	
			
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		printf("Deletado com sucesso!\n");
		system("pause");
	}
	
	if(file == NULL)
	{
		printf("Infelizmente o CPF solicitado n�o foi encontrado no sistema.\n");
		printf("Estamos voltando ao menu, tente novamente.\n");
		system("pause");
	}
	
}

int main()//Fun��o principal para o sistema funcionar. criando o menu
{
	int opcao=0;//Definindo vari�veis, tipo int
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//T�tulo do projeto
		printf("Seja bem-vindo(a)!\n\n");
		printf("Escolha a op��o desejada no menu:\n\n");//in�cio do menu com as op��es logo abaixo
		printf("\t1- Registrar Nomes\n");//op��o 1
		printf("\t2- Consultar Nomes\n");//op��o 2
		printf("\t3- Deletar Nomes\n");//op��o 3
		printf("\nOp��o:  ");
			
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
	
		system("cls");//comando para limpar a tela apos a��o anterior
	
		switch(opcao)//in�cio da sele��o do menu
		{
			case 1:
			registro();//chamada de fun��es
			break;
			
			case 2:
			consulta();//chamada de fun��es
			break;
			
			case 3:
			deletar();//chamada de fun��es
			break;
			
			default:
			printf("Infelizmente essa op��o n�o est� dispon�vel.\nVolte ao menu e tente novamente.\n");
			system("pause");
			break;
		}
	
	
	 }    
}
