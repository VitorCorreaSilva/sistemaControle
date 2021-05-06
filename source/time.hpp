#include "jogador.hpp"
#include <vector>

class Time{
	private:
		int id;
		string nome;
		Categorias categoria;
		vector<Jogador> jogadores;
	public:
		Time();
		Time(string nome, Categorias categoria);

		int getId();
		string getNome();
		Categorias getCategoria();
		vector<Jogador> getJogadores();

		void setId(int id);
		void setNome(string nome);
		void setCategoria(Categorias categoria);
		void setJogadores(vector<Jogador> jogadores);

		void adicionarJogador(Jogador jogador);
		void buscarJogador(int id);
		void buscarJogador(string nome);
		void relatorioGeral();
		void relatorioFinanceiro();

		int static ultimoIdTime;
		int gerarIdTime();
};