
#ifndef Vect_h
#define Vect_h

#include "Loc.h"

public class Vect{

public:

	float mag;		// magnitudinea
	float dir;		// directia - in radiani

	float rx;		// mag * cos(dir)
	float ry;		// mag * sin(dir)

	Loc* org;		// locatia origine a vectorului
	Loc* vf;		// locatia "varf" vector

	Vect();
	Vect(float, float, float, float, Loc, Loc);

};

#endif