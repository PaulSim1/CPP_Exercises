
#pragma once

#include "Pokemon.h"

#include <memory>

// A ball where a Pokemon sleeps.
class Pokeball {

public:

    bool empty() const{
        return _pokemon == nullptr;
    }

    void store (PokemonPtr pokemon) {
        // move permet d'affecter un pointeur à un autre, on perd dans un pour mettre dans l'autre
        _pokemon = std::move(pokemon);
    }

    // accesseur, depuis le pointeur on peut chopper le pokémon
    const Pokemon& pokemon() const {
        return *_pokemon;
    }


private:
    
    // pointeur pour les pokémons, défini dans Pokémon.h
    PokemonPtr _pokemon;

};