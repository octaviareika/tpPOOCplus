#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include <vector>
#include "ordem_servico.hpp"
#include "funcionarios.hpp"
#include "cliente.hpp"

using namespace std;

class Vendedor : public Funcionarios {
private:
    vector<Cliente> clientes;
    vector<OrdemServico> ordensDeServico;

public:
    Vendedor(string nome, string cpf);
    Vendedor(); 
    OrdemServico gerarOrdemDeServico(const Cliente& cliente, bool isManutencao, string motivo, double quilometragem);
    void visualizarOrdensPendentes();
    void setNome(string nome);
    void marcarOrdemComoAprovada(int indice);
    void visualizarOrdensExecutadas();
    void fecharOrdemDeServico(int indice);
    void cadastrarCliente(const Cliente cliente);
    void cadastrarVeiculo(const Cliente cliente);
    friend ostream& operator<<(ostream& os, const OrdemServico& ordem);
    void adicionarVeiculo(Veiculo veiculo);
    string getNome() const;
};

#endif
