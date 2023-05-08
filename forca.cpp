#include <iostream>
#include <string>


int main()
{
    std::string const PALAVRA_SECRETA = "MELANCIA";
    
    bool nao_enforcou = true;
    bool nao_acertou = true;
    std::string chute;

    while(nao_acertou && nao_acertou)
    {
        std::cout <<"Escolha uma palavra: ";
        std::cin >> chute;
        if(chute == PALAVRA_SECRETA)
        {
            std::cout <<"Parabéns você acertou a palavra!" << std::endl;
            nao_acertou = false;
        }
    }


    return 0;
}