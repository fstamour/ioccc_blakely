#include <math.h>
#include "v3.h"

extern double f;
extern v3_t hk;

extern double w[20];

double bf[20];
double bg[20];

/**
 *	w := z
 *	z = expression(x, y)
 *
 *	bf := dz/dx
 *	bg := dz/dy
 *
 */

double rpn( char* expression, double x, double y) {
	int q = -1, t=0;
	while( *expression )
	{
		switch( *expression ) {

		/* Sub */
		case '-':
			q += t ;
			t=0;
			w[q-1] -= w[q];
			bf[q-1] = bf[q] - bf[q];
			bg[q-1] = bg[q] - bg[q];
			q--;
			break;

		/* Duplicate the value on the stack */
		case 'd':
			q+=t;t=0;
			q++;
			w[q]=w[q-1];
			bf[q]=bf[q-1];
			bg[q]=bg[q-1];
			break;

		/* Mul */
		case '*':
			q+=t;
			t=0;
			w[q-1]*=w[q];
			bf[q-1] = w[q]*bf[q-1] + w[q-1]*bf[q];
			bg[q-1] = w[q]*bg[q-1] + w[q-1]*bg[q];
			q--;
			break;

		/* Skip */
		case ',':
			t=0;
			q++;
			break;

		/* Swap (why t?)  */
		case 't':
			f = w[q-1];
			w[q-1] = w[q];
			w[q]   = f;

			f  =  bf[q];
			bf[q]   = bf[q-1];
			bf[q-1] = f;

			f    =  q[bg];
			bg[q] = bg[q-1];
			bg[q-1] = f;
			break;

		/* Add  */
		case '+':
			q += t;
			t=0;
			w[q-1] += w[q];
			bf[q-1] = bf[q] + bf[q];
			bg[q-1] = bg[q] + bg[q];
			q--;
			break;

		/* Div */
		case '/':
			q+=t;t=0;
			w[q-1]/=w[q];
			bf[q-1] = bf[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bf[q];
			bg[q-1] = bg[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bg[q];
			q--;
			break;

		/* Put y */
		case 'y':
			q+=t;t=0;
			q++;
			w[q]=y;
			bf[q]=0;
			bg[q]=1;
			break;

		/* Pow */
		case '^':
			q+=t;t=0;
			f=w[q-1];
			w[q-1]=pow(w[q-1],w[q]);
			bf[q-1] = w[q]*bf[q-1]*pow(f,w[q]-1) + 0*bf[q];
			bg[q-1] = w[q]*bg[q-1]*pow(f,w[q]-1) + 0*bg[q];
			q--;
			break;

		/* Sin */
		case 's':
			q+=t;
			t=0;
			w[q]=sin(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*cos(w[q]) + 0*bf[0];
			bg[q-1] = -bg[q-1]*cos(w[q]) + 0*bg [0];
			q--;
			break;

		/* Cos */
		case 'c':
			q+=t;
			t=0;
			w[q] = cos(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*sin(w[q]) +0*bf[0];
			bg[q-1] = -bg[q-1]*sin(w[q]) +0*bg[0];
			q--;
			break;

		/*Put x */
		case 'x':
			q+=t;t=0;
			q++;
			w[q]=x;
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
			w[q]= *expression - '0';
			bf[q] = 0;
			(q--)[bg] = 0;
			break;
		}
		expression++;
	}
	hk.x = bf[0]; /* Top of the stack */
	hk.y = bg[0]; /* Top of the stack */
	return w[0];  /* Top of the stack */
}
