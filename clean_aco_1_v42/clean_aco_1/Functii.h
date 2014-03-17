
#ifndef Functii_h
#define Functii_h

#include <iostream>
#include <iomanip>

#include "Vect.h"

//-----------------------------------------------------------------------------

bool harta_curata(int **);
bool loc_intern_harta(Loc *);

void print_map(int, int **);
void print_viz(int, int **);

void print_mat_nr(int **);
void print_mat_nr(float **);

int** load_map();
int** aloc_mat_int();
float** aloc_mat_float();

void zero_mat_int(int **);
void zero_mat_float(float **);

int rand_poz_valid(int, int, int **);

void new_coord_from_dir(int dir, int x, int  y, int *xt, int *yt);

//-----------------------------------------------------------------------------

float norm_unghi(float);

float rad_to_grad(float);
float grad_to_rad(float);

float angle_from_cathetus(float, float);

Vect* vect_add(Vect, Vect);
Loc* vect_add_loc(Loc, Vect *);

//-----------------------------------------------------------------------------

#endif