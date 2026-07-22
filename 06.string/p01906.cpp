#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> ciphers;
    string allText;
    string line;

    // Read all cipher blocks
    while (getline(cin, line))
    {
        if (line == "ENDOFINPUT")
            break;
        if (line == "START")
        {
            string cipher;
            getline(cin, cipher);
            ciphers.push_back(cipher);
            allText += cipher;
            getline(cin, line);  // consume END
        }
    }

    // Frequency analysis on all cipher text combined
    int freq[26] = {0};
    for (char c : allText)
    {
        if (isalpha(c))
        {
            freq[toupper(c) - 'A']++;
        }
    }

    // Find most frequent letter → corresponds to 'E'
    int maxIdx = 0;
    for (int i = 1; i < 26; i++)
    {
        if (freq[i] > freq[maxIdx])
            maxIdx = i;
    }
    // shift = (most_frequent_cipher_idx - 'E'_idx + 26) % 26
    int shift = (maxIdx - 4 + 26) % 26;

    // Decrypt and output
    for (const string& s : ciphers)
    {
        for (char c : s)
        {
            if (isalpha(c))
            {
                char upper = toupper(c);
                cout << char((upper - 'A' - shift + 26) % 26 + 'A');
            }
            else
            {
                cout << c;
            }
        }
        cout << '\n';
    }

    return 0;
}
