#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>
class Cipher
{

    private:

    std::string key;
    std::string plainText;
    std::string cipheredText;
    public:
    virtual ~Cipher() 
    {

    }

    virtual std::string Encrypt(std::string plainText, std::string key) = 0;
    virtual std::string Decrypt(std::string cipheredText, std::string key) = 0;
};
#endif