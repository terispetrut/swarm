
#include "stdafx.h"
#include "ACO.h"
#include "test.h"
#include "harta_gen_form.h"

using namespace std;

//=============================================================================

extern test tt;

ACO::ACO(){
}

/*===========================================================================*/

void ACO::init_param_aco1(){

	this->L = 10;
	this->M = 10;
	this->Q = 20;
	this->ro = (float)0.3;
	this->alfa = (float)0.5;
	this->beta = (float)0.5;

	this->nr_tinte = 0;
}

//=============================================================================

void ACO::init_param_aco2(){

	this->L = 10;
	this->M = 10;
	this->Q = 20;
	this->ro = (float)0.3;
	this->alfa = (float)0.5;
	this->beta = (float)0.5;
	this->tmin = (float)1;
	this->tmax = (float)3;

	this->nr_tinte = 0;
}

//=============================================================================

void ACO::init_param_aco3(){

	this->L = 10;
	this->M = 10;
	this->Q = 20;
	this->ro = (float)0.3;
	this->alfa = (float)0.5;
	this->beta = (float)0.5;
	this->tau0 = (float)5;
	this->fi = (float)0.2;

	this->nr_tinte = 0;
}

//=============================================================================

void ACO::get_max_poz(int x, int y, float prob[4], 
				 float **fer, int **map, int* xx, int* yy){

	int valid[4];
	int vmax[4];
	int i, rr, ind = 0, nrm = 0;
	float pmin = 10000;
	
	for(i = 0; i < 4; i++){
		valid[i] = 0;
		vmax[i] = 0;
	}

	// verifica daca locatia e valida
	if(map[x - 1][y] == 0 || map[x - 1][y] == 2){
		valid[0] = 1;
	}
	if(map[x + 1][y] == 0 || map[x + 1][y] == 2){
		valid[1] = 1;
	}
	if(map[x][y + 1] == 0 || map[x][y + 1] == 2){
		valid[2] = 1;
	}
	if(map[x][y - 1] == 0 || map[x][y - 1] == 2){
		valid[3] = 1;
	}

	// cauta minim
	for(i = 0; i < 4; i++){
		if(pmin > prob[i] && valid[i] == 1){
			pmin = prob[i];
		}
	}

	// minim multiplu
	for(i = 0; i < 4; i++){
		if(prob[i] == pmin && valid[i] == 1){
			vmax[i] = 1;
			nrm++;
		}
	}

	if(nrm != 0){

		rr = rand() % nrm;

		// alege random un minim
		for(i = 0; i < 4; i++){
			if(vmax[i] == 1){
				if(rr == 0){
					ind = i;
					break;
				}
				else{
					rr--;
				}
			}
		}

		// alege noile coordonate
		if(ind == 0){
			(*xx) = x - 1;
			(*yy) = y;
		}
		if(ind == 1){
			(*xx) = x + 1;
			(*yy) = y;
		}
		if(ind == 2){
			(*xx) = x;
			(*yy) = y + 1;
		}
		if(ind == 3){
			(*xx) = x;
			(*yy) = y - 1;
		}
	}
	else{
		(*xx) = x;
		(*yy) = y;
	}
}

//=============================================================================

