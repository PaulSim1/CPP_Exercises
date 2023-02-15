#pragma once

#include <memory>
#include <string>

// A creature that is cute and can fight other ones.
class Pokemon {

public:

    Pokemon(const std::string& name)
        : _name {name}
        , _id {next_id++}
    {}

    // pour que les copies permettent d'incrémenter les id
    Pokemon(const Pokemon& other)
        : _name { other._name }
        , _id { next_id++ }
    {}
    Pokemon& operator=(const Pokemon& other){
        if (this == &other)
            _name = other._name;
        
        return *this;
    } 

    // premier const et & pour avoir une référence, permet de renvoyer un pointeur, moind lourd que toute la chaine
    // deuxieme const pour créer un pokémon sous forme de constante
    const std::string& name() const {
        return _name;
    }

    // const pour créer un pokémon sous forme de constante
    int id() const {
        return _id;
    }


private:
    
    static inline int next_id = 0;

    std::string _name;
    int _id = 0;

};

// pointeur pour les pokémons
using PokemonPtr = std::unique_ptr<Pokemon>;
