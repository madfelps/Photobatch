#include <gtest/gtest.h>
#include <limits>
#include <array>

#include </home/felipe/vscodeprojects/Photobatch/ArgumentParser.h>

TEST(TestArgumentParser, RegisterFlag)
{
    ArgumentParser argParser;

    //Verificar o estado antes da operação
    EXPECT_FALSE(argParser.IsFlagRegistered("MyFlag"));

    argParser.RegisterFlag("MyFlag");

    EXPECT_TRUE(argParser.IsFlagRegistered("MyFlag"));
    
}

TEST(TestArgumentParser, RegisterFlagWhitespace)
{
    ArgumentParser argParser;
    argParser.RegisterFlag("My Flag");

    EXPECT_TRUE(argParser.IsFlagRegistered("My Flag"));
    
}

TEST(TestArgumentParser, RegisterOption)
{
    ArgumentParser argParser;

    argParser.RegisterOption("MyOption");

    EXPECT_TRUE(argParser.IsOptionRegistered("MyOption"));
}

TEST(TestArgumentParser, Parse)
{
    ArgumentParser argParser;

    std::array<const char*, 5> args = 
    {
        "TestArgumentParser",
        "--flag",
        "--string=AaBbCcDd",
        "--number=42",
        "--float=4.2"
    };

    argParser.RegisterFlag("flag");
    argParser.RegisterOption("string");
    argParser.RegisterOption("number");
    argParser.RegisterOption("float");

    argParser.Parse(args.size(), args.data());

    EXPECT_FALSE(argParser.GetFlag("unregisteredFlag"));
    EXPECT_TRUE(argParser.GetFlag("flag"));
    EXPECT_EQ(argParser.GetOptionAs<std::string>("string"), "aabbccdd");
    EXPECT_EQ(argParser.GetOptionAs<int>("number"), 42);
    EXPECT_EQ(argParser.GetOptionAs<float>("float"), 4.2f);

}

TEST(TestArgumentParser, Parse_InvalidArguments)
{
    ArgumentParser argParser;


    argParser.Parse(0, nullptr);
    argParser.Parse(42, nullptr);
    argParser.Parse(-1, nullptr);
}

TEST(TestArgumentParser, HelpMessage)
{
    ArgumentParser argParser;

    std::array<const char*, 5> args = 
    {
        "TestArgumentParser",
        "--HeLp",
        "--string=AaBbCcDd",
        "--number=42",
        "--float=4.2"
    };

    argParser.RegisterFlag("help");
    argParser.RegisterOption("string");
    argParser.RegisterOption("number");
    argParser.RegisterOption("float");

    argParser.Parse(args.size(), args.data());

    EXPECT_TRUE(argParser.CheckHelp());
}