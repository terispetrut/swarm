
#include "stdafx.h"
#include "Vect.h"

Vect::Vect(){

	this->mag = 0;
	this->dir = 0;

	this->rx = 0;
	this->ry = 0;

	this->vf = new Loc(0, 0);
	this->org = new Loc(0, 0);
}

Vect::Vect(float m, float d, float rx, float ry, Loc h, Loc t){

	this->mag = m;
	this->dir = d;

	this->rx = rx;
	this->ry = ry;

	this->vf->x = h.x;
	this->vf->y = h.y;
	this->org->x = t.x;
	this->org->y = t.y;
}