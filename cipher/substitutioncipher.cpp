#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const char replace [26] = 
{
    'j' , 'a' , 'v' , 'b' , 'e' ,
    'n' , 'c' , 'd' , 'f' , 'g' ,
    'h' , 'i' , 'k' , 'l' , 'm' ,
    'o' , 'p' , 'q' , 'z' , 's' ,
    't' , 'u' , 'w' , 'r' , 'x' , 'y'
};

string encrypt(string &str)
{
    string temp;
    int n = str.length();
    char x;
    for (int i = 0; i < n; i++)
    {
        x = str[i];
        if(islower(x))
        {
            x = replace[x - 97];
        }
        if(isupper(x))
        {
            x = replace[x - 65];
            x = toupper(x);
        }
        temp.push_back(x);
    }
    return temp;
}

char decryptchar(char &x)
{
    if(isalpha(x))
    {
        for (int i = 0; i < 26; i++)
        {
            if(x == replace[i])
            {
                return 97 + i;
            }
        }
    }
    return x;
}

string decrypt(string &str)
{
    string temp;
    int n = str.length();
    char x;
    char y;
    for (int i = 0; i < n; i++)
    {
        x = str[i];
        y = tolower(x);
        y = decryptchar(y);
        if(isupper(x))
            y = toupper(y);
        temp.push_back(y);
    }
    return temp;
}