void ACO::step_ant_aco1(ant* a){

	int x = a->poz_x;
	int y = a->poz_y;

	int xx = x, yy = y;
	float prob[4];

	float fn, fs, fe, fv;		// valoare feromoni la n, s, e, v de furnica < a >
	float pn, ps, pe, pv;

	fn = this->fer[x - 1][y];
	fs = this->fer[x + 1][y];
	fe = this->fer[x][y + 1];
	fv = this->fer[x][y - 1];

	float sf = fn + fs + fe + fv;

	if(sf == 0){
		pn = ps = pe = pv = 0;
	}
	else{
		pn = fn / sf;
		ps = fs / sf;
		pe = fe / sf;
		pv = fv / sf;
	}

	// seteaza vectorul de probabilitati
	prob[0] = pn;
	prob[1] = ps;
	prob[2] = pe;
	prob[3] = pv;

	// apel functie pentru locatia cu cea mai mica urma de feromoni
	get_max_poz(x, y, prob, this->fer, this->map, &xx, &yy);

	this->prev[xx][yy] = 1;		// locatia curenta va fi acualizata (feromoni)

	// noua valoare a urmei de feromoni
	float new_f = (float)(this->Q / this->L);

	this->fer[xx][yy] = (1 - this->ro) * this->fer[xx][yy] + new_f;
	this->map[xx][yy] = 3;		// miscare furnica in noua locatie
	this->map[x][y] = 0;

	a->mem[xx][yy] = 1;
	a->poz_x = xx;
	a->poz_y = yy;
	this->viz[xx][yy] = 1;
}

//=============================================================================

void ACO::evaporare(){		// pentru locatiile care nu au fost deja actualizate
	
	for(int i = 0; i < tt.nr_ll; i++){
		for(int j = 0; j < tt.nr_cc; j++){

			if(this->prev[i][j] == 0){
				this->fer[i][j] = (1 - this->ro) * this->fer[i][j];
			}
		}
	}
}

//=============================================================================

void ACO::run_aco1(){

	cout << "Procesare aco1: \n";

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t = clock();
	int cnt = 0;
	srand ((int)time(NULL));

	this->init_param_aco1();

	this->map = load_map();

	this->fer = aloc_mat_float();
	this->viz = aloc_mat_int();
	this->prev = aloc_mat_int();

	this->fer[1][1] = 9;

	print_map(1, this->map);
	print_mat_nr(this->fer);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}
	
	arm.clear();	// reset armata furnici

	for(int i = 0; i < this->M; i++){

		ant att;
		att.id = i;
		att.poz_x = 1;
		att.poz_y = 1;
		att.init_mem();
		this->arm.push_back(att);
	}

	//-------------------------------------------------------------------------

	// itereaza pana harta devine curata
	while(! harta_curata(this->map)){
		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){

			this->step_ant_aco1(&this->arm.at(k));

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

		// < ??? > verifica redundanta
		for(int k = 0; k < this->M; k++){
			this->map[this->arm.at(k).poz_x][this->arm.at(k).poz_y] = 3;
		}

		this->evaporare();

		zero_mat_int(this->prev);
	}

	//-------------------------------------------------------------------------

	if(1 == 1){	
		print_map(0, this->map);
		print_mat_nr(this->fer);
		print_viz(1, this->viz);
	}
	
	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "aco1";
	rez->tinte = tt.nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================

void ACO::step_ant_aco2(ant* a){

	int x = a->poz_x;
	int y = a->poz_y;
	int xx = x, yy = y;
	float prob[4];

	float fn, fs, fe, fv;
	float pn, ps, pe, pv;

	fn = this->fer[x - 1][y];
	fs = this->fer[x + 1][y];
	fe = this->fer[x][y + 1];
	fv = this->fer[x][y - 1];

	float sf = fn + fs + fe + fv;

	if(sf == 0){
		pn = ps = pe = pv = 0;
	}
	else{
		pn = fn / sf;
		ps = fs / sf;
		pe = fe / sf;
		pv = fv / sf;
	}

	// seteaza vectorul de probabilitati
	prob[0] = pn;
	prob[1] = ps;
	prob[2] = pe;
	prob[3] = pv;

	// apel functie pentru locatia cu cea mai mica urma de feromoni
	get_max_poz(x, y, prob, this->fer, this->map, &xx, &yy);

	// noua valoare a urmei de feromoni
	float new_f = (1 - this->ro) * this->fer[xx][yy] + this->Q / this->L;
	if(new_f < this->tmin){
		new_f = this->tmin;
	}
	if(new_f > this->tmax){
		new_f = this->tmax;
	}

	this->fer[xx][yy] = new_f;
	this->map[xx][yy] = 3;
	this->map[x][y] = 0;
	a->mem[xx][yy] = 1;
	a->poz_x = xx;
	a->poz_y = yy;
	this->viz[xx][yy] = 1;
}

