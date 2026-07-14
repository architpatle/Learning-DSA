#include <iostream>
using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
            return false;
    }
    return true;
}
// Permutation In Strings
bool PermutationInStrings(string s1, string s2)
{

    // creating a frequency array for string s1
    int freq[26] = {0};

    // initailizing and updating the freq of each character of string s1 in freq array
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;
    }

    // Creating a Freq window
    int windowSize = s1.length();

    // traversing in string s2 and finding the match s1 permutaution in it
    for (int i = 0; i < s2.length(); i++)
    {

        int idx = i, windowIdx = 0;
        int windowFreq[26] = {0};

        while (windowIdx < windowSize && idx < s2.length())
        {
            windowFreq[s2[idx] - 'a']++;
            windowIdx++;
            idx++;
        }

        if (isFreqSame(freq, windowFreq))
        {
            return true;
        }
    }

    return false;  
}

int main()
{

    string s1 = "ab", s2 = "eodabcd";

    cout << PermutationInStrings(s1, s2);

    return 0;
}