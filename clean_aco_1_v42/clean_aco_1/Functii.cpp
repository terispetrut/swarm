
#include "stdafx.h"
#include "Functii.h"

#include "Reactiv.h"

#include "test.h"
extern test tt;

using namespace System;
using namespace std;

//=============================================================================

					/*			Matrix functions			 */

//=============================================================================

bool harta_curata(int **a){

	if(a == NULL)
		return false;

	for(int i = 0; i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){
			if(a[i][j] == 2){					// < 2 > = tinta
				return false;
			}
		}
	}
	return true;
}

//=============================================================================

int** load_map(){

	int **map;

	map = new int *[tt.nr_ll];

	for(int i = 0; i < tt.nr_ll; i++){
		map[i] = new int [tt.nr_cc];
	}

	for(int i = 0; i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){
			map[i][j] = tt.map[i][j];
		}
	}

	return map;
}

//=============================================================================

int** aloc_mat_int(){

	int **mat;

	mat = new int *[tt.nr_ll];

	for(int i = 0; i < tt.nr_ll; i++){
		mat[i] = new int [tt.nr_cc];
	}

	for(int i = 0; i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){
			mat[i][j] = 0;
		}
	}

	return mat;
}

//=============================================================================

float** aloc_mat_float(){

	float **mat;

	mat = new float *[tt.nr_ll];

	for(int i = 0; i < tt.nr_ll; i++){
		mat[i] = new float [tt.nr_cc];
	}

	for(int i = 0; i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){
			mat[i][j] = 0;
		}
	}

	return mat;
}

//=============================================================================

bool loc_intern_harta(Loc* lc){

	if(lc->x < 0)
		return false;
	if(lc->x >= tt.nr_ll)
		return false;

	if(lc->y < 0)
		return false;
	if(lc->y >= tt.nr_cc)
		return false;

	return true;
}

//=============================================================================

void print_map(int tip, int **map){

	cout << "> Map: \n";
	int v;

	for(int i = 0; i < tt.nr_ll; i++){

		for(int j = 0; j < tt.nr_cc; j++){

			v = map[i][j];

			if(tip == 0){				
				if(v == 0)
					cout << "_ ";
				if(v == 1)
					cout << "# ";
				if(v == 2)
					cout << "@ ";
				if(v == 3)
					cout << "* ";
			}
			else
				cout << v << " ";
		}
		cout << "\n";
	}
}

//=============================================================================

void print_viz(int tip, int **viz){

	cout << "> Viz: \n";
	int v;

	for(int i = 0; i < tt.nr_ll; i++){

		for(int j = 0; j < tt.nr_cc; j++){

			v = viz[i][j];

			if(tip == 1){
				if(v == 0){
					cout << "_ ";
				}
				if(v == 1){
					cout << "x ";
				}
			}
			else{
				cout << v << " ";
			}
		}
		cout << "\n";
	}
}

//=============================================================================