//=============================================================================

void ACO::run_aco2(){

	cout << "Procesare aco1: \n";

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t = clock();
	int cnt = 0;
	srand ((int)time(NULL));

	this->init_param_aco2();

	this->map = load_map();

	this->fer = aloc_mat_float();
	this->viz = aloc_mat_int();
	this->prev = aloc_mat_int();

	this->fer[1][1] = 8;

	print_map(1, this->map);
	print_mat_nr(this->fer);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}
	
	arm.clear();		// reset armata furnici

	for(int i = 0; i < this->M; i++){

		ant tt;
		tt.id = i;
		tt.poz_x = 1;
		tt.poz_y = 1;
		tt.init_mem();
		this->arm.push_back(tt);
		//arm.push_back(tt);
	}

	// itereaza pana harta devine curata
	while(! harta_curata(this->map)){
		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){
			this->step_ant_aco2(&this->arm.at(k));
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

		for(int k = 0; k < this->M; k++){
			this->map[this->arm.at(k).poz_x][this->arm.at(k).poz_y] = 3;
		}
	}
	
	if(1 == 1){
		print_map(0, this->map);
		print_mat_nr(this->fer);
		print_viz(1, this->viz);
	}

	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "aco2";
	rez->tinte = tt.nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================

void ACO::step_ant_aco3(ant* a){

	int x = a->poz_x;
	int y = a->poz_y;
	int xx = x, yy = y;
	float prob[4];

	float fn, fs, fe, fv;
	float pn, ps, pe, pv;

	fn = this->fer[x - 1][y];
	fs = this->fer[x + 1][y];
	fe = this->fer[x][y + 1];
	fv = this->fer[x][y - 1];

	float sf = fn + fs + fe + fv;

	if(sf == 0){
		pn = ps = pe = pv = 0;
	}
	else{
		pn = fn / sf;
		ps = fs / sf;
		pe = fe / sf;
		pv = fv / sf;
	}

	// seteaza vectorul de probabilitati
	prob[0] = pn;
	prob[1] = ps;
	prob[2] = pe;
	prob[3] = pv;

	// apel functie pentru locatia cu cea mai mica urma de feromoni
	get_max_poz(x, y, prob, this->fer, this->map, &xx, &yy);

	// noua valoare a urmei de feromoni
	float new_f = (1 - this->fi) * this->fer[xx][yy] + this->fi * this->tau0;

	this->fer[xx][yy] = new_f;
	this->map[xx][yy] = 3;
	this->map[x][y] = 0;

	a->mem[xx][yy] = 1;
	a->poz_x = xx;
	a->poz_y = yy;
	this->viz[xx][yy] = 1;
}

//=============================================================================

void ACO::run_aco3(){

	cout << "Procesare aco3: \n";

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t = clock();
	int cnt = 0;
	srand ((int)time(NULL));

	this->init_param_aco3();

	this->map = load_map();

	this->fer = aloc_mat_float();
	this->viz = aloc_mat_int();
	this->prev = aloc_mat_int();

	this->fer[1][1] = 7;

	print_map(1, this->map);
	print_mat_nr(this->fer);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}
	
	arm.clear();		//reset armata furnici

	for(int i = 0; i < this->M; i++){
		ant att;
		att.id = i;
		att.poz_x = 1;
		att.poz_y = 1;
		att.init_mem();
		this->arm.push_back(att);
	}

	//-------------------------------------------------------------------------

	// itereaza pana harta devine curata
	while(! harta_curata(this->map)){
		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){
			this->step_ant_aco3(&this->arm.at(k));
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
			this->map[this->arm.at(k).poz_x][this->arm.at(k).poz_y] = 3;			
		}
	}
	
	if(1 == 1){
		print_map(0, this->map);
		print_mat_nr(this->fer);
		print_viz(1, this->viz);
	}
	
	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "aco3";
	rez->tinte = tt.nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================

