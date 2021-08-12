#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n = 10;
    string word[n] = {"strawberry", "programming", "masculine", "avocado", "dumbell", "legendary", "abominable", "snowman", "fighter", "kingfisher"};
    srand(time(NULL));
    int x = rand() % n;

    bool ans[50] = {};
    bool dum = false;

    int turn = word[x].size() + 4;
    cout << "Welcome to HangMan\n\n";
    while(turn > 0)
    {
        int cnt = 0;
        for(int i = 0; i < word[x].size(); i++)
        {
            if(ans[i] == 0) 
            {
                cout << "_ ";
            }
            else
            {
                cout << word[x][i];
                cnt++;
            }
        }
        cout << endl;

        if(cnt == word[x].size())
        {
            dum = true;
            break;
        }
        cout << endl << "Remaining turns: " << turn-- << endl;

        cout << "Guess a letter: ";
        char c;
        cin >> c;

        for(int i = 0; i < word[x].size(); i++)
        {
            if(ans[i] == false && word[x][i] == c)
            {
                ans[i] = true;
            }
        }
    }

    if(dum)
        cout << "Well done!\n";
    else
        cout << "Better luck next time!\n";

    return 0;
}
