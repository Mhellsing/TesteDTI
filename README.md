# :space_invader: Teste de Estágio DTI :space_invader: 

### O Problema
Marina é uma nutricionista recém formada que está abrindo seu próprio consultório em Belo  
Horizonte. Ela ainda não possui uma secretária e terá que ser responsável por todas as  
atividades do seu consultório. Por isso, Marina contratou você para ajudá-la com um  
sistema de computador.  

Para realizar seu trabalho Marina precisará de ter os dados pessoais de seus clientes  
(nome, endereço, telefones, email e data de nascimento). Marina precisará também de  
informações de todas as consultas realizadas com cada paciente. Cada consulta deve  
contar com (data, horário, peso, % de gordura corporal e sensação física do paciente,além  
de dados das restrições alimentares determinadas por ela).  

Na forma de trabalho de Marina, as dietas são constituídas de alimentos de três grupos,  
cada alimento tem sua própria quantidade calórica. Durante uma consulta Marina deseja  
poder informar ao sistema uma meta de consumo calórico para o paciente e poder ver todas  
as combinações de três alimentos (um de cada grupo) que não extrapolam esse valor.  
Ajude a empreitada de Marina criando um sistema que atenda suas necessidades.

---

### Premissas Assumidas
* Inicialmente o programa a ser criado seria um MVP para avaliar a rotina do usuário e posteriormente implementar mais funcionalidades, deixando a aplicação mais robusta.

* Devido à entrega se tratar de um MVP  foi proposto limitar o número de clientes e consultas cadastradas, estabelecendo três amostras para cada item.

* Para se realizar o cálculo de possibilidades de dieta com base no limite calórico inserido pelo usuário, os alimentos  já seriam pré-estabelecidos no sistema com seu respectivo número de calorias.

* Foi assumido que o usuário poderia visualizar as consultas de cada paciente a qualquer momento, portanto a aplicação conta com uma navegação em menus.

* Foi assumido que o usuário poderia descrever os dados das consultas e dos clientes de maneira livre e diferente para cada caso, portanto, a maior parte dos campos foram descritos como inputs de texto de tamanho confortável.

---

### Decisões de projeto
* Para esta aplicação foi pensado em um menu de navegação principal para que o usuário pudesse escolher quais funções o sistema executaria, e submenus de escolha de cliente relativos as funções de visualização e cadastramento de novas consultas.

* Para este projeto foi definido que a linguagem de programação utilizada seria  **C**, pois esta é a linguagem que o candidato possui maior familiaridade.
---
### Modelagem

* Foi decidido que alimentos eram uma parte essencial do sistema, portanto, este dado se tornou uma classe com propriedades bem definidas no sistema. A classe de alimento possui os campos "nome" e "calorias".

* Foi decidido que o cliente também era uma parte importante do sistema, portanto, o mesmo também foi definido como uma classe. A classe cliente possui os campos "nome", "endereço", "telefone", "email", "data de nascimento", "consultas realizadas" e "consultas".
Para visualização das consultas de um cliente era necessário que as mesmas estivessem ligada a ele, portanto as propriedades consultas realizadas (int) e consultas (consulta) foram criadas para ter esta rastreabilidade.

* Foi decidido que as consultas também eram parte integrante do sistemas e também se tornou uma classe. A classe consulta possui os campos "data", "hora", "peso", "percentual de gordura", "estado físico" e "restrições alimentares".
---

### Instruções de execução

##### Opção 1
* Utilizar [este link](https://cplayground.com/?p=koala-bee-butterfly) para executar o projeto na plataforma **C Playground**.
##### Opção 2
* Executar o arquivo **teste_dti.exe** que se encontra no repositório.