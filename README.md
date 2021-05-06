# Sistema de controle para times esportivos
Este repositório foi criado e editado por mim para o trabalho A3 da disciplina de Programação Orientada a Objetos ministrada pelo professor [Vinicius Cassol](https://github.com/vinicassol) do curso de Ciência da Computação da Universidade Ritter dos Reis. O objetivo é desenvolver um sistema simples de controle para times esportivos em C++ aplicando os conceitos e técnicas que aprendemos em aula. Segue também [Link Video](https://youtu.be/fBeSjD7HrCo) com algumas explicações do funcionamento.


## O Desafio
O desafio do exercicio é resolver todos os problemas propostos no enunciado do projeto disponibilizado pelo mestre do curso. Então, temos como objetivos:
1. **Criar uma classe para representar um `Jogador` e esta classe deve:**
	- Implementar os atributos:
		- Nome
		- Id (Esta é uma informação única e gerada automaticamente)
		- Data de nascimento
		- Nacionalidade
		- Categoria de Atuação (Profissional/Base)
		- Salário bruto mensal
	- Fazer Getters e Setters para todos os atributos
	- Desenvolver um método para calcular a idade do jogador
	- Criar um método para mostrar quanto tempo falta para o jogador se aposentar
	- Construir um método para calcular o salário líquido. Para calcular o salário líquido, deve-se descontar o valor de INSS e o Valor de Imposto Retido na conta. Para isso, considere a tabela a seguir:
   

		|   FAIXA SALARIAL     |  INSS  | IRRF  |
		| :---                 |  :---: | :---: |
		| ATÉ R$ 1100,00       |   7.5% |   0%  |
		| ATÉ R$ 2000,00       |     9% | 7.5%  |
		| ATÉ R$ 3100,00       |    12% |  15%  |
		| ATÉ R$ 4.100,00      |    14% |  22%  |
		| ACIMA DE R$ 4.100,00 |    14% |  27%  |


2. **Criar classe para representar um `Time`  e esta classe deve:**
	- Implementar os atributos:
		- Nome
		- Id (Esta é uma informação única e gerada automaticamente)
		- Categoria (Profissional/Base)
		- Conjunto de jogadores que fazem parte do time
	- Fazer Getters e Setters para todos os atributos
	- Desenvolver um relatório geral que apresente o nome do time e os dados de todos os seus jogadores
	- Criar um relatório financeiro para apresentar o nome de todos os jogadores ativos do time, seu respectivo salário bruto e líquido


3. **Crie uma classe que represente uma `Empresa`. Esta classe será responsável por gerenciar vários times, com os atributos que julgar conveniente. Ela deve:**
	- Implementar uma consulta de jogador que pode receber um nome ou ID e apresentar de qual time o jogador faz parte, seus dados pessoais(nome/idade), seu salário bruto e líquido
	- Desenvolver um método para listar os jogadores. Similar ao método anterior, apresenta uma lista com todos os jogadores que fazem parte da empresa
	- Criar um relatório financeiro. Para cada time gerenciado pela empresa, apresentar o relatório contendo os custos totais de cada time, destacando:
		- Valor a ser pago em salários
		- Valor a ser destinado ao INSS
		- Valor retido a ser pago ao imposto de renda


## A Estrutura
A estrutura do projeto conta com um diretório chamado `source/` onde estão todos os arquivos com código escrito. Dentro deste foram criados arquivos de cabeçalho no formato `.hpp`. Estes contém todas as definições das classes que usamos no código. E também foram criados os arquivos `.cpp` onde esta a implementação das funções definidas anteriormente. No momento em que o build é executado será também criado um novo diretório na pasta raiz do projeto chamado `objects/` e o arquivo da aplicação chamado `sistemaControle.exe`.


## O Build
Para executar o build que gera os binários e o executavel do projeto sem muitas complicações foi implementado um arquivo `makefile`. Ele foi desenvolvido com base nesta [documentação](https://www.gnu.org/software/make/manual/make.html). Nesse arquivo foram criado os seguintes métodos:
- `make all`: executa as instruções para compilação e gera os binários e o executável do projeto. Para executar basta estar no mesmo diretório do arquivo `makefile` e digitar `make all` conforme abaixo. 

	```Shell
	# User@Computer .../sistemaControle
	$ make all
	Building target using GCC compiler: source/data.cpp
	g++ source/data.cpp -c -W -Wall       -o objects/data.o	

	Building target using GCC compiler: source/empresa.cpp
	g++ source/empresa.cpp -c -W -Wall       -o objects/empresa.o

	Building target using GCC compiler: source/jogador.cpp
	g++ source/jogador.cpp -c -W -Wall       -o objects/jogador.o

	Building target using GCC compiler: source/main.cpp
	g++ source/main.cpp -c -W -Wall       -o objects/main.o

	Building target using GCC compiler: source/time.cpp
	g++ source/time.cpp -c -W -Wall       -o objects/time.o

	Building binary using GCC linker: sistemaControle
	g++ objects/data.o objects/empresa.o objects/jogador.o objects/main.o objects/time.o -o sistemaControle
	Finished building binary: sistemaControle
	```


	Se algum erro de compilação acontecer o gcc informará o arquivo, a linha, a coluna onde o erro aconteceu e qual foi o erro. Nesse caso o erro esta na linha 10, na coluna 35 do arquivo jogador.cpp. E o erro que acontece é a falta de um ";" antes do "this" da linha 11.

	```Shell
	# User@Computer .../sistemaControle
	$ make all
	Building target using GCC compiler: source/data.cpp
	g++ source/data.cpp -c -W -Wall       -o objects/data.o

	Building target using GCC compiler: source/empresa.cpp
	g++ source/empresa.cpp -c -W -Wall       -o objects/empresa.o

	Building target using GCC compiler: source/jogador.cpp
	g++ source/jogador.cpp -c -W -Wall       -o objects/jogador.o
	source/jogador.cpp: In constructor 'Jogador::Jogador(std::string, Data, std::string, Categorias, float)':
	source/jogador.cpp:10:35: error: expected ';' before 'this'
	10 |  this->dataNascimento = nascimento
	  |                                   ^
	  |                                   ;
	11 |  this->nacionalidade = nacionalidade;
	  |  ~~~~
	source/jogador.cpp:7:55: warning: unused parameter 'nacionalidade' [-Wunused-parameter]
	7 | Jogador::Jogador(string nome, Data nascimento, string nacionalidade, Categorias categoria, float salarioBruto){
	  |                                                ~~~~~~~^~~~~~~~~~~~~
	make: *** [objects/jogador.o] Error 1
	```


- `make clean`: Serve para limpar os arquivos dos ultimos builds e não possui um retorno quando tem sucesso. É aconselhavel sempre executar antes de um `make all` para garantir que todos os arquivos serão compilados novamente. Para a execução devemos estar no mesmo diretório do arquivo `makefile`  e digitar `make clean` conforme código abaixo.

	```Shell
	# User@Computer .../sistemaControle
	$ make clean

	```