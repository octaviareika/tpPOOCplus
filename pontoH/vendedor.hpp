#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include "funcionarios.hpp"

using namespace std;

class Vendedor : public Funcionarios {
    
    public:
    Vendedor(string nome, string cpf);
    

};


#endif