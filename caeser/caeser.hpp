#ifndef CAESER_HPP
#define CAESER_HPP

namespace maurya
{
    #include <string>
    #include <ctype.h>

    using namespace std;

    string caesercipher(string &str, int shift)
    {
        string enc;
        char x;
        int temp = shift;
        for (int i = 0; i < str.size(); i++)
        {
            shift = temp;
            x = str[i];
            if(isalnum(x))
            {
                if(isalpha(x))
                {
                    shift %= 26;
                    if(shift < 0)
                        shift += 26;
                    if (isupper(x))
                    {
                        x -= 65;
                        x += shift;
                        x %= 26;
                        x += 65;
                    }
                    else
                    {                 
                        x -= 97;
                        x += shift;
                        x %= 26;
                        x += 97;
                    }
                }
                else
                {                
                    shift %= 10;
                    if(shift < 0)
                        shift += 10;
                    x -= 48;
                    x += shift;
                    x %= 10;
                    x += 48;
                }
            }
            enc.push_back(x);
        }
        return enc;
    }
    
} // namespace maurya

#endif