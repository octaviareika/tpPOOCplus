#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "funcionarios.hpp"
#include "cliente.hpp"
#include "mecanicos.hpp"
#include "ordem_servico.hpp"
#include <vector>

class Vendedor : public Funcionario {
private:
    std::vector<Cliente> clientes;
    std::vector<OrdemDeServico> ordensDeServico;

public:
    Vendedor(const std::string& nome, const std::string& senha);
    ~Vendedor();
    void cadastrarCliente(const Cliente& cliente);
    void cadastrarVeiculo(Veiculo& veiculo, Cliente& cliente);
    void gerarOrdemDeServico(Cliente* cliente, Mecanico& mecanico, bool isManutencao, const std::string& motivo, double quilometragem);
    void visualizarOrdensPendentes();
    void marcarOrdemComoAprovada(int indice, Mecanico& mecanico);
    void visualizarOrdensExecutadas();
    void fecharOrdemDeServico(int indice);
    void listarClientes();
    void setNome(const std::string& novoNome);
    void setSenha(const std::string& novaSenha);
    Cliente& getCliente(int indice);
    int getNumClientes() const;
    const std::vector<OrdemDeServico>& getOrdensServico() const;
};

#endif
