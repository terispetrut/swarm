
#include "stdafx.h"
#include "PSO.h"

#include "test.h"
#include "Functii.h"
#include "harta_gen_form.h"

extern test tt;

PSO::PSO(){
}

//=============================================================================

void PSO::init(){

	int x, y;

	this->constr = (float) 1;
	this->fi1 = (float) 0.5;
	this->fi2 = (float) 0.5;

	this->ct_w = (float) 0.9;

	this->pon_rand = 5;

	this->nr_tinte = 0;
	this->stol.clear();

	// initializare optim global

	x = rand() % tt.nr_ll;
	y = rand() % tt.nr_cc;

	while(this->map[x][y] != 0){		
		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;
	}

	this->opt_global.x = x;
	this->opt_global.y = y;

	//-------------------------------------------
	// initializare fiecare agent

	for(int i = 0; i < tt.nr_agenti; i++){

		Agent_pso *ag = new Agent_pso();

		ag->id = i;

		//---------------------------------------
		// locatia initiala

		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;

		while(this->map[x][y] != 0){		
			x = rand() % tt.nr_ll;
			y = rand() % tt.nr_cc;
		}

		ag->poz.x = x;
		ag->poz.y = y;

		this->map[x][y] = 3;

		// initializare optim local / personal
		ag->p_best.x = x;
		ag->p_best.y = y;

		//---------------------------------------
		// viteza initiala -> intre [-dim, +dim] -> 2 * dim - dim -> rand()

		x = rand() % (2 * tt.nr_ll - 2);
		y = rand() % (2 * tt.nr_cc - 2);

		ag->vv.rx = (float)(x - tt.nr_ll + 1) / 5;
		ag->vv.ry = (float)(y - tt.nr_cc + 1) / 5; 

		//---------------------------------------

		this->stol.push_back(ag);
	}
}

//=============================================================================

void PSO::zbor_pasare_1(Agent_pso *ap){			// Agent Pasare

	cout << "\n=================================================================\n";
	cout << ">>> Pasare [" << ap->poz.x << "][" << ap->poz.y << "] \t" << 
		" p_best [" << ap->p_best.x << "][" << ap->p_best.y << "] \t id <" << ap->id << " >\n";
	
	float r1, r2;

	Loc *rez;					// noua locatie a agentului
	Vect *vv = new Vect();		// viteza agentului

	r1 = (float)(rand() % 100) / 100;
	r2 = (float)(rand() % 100) / 100;

	cout << "> r1 = " << r1 << ", r2 = " << r2 << "\n";

	// formula algoritm de baza

	vv->ry = this->constr * (this->ct_w * ap->vv.ry + this->fi1 * r1 * (ap->p_best.x - ap->poz.x) +
		this->fi2 * r2 * (this->opt_global.x - ap->poz.x));

	vv->rx = this->constr * (this->ct_w * ap->vv.rx + this->fi1 * r1 * (ap->p_best.y - ap->poz.y) +
		this->fi2 * r2 * (this->opt_global.y - ap->poz.y));

	cout << "> vv = <" << vv->rx << "> <" << vv->ry << ">\n";

	// afla noua locatie stiind pozitia curenta si viteza
	rez = vect_add_loc(ap->poz, vv);

	cout << "> \t\t\t\t rez = [" << rez->x << "][" << rez->y << "]\n";

	//----------------------------------------------------------------------------

	if(loc_intern_harta(rez))

		if(this->map[rez->x][rez->y] != 1 && this->map[rez->x][rez->y] != 3){

			ap->vv.rx = vv->rx;
			ap->vv.ry = vv->ry;

			if(this->map[rez->x][rez->y] == 2){
				this->nr_tinte++;

				ap->p_best.x = rez->x;		// update optim propriu
				ap->p_best.y = rez->y;
			}
			
			this->map[ap->poz.x][ap->poz.y] = 0;
			ap->poz.x = rez->x;
			ap->poz.y = rez->y;
			this->map[rez->x][rez->y] = 3;
		}
}

//=============================================================================

