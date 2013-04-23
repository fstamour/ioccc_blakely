#include "v3.h"

#include <math.h>

double norm( v3_t v ) {
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z );
}

double dot( v3_t v1, v3_t v2 ) {
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

v3_t cross( v3_t v1, v3_t v2) {
	v3_t r;
	
	r.x =  v1.y*v2.z - v1.z*v2.y;
	r.y =  v1.x*v2.z - v1.z*v2.x;
	r.z =  v1.x*v2.y - v1.y*v2.x;
	
	return r;
}


void scale( v3_t* v, double s ) {
	v->x *= s;
	v->y *= s;
	v->z *= s;
}