void print_mat_nr(int **mat){
	
	cout << "\n";

	for(int i = 0; i < tt.nr_ll; i++){

		for(int j = 0; j < tt.nr_cc; j++){

			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

//=============================================================================

void print_mat_nr(float **mat){

	cout << "\n";
	
	for(int i = 0; i < tt.nr_ll; i++){

		for(int j = 0; j < tt.nr_cc; j++){

			cout << (int)mat[i][j] << " ";			// std::setprecision(2)
		}
		cout << "\n";
	}
	cout << "\n";
}

//=============================================================================

void zero_mat_int(int **mat){

	for(int i = 0; i < tt.nr_ll; i++){

		for(int j = 0; j < tt.nr_cc; j++){

			mat[i][j] = 0;
		}
	}
}

//=============================================================================

void zero_mat_int(float **mat){

	for(int i = 0; i < tt.nr_ll; i++){

		for(int j = 0; j < tt.nr_cc; j++){

			mat[i][j] = 0;
		}
	}
}

//=============================================================================

void new_coord_from_dir(int dir, int x, int  y, int *xt, int *yt){

	if(dir == 0){							// <<< EST >>>
		*xt = x;			*yt = y + 1;
	}
	if(dir == 1){							// <<< NORD >>>
		*xt = x - 1;		*yt = y;
	}
	if(dir == 2){							// <<< VEST >>>
		*xt = x;			*yt = y - 1;
	}
	if(dir == 3){							// <<< SUD >>>
		*xt = x + 1;		*yt = y;
	}
}

//=============================================================================

int rand_poz_valid(int x, int y, int **map){

	int r_val = 4;

	std::vector <int> v_rand;

		if(map[x][y + 1] == 0 || map[x][y + 1] == 2){
			v_rand.push_back(0);
		}
		if(map[x - 1][y] == 0 || map[x - 1][y] == 2){
			v_rand.push_back(1);
		}
		if(map[x][y - 1] == 0 || map[x][y - 1] == 2){
			v_rand.push_back(2);
		}
		if(map[x + 1][y] == 0 || map[x + 1][y] == 2){
			v_rand.push_back(3);
		}

		if(v_rand.size() > 0){
			r_val = v_rand.at(rand() % v_rand.size());
		}

		return r_val;
}

//=============================================================================

					/*			Vector				*/ 

//=============================================================================

float norm_unghi(float u){
	
	if(u < 0){
		while(u < 0){
			u = u + 2 * (float)Math::PI;
		}
	} else

	while(u > 2 * Math::PI){
		u = u - 2 * (float)Math::PI;
	}
	
	return u;
}

//=============================================================================

float rad_to_grad(float rd){

	return rd / (float)Math::PI * 180;
}

float grad_to_rad(float gr){

	return gr / 180 * (float)Math::PI;
}

//=============================================================================

Vect* vect_add(Vect p, Vect q){

	Vect *v = new Vect();

	float rx, ry;

	rx = p.mag * (float)Math::Cos(p.dir) + q.mag * (float)Math::Cos(q.dir);
	ry = p.mag * (float)Math::Sin(p.dir) + q.mag * (float)Math::Sin(q.dir);

	v->rx = rx;
	v->ry = ry;

	// directia - unghiul format de vector in sistem cartezian
	if(rx == 0){
		if(ry >= 0)
			v->dir = (float)Math::PI / 2;
		if(ry < 0)
			v->dir = - (float)Math::PI / 2;
	}
	else{
		v->dir = (float)Math::Atan(ry / rx);
	}

	// magnitudinea vectorului
	v->mag = (float)Math::Sqrt(rx * rx + ry * ry);
	
	// punctul de origine (originea primului vector - poate fi ralativ)
	v->org->x = p.org->x;
	v->org->y = p.org->y;

	// varful vectorului
	v->vf->x = p.org->x + (int)(v->mag * (float)Math::Cos(v->dir));
	v->vf->y = p.org->y + (int)(v->mag * (float)Math::Sin(v->dir));

	return v;
}

//=============================================================================

Loc* vect_add_loc(Loc lc, Vect *v){

	Loc *rez = new Loc();

	rez->x = lc.x + (int)v->ry;
	rez->y = lc.y + (int)v->rx;

	return rez;
}

//=============================================================================

float angle_from_cathetus(float rx, float ry){

	float rez, tmp;
	float xx, yy;

	if(rx < 0)
		xx = -rx;
	if(ry < 0)
		yy = -ry;

	if(rx == 0){
		if(ry >= 0)
			rez = (float) Math::PI / 2;
		else
			rez = (float) (3 * Math::PI / 2);
	}
	else{
		tmp = (float) Math::Atan(yy / xx);
		
		if(rx > 0 && ry >= 0)						// C1
			rez = tmp;

		if(rx > 0 && ry < 0)						// C4
			rez = (float) (2 * Math::PI - tmp);

		if(rx < 0 && ry >= 0)						// C2
			rez = (float) Math::PI - tmp;

		if(rx < 0 && ry < 0)						// C3
			rez = (float) Math::PI + tmp;
	}

	return rez;
}

//=============================================================================