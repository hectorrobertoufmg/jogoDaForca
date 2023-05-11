#include <iostream>
#include <string>
#include <map>
#include <vector>


// O chutou em um container map em que os elementos estão associados a 
// uma chave e valor 

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

bool nao_acertou(std::string PALAVRA_SECRETA)
{
    for(char letra : PALAVRA_SECRETA)
    {
        if(!chutou[letra])
        {
            return true;
        }
        
        
    }

    return false;
}


bool nao_enforcou()
{
    return (lixo.size() < 5); 
}

void abertura_jogo()
{
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    std::cout << "=-=-Bem vindo ao jogo da forca!=-=-==" << std::endl;
    std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
}

void imprime_erros(std::vector<char> lixo)
{
    std::cout <<"Lixo: ";
    
    for(auto letraErrada : lixo)
    {
        std::cout << letraErrada << " ";
    }

    std::cout << std::endl;
}

void imprime_palavra(std::string PALAVRA_SECRETA)
{
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
}

void chuta(std::string PALAVRA_SECRETA)
{
    char chute;
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
    
    std::cout << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::string const PALAVRA_SECRETA = "MELANCIA";
    
    abertura_jogo();   
    
    while((nao_enforcou()) && (nao_acertou(PALAVRA_SECRETA)))
    {   
        imprime_erros(lixo);
        imprime_palavra(PALAVRA_SECRETA);
        chuta(PALAVRA_SECRETA);

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
    }

    std::cout << "Fim de jogo!" << std::endl;
    std::cout << "A palavra secreta era: " << PALAVRA_SECRETA << std::endl;

    if(nao_acertou(PALAVRA_SECRETA))
    {
        std::cout << "Voce perdeu!" << std::endl;
    }
    else
    {
        std::cout << "Você ganhou!" << std::endl;
    }

    return 0;
}