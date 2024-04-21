#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include <vector>
#include "funcionarios.hpp"
#include "cliente.hpp"
#include "ordem_servico.hpp"

using namespace std;

class Vendedor : public Funcionarios {
private:
    string ordemDeServico;
    vector<Cliente> clientes;
    vector<OrdemServico> ordensDeServico;

public:
    Vendedor(string nome, string cpf, string ordemDeServico);
    Vendedor();
    OrdemServico gerarOrdemDeServico(Cliente cliente, bool manutencao, string motivo, double quilometragem);
    void visualizarOrdensPendentes();
    void marcarOrdemComoAprovada(int indice);
    void visualizarOrdensExecutadas();
    void fecharOrdemDeServico(int indice);
    void cadastrarCliente(Cliente cliente);
    void cadastrarVeiculo(Cliente cliente);
    void aprovarOrdemDeServico(string nomeCliente);
};

#endif
