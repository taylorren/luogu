#include <bits/stdc++.h>
using namespace std;

struct Doll
{
    int orientation;
    string name;
};

struct Order
{
    int direction;
    int steps;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Doll> dolls(n);
    vector<Order> orders(m);

    for (int i = 0; i < n; i++)
    {
        cin >> dolls[i].orientation >> dolls[i].name;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> orders[i].direction >> orders[i].steps;
    }

    int position = 0;
    for (int i = 0; i < m; i++)
    {
        // XOR determines direction: use it to calculate +steps or -steps
        int delta = (orders[i].direction ^ dolls[position].orientation) ? orders[i].steps : -orders[i].steps;
        position = (position + delta + n) % n;
    }

    cout << dolls[position].name << endl;

    return 0;
}
