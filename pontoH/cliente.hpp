#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <vector>
#include "veiculo.hpp"
using namespace std;
class OrdemServico;
class Cliente {
    private:
    string nome;
    string cpf;
    string endereco;
    string telefone;
    Veiculo veiculo;
    bool ordemDeServiçoAprovada;
    vector<OrdemServico> ordensServico;

    public:
    void adicionarOrdemServico(const OrdemServico& ordem);
    Cliente(string nome, string cpf, string endereco, string telefone, Veiculo veiculo);
    Cliente();
    string getNome() const;
    string getCpf() const;
    string getEndereco() const;
    string getTelefone() const;
    bool getAprovacao() const;
    void setNome(string nome);
    void setCpf(string cpf);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setVeiculo(Veiculo veiculo);
    void setAprovacao(bool ordemDeServicoAprovacao);
    Veiculo getVeiculo() const;

    

};

#endif