#include <iostream>
using namespace std;

string reversePrefix(string word, char ch) {

    int chIdx =0;

    for(int i = 0; i<word.size(); i++){
        if(word[i] == ch){
            chIdx = i;
            break;
        }
    }

    int stIdx = 0;

    while (stIdx<=chIdx)
    {
        swap(word[stIdx], word[chIdx]);
        stIdx++;
        chIdx--;
    }

    return word;
}

int main()
{
    string word = "abcdefd";
    char ch = 'd';

    return 0;
}