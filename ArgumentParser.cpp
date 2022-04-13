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

void ArgumentParser::Parse(int argc, char* argv[])
{
    if(argc > 1)
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
                    //Removeno os "--" inicais
                    arg = arg.substr(2);

                    //Depois do arg.substr: "rename"
                    if(arg.find_first_of('=') != std::string::npos)
                    {
                    //Isso é uma opção
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