void ACO::step_ant_reloc_aco1(ant* a){

	int x = a->poz_x;
	int y = a->poz_y;

	int xx = x, yy = y;
	float prob[4];

	float fn, fs, fe, fv;		// valoare feromoni la n, s, e, v de furnica < a >
	float pn, ps, pe, pv;

	fn = this->fer[x - 1][y];
	fs = this->fer[x + 1][y];
	fe = this->fer[x][y + 1];
	fv = this->fer[x][y - 1];

	float sf = fn + fs + fe + fv;

	if(sf == 0){
		pn = ps = pe = pv = 0;
	}
	else{
		pn = fn / sf;
		ps = fs / sf;
		pe = fe / sf;
		pv = fv / sf;
	}

	// seteaza vectorul de probabilitati
	prob[0] = pn;
	prob[1] = ps;
	prob[2] = pe;
	prob[3] = pv;

	// apel functie pentru locatia cu cea mai mica urma de feromoni
	this->get_max_poz(x, y, prob, this->fer, this->map, &xx, &yy);

	this->prev[xx][yy] = 1;		// locatia curenta va fi acualizata (feromoni)

	// noua valoare a urmei de feromoni
	float new_f = (float)(this->Q / this->L);

	if(this->map[xx][yy] == 2){
		this->nr_tinte++;			// contorizeaza tintele atinse
		this->relocare_tinta();
	}

	this->fer[xx][yy] = (1 - this->ro) * this->fer[xx][yy] + new_f;
	this->map[xx][yy] = 3;		// miscare furnica in noua locatie
	this->map[x][y] = 0;

	a->mem[xx][yy] = 1;
	a->poz_x = xx;
	a->poz_y = yy;
	this->viz[xx][yy] = 1;
}

//=============================================================================

void ACO::relocare_tinta(){

	int x, y, xx, yy, nr = 0;
	float f_sum, ref_sum = 100;		// total feromoni vecinatate		< !!!!! >

	while(nr < this->M + 1){
		
		x = rand() % tt.nr_ll;
		y = rand() % tt.nr_cc;

		if(this->map[x][y] == 0){

			nr++;

			f_sum = this->fer[x - 1][y - 1] +	this->fer[x - 1][y] +	this->fer[x - 1][y + 1]+
					this->fer[x][y - 1] +		this->fer[x][y] +		this->fer[x][y + 1]+
					this->fer[x + 1][y - 1] +	this->fer[x + 1][y] +	this->fer[x + 1][y + 1];

			if(f_sum < ref_sum){
				ref_sum = f_sum;
				xx = x;
				yy = y;
			}
		}
	}

	this->map[xx][yy] = 2;
}

//=============================================================================

void ACO::run_reloc_aco1(){

	cout << "Procesare aco1: \n";

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t, t1;
	float dt = 0;
	int cnt = 0;
	srand ((int)time(NULL));

	this->init_param_aco1();

	this->map = load_map();

	this->fer = aloc_mat_float();
	this->viz = aloc_mat_int();
	this->prev = aloc_mat_int();

	this->fer[1][1] = 9;

	print_map(1, this->map);
	print_mat_nr(this->fer);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}

	this->arm.clear();						// reset armata furnici
	
	for(int i = 0; i < this->M; i++){	// init armata furnici
		ant att;
		att.id = i;
		att.poz_x = 1;
		att.poz_y = 1;
		att.init_mem();
		this->arm.push_back(att);
	}

	//-------------------------------------------------------------------------

	t = clock();

	// itereaza pana harta devine curata
	while( true ){

		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){
			this->step_ant_reloc_aco1(&this->arm.at(k));
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

		// < ??? > verifica redundanta
		for(int k = 0; k < this->M; k++){
			this->map[this->arm.at(k).poz_x][this->arm.at(k).poz_y] = 3;
		}

		this->evaporare();
		zero_mat_int(this->prev);

		//---------------------------------------------------------------------------

		t1 = clock() - t;
		dt = ((float)t1) / CLOCKS_PER_SEC;

		if(dt >= tt.timp){
			break;
		}
	}

	//-------------------------------------------------------------------------
	
	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "reloc_aco1";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================

