#pragma once 

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>

// Classe usada para ler os argumentos da linha de comando
class ArgumentParser
{
public:
    //Registra uma flag usada durante o parse
    void RegisterFlag(const std::string& flag);

    //Registrar uma opção usada durante o parser
    void RegisterOption(const std::string& option);

    //Obter o valor de uma opção lida durante o parse
    const std::string& GetOption(const std::string& option) const;

    //Obtem o valor de uma flag obtida durante o parse
    bool GetFlag(const std::string& flag) const;

    //Faz o parse da lista de argumento em argv
    void Parse(int argc, char* argv[]);

private:
    std::map<std::string, bool> m_Flags;
    std::map<std::string, std::string> m_Options;
};