# Sistema de controle para times esportivos
Este projeto foi criado para o trabalho A3 da disciplina de Programação Orientada a Objetos ministrada pelo professor Vinicius Cassol da Universidade Ritter dos Reis. O objetivo é desenvolver um sistema simples de controle para times esportivos em C++ aplicando os conceitos e técnicas que aprendemos em aula.

## O Desafio
O desafio do exercicio é resolver todos os problemas propostos no enunciado do projeto disponibilizado pelo mestre do curso. Então, temos como objetivos:
###1. Criar uma classe para representar um `Jogador` e esta classe deve:
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

###2. Criar classe para representar um `Time`  e esta classe deve:
   - Implementar os atributos:
      - Nome
      - Id (Esta é uma informação única e gerada automaticamente)
      - Categoria (Profissional/Base)
      - Conjunto de jogadores que fazem parte do time
   - Fazer Getters e Setters para todos os atributos
   - Desenvolver um relatório geral que apresente o nome do time e os dados de todos os seus jogadores
   -  Criar um relatório financeiro para apresentar o nome de todos os jogadores ativos do time, seu respectivo salário bruto e líquido