void ACO::step_ant_reloc_aco2(ant* a){

	int x = a->poz_x;
	int y = a->poz_y;
	int xx = x, yy = y;
	float prob[4];

	float fn, fs, fe, fv;
	float pn, ps, pe, pv;

	fn = this->fer[x - 1][y];
	fs = this->fer[x + 1][y];
	fe = this->fer[x][y + 1];
	fv = this->fer[x][y - 1];

	float sf = fn + fs + fe + fv;

	if(sf == 0){
		pn = ps = pe = pv = 0;
	}
	else{
		pn = fn / sf;
		ps = fs / sf;
		pe = fe / sf;
		pv = fv / sf;
	}

	// seteaza vectorul de probabilitati
	prob[0] = pn;
	prob[1] = ps;
	prob[2] = pe;
	prob[3] = pv;

	// apel functie pentru locatia cu cea mai mica urma de feromoni
	this->get_max_poz(x, y, prob, this->fer, this->map, &xx, &yy);

	// noua valoare a urmei de feromoni
	float new_f = (1 - this->ro) * this->fer[xx][yy] + this->Q / this->L;
	if(new_f < this->tmin){
		new_f = this->tmin;
	}
	if(new_f > this->tmax){
		new_f = this->tmax;
	}

	if(this->map[xx][yy] == 2){
		this->nr_tinte++;			// contorizeaza tintele atinse
		this->relocare_tinta();
	}

	this->fer[xx][yy] = new_f;
	this->map[xx][yy] = 3;
	this->map[x][y] = 0;
	a->mem[xx][yy] = 1;
	a->poz_x = xx;
	a->poz_y = yy;
	this->viz[xx][yy] = 1;
}

//=============================================================================

void ACO::run_reloc_aco2(){

	cout << "Procesare aco1: \n";

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t, t1;
	float dt = 0;
	int cnt = 0;

	srand ((int)time(NULL));

	this->init_param_aco2();
	this->map = load_map();

	this->fer = aloc_mat_float();
	this->viz = aloc_mat_int();
	this->prev = aloc_mat_int();

	this->fer[1][1] = 8;

	print_map(1, this->map);
	print_mat_nr(this->fer);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}
	
	this->arm.clear();					// reset armata furnici locatie start

	for(int i = 0; i < this->M; i++){	// init furnici
		ant att;
		att.id = i;
		att.poz_x = 1;
		att.poz_y = 1;
		att.init_mem();
		this->arm.push_back(att);
	}

	//-------------------------------------------------------------------------

	t = clock();

	// itereaza pana harta devine curata
	while(true){

		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){
			this->step_ant_reloc_aco2(&this->arm.at(k));
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

		for(int k = 0; k < this->M; k++){
			this->map[this->arm.at(k).poz_x][this->arm.at(k).poz_y] = 3;
		}

		//---------------------------------------------------------------------

		t1 = clock() - t;
		dt = ((float)t1) / CLOCKS_PER_SEC;

		if(dt >= tt.timp){
			break;
		}
	}
	
	//-------------------------------------------------------------------------

	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "reloc_aco2";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================

