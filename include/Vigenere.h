#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>
#include <vector>
//#include <optional>
#include <fstream>
#include <iostream>
#include <sstream>
#include "cipher.h"
class Vigenere : public Cipher
{
    public:
    ~Vigenere() override;
     std::string Encrypt(std::string plainText, std::string key) override;
    std::string Decrypt(std::string cipheredText, std::string key) override;
};
#endif
