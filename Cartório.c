#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca de responsavel pela criação de strings


int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/strings
	 char arquivo[40];
     char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40];
    //Fim da criação de variáveis/strings

     printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
     scanf("%s", cpf); //%s refere-se a strings
     
     strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
     
     FILE *file; //cria o arquivo 
     file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
     fprintf(file, cpf); //salva valor da variavel
     fclose(file); //fecha o arquivo
 
     file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
     fprintf(file,","); // a "," serve para separar as informações 
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

int consulta() //Função responsavel por consultar os usuários no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	// inicio da criação da variável/string
	char cpf[40];
	char conteudo[200];
    //fim da criação da variável/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a strings
	
	FILE *file; // Criar arquivo
	file = fopen(cpf, "r");	//ler arquivo ja criado
	
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o CPF, CPF não cadastrado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //Função responsavel por deletar os usuários do sistema 
{
   char cpf[40];
   
   printf("Digite o cpf a ser deletado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   
   if (file == NULL)
   {
   	printf("CPF não encontrado, não cadastrado!");
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
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //responsavel por limpar a tela 
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem 
	
	
	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	printf("Escolha a opção desejada no menu:\n\n");
	printf("\t1 - Resgistrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opção: "); //Fim do menu
	
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	system("cls");
	
	switch(opcao) //inicio da seleção do menu 
	{
		    case 1:
			registro(); //chamada de funções 
		    break;
		    
		    case 2:
		    consulta(); //chamda de funções 
		    break;
		    
		    case 3:
		   	deletar(); //chamada de funções 
		    break;
		    
		    default:
		    printf("Essa opção não existe\n"); //
		    system("pause");
		    break;	    	
    }
	

}
	
}
