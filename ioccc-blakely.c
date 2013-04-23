#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "v3.h"
#include "parser.h"

double A;            
double B;       
double C = 1;       
      
double E;       
double F;       
double G;       
      
double I;       
double J;       
 
double M;       
double N;       
double O;       
double P;       
    
double S = 0;       
double T; 

/*
double H; 
double K;
*/


     
double E_;     
double w[20];  

double x=-1.3/8;
    
double l=0;     
double h=4e-3;  
double f;       
double m;       

char* expression;




v3_t vwx;
v3_t ylq;
v3_t rdu;
v3_t hk; //@todo init z


/*
Local:
	e
Set:
	f
	l
	V
	W
	X
	p
	d
*/
void solve( double* x1, double* x2 ){
	int e = 0;
	vwx.z = ylq.z*8;
	f = rpn(expression, ylq.x*8, ylq.y*8 );
	e = (f-vwx.z < 0) ? 1: -1;
	l = 0;
	while( (l+=h)<8 ) {
		vwx.x = ylq.x* 8+l*rdu.x;
		vwx.y = ylq.y* 8+l*rdu.y;
		vwx.z = ylq.z* 8+l*rdu.z;
		f = rpn(expression, vwx.x,vwx.y);
		if( (f-vwx.z) * e > 0 ){
			if( vwx.x>-1 && vwx.x<1 && vwx.y>-1 && vwx.y<1 ) {
				*x1 = vwx.x;
				*x2 = vwx.y;
				return;
			} else {
				e /= -1;
			}
		}
	}
	//p = d = -10;
	*x1 = *x2 = -10;
}


int main(int argc, char **argv)
{

	//------- Init -------//
	
	int c, f;
	char b[2];
	
	expression = argv[1];
	
	char width = atoi( argv[2] ) >> 1;
	b[1] = width*2;
	b[0] = width >> 9;
	
	J = 3.1415/width;
	
	hk.z = 1;
	
	//--------------//	
	
	printf("GIF89a");
		
	f = 6;
	while(--f>1)
		putchar((f%2)[b]);

	putchar(246);

	for(c=0;c<384;c++)
		putchar(c/3%2?c/6<<2:0);
	
	putchar(putchar(0));
	putchar('!'); putchar(255);	putchar(11);
	printf("NETSCAPE2.0");		
	putchar(3);
	putchar(1);
	putchar(384);
	putchar(384);		
	putchar(0);

	//--------------//
	
	double x1, x2;
	for(f=0; f <= width*2; f++)
	{
		N = S;
		E_= 1 - J*J/2;
		T = J*(1-J*J/6);
		S = S*E_ + C*T;
		C = C*E_ - N*T;
		A = -(C*C - S*S);
		P = -A*C;
		E = A*S;
		G = S*C*2;
		I = -G*S;
		F = G*C;
		
		putchar('!'); putchar(246); 		
		putchar(4);
		putchar(0);		putchar(10);
		putchar(0);putchar(0);putchar(0);
		putchar(44);
		
		putchar(0);putchar(0);putchar(0);putchar(0);
		putchar(b[1]);
		putchar(0);
		putchar(b[1]);
		putchar(0);putchar(0);
		
		putchar(7);
		
		
		
		char c;
		for( B = -width; B < width; B++) { //iteration en x ou y
			putchar(width+2);
			for( O = -width; O < width; O++ ) { //iteration en x ou y
				ylq.x = (E - P*B/width - G*O/width)*x;
				ylq.y = (I - F*B/width - A*O/width)*x;
				ylq.z = (-C +S* B/width)*x;
				rdu.x = - ylq.x + E;
				rdu.y =-ylq.y+I;
				rdu.z =-ylq.z-C;
				
				solve(&x1, &x2);
				
				w[3] = sqrt(rdu.x*rdu.x + rdu.y*rdu.y + rdu.z*rdu.z);
				
				if( x1 == -10 ) {
					m = 1;
				} else {				
					w[4] = norm(hk) * w[3];
					hk.x /= -w[4];
					hk.y /= -w[4];
					m = fabs(hk.x*rdu.x + hk.y*rdu.y + rdu.z/w[4]) * exp(-l*l/2);
				}
				
				//putchar( (char)(m * 63)*2 + ((char)((x1+1)*6) % 2 + (char)((x2+1)*6) % 2 == 1 ? 1 : 0) );
				c = (char)(m * 63)*2;
				if( (char)((x1+1)*6) % 2 + (char)((x2+1)*6) % 2 == 1 ) {
					c++;
				}
				putchar(c);

				
				//O ? l :( putchar(128), putchar(B != width-1 ? width : width+1) );
				if( !O ) {
					putchar(128);
					putchar(B != width-1 ? width : width+1);
				}
			}
			putchar(128);
		}
		putchar(129); putchar(0);
	}
	putchar(0x3b);
	
	return 0;
  }
