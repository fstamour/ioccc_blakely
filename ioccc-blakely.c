#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double A;            
double B;       
double C;       
double D;       
double E;       
double F;       
double G;       
double H;       
double I;       
double J;       
double K;       
double L;       
double M;       
double N;       
double O;       
double P;       
double Q;       
double R;       
double S;       
double T;       
double U;       
double V;       
double W;       
double X;       
double Y;       
double E_;     
double w[20];  
double bf[20]; 
double bg[20]; 
double x=-1.3/8;
double p;       
double d;       
double l=0;     
double h=4e-3;  
double f;       
double m;       


char e[17] = "FKE<<gMAQUDIYO9\"=";
char* k;
char* j;

double g(double p, double d) {
 int q = -1, t=0;
 j = k;
	while( *j )
	{
		if(*j==45){
			q += t ;
			t=0;
			w[q-1] -= w[q];
			bf[q-1] = bf[q] - bf[q];
			bg[q-1] = bg[q] - bg[q];
			q--;
		};
		if(*j==100) {
			q+=t;t=0;
			q++;
			w[q]=w[q-1];
			q[bf]=bf[q-1];
			q[bg]=bg[q-1];
		}
		if(*j==42) {
			q+=t;
			t=0;
			w[q-1]*=w[q];
			bf[q-1] = w[q]*bf[q-1] + w[q-1]*bf[q];
			bg[q-1] = w[q]*bg[q-1] + w[q-1]*bg[q];
			q--;
		}
		if(*j==44){
			t=0;
			q++;
		}
		if(*j==116){
			f=w[q-1];
			w[q-1]=w[q];
			w[q]=f;
			f=bf[q];
			q[bf]=bf[q-1];
			bf[q-1]=f;
			f=q[bg];
			bg[q]=(q-1)[bg];
			bg[q-1]=f;
		}
		if(*j==43) {
			q += t;
			t=0;
			w[q-1] += w[q];
			bf[q-1] = bf[q] + bf[q];
			bg[q-1] = bg[q] + bg[q];
			q--;
		}
		if(*j==47) {
			q+=t;t=0;
			w[q-1]/=w[q];
			bf[q-1] = bf[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bf[q];
			bg[q-1] = bg[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bg[q];
			q--;
		}
		if(*j==121){
			q+=t;t=0;
			q++;
			w[q]=d;
			bf[q]=0;
			bg[q]=1;
		}
		if(*j==94){
			q+=t;t=0;
			f=w[q-1];
			w[q-1]=pow(w[q-1],w[q]);
			bf[q-1] = w[q]*bf[q-1]*pow(f,w[q]-1) + 0*bf[q];
			bg[q-1] = w[q]*bg[q-1]*pow(f,w[q]-1) + 0*bg[q];
			q--;
		}
		if(*j==115) {
			q+=t;
			t=0;
			w[q]=sin(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*cos(w[q]) + 0*bf[0];
			bg[q-1] = -bg[q-1]*cos(w[q]) + 0*bg [0];
			q--;
		}
		if(*j==99){
			q+=t;
			t=0;
			w[q] = cos(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*sin(w[q]) +0*bf[0];
			bg[q-1] = -bg[q-1]*sin(w[q]) +0*bg[0];
			q--;
		};
		if(*j==120) {
			q+=t;t=0;
			q++;
			w[q]=p;
			bf[q]=1;
			bg[q]=0;
		}
		if(*j>=48&&*j<58) {
			q++;
			t=1;
			w[q]=*j-48;
			bf[q] = 0;
			(q--)[bg] = 0;
		}
		j++;
	}
	H=bf[0];
	K= bg[ 0];
	return w[0];
}


void s(){
	int e=0;
	X = Q*8;
	f = g(Y*8, L*8 );
	e = (f-X<0) ? 1:-1;
	l = 0;
	while((l+=h)<8) {
		V = Y*8+l*R;
		W = L* 8+l*D;
		X = Q*8+l*U;
		f = g(V,W);
		if( (f-X) * e > 0 ){
			if( V>-1 && V<1 && W>-1 && W<1 ) {
				p=V;
				d=W;
				return;
			} else {
				e /= -1;
			}
		}
	}
	p = d = -10;
}


int main(int argc, char **argv)
{
	int c, f;
	char b[2], Z;
	S=0, 
	C=1;
	k = argv[1];
	Z = atoi( argv[2] ) >> 1;
	b[1] = Z*2 & 255;
	b[0]= Z >> 9;
	J = 3.1415/Z;
	for(f=0;f<6;f++)putchar(f[e]^f+1);

	while(--f>1)
	putchar((f%2)[b]);

	putchar(246);

	for(c=0;c<384;c++)putchar(c/3%2?c/6<<2:0);

	putchar(putchar(0));
	putchar(putchar((putchar(33)<<3)-9)/23);

	for( f+=5; f < c/22; f++)
	putchar(e[f] ^ f - 3);

	for(; f > c/29 ; f-- )
	putchar(f>15?2*f-31:c);

	putchar(0);

	for(f=0; f <= Z*2; f++)
	{
	N = S;
	E_=1-J*J/2;
	T=J*(1-J*J/6);
	S=S*E_+C*T;
	C=C*E_-N*T;
	A=-(C*C-S*S);
	P=-A*C;
	E=A*S;
	G=S*C*2;
	I=-G*S;
	F=G*C;
	putchar((putchar(e[10]/2-1)<<3)-18);
	for(c=-1;c<5;c++)
	putchar((c+1)%2?0:-2*c*c+3*c+9);
	putchar(44);
	for(c=0;c<9;c++)putchar(c&4?(1-c%2)[b]:0);
	putchar(7);

	for(B=-Z ; B<Z ; B++) {
	putchar(Z+2);
	for(O=-Z;O<Z;O++) {
	Y = (E - P*B/Z - G*O/Z)*x;
	L = (I - F*B/Z - A*O/Z)*x;
	Q = (-C +S* B/Z)*x;
	R = - Y + E;
	D =-L+I;
	U =-Q-C;
	s();
	3[w] = sqrt(R*R + D*D + U*U);

	m = p == -10 ? 1: ( 4[w] = sqrt(H*H+K*K+1)*w[3],H/=-4[w],K/=-4[w], fabs(H*R + K*D + U/4[w])*exp(-l*l/2) );

	putchar((char)(m * 63)*2 + ((char)((p+1)*6) % 2 + (char)((d+1)*6) % 2 == 1 ? 1 : 0));
	O?l:(putchar(128),putchar(B!=Z-1 ? Z : Z+1));
	}
	putchar(128);
	}
	putchar(putchar(129)-129);
	}

	putchar(0x3b);
	
	return 0;
  }
