#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>
#include <optional>
#include <fstream>
#include <iostream>
#include <sstream>
class InputHandler
{
    public:
    bool isEncrypted;
    std::string GetUserInput();
    void ValidateUserInput(std::string input);
    //If you want to encrypt return true, If you want to decrypt return false
    bool AskForEncryptionType();
    //figure out if we want to encrupt or decrtypt
};
#endif