void PSO::zbor_stol_1(){

	int x, y;

	for(int i = 0; i < tt.nr_agenti; i++){

		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;

		while(this->map[x][y] == 1){		
			x = rand() % tt.nr_ll;
			y = rand() % tt.nr_cc;
		}

		this->opt_global.x = x;
		this->opt_global.y = y;

		cout << "> \t\t\t\t\t optim global = [" << this->opt_global.x << "][" <<
			this->opt_global.y << "]\n";

		this->zbor_pasare_1(this->stol.at(i));
	}
}

//=============================================================================

void PSO::run_pso_1(){

	srand((int)time(NULL));

	this->map = load_map();
	this->viz = aloc_mat_int();

	this->init();

	int cnt = 0;
	clock_t t = clock();
	Rezultat *rez = new Rezultat();
	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}

	while(! harta_curata(this->map)){

		cnt++;
		cout << "> cnt = " << cnt << "\n";

		this->zbor_stol_1();

		// afis harta
		if(tt.harta_pas == 1){

			// afis harta la cerere < next >
			if(tt.pas_cu_pas == 1){

				Application::DoEvents();

				while(tt.next_pas == 0){
					Application::DoEvents();
					Sleep(100);
				}
				tt.next_pas = 0;
			}

			hgf->reset_this_map(this->map);

			Application::DoEvents();
		}
	}

	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "PSO 1";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_pso.push_back(*rez);
}

//=============================================================================

//=============================================================================

void PSO::zbor_pasare_2(Agent_pso *ap){			// Agent Pasare

	cout << "\n=================================================================\n";
	cout << ">>> Pasare [" << ap->poz.x << "][" << ap->poz.y << "] \t" << 
		" p_best [" << ap->p_best.x << "][" << ap->p_best.y << "] \t id <" << ap->id << " >\n";
	
	float r1, r2;

	Loc *rez;					// noua locatie a agentului
	Vect *vv = new Vect();		// viteza agentului

	r1 = (float)(rand() % 100) / 100;
	r2 = (float)(rand() % 100) / 100;

	//r1 = r1 * this->pon_rand - this->pon_rand / 2;
	//r2 = r2 * this->pon_rand - this->pon_rand / 2;

	cout << "> r1 = " << r1 << ", r2 = " << r2 << "\n";

	// formula algoritm de baza

	vv->ry = this->constr * (this->ct_w * ap->vv.ry + this->fi1 * r1 * (ap->p_best.x - ap->poz.x) +
		this->fi2 * r2 * (this->opt_global.x - ap->poz.x));

	vv->rx = this->constr * (this->ct_w * ap->vv.rx + this->fi1 * r1 * (ap->p_best.y - ap->poz.y) +
		this->fi2 * r2 * (this->opt_global.y - ap->poz.y));

	cout << "> vv = <" << vv->rx << "> <" << vv->ry << ">\n";

	// afla noua locatie stiind pozitia curenta si viteza
	rez = vect_add_loc(ap->poz, vv);

	cout << "> \t\t\t\t rez = [" << rez->x << "][" << rez->y << "]\n";

	//----------------------------------------------------------------------------

	if(loc_intern_harta(rez))

		if(this->map[rez->x][rez->y] != 1 && this->map[rez->x][rez->y] != 3){

			ap->vv.rx = vv->rx;
			ap->vv.ry = vv->ry;

			if(this->map[rez->x][rez->y] == 2){
				this->nr_tinte++;

				ap->nr_tinte++;

				ap->p_best.x = rez->x;		// update optim propriu
				ap->p_best.y = rez->y;
			}
			
			this->map[ap->poz.x][ap->poz.y] = 0;
			ap->poz.x = rez->x;
			ap->poz.y = rez->y;
			this->map[rez->x][rez->y] = 3;
		}
}

//=============================================================================

