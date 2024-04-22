#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include <vector>
#include "ordem_servico.hpp"
#include "funcionarios.hpp"
#include "mecanicos.hpp"
#include "cliente.hpp"
using namespace std;

class Vendedor : public Funcionarios {
private:
    vector<Cliente> clientes;
    vector<OrdemServico> ordensDeServico;
    Mecanicos& mecanico;
public:
    Vendedor(const string& nome, const string& cpf, Mecanicos& mecanico);
    Vendedor(); 
    void setNome(const string& nome);
    string getNome() const;
    OrdemServico* gerarOrdemDeServico(Cliente& cliente, bool isManutencao, const string& motivo, double quilometragem);
    void visualizarOrdensPendentes();
    void marcarOrdemComoAprovada(int indice);
    void visualizarOrdensExecutadas();
    void fecharOrdemDeServico(int indice);
    void cadastrarCliente(const Cliente& cliente);
    void cadastrarVeiculo(const Veiculo& veiculo, const Cliente& cliente);
    void listarClientes() const;
    int getNumClientes() const;
    const Cliente& getCliente(int indice) const;
    void enviarOrdemParaMecanico(OrdemServico* ordem); 
    OrdemServico* getOrdemDeServico(int numeroOrdem);
};

#endif
