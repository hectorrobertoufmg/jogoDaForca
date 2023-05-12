#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>



// Cria um container do tipo map (só pode acessar elementos via key e nao index)
std::map<char, bool> chutou;

// vector é um outro tipo de container que permite o acesso via index, mas tem certas
// o peração que ele não é muito bom, por exemplo, adicionar um elemento em algum lugar
// no meio da lista.
std::vector<char> lixo;

// Funcao confereLetra() ela recebe dois parâmetros, o primeiro é o chute do usuário
// O segundo é a letra secreta. Esta função corre a letra_secreta e vai comparando
// Coma letra que o usuario chutou
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



// Funcção que retorna um tipo bool. Esta função compara a letra que o usuário chutou
// Se a letra tiver dentro do map, então o usário acertou, logo a funcao retorna false
// Se a pesso errou, ela retorna true
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

// Se o número de letras for = 5, então ela desenhou o elemento e o bonito enforcou

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

void le_arquivo()
{
    std::ifstream arquivo;
    arquivo.open("palavras.txt");
    
    int quantidade_palavras;
    
    arquivo >> quantidade_palavras;

    for(auto i = 0; i < quantidade_palavras; ++i)
    {
        std::string palavra_lida;

        arquivo >> palavra_lida;

    }


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