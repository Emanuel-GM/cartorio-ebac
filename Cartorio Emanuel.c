#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca para alocação de espaço na memoria
#include <locale.h> //biblioteca de localização de texto
#include <string.h> //biblioteca responsável por cuidar das string

int registro()//Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis/strings
	
	printf("Digite o CPF que gostaria de cadastrar (apenas numeros): ");//coletando dados do usuario
	scanf("%s",cpf);//%s se refere a string
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo no pc
	file = fopen(arquivo, "w");//cria o arquivo, "w" é para escrever
	fprintf(file,cpf);//salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//atualiza o arquivo, "a" é para atualizar
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome que gostaria de cadastrar (sem acentos): ");
	scanf("%s",nome);//comando para copiar a string nome no arquivo
	
	file = fopen(arquivo, "a");//atualiza o arquivo com nova informação
	fprintf(file,nome);//informação a ser atualizada
	fclose(file);
	
	file = fopen(arquivo, "a");//atualiza o arquivo com nova informação
	fprintf(file,", ");//adiciona a "," à linha de texto a ser salva
	fclose(file);
	
	printf("Digite o sobrenome que gostaria de cadastrar (apenas o último nome, sem acentos): ");
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

int consulta()//Função responsável pela consulta de usuários já cadastrados
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
		printf("Desculpe, CPF não encontrado.\nEstamos voltando ao menu, tente novamente.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}

int deletar()//Função responsável por deletar usuários já cadastrados
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que gostaria de deletar (apenas numeros): ");
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
		printf("Infelizmente o CPF solicitado não foi encontrado no sistema.\n");
		printf("Estamos voltando ao menu, tente novamente.\n");
		system("pause");
	}
	
}

int main()//Função principal para o sistema funcionar. criando o menu
{
	int opcao=0;//Definindo variáveis, tipo int
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//Título do projeto
		printf("Seja bem-vindo(a)!\n\n");
		printf("Escolha a opção desejada no menu:\n\n");//início do menu com as opções logo abaixo
		printf("\t1- Registrar Nomes\n");//opção 1
		printf("\t2- Consultar Nomes\n");//opção 2
		printf("\t3- Deletar Nomes\n");//opção 3
		printf("\nOpção:  ");
			
		scanf("%d", &opcao);//armazenando a escolha do usuário
	
		system("cls");//comando para limpar a tela apos ação anterior
	
		switch(opcao)//início da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();//chamada de funções
			break;
			
			case 3:
			deletar();//chamada de funções
			break;
			
			default:
			printf("Infelizmente essa opção não está disponível.\nVolte ao menu e tente novamente.\n");
			system("pause");
			break;
		}
	
	
	 }    
}
