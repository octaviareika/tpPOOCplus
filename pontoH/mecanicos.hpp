#ifndef MECANICOS_HPP
#define MECANICOS_HPP

#include <iostream>

#include "funcionarios.hpp"
using namespace std;

class Mecanicos : public Funcionarios {
    private:
    double salarioBase;
    double bonusSalario;

    public:
    Mecanicos(string nome, string cpf, double salarioBase, double bonusSalario);
    double getSalarioBase();
    double getBonusSalario();
    void setSalarioBase(double salarioBase);
    void setBonusSalario(double bonusSalario);
    

};

#endif