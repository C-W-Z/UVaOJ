#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

static unordered_map<char, char> mirror;

bool ispalindrome(string &str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}

bool ismirror(string &str)
{
    int i = 0, j = str.size() - 1;
    while (i <= j)
    {
        if (str[i] != mirror[str[j]])
            return false;
        i++, j--;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (char c = 'A'; c <= 'Z'; c++)
        mirror[c]='\0';
    for (char c = '1'; c <= '9'; c++)
        mirror[c]='\0';
    mirror['A']='A';
    mirror['E']='3';
    mirror['H']='H';
    mirror['I']='I';
    mirror['J']='L';
    mirror['L']='J';
    mirror['M']='M';
    mirror['O']='O';
    mirror['S']='2';
    mirror['T']='T';
    mirror['U']='U';
    mirror['V']='V';
    mirror['W']='W';
    mirror['X']='X';
    mirror['Y']='Y';
    mirror['Z']='5';
    mirror['1']='1';
    mirror['2']='S';
    mirror['3']='E';
    mirror['5']='Z';
    mirror['8']='8';

    string str;
    while(cin >> str)
    {
        bool p = ispalindrome(str);
        bool m = ismirror(str);
        cout << str;
        if (!p && !m)
            cout << " -- is not a palindrome.\n\n";
        else if (p && !m)
            cout << " -- is a regular palindrome.\n\n";
        else if (!p && m)
            cout << " -- is a mirrored string.\n\n";
        else
            cout << " -- is a mirrored palindrome.\n\n";
    }

    return 0;
}
