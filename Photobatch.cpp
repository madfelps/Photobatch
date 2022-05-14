#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <array>
#include <filesystem>

#include "ArgumentParser.h"

namespace Args
{
    namespace Flags
    {
        static constexpr const char* Rename     = "rename";
        static constexpr const char* Convert    = "convert";
        static constexpr const char* Resize     = "resize";
        static constexpr const char* Scale      = "scale";
        static constexpr const char* Help       = "help";
    }

    namespace Opts
    {
        static constexpr const char* Folder         = "folder";
        static constexpr const char* Filter         = "filter";
        static constexpr const char* Width          = "width";
        static constexpr const char* Height         = "height";
        static constexpr const char* Amount         = "amount";
        static constexpr const char* Prefix         = "prefix";
        static constexpr const char* StartNumber    = "startnumber";
        static constexpr const char* From           = "from";
        static constexpr const char* To             = "to";
    }
}

const std::string& GetInvalidChars()
{
    static const std::string invalidCharacters = "\\/*?\"<>:|:&";
    return invalidCharacters;
}

bool HasInvalidChars(const std::string& str)
{
    
    const bool bHasInvalidChars = str.find_first_of(GetInvalidChars()) != std::string::npos;
    return bHasInvalidChars;
    
}

void ValidateArguments(const ArgumentParser& argParser)
{
    //Ler flags que o ArgumentParser identificou
    const bool bRenameMode = argParser.GetFlag(Args::Flags::Rename);
    const bool bConvertMode = argParser.GetFlag(Args::Flags::Convert);
    const bool bResizeMode = argParser.GetFlag(Args::Flags::Resize);
    const bool bScaleMode = argParser.GetFlag(Args::Flags::Scale);


    const std::array<bool, 4>modes = {bRenameMode, bConvertMode, bResizeMode, bScaleMode};

    const std::ptrdiff_t numActiveModes = std::count(std::begin(modes), std::end(modes), true);

    //Verificar se somente um modo está ativo
    //if(!(bRenameMode ^ bConvertMode ^ bResizeMode ^ bScaleMode))
    if(numActiveModes != 1)
    {
        std::cout << "NumActiveModes: " << numActiveModes;
        //Lança exceção
        throw std::invalid_argument("Somente um modo pode estar ativo");
    }

    //Validar a pasta passada como opção
    const std::string folder = argParser.GetOptionAs<std::string>(Args::Opts::Folder);
    if(folder.empty())
    {
        throw std::invalid_argument("A pasta não pode estar vazia. ");
    }

    if(!std::filesystem::exists(folder))
    {
        //throw std::invalid_argument("A pasta informada não existe. ");
    }

    //Validar se o filtro é uma string válida
    const std::string filter = argParser.GetOptionAs<std::string>(Args::Opts::Filter);

    if(!filter.empty() && HasInvalidChars(filter))
    {
        const std::string invalidCharacters = "\\/*?\"<>:|";
        if(filter.find_first_of(invalidCharacters) != std::string::npos)
        {
            throw std::invalid_argument("O filtro não pode conter " + GetInvalidChars());
        }
    } 

    //Validar o modo Resize
    if(bResizeMode)
    {
        int width = 0;
        int height = 0;

        try
        {
            width     = argParser.GetOptionAs<int>(Args::Opts::Width);
            height    = argParser.GetOptionAs<int>(Args::Opts::Height);
        }
        catch(const std::invalid_argument& exception)
        {
            throw std::invalid_argument("O valor informado para Width ou Height não são números válidos. ");
        }

        //No modo resize o comprimento e a altura devem ser maiores que zero
        if(width <= 0 || height <= 0)
        {
            throw std::invalid_argument("Width e Height devem ser maiores que zero.");
        }

        if(filter.empty())
        {
            throw std::invalid_argument("Filter não pode estar em branco no modo Resize.");
        }
    }

    //Validar o modo Scale
    if(bScaleMode)
    {
        float amount = 0.0f;

        try
        {
            amount = argParser.GetOptionAs<float>(Args::Flags::Scale);
        }
        catch(const std::invalid_argument&)
        {
            throw std::invalid_argument("O valor informado para Amount não é um número válido. ");
        }
        

        //No modo escala, o amount deve ser maior que zero
        if(amount <= 0.0f)
        {
            throw std::invalid_argument("Amount deve ser maior que zero.");
        }

        if(filter.empty())
        {
            throw std::invalid_argument("Filter não pode estar em branco no modo Scale.");
        }
        
    }

    // Validar o modo rename
    if(bRenameMode)
    {
        
        int startNumber = -1;

        try
        {
            startNumber = argParser.GetOptionAs<int>(Args::Opts::StartNumber);
        }
        catch(const std::invalid_argument&)
        {
            throw std::invalid_argument("O valor informado para StartNumber não é um número válido");
        }


        std::string prefix  = argParser.GetOptionAs<std::string>(Args::Opts::Prefix); 

        if(startNumber < 0)
        {
            throw std::invalid_argument("StartNumber deve ser maior que zero");
        } 

        if(prefix.empty() || HasInvalidChars(prefix))
        {
            throw std::invalid_argument("Prefix não pode estar em branco e não pode conter os caracteres " + GetInvalidChars());
        }


    }

    //Validar o modo Convert
    if(bConvertMode)
    {
        const std::string from  = argParser.GetOptionAs<std::string>(Args::Opts::From);
        const std::string to    = argParser.GetOptionAs<std::string>(Args::Opts::To);
        const std::array<std::string, 2> convertOptions = { "jpg", "png" };

        const bool bIsFromValid = std::find(std::begin(convertOptions), std::end(convertOptions), from) != std::end(convertOptions);
        const bool bIsToValid   = std::find(std::begin(convertOptions), std::end(convertOptions), to) != std::end(convertOptions);

        if(!bIsFromValid || !bIsToValid)
        {
            throw std::invalid_argument("From e To devem ser jpg ou png");
        }

        if(from == to)
        {
            throw std::invalid_argument("From e To devem ser diferentes");
        }


    }


  
}

