#include <iostream>

using namespace std;

struct Interval
{
    double left;
    double right;
}rada[5]; //maxim 5 radacini
double f(double x){
     return x*x*x-x*x-20*x+20;
};
int Separation(double A, double B, double H);
double eps = 1e-9;
double Bisection(double a, double b, int &k);

int main()
{
    int n, i;
    double A=-5, B=5, H=0.05;
    double x;
    cout << "Proiect nr 1" << endl;
    n=Separation(A, B, H);

    for(i=0; i<n; i++)
    {
        cout << "O solutie se afla pe [" << rada[i].left << "; "<<rada[i].right << "]" << endl;
    };

    return 0;
}

int Separation(double A, double B, double H){
    int n=0;
    double x0, x;
    x0=A;
    do{
        x=x0+H;
        if(f(x0)*f(x) < 0){
            rada[n].left = x0;
            rada[n].right = x;
            n++;
        }
        x0=x;
    }while(x<B);
    return n;
}
