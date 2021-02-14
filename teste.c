#include <stdio.h>
#include <stdlib.h>

// Definindo struct Alimento
typedef struct
{
  char nome[50];
  int calorias;
}Alimento;

// Definindo struct Consulta
typedef struct
{
  char data[20];
  char hora[20];
  char peso[20];
  char percent_gordura[20];
  char estado_fisico[256];
  char restricoes[256];
}Consulta;

// Definindo struct Cliente
// Cliente possui uma propriedade chamada consultas pois era preciso ligar as consultas a um cliente, para que o usuário pudesse visualizar depois
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

// Para o sistema não ter que tratar tantos erros e não ficar muito complexo, foi limitado o número de clientes a 3
// Essa variável controla o número de clientes que a aplicação possui
int numeroclientes = 0;

// Uma das premissas assumidas é a de que os alimentos já estariam inseridos no sistema, por isso foram definidos aqui no código
Alimento frutas[3] = 
{
  [0] = {"Melancia", 50},
  [1] = {"Laranja", 30},
  [2] = {"Pera", 30}
};

Alimento carboidratos[3] = 
{
  [0] = {"Macarrao", 1000},
  [1] = {"Pao", 900},
  [2] = {"Arroz", 700}
};

Alimento proteinas[3] = 
{
  [0] = {"Peixe", 600},
  [1] = {"Frango", 700},
  [2] = {"Carne Vermelha", 1200}
};

// Algoritmo de combinação alimentar
// Ele soma todas as calorias em grupos de 3 alimentos (1 de cada grupo) para verificar se aquela combinação
// está dentro do limite inserido pelo usuário, em caso positivo, a função mostra a combinação na tela
void CombinacaoAlimentar()
{
  int soma = 0, limite;

  printf("\nDigite o limite calorico desejado: ");
  scanf("%i", &limite);

  printf("Combinacoes de alimentos possiveis por limite estabelecido: \n\n");

  for(int contadorfrutas = 0; contadorfrutas < 3; contadorfrutas++)
  {
    // Aqui somamos as calorias das frutas
    soma += frutas[contadorfrutas].calorias;

    for(int contadorcarboidratos = 0; contadorcarboidratos < 3; contadorcarboidratos++)
    {
      // Aqui somamos as calorias dos carboidratos
      soma += carboidratos[contadorcarboidratos].calorias;
      
      for(int contadorproteinas = 0; contadorproteinas < 3; contadorproteinas++)
      {
        // Aqui somamos as calorias das proteínas
        soma += proteinas[contadorproteinas].calorias;

        // Em caso positivo, mostramos na tela a combinação que atendeu ao critério de limite calórico
        if(soma <= limite)
        {
          printf("%s-%s-%s\n", frutas[contadorfrutas].nome, carboidratos[contadorcarboidratos].nome, proteinas[contadorproteinas].nome);
        }

        // Aqui retiramos as calorias do alimento proteína atual antes de somar o próximo item da lista, para que a soma não acumule de forma errada.
        soma -= proteinas[contadorproteinas].calorias;
      }
      // Aqui retiramos as calorias do alimento carboidrato atual antes de somar o próximo item da lista, para que a soma não acumule de forma errada.
      soma -= carboidratos[contadorcarboidratos].calorias;
    }
    // Aqui retiramos as calorias do alimento fruta atual antes de somar o próximo item da lista para que a soma não acumule de forma errada.
    soma -= frutas[contadorfrutas].calorias;
  }
  printf("\n");
}

// Aqui imprimimos os dados do cliente na tela
void ImprimeCliente(Cliente C)
{
  printf("\nNome: %s\nEndereco: %s\nTelefone: %s\nEmail: %s\nData de nascimento: %s\n", C.nome, C.endereco, C.telefone, C.email, C.data_nascimento);
}

// Aqui limpamos tudo o que está escrito na tela atual
void LimpaConsole()
{
  system("@cls||clear");
}

// Aqui imprimimos os dados da consulta na tela
void ImprimeConsulta(Consulta C, int numeroconsulta)
{
  printf("\n=== Consulta %i ===\n", numeroconsulta);
  printf("Data: %s\nHora: %s\nPeso: %s\n%% de Gordura: %s\nEstado Físico do paciente: %s\nRestrições alimentares: %s\n\n",C.data, C.hora, C.peso, C.percent_gordura, C.estado_fisico, C.restricoes);
}

// Aqui preenchemos os dados do cliente e retornamos uma variável do tipo Cliente para armazenar no sistema
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

  // Variável de controle para demonstrar que o cliente não efetuou consultas ainda
  cliente.consultasrealizadas = 0; 
  
  return cliente;
}

// Aqui preenchemos os dados de uma consulta e retornamos uma variável do tipo Consulta para armazenar na lista de consultas do usuário que está no sistema
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

