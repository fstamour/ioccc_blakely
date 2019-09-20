#ifndef V3_H
#define V3_H

typedef struct {
	double x, y, z;
} v3_t ;

double norm( v3_t v );
double dot( v3_t v1, v3_t v2 );
v3_t cross( v3_t v1, v3_t v2);

void scale( v3_t* v, double s );

#endif /*V3_H*/

