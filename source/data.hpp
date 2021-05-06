#include <iostream> 
#include <time.h>

using namespace std;

class Data{
	private:
		int dia;
		int mes;
		int ano;
	public:
	 	Data();
		Data(int dia, int mes, int ano);

		int getDia();
		int getMes();
		int getAno();

		void setDia(int dia);
		void setMes(int mes);
		void setAno(int ano);

		string toString();
		static Data now();
};