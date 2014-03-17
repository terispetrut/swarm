
#ifndef ACO_h
#define ACO_h

#include "stdafx.h"
#include "ant.h"
#include "Functii.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <stdlib.h>
#include <time.h> 

namespace clean_aco_1{
	ref class harta_gen_form;
}

public class ACO{

public:

	int nr_bot;
	int M;			// numarul de roboti
	int Q;			// constanta feromon
	int L;			// lungime traseu
	float ro;		// rata de evaporare
	float alfa;		// constanta ...
	float beta;		// constanta ...

	float tmin;
	float tmax;

	float tau0;
	float fi;

	std::vector <ant> arm;	// grupul de furnici

	int nr_tinte;

	int **map;				// harta start
	int **viz;				// locatii vizitate
	int **prev;				// locatii actualizate
	float **fer;			// valori feromoni pe harta

	void init_param_aco1();
	void step_ant_aco1(ant*);
	void run_aco1();

	void init_param_aco2();
	void step_ant_aco2(ant*);
	void run_aco2();

	void init_param_aco3();
	void step_ant_aco3(ant*);
	void run_aco3();


	void step_ant_reloc_aco1(ant*);
	void run_reloc_aco1();
	
	void step_ant_reloc_aco2(ant*);
	void run_reloc_aco2();

	void step_ant_reloc_aco3(ant*);
	void run_reloc_aco3();

	void evaporare();
	void relocare_tinta();

	void get_max_poz(int x, int y, float prob[4], 
				 float **fer, int **map, int* xx, int* yy);
	
	ACO();
};

#endif