
#ifndef Agent_pso_h
#define Agent_pso_h

#include "Vect.h"

public class Agent_pso{

public:

	int id;					// udentificator unic
	int nr_tinte;

	bool deplasare;			// agentul se deplaseaza catre o tinta / sau calculeaza una noua
	Loc poz;				// locatia curenta
	Loc poz_dest;			// locatia destinatie

	Loc p_best;				// locatie optima - pana la momentul curent
	
	Vect vv;				// viteza agent

	float dir;				// dir unghi in radiani
	int dir_discret;		// < E = 0>, < N = 1 >, < V = 2 >, < S = 3 >

	Agent_pso();

};

#endif