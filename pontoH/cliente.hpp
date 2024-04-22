#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include "veiculo.hpp"
using namespace std;

class Cliente {
    private:
    string nome;
    string cpf;
    string endereco;
    string telefone;
    Veiculo veiculo;
    bool ordemDeServiçoAprovada;


    public:
    Cliente(string nome, string cpf, string endereco, string telefone, Veiculo veiculo);
    Cliente();
    string getNome();
    string getCpf();
    string getEndereco();
    string getTelefone();
    bool getAprovacao();
    void setNome(string nome);
    void setCpf(string cpf);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setVeiculo(Veiculo veiculo);
    void setAprovacao(bool ordemDeServicoAprovacao);
    Veiculo getVeiculo();

    

};

#endif