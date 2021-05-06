#include "time.hpp"

int Time::ultimoIdTime = 0;

Time::Time(){}

Time::Time(string nome, Categorias categoria){
	this->nome = nome;
	this->categoria = categoria;
	this->id = gerarIdTime();
}

int Time::getId(){
	return id;
}

string Time::getNome(){
	return nome;
}

Categorias Time::getCategoria(){
	return categoria;
}

vector<Jogador> Time::getJogadores(){
	return jogadores;
}

void Time::setId(int id){
	this->id = id;
}

void Time::setNome(string nome){
	this->nome = nome;
}

void Time::setCategoria(Categorias categoria){
	this->categoria = categoria;
}

void Time::setJogadores(vector<Jogador> jogadores){
	/*
	std::move é usado para indicar que um objeto t pode ser "movido de", 
	ou seja, permitindo a transferência eficiente de recursos de t para outro objeto.
	*/
	this->jogadores = move(jogadores);
}

void Time::adicionarJogador(Jogador jogador){
	jogadores.push_back(jogador);
}

void Time::relatorioGeral(){
	int numeroJogadores = jogadores.size();

	cout << nome << endl;
	for (int i = 0; i < numeroJogadores; ++i)
	{
		jogadores[i].mostrarDados();
	}
}

void Time::buscarJogador(int id){
	int numJogadores = jogadores.size();
	for (int i = 0; i < numJogadores; ++i)
	{
		if(jogadores[i].getId() == id){
			jogadores[i].mostrarDados();
		}
	}
}

void Time::buscarJogador(string nome){
	int numJogadores = jogadores.size();
	for (int i = 0; i < numJogadores; ++i)
	{
		if(jogadores[i].getNome() == nome){
			jogadores[i].mostrarDados();
		}
	}
}

void Time::relatorioFinanceiro(){
	int numeroJogadores = jogadores.size();

	for (int i = 0; i < numeroJogadores; ++i)
	{
		cout << jogadores[i].getNome() << " - ";
		cout << jogadores[i].getSalarioBruto() << " - ";
		cout << jogadores[i].calcularSalarioLiquido(jogadores[i].getSalarioBruto()) << endl;
	}
}

int Time::gerarIdTime(){
	ultimoIdTime++;
	return ultimoIdTime;
}