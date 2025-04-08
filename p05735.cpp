#include <bits/stdc++.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() 
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = dist(x1, y1, x2, y2);
    double b = dist(x2, y2, x3, y3);
    double c = dist(x1, y1, x3, y3);
    cout<<fixed<<setprecision(2)<<a+b+c<<endl;

    return 0;
}