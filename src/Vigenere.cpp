#include "Vigenere.h"
std::string Vigenere::NormalizeKey(std::string oldkey)
{
    std::string newKey{};
    for(char c : oldkey)
    {
        if(isalpha(c))
        {
        newKey += tolower(c); 
        }
    }
    return newKey;
}
std::string Vigenere::Encrypt(std::string plainText, std::string key) {
    key = NormalizeKey(key);
    std::string cipheredText;   
    int keyI = 0;
    keyShift = 0;
    for(char c: plainText)
    {
        if(isalpha(c))
        {
            if(isupper(c))
            {
            keyShift = key[keyI] - 'A';
            keyI++;
             keyI = (keyI % key.length());
            cipheredText.push_back(CharEncrypt(c));
            }
           else if(islower(c))
            {
            keyShift = key[keyI] - 'a';
             keyI++;
             keyI = (keyI % key.length());
            cipheredText.push_back(CharEncrypt(c));
            }
        }
        else if(isdigit(c))
        {
            keyShift = key[keyI] - '0';
            keyI++;
            keyI = (keyI % key.length());

            cipheredText.push_back(NumEncrypt(c));
        }
        else{
            cipheredText.push_back(c);
        }
    }
return cipheredText;
}
char Vigenere::NumEncrypt(char c)
{
    c = c - '0';
    c += keyShift;
    c = c % 10;
    c = c + '0';
    return c;
}
char Vigenere::CharEncrypt(char c)
{
    if(isupper(c))
        {
            c = c - 'A';
            c += keyShift + 26;
             c = c % 26;
            c = c + 'A';
            return c;
        }   
    else if (islower(c))
        {
            c = c - 'a';
            c += keyShift + 26;
             c = c % 26;
            c = c + 'a';
            return c;
        }
    else {
    return c;
    }
}
char Vigenere::CharDecrypt(char c)
{
if(isupper(c))
        {
            c = c - 'A';
            c = c - keyShift + 26; // Add 26 to deal with negatives
             c = c % 26;
            c = c + 'A';

            return c;
        }   
    else if (islower(c))
        {
            c = c - 'a';
            c = c - keyShift + 26; //Add 26 to deal with negatives
               c = c % 26;
            c = c + 'a';

            return c;
        }
    else {
    return c;
    }
}
char Vigenere::NumDecrypt(char c)
{
    c = c - '0';
    c = c - keyShift + 10; // Add 10 to ensure positive
     c = c % 10;
    c = c + '0';

    return c;
}

std::string Vigenere::Decrypt(std::string cipheredText, std::string key) {
        key = NormalizeKey(key);
std::string uncipheredText;   
    int keyI = 0;
    keyShift = 0;
    for(char c: cipheredText)
    {
        if(isalpha(c))
        {
            if(isupper(c))
            {
            keyShift = key[keyI] - 'A';
            keyI++;
             keyI = (keyI % key.length());
            uncipheredText.push_back(CharDecrypt(c));
            }
           else if(islower(c))
            {
            keyShift = key[keyI] - 'a';
             keyI++;
             keyI = (keyI % key.length());
            uncipheredText.push_back(CharDecrypt(c));
            }
        }
        else if(isdigit(c))
        {
            keyShift = key[keyI] - '0';
            keyI++;
            keyI = (keyI % key.length());

            uncipheredText.push_back(NumDecrypt(c));
        }
        else{
            uncipheredText.push_back(c);
        }
    }
return uncipheredText;
}
Vigenere::~Vigenere() {
    // Clean up resources if necessary
    // If there were dynamically allocated resources, they would be freed here
}