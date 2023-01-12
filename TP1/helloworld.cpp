#include <iostream>
#include <string>

/*

EXERCICE 1

Pour faire le git et récupérer:
- Allez sur le site du dépôt, cliquez sur fork, et le créer, pas juste voir les forks existant mais bien créer!
- Cliquez sur le bouton Code, recopier le lien https = LIEN_HTTPS, SSH
- Dans le répertoire souhaité:
  $ git clone LIEN_HTTPS
- Le repertoire CPP_Exercises/ se crée, se placer dedans
- Rentrer la commande suivante pour se placer sur la branche tp1:
  $ git checkout tp1
  Le TP1 se crée, avec un CMakeLists.txt dedans

Editer et executer, dans le dossier TP1:
- Créer le fichier .cpp, et faire le code voulu
- Editer/créer le CMakeLists.txt, en ajoutant le nom de l'executable avec tous les fichiers cpp concernés
  Dans notre cas, ce sera:
  add_executable(
    hello
    helloworld.cpp
  )
- Dans le dossier TP1, créer le dossier build, s'y placer, et lancer la commande
  $ cmake ..
  Cela va permettre de créer le make file, et mettre tous les fichiers polluants dans le dossier build
- Ensuite, toujours dans build, on lance:
  $ make
  $ ./hello

g++ ./helloworld.cpp -o hello
./hello

*/

int main(int argc, char** argv){

  std::cout << "Give me your name!" << std::endl;

  auto name = std::string {};
  std::cin >> name;

  std::cout << "Hello " << name << std::endl; 

  return 0;

}