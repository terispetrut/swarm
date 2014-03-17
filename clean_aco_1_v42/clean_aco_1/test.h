#ifndef test_h
#define test_h

#include "stdafx.h"

#include "Functii.h"

#include "Reactiv.h"

#include "ACO.h"
#include "PSO.h"

#include "Loc.h"
#include "Rezultat.h"

#include <iostream>
#include <time.h> 
#include <msclr\marshal_cppstd.h>

using namespace std;

namespace clean_aco_1{

	ref class Form1;
	ref class ACO_form;
	ref class PSO_form;
	ref class MAS_form;
	ref class generare_form;
	ref class harta_gen_form;
	ref class Reactiv_form;
	ref class Rezultate_form;
	ref class Statistici_form;
}

public class test{

public:

	Reactiv ob_react;			// Agenti pur reactivi

	ACO alg_aco;				// aco algorithm / variants
	PSO alg_pso;				// variante algoritm PSO

	std::list <Rezultat> rez_aco;
	std::list <Rezultat> rez_pso;

	int **map;

	Loc start_loc;			// locatia de start, de unde pornesc agentii
	int timp;				// timp cautare, in secunde, pentru relocare tinte
	int nr_agenti;			// numar de agenti
	int nr_ll;				// numar de linii
	int nr_cc;				// numar de coloane
	int nr_obst;			// numar de obstacole
	int nr_tinte;			// numarul de tinte
	int nr_clusters;		// number of clusters

	bool loc_valid(Loc);
	std::string nume_loc;

	int harta_pas;			// afis evolutie pas cu pas automat
	int pas_cu_pas;			// afis pas cu pas doar prin next, la cerere
	int next_pas;			// decide daca pas_cu_pas la cerere

	void run_aco1();		// rulare trei modele ACO
	void run_aco2();
	void run_aco3();

	void aloc_map();
	void afis_map_1();

	void gen_random_map();
	void gen_cluster_random();

	int valid_random_point(Loc *lc, int dist);	// seteaza o tinta in raza dist a puctului lc

	void gen_dfs_map();
	void gen_cluster_dfs();

	void show_aco_form();
	void show_pso_form();
	void show_mas_form();
	void show_reactiv_form();
	void show_rezultate_form();
	void show_statistici_form();

	void show_generare_form();
	void show_harta_gen_form();

	void zero_map();

	test();

};

#endif