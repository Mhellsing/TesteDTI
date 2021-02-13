#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numeroclientes = 0;

typedef struct
{
  char data[20];
  char hora[20];
  char peso[20];
  char percent_gordura[20];
  char estado_fisico[256];
  char restricoes[256];
}Consulta;

typedef struct
{
  char nome[50];
  char endereco[256];
  char telefone[25];
  char email[100];
  char data_nascimento[10];
  int consultasrealizadas;
  Consulta consultas[3]; 
}Cliente;

void ImprimeCliente(Cliente C)
{
  printf("\nNome: %s\nEndereco: %s\nTelefone: %s\nEmail: %s\nData de nascimento: %s\n", C.nome, C.endereco, C.telefone, C.email, C.data_nascimento);
  
}

void ImprimeConsulta(Consulta C, int numeroconsulta)
{
  printf("\n=== Consulta %i ===\n", numeroconsulta);
  printf("Data: %s\nHora: %s\nPeso: %s\n%% de Gordura: %s\nEstado Físico do paciente: %s\nRestrições alimentares: %s\n\n",C.data, C.hora, C.peso, C.percent_gordura, C.estado_fisico, C.restricoes);
}

Cliente PreencheDadosCliente()
{
  Cliente cliente;
  
  printf("Digite os dados do paciente:\n");

  printf("Nome: ");
  fgets(cliente.nome, sizeof(cliente.nome), stdin);
  
  printf("Endereco: ");
  fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
  
  printf("Telefone: ");
  fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
  
  printf("Email: ");
  fgets(cliente.email, sizeof(cliente.email), stdin);
  
  printf("Data de Nascimento: ");
  fgets(cliente.data_nascimento, sizeof(cliente.data_nascimento), stdin);

  return cliente;
}

Consulta PreencheDadosConsulta()
{
  Consulta consulta;
  
  printf("Digite os dados da consulta:\n");

  printf("Data: ");
  fgets(consulta.data, sizeof(consulta.data), stdin);
  
  printf("Hora: ");
  fgets(consulta.hora, sizeof(consulta.hora), stdin);
  
  printf("Peso: ");
  fgets(consulta.peso, sizeof(consulta.peso), stdin);
  
  printf("Percentual de Gordura: ");
  fgets(consulta.percent_gordura, sizeof(consulta.percent_gordura), stdin);
  
  printf("Estado fisico do paciente: ");
  fgets(consulta.estado_fisico, sizeof(consulta.estado_fisico), stdin);

  printf("Restricoes alimentares: ");
  fgets(consulta.restricoes, sizeof(consulta.restricoes), stdin);

  return consulta;
}

void MenuClientes(Cliente clientes[3])
{
  char stringescolha[1];
  int escolha;
  
  do
  {
    printf("=== Escolha o cliente que deseja visualizar as consultas ===\n");
    for(int i = 0; i < numeroclientes; i++)
    {
      printf("%i-%s", i+1, clientes[i].nome);
    }

    printf("4-Retornar ao menu anterior\n");
    scanf("%i", &escolha);
    getchar(); //consome o \n.
   
    switch(escolha)
    {
      case 1:
        if(clientes[0].consultasrealizadas == 0)
        {
          printf("ERRO: Não possui consultas cadastradas.\n");
        }
        else
        {
          for(int i = 0; i < clientes[0].consultasrealizadas; i++)
          {
            ImprimeConsulta(clientes[0].consultas[i], i+1);
          }
        }
      break;

      case 2:
        if(numeroclientes < 2)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          if(clientes[1].consultasrealizadas == 0)
          {
            printf("ERRO: Não possui consultas cadastradas.\n");
          }
          else
          {
            for(int i = 0; i < clientes[1].consultasrealizadas; i++)
            {
              ImprimeConsulta(clientes[1].consultas[i], i+1);
            }
          }
        }
      break;

      case 3:
        if(numeroclientes < 3)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          if(clientes[2].consultasrealizadas == 0)
          {
            printf("ERRO: Não possui consultas cadastradas.\n");
          }
          else
          {
            for(int i = 0; i < clientes[2].consultasrealizadas; i++)
            {
              ImprimeConsulta(clientes[2].consultas[i], i+1);
            }
          }
        }
      break;

      case 4:
        printf("\e[1;1H\e[2J");
      break;
    }

  }while(escolha != 4);
}