void ACO::step_ant_reloc_aco3(ant* a){

	int x = a->poz_x;
	int y = a->poz_y;
	int xx = x, yy = y;
	float prob[4];

	float fn, fs, fe, fv;
	float pn, ps, pe, pv;

	fn = this->fer[x - 1][y];
	fs = this->fer[x + 1][y];
	fe = this->fer[x][y + 1];
	fv = this->fer[x][y - 1];

	float sf = fn + fs + fe + fv;

	if(sf == 0){
		pn = ps = pe = pv = 0;
	}
	else{
		pn = fn / sf;
		ps = fs / sf;
		pe = fe / sf;
		pv = fv / sf;
	}

	// seteaza vectorul de probabilitati
	prob[0] = pn;
	prob[1] = ps;
	prob[2] = pe;
	prob[3] = pv;

	// apel functie pentru locatia cu cea mai mica urma de feromoni
	get_max_poz(x, y, prob, this->fer, this->map, &xx, &yy);

	// noua valoare a urmei de feromoni
	float new_f = (1 - this->fi) * this->fer[xx][yy] + this->fi * this->tau0;

	if(this->map[xx][yy] == 2){
		this->nr_tinte++;			// contorizeaza tintele atinse
		this->relocare_tinta();
	}

	this->fer[xx][yy] = new_f;		// actualizeaza valoare feromon
	this->map[xx][yy] = 3;			// reset noua locatie harta pentru mutare
	this->map[x][y] = 0;			// elibereaza vechea locatie

	a->mem[xx][yy] = 1;				// memoria furnicii / vizitat
	a->poz_x = xx;					//noile coordonate
	a->poz_y = yy;
	this->viz[xx][yy] = 1;			// marcheaza locatia ca vizitata
}

//=============================================================================

void ACO::run_reloc_aco3(){

	cout << "Procesare aco3: \n";

	clean_aco_1::harta_gen_form ^hgf = gcnew clean_aco_1::harta_gen_form();

	Rezultat *rez = new Rezultat();

	clock_t t, t1;
	float dt = 0;				// diferenta d timp
	int cnt = 0;				// contor pasi
	srand ((int)time(NULL));

	this->init_param_aco3();
	this->map = load_map();

	this->fer = aloc_mat_float();
	this->viz = aloc_mat_int();
	this->prev = aloc_mat_int();

	this->fer[1][1] = 7;

	print_map(1, this->map);
	print_mat_nr(this->fer);

	// afis form harta
	if(tt.harta_pas == 1){
		hgf->color_map_init();
		hgf->Show();
	}
	
	this->arm.clear();					// reset armata furnici in locatie start

	for(int i = 0; i < this->M; i++){	// init furnici

		ant att;
		att.id = i;
		att.poz_x = 1;
		att.poz_y = 1;
		att.init_mem();
		this->arm.push_back(att);
	}

	//-------------------------------------------------------------------------

	t = clock();

	// itereaza pana harta devine curata
	while( true ){

		cout << "\n> cnt <<< " << cnt++ << " >>>\n";
	
		for(int k = 0; k < this->M; k++){
			this->step_ant_reloc_aco3(&this->arm.at(k));
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
			this->map[this->arm.at(k).poz_x][this->arm.at(k).poz_y] = 3;			
		}

		//---------------------------------------------------------------------

		t1 = clock() - t;
		dt = ((float)t1) / CLOCKS_PER_SEC;

		if(dt >= tt.timp){
			break;
		}
	}
	
	//-------------------------------------------------------------------------
	
	t = clock() - t;
	float tc = ((float)t) / CLOCKS_PER_SEC;

	rez->tip = "reloc_aco3";
	rez->tinte = this->nr_tinte;
	rez->timp = tc;
	rez->pasi = cnt - 1;

	tt.rez_aco.push_back(*rez);

	cout << "> Iteratii: <<< " << cnt - 1 << " >>>\n";
	cout << "\n> Timp de calcul: " << tc << " secunde.\n";
	cout << "Final procesare aco1!\n";
}

//=============================================================================