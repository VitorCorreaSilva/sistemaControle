#include "jogador.hpp"

int Jogador::ultimoIdJogador = 0;

Jogador::Jogador(){}

Jogador::Jogador(string nome, Data nascimento, string nacionalidade, Categorias categoria, float salarioBruto){
	this->nome = nome;
	this->id = gerarIdJogador();
	this->dataNascimento = nascimento;
	this->nacionalidade = nacionalidade;
	this->categoria = categoria;
	this->salarioBruto = salarioBruto;
}

string Jogador::getNome(){
	return nome;
}

int Jogador::getId(){
	return id;
}

Data Jogador::getDataNascimento(){
	return dataNascimento;
}

string Jogador::getNacionalidade(){
	return nacionalidade;
}

Categorias Jogador::getCategoria(){
	return categoria;
}

float Jogador::getSalarioBruto(){
	return salarioBruto;
}

void Jogador::setNome(string n){
	nome = n;
}

void Jogador::setId(int i){
	id = i;
}

void Jogador::setDataNascimento(int d, int m, int a){
	dataNascimento = Data(d, m, a);
}

void Jogador::setNacionalidade(string nac){
	nacionalidade = nac;
}

void Jogador::setCategoria(Categorias cat){
	categoria = cat;
}

void Jogador::setSalarioBruto(float salario){
	salarioBruto = salario;
}

float Jogador::calcularSalarioLiquido(float salarioBruto){
	float salarioLiquido = salarioBruto - calcularDescontoInss(salarioBruto);
	return salarioLiquido - calcularDescontoIrrf(salarioLiquido);
}

float Jogador::calcularDescontoInss(float salarioBruto){
	float inss;

	if(salarioBruto < 0){
		cout << "Insira um Salario Válido." << endl;
	}
	else if(salarioBruto <= 1100){
		inss = 7.5;
	}
	else if(salarioBruto <= 2000){
		inss = 9;
	}
	else if(salarioBruto <= 3100){
		inss = 12;
	}
	else if(salarioBruto <= 4100){
		inss = 14;
	}
	else{
		inss = 14;
	}

	return salarioBruto * (inss/100);
}

float Jogador::calcularDescontoIrrf(float salarioSemInss){
	float irrf;

	if(salarioSemInss < 0){
		cout << "Insira um Salario Válido." << endl;
	}
	else if(salarioSemInss <= 1100){
		irrf = 0;
	}
	else if(salarioSemInss <= 2000){
		irrf = 7.5;
	}
	else if(salarioSemInss <= 3100){
		irrf = 15;
	}
	else if(salarioSemInss <= 4100){
		irrf = 22;
	}
	else{
		irrf = 27;
	}

	return salarioSemInss * (irrf/100);
}

int Jogador::calcularIdade(Data dataNascimento){
	Data agora = Data::now();
	int idade = agora.getAno() - dataNascimento.getAno();
	int meses = agora.getMes() - dataNascimento.getMes();
	int dias = agora.getDia() - dataNascimento.getDia();

	if(meses < 0){
		idade--;
	}
	else if(meses == 0){
		if(dias < 0){
			idade--;
		}
	}

	return idade;
}

int Jogador::calcularTempoAposentadoria(Data dataNascimento){
	int idade =  calcularIdade(dataNascimento);
	return IDADE_APOSENTADORIA - idade;
}

void Jogador::mostrarDados(){
	cout << id << " - ";
	cout << nome << " - ";
	cout << nacionalidade << " - ";
	cout << dataNascimento.toString() << " - ";
	cout << categoria << endl;
}

int Jogador::gerarIdJogador(){
	ultimoIdJogador++;
	return ultimoIdJogador;
}