void PSO::zbor_stol_2(){

	int x, y, temp, ind = 0, max = 0;

	// alege agentul cu cele mai multe tinte atinse, folosind ultimul p_best
	for(int i = 0; i < tt.nr_agenti; i++){
	
		temp = this->stol.at(i)->nr_tinte;
		if(max < temp){
		
			max = temp;
			ind = i;
		}
	}

	this->opt_global.x = this->stol.at(ind)->p_best.x;
	this->opt_global.y = this->stol.at(ind)->p_best.y;

	if(max == 0){

		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;

		while(this->map[x][y] == 1){		
			x = rand() % tt.nr_ll;
			y = rand() % tt.nr_cc;
		}

		this->opt_global.x = x;
		this->opt_global.y = y;
	}

	cout << "> \t\t\t\t\t optim global = [" << this->opt_global.x << "][" <<
			this->opt_global.y << "]\n";

	for(int i = 0; i < tt.nr_agenti; i++){

		this->zbor_pasare_2(this->stol.at(i));
	}
}

//=============================================================================

void PSO::run_pso_2(){

	srand((int)time(NULL));

	this->map = load_map();
	this->viz = aloc_mat_int();

	this->init();

	int cnt = 0;
	clock_t t = clock();
	Rezultat *rez = new Rezultat();
	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}

	while(! harta_curata(this->map)){

		cnt++;
		cout << "> cnt = " << cnt << "\n";

		this->zbor_stol_2();

		// afis harta
		if(tt.harta_pas == 1){

			// afis harta la cerere < next >
			if(tt.pas_cu_pas == 1){

				Application::DoEvents();

				while(tt.next_pas == 0){
					Application::DoEvents();
					Sleep(100);
				}
				tt.next_pas = 0;
			}

			hgf->reset_this_map(this->map);

			Application::DoEvents();
		}
	}

	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "PSO 1";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_pso.push_back(*rez);
}

//=============================================================================

int PSO::dir_loc_loc(Loc org, Loc *trg){

	int rx, ry, dir = 0;
	
	ry = trg->x - org.x;
	rx = trg->y - org.y;

	if(rx >= 0 && ry >= 0){
		if(rx >= ry)
			dir = 0;
		else
			dir = 3;
	}
	else
		if(rx >= 0 && ry < 0){
			if(rx >= -ry)
				dir = 0;
			else
				dir = 1;
		}
		else
			if(rx < 0 && ry >= 0){
				if(-rx > ry)
					dir = 2;
				else
					dir = 3;
			}
			else
				if(rx < 0 && ry < 0){
					if(-rx > -ry)
						dir = 2;
					else
						dir = 1;
				}

	return dir;
}

//=============================================================================

