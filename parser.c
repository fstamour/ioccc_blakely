#include <math.h>
#include "v3.h"


extern double w[20];
extern double f;
extern v3_t hk;


double bf[20]; 
double bg[20]; 


/*j - > expression*/
double rpn( char* j, double p, double d) {
	int q = -1, t=0;
	while( *j )
	{
		switch( *j ) {
		case '-':
			q += t ;
			t=0;
			w[q-1] -= w[q];
			bf[q-1] = bf[q] - bf[q];
			bg[q-1] = bg[q] - bg[q];
			q--;
			break;
		case 'd':
			q+=t;t=0;
			q++;
			w[q]=w[q-1];
			q[bf]=bf[q-1];
			q[bg]=bg[q-1];
			break;
		case '*':
			q+=t;
			t=0;
			w[q-1]*=w[q];
			bf[q-1] = w[q]*bf[q-1] + w[q-1]*bf[q];
			bg[q-1] = w[q]*bg[q-1] + w[q-1]*bg[q];
			q--;
			break;
		case ',':
			t=0;
			q++;
			break;
		case 't':
			f=w[q-1];
			w[q-1]=w[q];
			w[q]=f;
			f=bf[q];
			q[bf]=bf[q-1];
			bf[q-1]=f;
			f=q[bg];
			bg[q]=(q-1)[bg];
			bg[q-1]=f;
			break;
		case '+':
			q += t;
			t=0;
			w[q-1] += w[q];
			bf[q-1] = bf[q] + bf[q];
			bg[q-1] = bg[q] + bg[q];
			q--;
			break;
		case '/':
			q+=t;t=0;
			w[q-1]/=w[q];
			bf[q-1] = bf[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bf[q];
			bg[q-1] = bg[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bg[q];
			q--;
			break;
		case 'y':
			q+=t;t=0;
			q++;
			w[q]=d;
			bf[q]=0;
			bg[q]=1;
			break;
		case '^':
			q+=t;t=0;
			f=w[q-1];
			w[q-1]=pow(w[q-1],w[q]);
			bf[q-1] = w[q]*bf[q-1]*pow(f,w[q]-1) + 0*bf[q];
			bg[q-1] = w[q]*bg[q-1]*pow(f,w[q]-1) + 0*bg[q];
			q--;
			break;
		case 's':
			q+=t;
			t=0;
			w[q]=sin(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*cos(w[q]) + 0*bf[0];
			bg[q-1] = -bg[q-1]*cos(w[q]) + 0*bg [0];
			q--;
			break;
		case 'c':
			q+=t;
			t=0;
			w[q] = cos(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*sin(w[q]) +0*bf[0];
			bg[q-1] = -bg[q-1]*sin(w[q]) +0*bg[0];
			q--;
			break;
		case 'x':
			q+=t;t=0;
			q++;
			w[q]=p;
			bf[q]=1;
			bg[q]=0;
			break;
			
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			q++;
			t=1;
			w[q]= *j - '0';
			bf[q] = 0;
			(q--)[bg] = 0;
			break;		
		}
		j++;
	}
	hk.x = bf[0];
	hk.y = bg[0];
	return w[0];
}