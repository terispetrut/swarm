
#include "stdafx.h"
#include "ant.h"

using namespace std;

void ant::print_mem(){
	
	cout << "Memorie ant < " << this->id << " > :\n";

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			cout << this->mem[i][j] << " ";
		}
		cout << "\n";
	}
}

void ant::init_mem(){
	
	for(int  i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			this->mem[i][j] = 0;
		}
	}
}

void ant::init_ant(){
	
}