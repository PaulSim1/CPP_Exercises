#pragma once
#include <iostream>
#include <string>

class Plush {

public:

    Plush(){
        _cost = 10;
    }

    Plush(const int &price){
        _cost = price;
    }

    void set_cost(const int &cost){
        _cost = cost;
    }

    int get_cost(){
        return _cost;
    }

private:
    int _cost;

};