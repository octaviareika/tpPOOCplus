#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP

#include <iostream>

using namespace std;

class Funcionarios {
    private:
    string nome; 
    string cpf;

    public:
    Funcionarios(string nome, string cpf);
    string getNome();
    string getCpf();
    void setNome(string nome);
    void setCpf(string cpf);
};

#endif