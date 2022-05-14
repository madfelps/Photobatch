#pragma once 

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>

template<typename T>
struct tag { using type = T; };

// Classe usada para ler os argumentos da linha de comando
class ArgumentParser
{
public:
    //Registra uma flag usada durante o parse
    void RegisterFlag(const std::string& flag);

    //Registrar uma opção usada durante o parser
    void RegisterOption(const std::string& option);

    //Registrar se a flag está registrada
    bool IsFlagRegistered(const std::string& flag) const;


    //Registrar se a opção está registrada
    bool IsOptionRegistered(const std::string& option) const;

    //Obtem o valor de uma flag obtida durante o parse
    bool GetFlag(const std::string& flag) const;

    template<typename T>
    T GetOptionAs(const std::string& option) const { return GetOptionAs(option, tag<T>{}); }

    const std::string& GetOptionAs(const std::string& option, tag<std::string>) const { return GetOption(option); }

    float GetOptionAs(const std::string& option, tag<float>) const{return GetOptionAsFloat(option); }

    int GetOptionAs(const std::string& option, tag<int>) const { return GetOptionAsInt(option); }


    //Faz o parse da lista de argumento em argv
    void Parse(int argc, const char* argv[]);

    //Check existência do comando help e mostra na tela
    bool CheckHelp();

private:
    std::map<std::string, bool> m_Flags;
    std::map<std::string, std::string> m_Options;

    //Obter o valor de uma opção lida durante o parse
    const std::string& GetOption(const std::string& option) const;

    //Obter o valor de uma opção convertida para float
    float GetOptionAsFloat(const std::string& option) const;

    //Obter o valor de uma opção convertida para int
    int GetOptionAsInt(const std::string& option) const;

    
};