// Aqui temos um menu para escolher o cliente, e posteriormente visualizar as consultas que o mesmo fez
void MenuClientesVisualizarConsultas(Cliente clientes[3]) 
{
  int escolha;
  
  do
  {
    printf("=== Escolha o cliente que deseja visualizar as consultas ===\n");
    // Esse for serve pra mostrar as opções na tela somente se o usuário existir.
    // Todas as 3 opções existem por padrão, mas não mostramos na tela caso não exista usuário naquela posição
    for(int i = 0; i < numeroclientes; i++)
    {
      printf("%i-%s", i+1, clientes[i].nome);
    }

    printf("4-Retornar ao menu principal\n");
    scanf("%i", &escolha);
    // A função fgets não funcionava direito no while pois ela não travava o console, então usei o scanf
    // Porém o scanf quando o usuário apertava enter, "bugava" a resposta da próxima inserção do usuário
    // A função getchar serviu para "capturar" o "\n" (enter) que o usuário usava e não influenciar futuros inputs
    getchar();
   
    switch(escolha)
    {
      // Cliente 1
      // Essa tela só é acessada caso pelo menos um cliente exista, então é checado se o cliente possui consultas cadastradas
      // Em caso positivo, o sistema imprime as consultas na tela, em caso negativo é retornado um erro
      case 1:
        if(clientes[0].consultasrealizadas == 0)
        {
          printf("ERRO: Não possui consultas cadastradas.\n");
        }
        else
        {
          for(int i = 0; i < clientes[0].consultasrealizadas; i++)
          {
            // Mostra na tela as consultas existentes
            ImprimeConsulta(clientes[0].consultas[i], i+1);
          }
        }
      break;

      // Cliente 2
      case 2:
        // É checado se o cliente existe, em caso negativo é retornado um erro
        if(numeroclientes < 2)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          // É checado se o cliente possui consultas cadastradas, em caso positivo, o sistema imprime as consultas na tela, em caso negativo é retornado um erro
          if(clientes[1].consultasrealizadas == 0)
          {
            printf("ERRO: Não possui consultas cadastradas.\n");
          }
          else
          {
            for(int i = 0; i < clientes[1].consultasrealizadas; i++)
            {
              // Mostra na tela as consultas existentes
              ImprimeConsulta(clientes[1].consultas[i], i+1);
            }
          }
        }
      break;
      
      // Cliente 3
      case 3:
        // É checado se o cliente existe, em caso negativo é retornado um erro
        if(numeroclientes < 3)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          // É checado se o cliente possui consultas cadastradas, em caso positivo, o sistema imprime as consultas na tela, em caso negativo é retornado um erro
          if(clientes[2].consultasrealizadas == 0)
          {
            printf("ERRO: Não possui consultas cadastradas.\n");
          }
          else
          {
            for(int i = 0; i < clientes[2].consultasrealizadas; i++)
            {
              // Mostra na tela as consultas existentes
              ImprimeConsulta(clientes[2].consultas[i], i+1);
            }
          }
        }
      break;

      case 4:
        // Opção de sair, limpa o console e volta ao menu principal
        LimpaConsole();
      break;
    }
  }while(escolha != 4);
}