void PSO::zbor_pasare_3(Agent_pso *ap){			// Agent Pasare

	cout << "\n=================================================================\n";
	cout << ">>> Pasare [" << ap->poz.x << "][" << ap->poz.y << "] \t" << 
		" p_best [" << ap->p_best.x << "][" << ap->p_best.y << "] \t id <" << ap->id << " >\n";
	
	int x, y, dir = 0, new_x, new_y;
	float r1, r2;

	if(ap->nr_tinte == 0){

		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;

		while(this->map[x][y] == 1){		
			x = rand() % tt.nr_ll;
			y = rand() % tt.nr_cc;
		}

		ap->p_best.x = x;
		ap->p_best.y = y;
	}

	Loc *rez;					// noua locatie a agentului
	Vect *vv = new Vect();		// viteza agentului

	r1 = (float)(rand() % 100) / 100;
	r2 = (float)(rand() % 100) / 100;

	//r1 = r1 * this->pon_rand - this->pon_rand / 2;
	//r2 = r2 * this->pon_rand - this->pon_rand / 2;

	cout << "> r1 = " << r1 << ", r2 = " << r2 << "\n";

	// formula algoritm de baza

	vv->ry = this->constr * (this->ct_w * ap->vv.ry + this->fi1 * r1 * (ap->p_best.x - ap->poz.x) +
		this->fi2 * r2 * (this->opt_global.x - ap->poz.x));

	vv->rx = this->constr * (this->ct_w * ap->vv.rx + this->fi1 * r1 * (ap->p_best.y - ap->poz.y) +
		this->fi2 * r2 * (this->opt_global.y - ap->poz.y));

	cout << "> vv = <" << vv->rx << "> <" << vv->ry << ">\n";

	// afla noua locatie stiind pozitia curenta si viteza
	rez = vect_add_loc(ap->poz, vv);

	cout << "> \t\t\t\t rez = [" << rez->x << "][" << rez->y << "]\n";

	dir = dir_loc_loc(ap->poz, rez);
	new_coord_from_dir(dir, ap->poz.x, ap->poz.y, &new_x, &new_y);
	
	cout << "\n>>> from [" << ap->poz.x << "][" << ap->poz.y <<
		"] to [" << rez->x << "][" << rez->y << "] go to <<< " << dir << " >>>\n\n";

	//----------------------------------------------------------------------------

		if(this->map[new_x][new_y] != 1 && this->map[new_x][new_y] != 3){

			ap->vv.rx = vv->rx;
			ap->vv.ry = vv->ry;

			if(this->map[new_x][new_y] == 2){
				this->nr_tinte++;

				ap->nr_tinte++;

				ap->p_best.x = new_x;		// update optim propriu
				ap->p_best.y = new_y;
			}
			
			this->map[ap->poz.x][ap->poz.y] = 0;
			ap->poz.x = new_x;
			ap->poz.y = new_y;
			this->map[new_x][new_y] = 3;
		}
		else{
			dir = rand_poz_valid(ap->poz.x, ap->poz.y, this->map);

			if(dir != 4){

				new_coord_from_dir(dir, ap->poz.x, ap->poz.y, &new_x, &new_y);

				ap->vv.rx = vv->rx;
				ap->vv.ry = vv->ry;

				if(this->map[new_x][new_y] == 2){
					this->nr_tinte++;

					ap->nr_tinte++;

					ap->p_best.x = new_x;		// update optim propriu
					ap->p_best.y = new_y;
				}
				
				this->map[ap->poz.x][ap->poz.y] = 0;
				ap->poz.x = new_x;
				ap->poz.y = new_y;
				this->map[new_x][new_y] = 3;
			}
		}
}

//=============================================================================

void PSO::zbor_stol_3(){

	int x, y, temp, ind = 0, max = 0;

	// alege agentul cu cele mai multe tinte atinse, folosind ultimul p_best
	for(int i = 0; i < tt.nr_agenti; i++){
	
		temp = this->stol.at(i)->nr_tinte;
		if(max < temp){
		
			max = temp;
			ind = i;
		}
	}

	this->opt_global.x = this->stol.at(ind)->p_best.x;
	this->opt_global.y = this->stol.at(ind)->p_best.y;

	if(max == 0){

		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;

		while(this->map[x][y] == 1){		
			x = rand() % tt.nr_ll;
			y = rand() % tt.nr_cc;
		}

		this->opt_global.x = x;
		this->opt_global.y = y;
	}

	cout << "> \t\t\t\t\t optim global = [" << this->opt_global.x << "][" <<
			this->opt_global.y << "]\n";

	for(int i = 0; i < tt.nr_agenti; i++){

		this->zbor_pasare_3(this->stol.at(i));
	}
}

//=============================================================================

void PSO::run_pso_3(){

	srand((int)time(NULL));

	this->map = load_map();
	this->viz = aloc_mat_int();

	this->init();

	int cnt = 0;
	clock_t t = clock();
	Rezultat *rez = new Rezultat();
	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}

	while(! harta_curata(this->map)){

		cnt++;
		cout << "> cnt = " << cnt << "\n";

		this->zbor_stol_3();

		// afis harta
		if(tt.harta_pas == 1){

			// afis harta la cerere < next >
			if(tt.pas_cu_pas == 1){

				Application::DoEvents();

				while(tt.next_pas == 0){
					Application::DoEvents();
					Sleep(100);
				}
				tt.next_pas = 0;
			}

			hgf->reset_this_map(this->map);

			Application::DoEvents();
		}
	}

	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "PSO 1";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_pso.push_back(*rez);
}

//=============================================================================