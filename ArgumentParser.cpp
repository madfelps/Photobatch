#include "ArgumentParser.h"
#include "Utils.h"

#include <algorithm>




void ArgumentParser::RegisterFlag(const std::string& flag)
{
    if(!flag.empty())
    {
        m_Flags[flag] = false;
        
    }
}

void ArgumentParser::RegisterOption(const std::string& option)
{
    if(!option.empty())
    {
        m_Options[option] = "";
    }
}

bool ArgumentParser::IsFlagRegistered(const std::string& flag) const
{
    if(!flag.empty())
    {
        return m_Flags.count(flag) == 1;
    }

    return false;
}

bool ArgumentParser::IsOptionRegistered(const std::string& option) const
{
    if(!option.empty())
    {
        return m_Options.count(option) == 1;
    }

    return false;
}

const std::string& ArgumentParser::GetOption(const std::string& option) const
{
    if(!option.empty())
    {
        auto optionIt = m_Options.find(option);
        if(optionIt != std::end(m_Options))
        {
            return optionIt->second;
        }
    }

    static std::string EmptyOption = "";
    return EmptyOption;
}

float ArgumentParser::GetOptionAsFloat(const std::string& option) const
{
    const std::string& optionValue = GetOption(option);
    
    if(!optionValue.empty())
    {
        return std::stof(optionValue);
    }
    return -1;
}

int ArgumentParser::GetOptionAsInt(const std::string& option) const
{
    const std::string& optionValue = GetOption(option);
    
    if(!optionValue.empty())
    {
        return std::stoi(optionValue);
    }
    return -1;
}



bool ArgumentParser::GetFlag(const std::string& flag) const
{
    if(!flag.empty())
    {
        auto flagIt = m_Flags.find(flag);
        if(flagIt != std::end(m_Flags))
        {
            return flagIt->second;
        }
    }
    return false;
}

bool ArgumentParser::CheckHelp() 
{
    const std::string& flag = "help";
    bool IsHelpActive;
    if(!flag.empty())
    {
        auto flagIt = m_Flags.find(flag);

        if(flagIt != std::end(m_Flags))
        {
            IsHelpActive =  flagIt->second;
        }
    }
    
    if(IsHelpActive)
    {
        std::cout << "O Photobatch possui 4 modos: \n";

        std::cout << "Rename: Permite a modificação dos arquivos alvo. " << std::endl;
        std::cout << "- prefix: prefixo dos arquvios renomeados. " << std::endl;
        std::cout << "- startnumber: numero inicial a ser incluido no arquivo renomeado. " << std::endl;

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

        std::cout << "Convert: converte os arquivos alvo de png->jpg e jpg->png" << std::endl;

        std::cout << "- from: tipo de formato de origem para conversão. " << std::endl;
        std::cout << "- to: tipo de formato alvo para conversão.  " << std::endl;

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

        std::cout << "Resize: permite a modificação do tamanho do arquivo. " << std::endl;
        std::cout << "- width: modificação da largura da imagem.  " << std::endl;
        std::cout << "- height: modificação da altura da imagem. " << std::endl;

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

        std::cout << "Scale: permite o dimensionamento em escala dos arquivos. " << std::endl;
        std::cout << "- amount: fator de escala para o arquivo final. " << std::endl;

        std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

        std::cout << "Em comum, os seguintes modos podem ser utilizados para todos os modos: " << std::endl;
        std::cout << "- folder: seleciona o diretório dos arquivos a ser processados. " << std::endl;
        std::cout << "- filter: filtra os arquivos a ser processados conforme a regra do filtro. \n" << std::endl;
    }

    return IsHelpActive;
    
}


void ArgumentParser::Parse(int argc, const char* argv[])
{
    if(argc > 1 && argv != nullptr)
    {
        for(int i = 1; i < argc; ++i)
        {
            std::string arg = Utils::ToLower(argv[i]);

            if(arg.length() >= 3)
            {
                //Argumento tem q ter pelo menos 3 chars
                if(arg[0] == '-' && arg[1] == '-')
                {

                    // --rename
                    //Removendo os "--" iniciais
                    arg = arg.substr(2);

                    //Depois do arg.substr: "rename"
                    if(arg.find_first_of('=') != std::string::npos)
                    {
                    //Isso é uma opção
                        const size_t equalSignPos = arg.find('=');
                        if(equalSignPos != std::string::npos)
                        {
                            //Dividir a opção em chave e valor
                            std::string optionName = arg.substr(0, equalSignPos);
                            std::string optionValue = arg.substr(equalSignPos + 1);

                            auto optionIt = m_Options.find(optionName);
                            if(optionIt != std::end(m_Options))
                            {
                                //Achamos uma opção registrada
                                optionIt->second = optionValue;
                            }
                        }

                    }
                    else
                    {
                        //É uma flag
                        auto flagIt = m_Flags.find(arg);
                        if(flagIt != std::end(m_Flags))
                        {
                            flagIt->second = true;
                        }

                    }
                }
            }
        }
    }
}
