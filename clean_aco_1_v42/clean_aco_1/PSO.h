
#ifndef PSO_h
#define PSO_h

#include <vector>

#include "Functii.h"
#include "Vect.h"
#include "Agent_pso.h"

using namespace std;

public class PSO{

public:

	std::vector<Agent_pso*> stol;		// grupul de agenti

	float pon_rand;			// interval pondere random

	float constr;			// factor de constrangere
	float ct_w;				// pondere viteza de la pasul anterior

	float fi1;				// constanta influenta personala
	float fi2;				// constanta influenta globala

	Loc opt_global;			// optim global

	int nr_tinte;			// nnumarul de tinte atinse

	int **map;				// harta start
	int **viz;				// locatii vizitate

	void init();			// initializare agenti si variabile algoritm

	void zbor_pasare_1(Agent_pso *);	// deplasare agent
	void zbor_stol_1();					// deplasare agenti
	void run_pso_1();					// rulare algoritm

	void zbor_pasare_2(Agent_pso *);	// deplasare agent
	void zbor_stol_2();					// deplasare agenti
	void run_pso_2();					// rulare algoritm

	void zbor_pasare_3(Agent_pso *);	// deplasare agent
	void zbor_stol_3();					// deplasare agenti
	void run_pso_3();					// rulare algoritm

	int dir_loc_loc(Loc, Loc*);

	PSO();
};

#endif