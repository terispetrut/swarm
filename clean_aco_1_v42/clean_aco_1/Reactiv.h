
#ifndef Reactiv_h
#define Reactiv_h

#include "stdafx.h"
#include "ag_reactiv.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <time.h> 
#include <cmath>

namespace clean_aco_1{
	ref class harta_gen_form;
}

public class Reactiv{

public:

	int M;					// numarul de roboti

	std::vector <ag_reactiv> arm;
	
	int d_coeziune;			// distanta
	int d_dispersie;
	int d_aliniere;

	float mag_coez;			// magnitude
	float mag_disp;
	float mag_alin;
	float mag_hist;			// past influence

	float u_coez;
	float u_disp;
	float u_alin;

	float rx_coez;
	float ry_coez;

	float rx_disp;
	float ry_disp;

	float rx_alin;
	float ry_alin;

	float u_nord;
	float u_sud;
	float u_est;
	float u_vest;

	float distanta_ag(ag_reactiv *, ag_reactiv *);
	float distanta(int, int, int, int);
	
	int **map;				// harta start
	int **viz;

	void run();

	int nr_tinte;
	int directie(ag_reactiv *);

	void load_coeziune(ag_reactiv *);
	void load_dispersie(ag_reactiv *);
	void load_aliniere(ag_reactiv *);
	
	void find_angle_acd();		// angle alignment cohesion dispersion

	void reset_rxy();
	void init_param();
	void step_ant(ag_reactiv *);

	Reactiv();
	
};

#endif