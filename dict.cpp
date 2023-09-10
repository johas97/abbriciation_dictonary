#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "search_functions.h"

/* class dictonary
{

}; */


struct dict_entry
{
    std::string short_name;
    std::string full_name;
   // std::string description;
};

void print_map(std::map<std::string, dict_entry> map_to_print)
{
     for (auto& [short_name, entry] : map_to_print)
    {
        std::cout << short_name << std::endl;
        std::cout << entry.full_name << std::endl;
    }
}


void add_abbriv( std::map<std::string, dict_entry>& dict_map ,std::string user_abriv)
{
    dict_entry temp_entry;

    print_map(dict_map);

    std::cout << "Enter definition for " << user_abriv << ": ";
    std::getline(std::cin,temp_entry.full_name);
    
    temp_entry.short_name = user_abriv;
    dict_map[temp_entry.short_name] = temp_entry;         
}




int main()
{
    
    
    // read the file########################################################
    std::ifstream MyReadFile("Abbrevations.txt");

    // add to map ########################################################
    std::map<std::string, dict_entry> dict_map;
    std::string full_line;
    while (getline(MyReadFile, full_line))
    {
        // Ignore empty lines 
        if(full_line == "") {continue;}

        //create abbriviation entry to map
        dict_entry temp_entry;
        temp_entry.short_name = full_line.substr(0, full_line.find(" "));  
        temp_entry.full_name = full_line.substr(full_line.find("-"), full_line.size());
        dict_map[temp_entry.short_name] = temp_entry;         
    }

    // console input
    std::string user_abriv;
    while (true)
    {
        std::cout << "Enter abbriviation: ";
        std::cin >> user_abriv;

        // search for abbriveation
        if(dict_map[user_abriv].full_name != "") {
            std::cout << dict_map[user_abriv].full_name << std::endl;
        }
        else{
            std::cout << "No such abbriviation, do you wanna search google? (press g): ";
            
            std::string action_no_match;
            std:: cin >> action_no_match;

            //Search options 
            if (action_no_match == "g") { google_abbriv(user_abriv);}
            if (action_no_match == "g_sv") { google_abbriv_sv(user_abriv);}
            if (action_no_match == "g_fr") { google_abbriv_fr(user_abriv);}

            if (action_no_match == "d") { ddgo_search(user_abriv);}
            if (action_no_match == "d_sv") { ddgo_search_sv(user_abriv);}
            if (action_no_match == "d_fr") { ddgo_search_fr(user_abriv);}
 
            if (action_no_match == "a") { add_abbriv(dict_map, user_abriv);}

        }
        

    }
    
    
   
    // no dubblecates.

    // deliver description


// 

      // Close the file
    MyReadFile.close();
}



