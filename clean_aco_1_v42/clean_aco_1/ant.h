#ifndef ant_h
#define ant_h

#include "stdafx.h"
#include <iostream>

public class ant{

public :

	int id;
	int nro;
	int poz_x;
	int poz_y;
	int mem[20][20];
	
	void init_mem();
	void init_ant();
	void print_mem();
};

#endif