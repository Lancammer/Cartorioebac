#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado:  "); //Coletando informa��o do usu�rio
	scanf("%s" ,cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o"w" significa escrever
	fprintf(file, cpf); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //A fun��o "a" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //A fun��o "a" atualiza o arquivo
	fprintf(file,nome); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //A fun��o "a" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a"); //A fun��o "a" atualiza o arquivo
	fprintf(file,sobrenome); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //A fun��o "a" atualiza o arquivo
	fprintf(file, ",");
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s" ,cargo);	//%s refere-se a string
	
	file = fopen(arquivo, "a"); //A fun��o "a" atualiza o arquivo
	fprintf(file,cargo); //Salvo o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	system("pause");
}


int consulta ()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguaguem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo); 
		printf("\n\n");
	}
	
	system("pause");


}

int deletar () //Fun��o respons�vel por deletar usu�rios
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}	
	
}




int main()
    {
	int opcao=0; //Definindo �s vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); 
	
	
	    setlocale(LC_ALL,"Portuguese"); //Definindo a Linguaguem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Opcao:  "); //Fim do Menu
	
	    scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //Respons�vel por limpar a tela
	
	   switch(opcao) //Inicio da Sele��o do menu
	   {
	   	  case 1:
	   	 registro(); //Chamada de fun��es
		  break;
		  	  	
		  case 2:
		  consulta();
		  break;
		  
		  case 3:
	     deletar();
		  break;
		  
		  case 4:
		  printf("Obrigado por utilizar o sistema!\n");
		  return 0;
		  break;	
		  
		  default:
		  printf("Essa op��o n�o est� dispon�vel!\n");
		  system("pause");	
		  break;
		  
	   } //Fim da Sele��o
	   
	   
	}
}
