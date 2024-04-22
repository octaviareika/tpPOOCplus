#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "cliente.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class OrdemServico {
private:
    Cliente* cliente;
    bool manutencao;
    string motivo;
    double quilometragem;
    bool aprovada;
    bool executada;
    vector<string> servicos;
    vector<double> precosServicos;
    vector<string> pecas;
    vector<double> precosPecas;

public:
    OrdemServico(Cliente* cliente, bool manutencao, string motivo, double quilometragem);
    ~OrdemServico();
    Cliente* getCliente() const;
    string getMotivo() const;
    bool foiAprovada() const;
    bool foiExecutada() const;
    void aprovar();
    void fechar();
    void adicionarServico(const string& servico, double preco);
    void adicionarPeca(const string& peca, double preco);
    bool isManutencao() const;

    OrdemServico& operator=(const OrdemServico& other);

    friend ostream& operator<<(ostream& os, const OrdemServico& ordem);
};

#endif
