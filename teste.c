#include <stdio.h>

typedef struct
{
  char nome[50];
  char endereco[256];
  char telefone[25];
  char email[100];
  char data_nascimento[10];
}Cliente;

typedef struct
{
  char data[20];
  char hora[20];
  char peso[20];
  char percent_gordura[20];
  char estado_fisico[256];
  char restricoes[256];
}Consulta;

int main(void)
{
  return 0;
}