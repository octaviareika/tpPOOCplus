#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "cliente.hpp"
#include <vector>
#include <mecanicos.hpp>
#include <string>
#include <iostream>
class Mecanicos;
using namespace std;

class OrdemServico {
private:
    Cliente* cliente;
    Mecanicos* mecanico;
    bool manutencao;
    string motivo;
    double quilometragem;
    int numero;
    bool aprovada;
    bool finalizada;
    bool realizada;
    vector<string> servicos;
    vector<double> precosServicos;
    vector<string> pecas;
    vector<double> precosPecas;

public:
    OrdemServico(Cliente* cliente, Mecanicos* mecanico, bool manutencao, string motivo, double quilometragem,int numero);
    OrdemServico();
    Cliente* getCliente() const;
    string getMotivo() const;
    bool foiAprovada() const;
    bool foiExecutada() const;
    void aprovar();
    void fechar();
    void adicionarServico(const string& servico, double preco);
    void adicionarPeca(const string& peca, double preco);
    bool finalizar() const;
    bool isManutencao() const;
    void executar();
    int getNumero() const;
    bool isValid() const;
    void setCliente(Cliente* cliente);
    void setMecanico(Mecanicos* mecanico);
    string getMecanico() const;;
    void setNumero(int numero);
    OrdemServico& operator=(const OrdemServico& other);
    friend ostream& operator<<(ostream& os, const OrdemServico& ordem);
};

#endif