#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx, const double xmin) {
    for(int i=0; i<N; i++)
	cout << i*dx + xmin << "\t" << p[i] << endl;
}

void array(double* p, const int N, const double dx, const double xmin) {
    for(int i=0; i<N; i++)
	p[i] = exp(-(i*dx + xmin)*(i*dx + xmin));
}

void derivative(double* p, const int N, const double dx) {
    double paul1 = p[0];
    double paul2 = p[1];
      
    p[0] = p[1]/(2*dx);
    
    for(int i=1; i<N-1; i++) {
	p[i] = (p[i+1] - paul1)/(2*dx); 
	paul1 = paul2;
	paul2 = p[i+1];
    }
    
    p[N-1] = -paul1/(2*dx);
}

int main(){
    const int N = 100;
    double p[N];
    const double xmax = 15;
    const double xmin = -15;
    const double dx = (xmax-xmin)/(N-1);

    array(p, N, dx, xmin);
    derivative(p, N, dx);
    print(p, N, dx, xmin);

    return 0;
}
