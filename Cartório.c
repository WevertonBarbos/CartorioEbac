#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca de responsavel pela cria��o de strings


int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/strings
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
    //Fim da cria��o de vari�veis/strings

     printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
     scanf("%s", cpf); //%s refere-se a strings
     
     strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
     
     FILE *file; //cria o arquivo 
     file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
     fprintf(file, cpf); //salva valor da variavel
     fclose(file); //fecha o arquivo
 
     file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
     fprintf(file,","); // a "," serve para separar as informa��es 
     fclose(file); // serve para fechar o arquivo
     
     printf("Digite o nome a ser cadastrado: ");
     scanf("%s",nome);
     
     file = fopen(arquivo, "a");
     fprintf(file,nome);
     fclose(file);
     
     file = fopen(arquivo, "a");
     fprintf(file,",");
     fclose(file);
     
     printf("Digite o sobrenome a ser cadastrado: ");
     scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
   	file = fopen(arquivo, "a");
     fprintf(file,",");
     fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

    file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
		
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	// inicio da cria��o da vari�vel/string
	char cpf[40];
	char conteudo[200];
    //fim da cria��o da vari�vel/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a strings
	
	FILE *file; // Criar arquivo
	file = fopen(cpf, "r");	//ler arquivo ja criado
	
	
	if(file == NULL)
	{
		printf("N�o foi possivel localizar o CPF, CPF n�o cadastrado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //Fun��o responsavel por deletar os usu�rios do sistema 
{
   char cpf[40];
   
   printf("Digite o cpf a ser deletado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   
   if (file == NULL)
   {
   	printf("CPF n�o encontrado, n�o cadastrado!");
   }
   
   fclose(file);
   
   remove(cpf);
   
   if (file != NULL)
   {
   	printf("CPF deletado com sucesso!.");
   }
   	
   	system("pause");
}



int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela 
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	
	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a op��o desejada no menu:\n\n");
	printf("\t1 - Resgistrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Op��o: "); //Fim do menu
	
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	system("cls");
	
	switch(opcao) //inicio da sele��o do menu 
	{
		    case 1:
			registro(); //chamada de fun��es 
		    break;
		    
		    case 2:
		    consulta(); //chamda de fun��es 
		    break;
		    
		    case 3:
		   	deletar(); //chamada de fun��es 
		    break;
		    
		    default:
		    printf("Essa op��o n�o existe\n"); //
		    system("pause");
		    break;	    	
    }
	

}
	
}
