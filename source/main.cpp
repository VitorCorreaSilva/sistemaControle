#include "empresa.hpp"

int main(){
	//Jogador(string nome, Data dataNascimento, string nacionalidade, Categorias categoria, float salarioBruto);
	Jogador j1("vitor", Data(22,04,1990), "Brasil", PROFISSIONAL, 4690.54);
	Jogador j2("joao", Data(15,10,1984), "Argentina", PROFISSIONAL, 2450.54);
	Jogador j3("pedro", Data(22,9,2002), "Nigeria", PROFISSIONAL, 14690.00);
	Jogador j4("jose", Data(14,07,1993), "Chile", PROFISSIONAL, 4690.54);
	Jogador j5("lucas", Data(15,8,1994), "Brasil", PROFISSIONAL, 2450.54);
	
	Jogador j6("mateus", Data(03,06,1999), "Brasil", BASE, 2000.00);
	Jogador j7("rafael", Data(24,06,1998), "Argentina", BASE, 2000.00);
	Jogador j8("gabriel", Data(01,01,1984), "Peru", BASE, 2000.00);
	Jogador j9("francisco", Data(26,02,1991), "Colombia", BASE, 2000.00);
	Jogador j10("julio", Data(06,11,1990), "Russia", BASE, 2000.00);

	Jogador j11("andre", Data(26,12,1981), "Alemanha", PROFISSIONAL, 5400.54);
	Jogador j12("gustavo", Data(30,9,2002), "Espanha", PROFISSIONAL, 12000.00);
	Jogador j13("paulo", Data(26,12,1989), "Portugal", PROFISSIONAL, 5600.54);
	Jogador j14("saulo", Data(17,12,2004), "Inglaterra", PROFISSIONAL, 8000.00);
	Jogador j15("santiago", Data(30,9,2002), "Chile", PROFISSIONAL, 11000.00);

	//Time(string nome, Categorias categoria);
	Time t1("desenvolvedores futebol clube", PROFISSIONAL);

	Time t2("atletico clube vacionados", BASE);
	
	Time t3("unidos contra covid", PROFISSIONAL);

	//Empresa(string nome);
	Empresa empresa("UNIRITTER SPORTS");

	t1.adicionarJogador(j1);
	t1.adicionarJogador(j2);
	t1.adicionarJogador(j3);
	t1.adicionarJogador(j4);
	t1.adicionarJogador(j5);

	t2.adicionarJogador(j6);
	t2.adicionarJogador(j7);
	t2.adicionarJogador(j8);
	t2.adicionarJogador(j9);
	t2.adicionarJogador(j10);

	t3.adicionarJogador(j11);
	t3.adicionarJogador(j12);
	t3.adicionarJogador(j13);
	t3.adicionarJogador(j14);
	t3.adicionarJogador(j15);

	empresa.adicionarTime(t1);
	empresa.adicionarTime(t2);
	empresa.adicionarTime(t3);


	
	//cout << j1.calcularIdade(j1.getDataNascimento()) << endl;
	//j1.setIdadeAposentadoria(38);	
	//cout << j1.calcularTempoAposentadoria(j1.getIdadeAposentadoria()) << endl;
	//cout << j1.calcularSalarioLiquido(j1.getSalarioBruto()) << endl;

	//t1.relatorioGeral();
	//t1.relatorioFinanceiro();

	//empresa.consultarJogador("francisco");
	//empresa.consultarJogador(7);
	//empresa.listaJogadores();
	empresa.relatorioFinanceiro();

	



	return 0;
}