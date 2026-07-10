#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        bool relatedToSeven = (i % 7 == 0 || i % 10 == 7 || i / 10 == 7);

        if (relatedToSeven)
        {
            continue;
        }
        sum += i * i;
    }

    cout << sum << '\n';
    return 0;
}
