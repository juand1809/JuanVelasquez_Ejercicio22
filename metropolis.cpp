#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

void metropolis(int N);
double g(float x);

int main(){
    int x;
    x = 10000;
    metropolis(x);          
}    


void metropolis(int N){
    float sigma;
    int i;
    double x,x_prop;
    float paso;
    srand48(1);
    float r,alpha;
        
    sigma = 1.0;
    i = 0;
    x = drand48();
    while (i < N){
        paso = drand48() - sigma;
        x_prop = x + paso;
        r = g(x_prop)/g(x);
        alpha = drand48();
        if (alpha < r){
            cout << x_prop << endl;
        }
        else{
            cout << x << endl;
    }
    i++       
}
    
double g(double x){
    return exp(-x + (x/2))
}