void MenuClientesConsulta(Cliente clientes[3])
{
  char stringescolha[1];
  int escolha;
  
  do
  {
    printf("=== Escolha o cliente para o qual deseja iniciar uma consulta ===\n");
    for(int i = 0; i < numeroclientes; i++)
    {
      printf("%i-%s", i+1, clientes[i].nome);
    }

    printf("4-Retornar ao menu anterior\n");
    scanf("%i", &escolha);
    getchar(); //consome o \n.
   
    switch(escolha)
    {
      case 1:
        if(clientes[0].consultasrealizadas > 2)
        {
          printf("ERRO: Numero maximo de consultas atingido.\n");
        }
        else
        {
          int numeroconsultas = clientes[0].consultasrealizadas;
          clientes[0].consultas[numeroconsultas] = PreencheDadosConsulta();
          clientes[0].consultasrealizadas++;
        }
      break;

      case 2:
        if(numeroclientes < 2)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          if(clientes[1].consultasrealizadas > 2)
          {
            printf("ERRO: Numero maximo de consultas atingido.\n");
          }
          else
          {
            int numeroconsultas = clientes[1].consultasrealizadas;
            clientes[1].consultas[numeroconsultas] = PreencheDadosConsulta();
            clientes[1].consultasrealizadas++;
          }
        }
      break;

      case 3:
        if(numeroclientes < 3)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          if(clientes[2].consultasrealizadas > 2)
          {
            printf("ERRO: Numero maximo de consultas atingido.\n");
          }
          else
          {
            int numeroconsultas = clientes[1].consultasrealizadas;
            clientes[2].consultas[numeroconsultas] = PreencheDadosConsulta();
            clientes[2].consultasrealizadas++;
          }
        }
      break;

      case 4:
        printf("\e[1;1H\e[2J");
      break;
    }

  }while(escolha != 4);
}

void MenuPrincipal()
{
  char stringescolha[1];
  int escolha;
  Cliente clientes[3];

  do
  {
    printf("=== Menu Principal ===\n");
    printf("1-Cadastrar Paciente\n");
    printf("2-Listar Consultas\n");
    printf("3-Iniciar consulta\n");
    printf("4-Sair\n");
    scanf("%i", &escolha);
    getchar();//consome o \n
    
    switch(escolha)
    {
      case 1:
        if(numeroclientes > 2)
        {
          printf("ERRO: Numero maximo de cliente cadastrados, para ampliar esta capacidade contrate o plano premium.\n");
        }
        else
        {
          printf("\e[1;1H\e[2J");//string para limpar a tela do console.

          clientes[numeroclientes] = PreencheDadosCliente();
          numeroclientes++;

          printf("\e[1;1H\e[2J");
          printf("SUCESSO: Cadastro de cliente executado com sucesso.\n");
        }
      break;

      case 2:
        if(numeroclientes == 0)
        {
          printf("\e[1;1H\e[2J");
          printf("ERRO: Nao existem cliente cadastrados.\n");
        }
        else
        {
          printf("\e[1;1H\e[2J");//string para limpar a tela do console.

          MenuClientes(clientes);

          printf("\e[1;1H\e[2J");
          
        }
      break;

      case 3:
        if(numeroclientes == 0)
        {
          printf("\e[1;1H\e[2J");
          printf("ERRO: Sistema nao possui clientes cadastrados, impossivel iniciar uma consulta.\n");
        }
        else
        {
          printf("\e[1;1H\e[2J");

          MenuClientesConsulta(clientes);

          printf("\e[1;1H\e[2J");
          
        }
      break;

      case 4:
      break;
    }

  }while(escolha != 4);
}

int main(void)
{
  MenuPrincipal();

  return 0;
}