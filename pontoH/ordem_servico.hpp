// ordem_servico.hpp
#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "cliente.hpp"

class OrdemServico {
private:
    Cliente cliente;
    bool manutencao; // true se for manutenção, false se for orçamento
    string motivo;
    double quilometragem;
    bool aprovada;
    bool executada;
    vector<string> servicos;
    vector<double> precosServicos;
    vector<string> pecas;
    vector<double> precosPecas;

public:
    OrdemServico(Cliente cliente, bool manutencao, string motivo, double quilometragem);
    Cliente getCliente() const;
    string getMotivo() const;
    bool foiAprovada() const;
    bool foiExecutada() const;
    void aprovar();
    void fechar();
    void adicionarServico(const string& servico, double preco);
    void adicionarPeca(const string& peca, double preco);
};

#endif
