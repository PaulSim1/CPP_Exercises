#pragma once

#include <string>

#include "Card.hpp"

enum class Attribute{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind,
};

std::string to_symbol(const Attribute attribute){
    switch (attribute){

        case Attribute::Dark:
            return u8"闇";

        case Attribute::Divine:
            return u8"神";

        case Attribute::Earth:
            return u8"地";

        case Attribute::Fire:
            return u8"炎";

        case Attribute::Light:
            return u8"光";

        case Attribute::Water:
            return u8"水";

        case Attribute::Wind:
            return u8"風";

    }

    return "";
}

// Monster hérite de Card
class Monster: public Card{

    public:

        // Vu que Monster hérite de Card, des variables sont affectées 
        Monster(std::string id, std::string name, Attribute attribute, std::string description, int atk, int def)
            : Card { std::move(id), CardType::Monster }
            , _attribute { attribute }
            , _description { std::move(description) }
            , _atk { atk }
            , _def { def }
        {
            set_name(std::move(name));
        }

        Attribute get_attribute() const {
            return _attribute;
        }

        int get_atk() const {
            return _atk;
        }

        int get_def() const {
            return _def;
        }

        std::string get_description() const {
            return "[" + _description + "]\n" + Card::get_description() + "\nATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
        }

    protected:
        

    private:
        Attribute _attribute;
        std::string _description;
        int _atk;
        int _def;

};