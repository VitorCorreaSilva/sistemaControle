#include <iostream>
#include "data.hpp"

using namespace std;

enum Categorias{
	BASE,
	PROFISSIONAL
};

class Jogador{
	private:
		int id;
		string nome;
		Data dataNascimento;
		string nacionalidade;
		Categorias categoria;
		float salarioBruto;
	public:
		Jogador();
		Jogador(string nome, Data dataNascimento, string nacionalidade, Categorias categoria, float salarioBruto);

		string getNome();
		int getId();
		Data getDataNascimento();
		string getNacionalidade();
		Categorias getCategoria();
		float getSalarioBruto();

		void setNome(string nome);
		void setId(int id);
		void setDataNascimento(int dia, int mes, int ano);
		void setNacionalidade(string nacionalidade);
		void setCategoria(Categorias categoria);
		void setSalarioBruto(float salarioBruto);

		float calcularSalarioLiquido(float salarioBruto);
		float calcularDescontoInss(float salarioBruto);
		float calcularDescontoIrrf(float salarioSemInss);
		int calcularIdade(Data dataNascimento);
		int calcularTempoAposentadoria(Data dataNascimento);
		void mostrarDados();

		int static ultimoIdJogador;
		int gerarIdJogador();

		int const IDADE_APOSENTADORIA = 40;
};