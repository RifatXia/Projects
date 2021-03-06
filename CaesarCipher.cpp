#include <iostream>
using namespace std;

#define en "\n"

int main(void)
{
	string s;
	int n, key;

	cout << "What do you want to do : 1) Encrypt 2)Decrypt";
	cin >> n;
	cin.ignore();

	cout << "Enter the message : ";
	getline(cin, s);

	cout << "Enter the key : ";
	cin >> key;

	char letter[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	if(n == 1)
	{
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
				s[i] = letter[(s[i] - 'a' + key) % 26];
		}

		cout << "Your encrypted message : " << s << en;
	}
	else
	{
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				int ans = (s[i] - 'a' - key);
				if(ans < 0)
				{
					ans += 26;
					s[i] = letter[ans];
				}
				else
					s[i] = letter[ans];
			}
		}
		cout << "Your decrypted message : " << s << en;
	}
	return 0;
}
