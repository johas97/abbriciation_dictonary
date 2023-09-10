#include <string>
#include <stdlib.h>


void google_abbriv(std::string user_abriv)
{
    
    std::string op = std::string("start https://www.google.com/search?q=definition+of+").append(user_abriv);
    system(op.c_str());

}

void google_abbriv_sv(std::string user_abriv)
{
    //Söker på svenska!
    std::string op = std::string("start https://www.google.com/search?q=Definition+av+").append(user_abriv);
    system(op.c_str());

}

void google_abbriv_fr(std::string user_abriv)
{
    //Söker på svenska!
    std::string op = std::string("start https://www.google.com/search?q=la+définition+du+").append(user_abriv);
    system(op.c_str());

}


void ddgo_search(std::string user_abriv)
{
    
    std::string op = std::string("start https://duckduckgo.com/?q=definition+of+").append(user_abriv);
    system(op.c_str());

}

void ddgo_search_sv(std::string user_abriv)
{
    //Söker på svenska!
    std::string op = std::string("start https://duckduckgo.com/?q=Definition+av+").append(user_abriv);
    system(op.c_str());

}

void ddgo_search_fr(std::string user_abriv)
{
    //Söker på svenska!
    std::string op = std::string("start https://duckduckgo.com/?q=la+définition+du+").append(user_abriv);
    system(op.c_str());

}