int main(int argc, const char* argv[])
{

    setlocale(LC_ALL, "pt_BR");
    setlocale(LC_NUMERIC, "en_US");


    ArgumentParser argParser;

    //Registra as flags
    argParser.RegisterFlag(Args::Flags::Rename);
    argParser.RegisterFlag(Args::Flags::Convert);
    argParser.RegisterFlag(Args::Flags::Resize);
    argParser.RegisterFlag(Args::Flags::Scale);
    argParser.RegisterFlag(Args::Flags::Help);

    //Registra as opções do Photobatch
    argParser.RegisterOption(Args::Opts::Folder);
    argParser.RegisterOption(Args::Opts::Filter);
    argParser.RegisterOption(Args::Opts::Width);
    argParser.RegisterOption(Args::Opts::Height);
    argParser.RegisterOption(Args::Opts::Amount);
    argParser.RegisterOption(Args::Opts::Prefix);
    argParser.RegisterOption(Args::Opts::StartNumber);
    argParser.RegisterOption(Args::Opts::From);
    argParser.RegisterOption(Args::Opts::To);

    argParser.Parse(argc, argv);

    if(argParser.CheckHelp())
    {
        return 0;
    }

    ValidateArguments(argParser);
    
    

    std::cout << std::boolalpha << "Rename : " << argParser.GetFlag(Args::Flags::Rename) << std::endl;
    std::cout << std::boolalpha << "Convert : " << argParser.GetFlag(Args::Flags::Convert) << std::endl;
    std::cout << std::boolalpha << "Resize : " << argParser.GetFlag(Args::Flags::Resize) << std::endl;
    std::cout << std::boolalpha << "Scale : " << argParser.GetFlag(Args::Flags::Scale) << std::endl;


    std::cout << "Folder: " << argParser.GetOptionAs<std::string>("folder") << std::endl;
    //std::cout << "Amount (float) : " << argParser.GetOptionAs<float>("amount") << std::endl;
    //std::cout << "Amount (int)   : " << argParser.GetOptionAs<int>("amount") << std::endl;

    try
    {
        ValidateArguments(argParser);
    }
    catch(const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }
    

   
    return 0;
}

