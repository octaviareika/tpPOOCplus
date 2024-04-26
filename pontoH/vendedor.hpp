#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include <vector>
#include "ordem_servico.hpp"
#include "funcionarios.hpp"
#include "cliente.hpp"
#include <stdexcept> 
#include "mecanicos.hpp"
using namespace std;
class Mecanicos;
class Cliente;
class Vendedor : public Funcionarios {
private:
    vector<Cliente> clientes; // armazenar os clientes cadastrados 
    vector<OrdemServico> ordensDeServico; // armazenar as ordens de serviço geradas
public:
    Vendedor(string nome, string cpf);
    Vendedor(); 
    void setNome(const string& nome);
    string getNome() const;
    OrdemServico gerarOrdemDeServico(Cliente* cliente, Mecanicos& mecanico, bool isManutencao, const string& motivo, double quilometragem);
    void visualizarOrdensPendentes();
    void marcarOrdemComoAprovada(int indice, Mecanicos& mecanico);
    void visualizarOrdensExecutadas();
    void cadastrarCliente(const Cliente& cliente);
    void cadastrarVeiculo(const Veiculo& veiculo, const Cliente& cliente);
    void listarClientes() const;
    int getNumClientes() const;
    const Cliente& getCliente(int indice) const;
    void receberOrdemDeServicoVendedor(OrdemServico& ordem);
    void fecharOrdemDeServico(int indice);
};

#endif