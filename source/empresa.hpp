#include "time.hpp"

class Empresa{
	private:
		string nome;
		vector<Time> times;
	public:
		Empresa();
		Empresa(string nome);

		string getNome();
		vector<Time> getTimes();

		void setNome(string nome);
		void setTimes(vector<Time> times);

		void consultarJogador(int id);
		void consultarJogador(string nome);
		void listaJogadores();
		void relatorioFinanceiro();
		void adicionarTime(Time time);

};