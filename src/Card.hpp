#pragma once

#include <string>

enum class CardType{
    Monster,
    Spell,
    Trap,
};


std::string to_string(const CardType type){
    switch (type){
        case CardType::Monster:
            return "Monster";

        case CardType::Spell:
            return "Spell";

        case CardType::Trap:
            return "Trap";
    }
    return "";
}

class Card{

    public:

        Card(std::string id, CardType type)
            : _id { std::move(id) } //sans move ça marche quand même, permet juste de déplacer les données
            , _type { type }
        {}

        /*
        - premier const et & pour transmettre pointeur d'une chaine, moins couteux, on renvoie une "référence"
        - deuxième const pour être sur qu'on ne modifie rien (si on met ce const on est obligé de mettre le premier?)
          on doit le mettre quand on veut définir des fonctions-membres constantes
        */
        const std::string& get_id() const{
            return _id;
        }

        CardType get_type() const {
            return _type;
        }

        std::string get_name() const {
            return _name;
        }

        std::string get_description() const {
            return _description;
        }

        void set_name(std::string name){
            _name = name;
        }

        void set_description (std::string description){
            _description = description;
        }

    protected:
        

    private:
        std::string _id;
        CardType _type;
        std::string _name;
        std::string _description;

};