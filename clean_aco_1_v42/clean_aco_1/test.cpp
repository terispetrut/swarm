
#include "stdafx.h"
#include "test.h"

#include "Form1.h"
#include "ACO_form.h"
#include "PSO_form.h"
#include "MAS_form.h"
#include "generare_form.h"
#include "harta_gen_form.h"
#include "Reactiv_form.h"
#include "Rezultate_form.h"
#include "Statistici_form.h"

//=============================================================================

test tt;

//=============================================================================

test::test(){

	srand ((int)time(NULL));

	this->start_loc.x = 9;
	this->start_loc.y = 9;

	this->nr_cc = 20;
	this->nr_ll = 20;
	this->nr_agenti = 10;
	this->timp = 5;
	this->nr_obst = 15;
	this->nr_tinte = 30;
	this->nr_clusters = 1;

	this->nume_loc = "Temp_loc.txt";
}

//=============================================================================

void test::show_aco_form(){

	clean_aco_1::ACO_form ^f_aco = gcnew clean_aco_1::ACO_form();

	f_aco->Show();
}

//=============================================================================

void test::show_pso_form(){
	
	clean_aco_1::PSO_form ^f_pso = gcnew clean_aco_1::PSO_form();

	f_pso->Show();
}

//=============================================================================

void test::show_mas_form(){

	clean_aco_1::MAS_form ^f_mas = gcnew clean_aco_1::MAS_form();

	f_mas->Show();
}

//=============================================================================

void test::show_reactiv_form(){

	clean_aco_1::Reactiv_form ^f_react = gcnew clean_aco_1::Reactiv_form();

	f_react->Show();
}

//=============================================================================

void test::show_rezultate_form(){

	clean_aco_1::Rezultate_form ^f_rez = gcnew clean_aco_1::Rezultate_form();

	f_rez->Show();
}

//=============================================================================

void test::show_statistici_form(){

	clean_aco_1::Statistici_form ^f_stat = gcnew clean_aco_1::Statistici_form();

	f_stat->Show();
}

//=============================================================================

void test::show_generare_form(){

	clean_aco_1::generare_form ^f_gen = gcnew clean_aco_1::generare_form();

	f_gen->Show();
}

//=============================================================================

void test::show_harta_gen_form(){

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	hgf->color_map_init();
	hgf->reset_map();

	hgf->Show();
}

//=============================================================================

void test::zero_map(){

	for(int i = 0; i < this->nr_ll; i++){
		for(int j = 0; j < this->nr_cc; j++){
			this->map[i][j] = 0;
		}
	}
}

//=============================================================================

void test::aloc_map(){

	this->map = new int *[this->nr_ll];

	for(int i = 0; i < this->nr_ll; i++){
		this->map[i] = new int [this->nr_cc];
	}

	for(int i = 0; i < this->nr_ll; i++){
		for(int j = 0; j < this->nr_cc; j++){
			this->map[i][j] = 0;
		}
	}
}

//=============================================================================

