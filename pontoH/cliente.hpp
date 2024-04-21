#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include "veiculo.hpp";
using namespace std;

class Cliente {
    private:
    string nome;
    string cpf;
    string endereco;
    string telefone;
    Veiculo veiculo;
    

    public:
    Cliente(string nome, string cpf, string endereco, string telefone);
    string getNome();
    string getCpf();
    string getEndereco();
    string getTelefone();
    void setNome(string nome);
    void setCpf(string cpf);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setVeiculo(Veiculo veiculo);
    Veiculo getVeiculo();
    

};

#endif