#include <iostream>

#include <string>
#include <string_view>

#include <cstdint>

namespace
{
    void menu();

    constexpr std::string_view v{ "1 -> 1" };
    std::string e_v1(std::string str, long key)
    {
        std::string fstr{ "" };
        for (int idx{ 0 }; idx < str.length(); ++idx)
        {
            char chr{ str[idx] };
            long num{ chr * key };
            fstr += std::to_string(num) + '.';
        }
        return '.' + fstr;
    }

    std::string d_v1(std::string str, long key)
    {
        std::string fstr{ "" };
        int lst{ 0 };
        for (int idx{ 1 }; idx < str.length(); ++idx)
        {
            if (str[idx] == '.')
            {
                std::string sgm = str.substr(lst + 1, idx);
                sgm = sgm.substr(0, sgm.find('.'));
                fstr += static_cast<char>(std::stoi(sgm) / key);
                lst = idx;
            }
        }
        return fstr;
    }
    void clear()
    {
        std::system("cls");
    }

    void error(std::string msg)
    {
        clear();
        std::cout << "Something went wrong: " << msg << '\n';
        std::system("pause");
        ::menu();
    }

    void encrypt()
    {
        std::system("title Encrypt");
        std::cout << "--- Select one of the variations ---\n\n";
        std::cout << "\t" << ::v << "\n\n> ";
        int chs{};
        std::cin >> chs;
        switch (chs) 
        {
        case 1:
            ::clear();
            std::cout << "--- Enter some text you want to encrypt ---\n\n> ";
            std::string txt{};
            std::getline(std::cin >> std::ws, txt);
            ::clear();
            std::cout << "--- Enter a key (an integer) ---\n\n> ";
            long key{};
            std::cin >> key;
            std::string rsl{::e_v1(txt, key)};
            ::clear();
            std::cout << "Result: " << rsl << '\n';
            std::system("pause");
            ::menu();
            break;
        }
    }

    void decrypt()
    {
        std::system("title Decrypt");
        std::cout << "--- Select one of the variations ---\n\n";
        std::cout << "\t" << ::v << "\n\n> ";
        int chs{};
        std::cin >> chs;
        switch (chs)
        {
        case 1:
            ::clear();
            std::cout << "--- Enter the encrypted text ---\n\n> ";
            std::string txt{};
            std::getline(std::cin >> std::ws, txt);
            ::clear();
            std::cout << "--- Enter the key used during encryption ---\n\n> ";
            long key{};
            std::cin >> key;
            std::string rsl{ ::d_v1(txt, key) };
            ::clear();
            std::cout << "Result: " << rsl << '\n';
            std::system("pause");
            ::menu();
            break;
        }
    }

    void help() 
    {
        std::system("title Help");
        std::cout << "--- What do you need help with? ---\n\n\t1. Keys\n\t2. Go Back\n> ";
        char chs{};
        std::cin >> chs;
        switch (chs) 
        {
        case '1':
            ::clear();
            std::cout << "Your key has to be an integer, otherwise unexpected things could happen.\nIf you need more help please contact the owner on Discord: <@671149601369096202>;\n";
            std::system("pause");
            ::menu();
            break;
        case '2':
            ::menu();
            break;
        default:
            ::error("Invalid Choice; You need to choose 1 or 2;");
            break;
        }

    }

    void menu()
    {
        ::clear();
        std::system("title Menu");
        std::cout << "\tMade by ROMAHKAO\n--- Select one of the following ---\n\n\t1. Encrypt\n\t2. Decrypt\n\t3. Help\n\t4. Quit\n\n> ";
        char chs{};
        std::cin >> chs;
        switch (chs) 
        {
        case '1':
            ::clear();
            ::encrypt();
            break;
        case '2':
            ::clear();
            ::decrypt();
            break;
        case '3':
            ::clear();
            ::help();
            break;
        case '4':
            std::system("exit");
            break;
        default:
            ::error("Invalid Choice; You need to choose 1, 2, 3, or 4;");
            break;
        }
    }
}

int main()
{
    ::menu();
}
