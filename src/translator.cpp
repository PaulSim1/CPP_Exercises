#include <fstream>
#include <iostream>
#include <map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>

using Dico = std::map<std::string, std::string>;

std::unordered_set<std::string> make_exit_commands(){
    return { "q", "e", "exit", "quit" };
}

int main(){

    std::string line;
    Dico dico;

    std::cout << std::endl;

    while(true) {

        // cin >> word -> ne permet que de prendre qu'un mot
        getline (std::cin, line);

        // Pour quitter
        if(make_exit_commands().count(line)){
            std::cout << std::endl;
            break;
        }

        std::stringstream ss(line); // un flux de la chaine line
        std::string word; // chaque mot du flux
        std::vector<std::string> values; // flux en tableau

        // Pour chaque mot du flux on le met dans le tableau, ce sera plus facile à manier ensuite
        while (ss >> word)
            values.emplace_back(word);

        // Affichage et clear
        if(values.size()==1){

            if(values[0]=="print"){

                if (dico.size() == 0)
                    std::cout << "dico empty\n" << std::endl;

                else{
                    for (auto it=dico.begin(); it!=dico.end(); ++it){
                        std::cout << it->first << " => " << it->second << std::endl;
                    }
                    std::cout << std::endl;
                }

            }

            if(values[0]=="clear"){
                dico.clear();
                std::cout << "dico cleared\n" << std::endl;
            }

        }

        // Add, traduction, save, load et remove
        if(values.size()>=2){

            if(values[0]=="add" && values.size()==3){
                if (dico.find(values[1]) == dico.end()){
                    std::cout << values[1] << "=>" << values[2] << "\n" << std::endl;
                    dico.emplace(values[1], values[2]);
                }
                else
                    std::cout << values[1] << " already has a traduction\n" << std::endl;
            }

            if(values[0]=="translate"){
                for(int i = 1; i<values.size(); i++){
                    if (dico.find(values[i]) == dico.end())
                        std::cout << "???" << std::endl;
                    else
                        std::cout << values[i] << " -> " << dico[values[i]] << std::endl;
                }
                std::cout << std::endl;
            }

            if(values[0]=="save" && values.size()==2){

                if (dico.size() == 0)
                    std::cout << "dico empty\n" << std::endl;

                else{
                    std::ofstream myfile;
                    myfile.open (values[1]+".txt");
                    for (auto it=dico.begin(); it!=dico.end(); ++it){
                        myfile << it->first + " " + it->second + "\n";
                    }
                    myfile.close();
                    std::cout << values[1] << ".txt was created successfully\n" << std::endl;
                }

            }

            if(values[0]=="load" && values.size()==2){

                std::ifstream myfile (values[1]);
                if ( myfile.is_open() ) {
                    std::string line;
                    while (std::getline(myfile, line)){
                        std::istringstream iss(line);
                        std::string a, b;
                        if (!(iss >> a >> b)) { break; }
                        else{
                            //std::cout << a << " " << b << std::endl;
                            if (dico.find(a) == dico.end()){
                                std::cout << a << "=>" << b << std::endl;
                                dico.emplace(a, b);
                            }
                            else
                                std::cout << a << " already has a traduction" << std::endl;
                        }
                    }
                    std::cout << std::endl;
                }
                else{
                    std::cout << "can't find " << values[1] << "\n" << std::endl;
                }

            }

            if(values[0]=="remove" && values.size()==2){
                //dico.erase(values[1]); juste pour effacer ceux avec la clé choisie
                for (auto it=dico.begin(); it!=dico.end(); ++it){
                    if(it->first==values[1] || it->second==values[1]){
                        dico.erase(it);
                        std::cout << "remove " << values[1] << " complete" << std::endl;
                    }
                    std::cout << std::endl;
                }
            }

        }

    }

    return 0;
}