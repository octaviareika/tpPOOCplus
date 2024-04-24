#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include <vector>
#include "ordem_servico.hpp"
#include "funcionarios.hpp"
#include "mecanicos.hpp"
#include "cliente.hpp"
#include <stdexcept> 
#include "mecanicos.hpp"
using namespace std;
class Mecanicos;
class Vendedor : public Funcionarios {
private:
<<<<<<< HEAD
    vector<Cliente> clientes;
    vector<OrdemServico> ordensDeServico;
    Mecanicos& mecanico;
=======
    vector<Cliente> clientes; // armazenar os clientes cadastrados 
    vector<OrdemServico> ordensDeServico; // armazenar as ordens de serviço geradas
>>>>>>> testezin
public:
    Vendedor(const string& nome, const string& cpf, Mecanicos& mecanico);
    Vendedor(); 
    void setNome(const string& nome);
    string getNome() const;
<<<<<<< HEAD
    OrdemServico* gerarOrdemDeServico(Cliente& cliente, bool isManutencao, const string& motivo, double quilometragem);
=======
    OrdemServico gerarOrdemDeServico(Cliente& cliente, Mecanicos& mecanico, bool isManutencao, const string& motivo, double quilometragem);
>>>>>>> testezin
    void visualizarOrdensPendentes();
    void marcarOrdemComoAprovada(int indice, Mecanicos& mecanico);
    void visualizarOrdensExecutadas();
    void cadastrarCliente(const Cliente& cliente);
    void cadastrarVeiculo(const Veiculo& veiculo, const Cliente& cliente);
    void listarClientes() const;
    int getNumClientes() const;
    const Cliente& getCliente(int indice) const;
<<<<<<< HEAD
    void enviarOrdemParaMecanico(OrdemServico* ordem); 
    OrdemServico* getOrdemDeServico(int numeroOrdem);
=======
    void receberOrdemDeServicoVendedor(OrdemServico& ordem);
    void fecharOrdemDeServico(int indice);
>>>>>>> testezin
};

#endif
