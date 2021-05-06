#include "empresa.hpp"

Empresa::Empresa(){}

Empresa::Empresa(string nome){
	this->nome = nome;
}

void Empresa::consultarJogador(int id){
	int numTimes = times.size();
	for (int i = 0; i < numTimes; ++i)
	{
		vector<Jogador> jogadores = times[i].getJogadores();
		int numJogadores = jogadores.size();
		for (int j = 0; j < numJogadores; ++j)
		{
			if(jogadores[j].getId() == id){
				cout << fixed;
				cout << "Time: " << times[i].getNome() << endl;
				cout << "Nome: " << jogadores[j].getNome() << endl;
				cout << "Idade: " << jogadores[j].calcularIdade(jogadores[j].getDataNascimento()) << " anos" << endl;
				cout.precision(2);
				cout << "Salario Bruto: " << jogadores[j].getSalarioBruto() << " R$" << endl;
				cout << "Salario Liquido: " << jogadores[j].calcularSalarioLiquido(jogadores[j].getSalarioBruto()) << " R$" << endl;
			}
		}
	}
}

void Empresa::consultarJogador(string nome){
	int numTimes = times.size();
	for (int i = 0; i < numTimes; ++i)
	{
		vector<Jogador> jogadores = times[i].getJogadores();
		int numJogadores = jogadores.size();
		for (int j = 0; j < numJogadores; ++j)
		{
			if(jogadores[j].getNome() == nome){
				cout << fixed;
				cout << "Time: " << times[i].getNome() << endl;
				cout << "Nome: " << jogadores[j].getNome() << endl;
				cout << "Idade: " << jogadores[j].calcularIdade(jogadores[j].getDataNascimento()) << " anos" << endl;
				cout.precision(2);
				cout << "Salario Bruto: " << jogadores[j].getSalarioBruto() << " R$" << endl;
				cout << "Salario Liquido: " << jogadores[j].calcularSalarioLiquido(jogadores[j].getSalarioBruto()) << " R$" << endl;
			}
		}
	}
}

void Empresa::listaJogadores(){
	int numTimes = times.size();
	for (int i = 0; i < numTimes; ++i)
	{
		vector<Jogador> jogadores = times[i].getJogadores();
		int numJogadores = jogadores.size();
		for (int j = 0; j < numJogadores; ++j)
		{
			cout << "ID: " << jogadores[j].getId();
			cout << " Nome: " << jogadores[j].getNome() << endl;
		}
	}
}

void Empresa::relatorioFinanceiro(){
	int numTimes = times.size();
	for (int i = 0; i < numTimes; ++i)
	{
		float salarios = 0;
		float totalInss = 0;
		float totalIrrf = 0;

		vector<Jogador> jogadores = times[i].getJogadores();
		int numJogadores = jogadores.size();

		for (int j = 0; j < numJogadores; ++j)
		{
			float descontoInss = jogadores[j].calcularDescontoInss(jogadores[j].getSalarioBruto());
			salarios +=  jogadores[j].calcularSalarioLiquido(jogadores[j].getSalarioBruto());
			totalInss += descontoInss;
			totalIrrf += jogadores[j].calcularDescontoIrrf(jogadores[j].getSalarioBruto() - descontoInss);
		}

		cout << fixed;
		cout.precision(2);
		cout << "Time: " << times[i].getNome() << endl;
		cout << "Total Salarios: " << salarios << endl;
		cout << "Total INSS: " << totalInss << endl;
		cout << "Total IRRF: " << totalIrrf << endl;
		cout << endl;
	}
}

void Empresa::adicionarTime(Time time){
	times.push_back(time);
}