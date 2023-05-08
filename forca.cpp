#include <iostream>
#include <string>
#include <map>
#include <vector>


std::map<char, bool> chutou;

std::vector<char> lixo;

bool confereLetra(char chute, std::string letra_secreta)
{
    for(char letra : letra_secreta)
    {
        
        if(chute == letra)
        {
            return true;
        }
        
    }

    return false;
    
}



int main()
{
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    std::cout << "=-=-Bem vindo ao jogo da forca!=-=-==" << std::endl;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    std::string const PALAVRA_SECRETA = "MELANCIA";
    
    bool nao_enforcou = true;
    bool nao_acertou = true;
    char chute;

    while(nao_enforcou && nao_acertou)
    {   
        std::cout << std::endl;
        std::cout << std::endl;
        for(char letra : PALAVRA_SECRETA)
        {
            if(chutou[letra])
            {
                std::cout << letra << " ";

            }
            else
            {
                std::cout << "_ ";
            }
            
        }
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout <<"Lixo: ";
        
        for(auto letraErrada : lixo)
        {
            std::cout << letraErrada << " ";
        }

        std::cout << std::endl;


        std::cout <<"Escolha uma palavra: ";
        std::cin >> chute;

        if(confereLetra(chute, PALAVRA_SECRETA))
        {
            chutou[chute] = true;
        }
        else
        {
            chutou[chute] = false;
            lixo.push_back(chute);
        }

        
    }

    return 0;
}