
#include "stdafx.h"
#include "Reactiv.h"

#include "test.h"
#include "harta_gen_form.h"

using namespace std;

//=============================================================================

extern test tt;

Reactiv::Reactiv(){
}

//=============================================================================

void Reactiv::init_param(){

	this->M = tt.nr_agenti;
	this->nr_tinte = 0;

	this->d_aliniere = 20;
	this->d_coeziune = 20;
	this->d_dispersie = 20;

	this->mag_hist = 5;

	this->mag_alin = 50;
	this->mag_coez = 5;
	this->mag_disp = 1;
}

//=============================================================================

// distance between two points 

float Reactiv::distanta(int x1, int y1, int x2, int y2){

	return (float)Math::Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

//=============================================================================

// distance between two agents

float Reactiv::distanta_ag(ag_reactiv *ag1, ag_reactiv *ag2){

	return (float)Math::Sqrt((ag1->x - ag2->x) * (ag1->x - ag2->x)
		+ (ag1->y - ag2->y) * (ag1->y - ag2->y));
}

//=============================================================================

void Reactiv::load_coeziune(ag_reactiv *ag){

	int sx = 0, sy = 0, nr = 0;
	float cx, cy;				// centru de greutate

	for(int i = 0; i < this->M; i++){

		if(this->distanta_ag(ag, &(this->arm[i])) <= this->d_coeziune){
		
			sx += this->arm[i].x;
			sy += this->arm[i].y;
			nr++;
		}
	}
	cx = (float) sx / nr;		// center of gravity for cohesion
	cy = (float) sy / nr;

	this->ry_coez = (float)ag->x - cx;	// vector influence of cohesion
	this->rx_coez = (float)ag->y - cy;
}

//=============================================================================

void Reactiv::load_dispersie(ag_reactiv *ag){

	int sx = 0, sy = 0, nr = 0;
	float cx, cy;				// centru de greutate

	for(int i = 0; i < this->M; i++){

		if(this->distanta_ag(ag, &(this->arm[i])) <= this->d_dispersie){
		
			sx += this->arm[i].x;
			sy += this->arm[i].y;
			nr++;
		}
	}
	cx = (float) sx / nr;
	cy = (float) sy / nr;

	this->ry_disp = -((float)ag->x - cx);	// negam pentru a obtine punctul simetric
	this->rx_disp = -((float)ag->y - cy);
}

//=============================================================================

void Reactiv::load_aliniere(ag_reactiv *ag){

	for(int i = 0; i < this->M; i++){

		if(this->distanta_ag(ag, &(this->arm[i])) <= this->d_aliniere){
		
			this->rx_alin += cos(this->arm[i].unghi);
			this->ry_alin += sin(this->arm[i].unghi);
		}
	}
}

//=============================================================================

void Reactiv::reset_rxy(){

	this->rx_alin = 0;
	this->rx_coez = 0;
	this->rx_disp = 0;

	this->ry_alin = 0;
	this->ry_coez = 0;
	this->ry_disp = 0;
}

//=============================================================================

int Reactiv::directie(ag_reactiv *ag){

	if(ag->unghi >= 5.49778 || ag->unghi < 0.78539)
		return 0;
	if(ag->unghi >= 0.78538 && ag->unghi < 2.35619 )
		return 1;
	if(ag->unghi >= 2.35619 && ag->unghi < 3.92699 )
		return 2;
	if(ag->unghi >= 3.92699 && ag->unghi < 5.49778 )
		return 3;

	return 4;
}

//=============================================================================

void Reactiv::find_angle_acd(){
	
	this->u_alin = angle_from_cathetus(this->rx_alin, this->ry_alin);

	this->u_coez = angle_from_cathetus(this->rx_coez, this->ry_coez);

	this->u_disp = angle_from_cathetus(this->rx_disp, this->ry_disp);	
}

//=============================================================================

//=============================================================================

void Reactiv::step_ant(ag_reactiv* ag){

	this->reset_rxy();

	int x = ag->x;			// current location
	int y = ag->y;

	int xx = x, yy = y;			// final location
	int xt = x, yt = y;			// temp coord

	int rez_directie;
	int rand_val = -1;

	float rx = 0, ry = 0;		// vector projections

	this->load_coeziune(ag);
	this->load_dispersie(ag);
	this->load_aliniere(ag);

	cout << "> rxy_alin: "<< this->rx_alin << ", " << this->ry_alin << "\n";
	cout << "> rxy_coez: "<< this->rx_coez << ", " << this->ry_coez << "\n"; 
	cout << "> rxy_disp: "<< this->rx_disp << ", " << this->ry_disp << "\n"; 

	this->u_alin = angle_from_cathetus(this->rx_alin, this->ry_alin);
	this->u_coez = angle_from_cathetus(this->rx_coez, this->ry_coez);
	this->u_disp = angle_from_cathetus(this->rx_disp, this->ry_disp);	

	cout << "\n>>> u_alin = " << u_alin << ", u_coez = " << u_coez << 
		", u_disp = " << u_disp << "\n"; 

	rx	=	this->mag_alin * cos(this->u_alin) / 100 +
			this->mag_coez * cos(this->u_coez) / 100 +
			this->mag_disp * cos(this->u_disp) / 100 +
			this->mag_hist * cos(ag->unghi) / 100;

	ry	=	this->mag_alin * sin(this->u_alin) / 100 +
			this->mag_coez * sin(this->u_coez) / 100 +
			this->mag_disp * sin(this->u_disp) / 100 +
			this->mag_hist * sin(ag->unghi) / 100;

	cout << "\n>>> rx = " << rx << ", ry = " << ry << "\n";

	ag->unghi = angle_from_cathetus(rx, ry);
	ag->unghi = norm_unghi(ag->unghi);

	rez_directie = this->directie(ag);

	cout << "\n>>> \t DIRECTIE = <<< " << rez_directie << " >>>\n\n";

	if(rez_directie == 4){
		cout << "\n\n >>> ERROR !!! (dir = 4) \n\n\n";
	}

	new_coord_from_dir(rez_directie, x, y, &xt, &yt);
	
	if(this->map[xt][yt] == 0 || this->map[xt][yt] == 2){
		xx = xt;
		yy = yt;
	}
	else{

		/* pick a random valid place */
		rand_val = rand_poz_valid(x, y, this->map);

		if(rand_val == 0){							// <<< EST >>>
			xx = x;			yy = y + 1;
			ag->unghi = (float) 0;
		}
		if(rand_val == 1){							// <<< NORD >>>
			xx = x - 1;		yy = y;
			ag->unghi = (float) 1.55;
		}
		if(rand_val == 2){							// <<< VEST >>>
			xx = x;			yy = y - 1;
			ag->unghi = (float) 3.14;
		}
		if(rand_val == 3){							// <<< SUD >>>
			xx = x + 1;		yy = y;
			ag->unghi = (float) 4.65;
		}
	}

	cout << "\n>>> \t\t\t Unghi FINAL = <<< " << ag->unghi << " >>>\n";
	cout << "===========================================================\n";

	if(this->map[xx][yy] == 2){
		this->nr_tinte++;
	}

	this->map[x][y] = 0;
	this->map[xx][yy] = 3;

	ag->x = xx;
	ag->y = yy;

	this->viz[xx][yy]++;
}

//=============================================================================

void Reactiv::run(){

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t = clock();
	int cnt = 0;
	srand ((int)time(NULL));

	this->init_param();

	this->map = load_map();
	this->viz = aloc_mat_int();

	print_map(1, this->map);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}
	
	for(int i = 0; i < this->M; i++){

		ag_reactiv att;
		att.id = i;
		att.x = tt.start_loc.x;
		att.y = tt.start_loc.y;
		att.unghi = (float)(2 * Math::PI * (rand() % 100) / 100);
		this->arm.push_back(att);
	}

	//-------------------------------------------------------------------------

	// itereaza pana harta devine curata
	while(! harta_curata(this->map)){

		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){
			this->step_ant(&this->arm.at(k));
		}

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

		// necesar ???
		for(int k = 0; k < this->M; k++){
			this->map[this->arm.at(k).x][this->arm.at(k).y] = 3;			
		}

		print_map(0, this->map);
		print_viz(1, this->viz);
	}
	
	if(1 == 1){
		print_map(0, this->map);
		print_viz(1, this->viz);
	}
	
	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "reactiv";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================