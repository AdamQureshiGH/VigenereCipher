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
    int keyShift;
    char NumEncrypt(char c);
    char CharEncrypt(char c);
    char CharDecrypt(char c);
    char NumDecrypt(char c);
    std::string NormalizeKey(std::string oldkey);
    std::string Encrypt(std::string plainText, std::string key) override;
    std::string Decrypt(std::string cipheredText, std::string key) override;
};
#endif