// Aqui temos um menu para escolher o cliente, e posteriormente iniciar uma consulta
void MenuClientesCadastrarConsultas(Cliente clientes[3])
{
  int escolha;
  
  do
  {
    printf("=== Escolha o cliente para o qual deseja iniciar uma consulta ===\n");
    // Esse for serve pra mostrar as opções na tela somente se o usuário existir.
    // Todas as 3 opções existem por padrão, mas não mostramos na tela caso não exista usuário naquela posição
    for(int i = 0; i < numeroclientes; i++)
    {
      printf("%i-%s", i+1, clientes[i].nome);
    }

    printf("4-Retornar ao menu principal\n");
    scanf("%i", &escolha);
    // A função fgets não funcionava direito no while pois ela não travava o console, então usei o scanf
    // Porém o scanf quando o usuário apertava enter, "bugava" a resposta da próxima inserção do usuário
    // A função getchar serviu para "capturar" o "\n" (enter) que o usuário usava e não influenciar futuros inputs
    getchar();
   
    switch(escolha)
    {
      case 1:
        // Cliente 1
        // Essa tela só é acessada caso pelo menos um cliente exista, então é checado se o cliente já atingiu o número máximo de consultas
        // Em caso negativo, o sistema inicia uma consulta, em caso positivo é retornado um erro
        if(clientes[0].consultasrealizadas > 2)
        {
          printf("ERRO: Numero maximo de consultas atingido.\n");
        }
        else
        {
          // Verificamos quantas consultas o cliente possui para descobrirmos em qual posição da lista inserir a nova
          int numeroconsultas = clientes[0].consultasrealizadas;
          // Preenchemos os dados
          clientes[0].consultas[numeroconsultas] = PreencheDadosConsulta();
          // Efetuamos os cálculos de combinação alimentar
          CombinacaoAlimentar();
          // Registramos uma nova consulta
          clientes[0].consultasrealizadas++;
        }
      break;

      // Cliente 2
      case 2:
        // É checado se o cliente existe, em caso negativo é retornado um erro
        if(numeroclientes < 2)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          // Checamos se o cliente já atingiu o número máximo de consultas
          // Em caso negativo, o sistema inicia uma consulta, em caso positivo é retornado um erro
          if(clientes[1].consultasrealizadas > 2)
          {
            printf("ERRO: Numero maximo de consultas atingido.\n");
          }
          else
          {
            // Verificamos quantas consultas o cliente possui para descobrirmos em qual posição da lista inserir a nova
            int numeroconsultas = clientes[1].consultasrealizadas;
            // Preenchemos os dados
            clientes[1].consultas[numeroconsultas] = PreencheDadosConsulta();
            // Efetuamos os cálculos de combinação alimentar
            CombinacaoAlimentar();
            // Registramos uma nova consulta
            clientes[1].consultasrealizadas++;
          }
        }
      break;

      // Cliente 3
      case 3:
        // É checado se o cliente existe, em caso negativo é retornado um erro
        if(numeroclientes < 3)
        {
          printf("ERRO: Opção inexistente.\n");
        }
        else
        {
          // Checamos se o cliente já atingiu o número máximo de consultas
          // Em caso negativo, o sistema inicia uma consulta, em caso positivo é retornado um erro
          if(clientes[2].consultasrealizadas > 2)
          {
            printf("ERRO: Numero maximo de consultas atingido.\n");
          }
          else
          {
            // Verificamos quantas consultas o cliente possui para descobrirmos em qual posição da lista inserir a nova
            int numeroconsultas = clientes[1].consultasrealizadas;
            // Preenchemos os dados
            clientes[2].consultas[numeroconsultas] = PreencheDadosConsulta();
            // Efetuamos os cálculos de combinação alimentar
            CombinacaoAlimentar();
            // Registramos uma nova consulta
            clientes[2].consultasrealizadas++;
          }
        }
      break;

      case 4:
        // Opção de sair, limpa o console e volta ao menu principal
        LimpaConsole();
      break;
    }

  }while(escolha != 4);
}

// Aqui temos o menu principal da aplicação, onde é possível cadastrar clientes, listar as consultas dos clientes cadastrados e iniciar uma nova consulta para um cliente cadastrado
void MenuPrincipal()
{
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
    // A função fgets não funcionava direito no while pois ela não travava o console, então usei o scanf
    // Porém o scanf quando o usuário apertava enter, "bugava" a resposta da próxima inserção do usuário
    // A função getchar serviu para "capturar" o "\n" (enter) que o usuário usava e não influenciar futuros inputs
    getchar();

    switch(escolha)
    {
      // Cadastro de clientes
      case 1:
        // Se o número máximo de clientes já foi atingido, é impossível cadastrar mais, e a aplicação retorna um erro
        if(numeroclientes > 2)
        {
          printf("ERRO: Numero maximo de cliente cadastrados, para ampliar esta capacidade contrate o plano premium.\n");
        }
        else
        {
          LimpaConsole();
          // Cadastra o Cliente
          clientes[numeroclientes] = PreencheDadosCliente();
          numeroclientes++;

          LimpaConsole();
          printf("SUCESSO: Cadastro de cliente executado.\n");
        }
      break;

      // Visualizar consultas
      case 2:
        // Checa se existem clientes cadastrados, em caso negativo, retorna um erro
        if(numeroclientes == 0)
        {
          LimpaConsole();
          printf("ERRO: Nao existem cliente cadastrados.\n");
        }
        else
        {
          // Abre o menu de visualização de clientes/consultas
          LimpaConsole();
          MenuClientesVisualizarConsultas(clientes);
          LimpaConsole();
        }
      break;

      // Inicia uma consulta
      case 3:
        // Checa se existem clientes cadastrados, em caso negativo, retorna um erro
        if(numeroclientes == 0)
        {
          LimpaConsole();
          printf("ERRO: Sistema nao possui clientes cadastrados, impossivel iniciar uma consulta.\n");
        }
        else
        {
          // Abre o menu de iniciar consultas
          LimpaConsole();
          MenuClientesCadastrarConsultas(clientes);
          LimpaConsole();          
        }
      break;

      // Encerra a aplicação
      case 4:
      printf("=== Programa Encerrado ===");
      exit(0);
      break;
    }

  }while(escolha != 4);
}

int main(void)
{
  // Chama o Menu Principal
  MenuPrincipal();  
  return 0;
}