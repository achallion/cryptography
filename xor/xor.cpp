#include <iostream>
#include <string>

using namespace std;

string xorenc(string simple, string key)
{
    int n = simple.size();
    int l = key.size();
    string ans = "";
    for (int i = 0; i < n; i++)
        ans += (simple[i] ^ key[i % l]);

    return ans;
}

int main()
{
    string str, key;
    cout << "\nGive Text : ";
    getline(cin, str);
    cout << "\nGive Key : ";
    getline(cin, key);

    string enc = xorenc(str, key);
    cout << "\n\nEncrypted : {" << enc << "}";
    cout << "\n\nDecrypted : {" << xorenc(enc, key) << "}";
    return 0;
}