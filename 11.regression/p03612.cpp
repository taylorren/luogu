#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

// Function to find the N-th character in the infinite code string
char find_nth_character(const string &s, ull N)
{
    ull L = s.length();
    // Initialize the size to the length of the initial string
    ull size = L;

    // Step 1: Determine the smallest size >= N by doubling
    while (size < N)
    {
        // Prevent overflow: if size > 1e18 / 2, set to at least 1e18
        if (size > (1e18 / 2))
        {
            size = 1e18;
            break;
        }
        size *= 2;
    }

    // Step 2: Trace back to find the character
    while (size > L)
    {
        ull half = size / 2;
        if (N > half)
        {
            ull pos_in_rotated = N - half;
            if (pos_in_rotated == 1)
            {
                N = half;
            }
            else
            {
                N = pos_in_rotated - 1;
            }
        }
        // Update size outside the if-else
        size = half;
    }

    // Now, size == L, so N is within the initial string
    return s[N - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    ull N;
    // Read input: the string and N
    cin >> s >> N;
    // Find and print the N-th character
    char result = find_nth_character(s, N);
    cout << result;
}
