#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::endl;

void metropolis(int N);
double g(double x);

int main(){
    metropolis(10000);
    return 0;
}    


void metropolis(int N){
    float sigma,r,alpha,paso;
    int i;
    double x,x_prop;
    srand48(10);
        
    sigma = 1.0;
    i = 0;
    x = drand48();
    while (i < N){
        paso = 2.0*drand48() - sigma;
        x_prop = x + paso;
        r = std::min(1.0,g(x_prop)/g(x));
        alpha = drand48();
        if (alpha < r){
            x = x_prop;
        }
        else{
            x = x;
        }
        cout << x << endl;
        i++; 
    }     
}
    
double g(double x) {
    return exp(-x + (x/2));
}