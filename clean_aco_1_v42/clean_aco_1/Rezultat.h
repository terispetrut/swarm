
#ifndef Rezultat_h
#define Rezultat_h

#include <string>
using namespace std;

public class Rezultat{

public:
	
	std::string tip;	// tipul de algoritm rulat
	
	int pasi;			// numar de iteratii
	int tinte;			// numar de tinte
	float timp;			// timp curatare
	float rel;			// metrica relativa la harta

	Rezultat();

};

#endif