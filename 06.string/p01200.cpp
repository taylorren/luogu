#include <iostream>
#include <string>
using namespace std;

// Calculate product of letter values mod 47
int calculateProduct(const string& s)
{
    int product = 1;
    for (char c : s)
    {
        product = (product * (c - 'A' + 1)) % 47;
    }
    return product;
}

int main()
{
    string comet, team;
    cin >> comet >> team;

    int comet_product = calculateProduct(comet);
    int team_product = calculateProduct(team);

    if (comet_product == team_product)
    {
        cout << "GO" << endl;
    }
    else
    {
        cout << "STAY" << endl;
    }

    return 0;
}