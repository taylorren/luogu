#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin>>a>>b>>c;

    double delta=b*b-4.0*a*c;
    
    if(abs(delta)<=1E-6)
    {
        printf("x1=x2=%.5f\n", -b/2/a);
    }
    else if(delta>1e-6)
    {
        double s_delta=sqrt(delta);
        double x1, x2;
        x1=(-b+s_delta)/2/a;
        x2=(-b-s_delta)/2/a;
        //cout<<"x1="<<x1<<";x2="<<x2<<endl;
        if(x1>x2)
        {
            double tmp=x1;
            x1=x2;
            x2=tmp;
        }
        printf("x1=%.5lf;x2=%.5lf\n", x1, x2);
    }
    else 
    {
        cout<<"No answer!"<<endl;
    }
    return 0;
}