void test::afis_map_1(){
	
	cout << "\n> Map \n";
	for(int i = 0; i < this->nr_ll; i++){
		for(int j = 0; j < this->nr_cc; j++){
			cout << this->map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//=============================================================================
// verifica daca locatia este in interiorul bordurii hartii  

bool test::loc_valid(Loc lc){

	if(lc.x < 1)
		return false;
	if(lc.x >= tt.nr_ll - 1)
		return false;

	if(lc.y < 1)
		return false;
	if(lc.y >= tt.nr_cc - 1)
		return false;

	return true;
}

//=============================================================================

int nr_vecin_2(Loc lc, int **a){

	int nr = 0;

	if(a[lc.x + 1][lc.y] == 2)
		nr++;
	if(a[lc.x - 1][lc.y] == 2)
		nr++;
	if(a[lc.x][lc.y - 1] == 2)
		nr++;
	if(a[lc.x][lc.y + 1] == 2)
		nr++;

	return nr;
}

//=============================================================================

void test::gen_random_map(){

	int ii, jj, nr_trg, nr_obst, ct_c, ct_l;

	nr_obst = this->nr_obst;
	nr_trg = this->nr_tinte;

	ct_c = this->nr_cc;
	ct_l = this->nr_ll;

	// bordare harta

	for(int i = 0 ; i < ct_l; i++){
		this->map[i][0] = 1;
		this->map[i][ct_c - 1] = 1;
	}

	for(int j = 0; j < ct_c; j++){
		this->map[0][j] = 1;
		this->map[ct_l - 1][j] = 1;
	}

	// obstacole plasate random

	while(nr_obst > 0){

		ii = rand() % this->nr_ll;
		jj = rand() % this->nr_cc;

		if(this->map[ii][jj] == 0){
			this->map[ii][jj] = 1;
			nr_obst--;
		}
	}

	// tinte plasate random

	while(nr_trg > 0){
		
		ii = rand() % ct_l;
		jj = rand() % ct_c;

		if(this->map[ii][jj] == 0){
			this->map[ii][jj] = 2;
			nr_trg--;
		}
	}
}

//=============================================================================

int test::valid_random_point(Loc *lc, int dist){

	int xx, yy, i1, i2, j1, j2;

	std::vector<Loc*> vc;

	xx = lc->x;
	yy = lc->y;

	i1 = Math::Max(0, xx - dist);
	i2 = Math::Min(tt.nr_ll, xx + dist);

	j1 = Math::Max(0, yy - dist);
	j2 = Math::Min(tt.nr_cc, yy + dist);

	for(int i = i1; i < i2; i++){
	
		for(int j = j1; j < j2; j++){
		
			if(tt.map[i][j] == 0){
				vc.push_back(new Loc(i, j));
			}
		}
	}

	if(vc.size() > 0){
		Loc *ll = vc.at(rand() % vc.size());
		tt.map[ll->x][ll->y] = 2;
		vc.clear();									// todo

		return 1;
	}
	else
		return 0;	
}

//=============================================================================

void test::gen_cluster_random(){

	int ii, jj, nr_trg, nr_obst, nr_cl, ct_c, ct_l, dif_tr,  dist, nr = 0;

	std::vector<Loc*> vc;		// vector cluster

	cout << "\n>>> test anomaly \n\n";
	tt.afis_map_1();

	//tt.zero_map();

	nr_obst = this->nr_obst;
	nr_trg = this->nr_tinte;
	nr_cl = this->nr_clusters;

	ct_c = this->nr_cc;
	ct_l = this->nr_ll;

	dif_tr = Math::Min(nr_cl, nr_trg);

	// bordare harta

	for(int i = 0 ; i < ct_l; i++){
		this->map[i][0] = 1;
		this->map[i][ct_c - 1] = 1;
	}

	for(int j = 0; j < ct_c; j++){
		this->map[0][j] = 1;
		this->map[ct_l - 1][j] = 1;
	}

	// obstacole plasate random

	while(nr_obst > 0){

		ii = rand() % this->nr_ll;
		jj = rand() % this->nr_cc;

		if(this->map[ii][jj] == 0){
			this->map[ii][jj] = 1;
			nr_obst--;
		}
	}

	tt.afis_map_1();

	// tinte plasate random in clustere

	while(dif_tr > 0){

		cout << ">> step 1\n";
		tt.afis_map_1();
		
		ii = rand() % ct_l;
		jj = rand() % ct_c;

		if(this->map[ii][jj] == 0){
			vc.push_back(new Loc(ii, jj));
			this->map[ii][jj] = 2;

			dif_tr--;
		}
	}

	if(dif_tr < nr_trg){		// mai sunt tinte de plasat

		cout << ">>> step 2\n";
		tt.afis_map_1();

		dif_tr = nr_trg - nr_cl;

		while(dif_tr > 0){
			dif_tr--;
			nr++;
			dist = 1;

			while(valid_random_point(vc.at(nr % vc.size()), dist) == 0){
				dist++;
			}
		}
	}
}

//=============================================================================

void test::gen_dfs_map(){
	
	int ii, jj, rr;
	int nr_trg = tt.nr_tinte;
	int ct_l = tt.nr_ll;
	int ct_c = tt.nr_cc;
	int **a = new int *[tt.nr_ll];

	for(int i = 0; i < tt.nr_ll; i++){
		a[i] = new int [tt.nr_cc];
	}

	for(int i = 0; i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){
			a[i][j] = 0;
		}
	}

	Loc *start = new Loc(tt.start_loc.x, tt.start_loc.y);

	std::vector<Loc*> vec;
	std::vector<Loc*> ran;

	vec.push_back(start);
	a[start->x][start->y] = 1;

	Loc *temp, *ln, *ls, *le, *lv;

	while(vec.size() > 0){
		
		temp = vec.back();
		vec.pop_back();

		if(nr_vecin_2(*temp, a) < 2){

			a[temp->x][temp->y] = 2;
		
			ln = new Loc(temp->x + 1, temp->y);
			ls = new Loc(temp->x - 1, temp->y);
			le = new Loc(temp->x, temp->y + 1);
			lv = new Loc(temp->x, temp->y - 1);

			if(this->loc_valid(*ln) && a[ln->x][ln->y] == 0){
				a[ln->x][ln->y] = 1;			
				ran.push_back(ln);
			}
			if(this->loc_valid(*ls) && a[ls->x][ls->y] == 0){
				a[ls->x][ls->y] = 1;			
				ran.push_back(ls);
			}
			if(this->loc_valid(*le) && a[le->x][le->y] == 0){
				a[le->x][le->y] = 1;
				ran.push_back(le);
			}
			if(this->loc_valid(*lv) && a[lv->x][lv->y] == 0){
				a[lv->x][lv->y] = 1;
				ran.push_back(lv);
			}

			while(ran.size() > 0){
				rr = rand() % ran.size();
				vec.push_back(ran.at(rr));
				ran.erase(ran.begin() + rr);
			}
		}
	}

	for(int i = 0;  i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){
			if(a[i][j] != 2){
				tt.map[i][j] = 1;
			}
		}
	}

	// adaugare tinte
	while(nr_trg > 0){
		
		ii = rand() % ct_l;
		jj = rand() % ct_c;

		if(this->map[ii][jj] == 0){
			this->map[ii][jj] = 2;
			nr_trg--;
		}
	}

	tt.afis_map_1();
}

//=============================================================================
