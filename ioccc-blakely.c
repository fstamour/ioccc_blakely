#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double A;            
double B;       
double C = 1;       
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
double S = 0;       
double T;       
double U;       
double V;       
double W;       
double X;       
double Y;
char Z;     
double E_;     
double w[20];  
double bf[20]; 
double bg[20]; 
double x=-1.3/8;

/*
double p;       
double d;   
*/
    
double l=0;     
double h=4e-3;  
double f;       
double m;       


//char e[17] = "FKE<<gMAQUDIYO9\"=";
char* k;
char* j;

double rpn(double p, double d) {
	int q = -1, t=0;
	j = k;
	while( *j )
	{
		switch( *j ) {
		// if(*j=='-'){
		case '-':
			q += t ;
			t=0;
			w[q-1] -= w[q];
			bf[q-1] = bf[q] - bf[q];
			bg[q-1] = bg[q] - bg[q];
			q--;
			break;
		// if(*j=='d') {
		case 'd':
			q+=t;t=0;
			q++;
			w[q]=w[q-1];
			q[bf]=bf[q-1];
			q[bg]=bg[q-1];
			break;
		// if(*j=='*') {
		case '*':
			q+=t;
			t=0;
			w[q-1]*=w[q];
			bf[q-1] = w[q]*bf[q-1] + w[q-1]*bf[q];
			bg[q-1] = w[q]*bg[q-1] + w[q-1]*bg[q];
			q--;
			break;
		// if(*j==','){
		case ',':
			t=0;
			q++;
			break;
		// if(*j=='t'){
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
		// if(*j=='+') {
		case '+':
			q += t;
			t=0;
			w[q-1] += w[q];
			bf[q-1] = bf[q] + bf[q];
			bg[q-1] = bg[q] + bg[q];
			q--;
			break;
		// if(*j=='/') {
		case '/':
			q+=t;t=0;
			w[q-1]/=w[q];
			bf[q-1] = bf[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bf[q];
			bg[q-1] = bg[q-1]/w[q] - w[q-1]/( w[q]*w[q] )*bg[q];
			q--;
			break;
		// if(*j=='y'){
		case 'y':
			q+=t;t=0;
			q++;
			w[q]=d;
			bf[q]=0;
			bg[q]=1;
			break;
		// if(*j=='^'){
		case '^':
			q+=t;t=0;
			f=w[q-1];
			w[q-1]=pow(w[q-1],w[q]);
			bf[q-1] = w[q]*bf[q-1]*pow(f,w[q]-1) + 0*bf[q];
			bg[q-1] = w[q]*bg[q-1]*pow(f,w[q]-1) + 0*bg[q];
			q--;
			break;
		// if(*j=='s') {
		case 's':
			q+=t;
			t=0;
			w[q]=sin(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*cos(w[q]) + 0*bf[0];
			bg[q-1] = -bg[q-1]*cos(w[q]) + 0*bg [0];
			q--;
			break;
		// if(*j=='c'){
		case 'c':
			q+=t;
			t=0;
			w[q] = cos(w[q]);
			q++;
			bf[q-1] = -bf[q-1]*sin(w[q]) +0*bf[0];
			bg[q-1] = -bg[q-1]*sin(w[q]) +0*bg[0];
			q--;
			break;
		//if(*j=='x') {
		case 'x':
			q+=t;t=0;
			q++;
			w[q]=p;
			bf[q]=1;
			bg[q]=0;
			break;
			
		//if(*j >= '0' && *j <= '9') {
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
	H = bf[0];
	K = bg[0];
	return w[0];
}

/*
Local:
	e

Use:


Set:
	X
	f
	l
	V
	W
	X
	p
	d


*/

void solve( double* x1, double* x2 ){
	int e=0;
	X = Q*8;
	f = rpn(Y*8, L*8 );
	e = (f-X<0) ? 1:-1;
	l = 0;
	while( (l+=h)<8 ) {
		V = Y* 8+l*R;
		W = L* 8+l*D;
		X = Q* 8+l*U;
		f = rpn(V,W);
		if( (f-X) * e > 0 ){
			if( V>-1 && V<1 && W>-1 && W<1 ) {
				//p = V;
				*x1 = V;
				//d = W;
				*x2 = W;
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
	int c, f;
	char b[2];
	
	k = argv[1];
	
	//Z = atoi( argv[2] ) >> 1;
	Z = atoi( argv[2] ) >> 1;
	b[1] = Z*2;	//b[1] = Z*2 & 255;
	b[0] = Z >> 9;
	
	J = 3.1415/Z;
	

	/*for( f = 0; f < 6; f++)
		putchar(f[e]^f+1);*/
	printf("GIF89a");

		
	f = 6;
	while(--f>1)
		putchar((f%2)[b]);

	putchar(246);

	for(c=0;c<384;c++)
		putchar(c/3%2?c/6<<2:0);
	
	putchar(putchar(0));
	//putchar(putchar((putchar('!')<<3)-9)/23);
	putchar('!'); putchar(255);	putchar(11);

	/*for( f+=5; f < c/22; f++)
		putchar(e[f] ^ f - 3);*/
	printf("NETSCAPE2.0");
		
	/*f = 17;
	for(; f > c/29 ; f-- )
		putchar(f>15?2*f-31:c);*/
	putchar(3);
	putchar(1);
	putchar(384);
	putchar(384);
		
	putchar(0);

	
	double x1, x2;
	for(f=0; f <= Z*2; f++)
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
		
		//putchar((putchar(e[10]/2-1)<<3)-18);
		putchar('!'); putchar(246); 		
		
		/*for(c=-1;c<5;c++) {
			putchar((c+1)%2?0:-2*c*c+3*c+9);
		}*/
		putchar(4);
		putchar(0);		putchar(10);
		putchar(0);putchar(0);putchar(0);
		putchar(44);
		
		/*for(c=0;c<9;c++)
			putchar(c&4?(1-c%2)[b]:0);*/
		putchar(0);putchar(0);putchar(0);putchar(0);
		putchar(b[1]);
		putchar(0);
		putchar(b[1]);
		putchar(0);putchar(0);
		
		putchar(7);

		for( B = -Z; B < Z; B++) { //iteration en x ou y
			putchar(Z+2);
			for( O = -Z; O < Z; O++ ) { //iteration en x ou y
				Y = (E - P*B/Z - G*O/Z)*x;
				L = (I - F*B/Z - A*O/Z)*x;
				Q = (-C +S* B/Z)*x;
				R = - Y + E;
				D =-L+I;
				U =-Q-C;
				
				solve(&x1, &x2);
				
				w[3] = sqrt(R*R + D*D + U*U);
				
				
				/*m = p == -10 ? 1: (
					4[w] = sqrt(H*H+K*K+1)*w[3],
					H/=-4[w],K/=-4[w],
					fabs(H*R + K*D + U/4[w])*exp(-l*l/2)
				);*/
				//if( p == -10 ) {
				if( x1 == -10 ) {
					m = 1;
				} else {				
					w[4] = sqrt(H*H + K*K + 1) * w[3];
					H /= -w[4];
					K /= -w[4];
					m = fabs(H*R + K*D + U/4[w]) * exp(-l*l/2);
				}

				//putchar( (char)(m * 63)*2 + ((char)((p+1)*6) % 2 + (char)((d+1)*6) % 2 == 1 ? 1 : 0) );
				putchar( (char)(m * 63)*2 + ((char)((x1+1)*6) % 2 + (char)((x2+1)*6) % 2 == 1 ? 1 : 0) );
				O ? l :( putchar(128),putchar(B != Z-1 ? Z : Z+1) );
			}
			putchar(128);
		}
		//putchar(putchar(129)-129);
		putchar(129); putchar(0);
	}
	putchar(0x3b);
	
	return 0;
  }
