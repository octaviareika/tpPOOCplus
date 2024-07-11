#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "funcionarios.hpp"
#include "cliente.hpp"
#include "mecanicos.hpp"
#include "ordem_servico.hpp"
#include <vector>
#include <memory>  // Para std::shared_ptr

class Vendedor : public Funcionario {
private:
    std::vector<Cliente> clientes;
    std::vector<std::shared_ptr<OrdemDeServico>> ordensDeServico;  

public:
    Vendedor(const std::string& nome, const std::string& senha);
    ~Vendedor();
    void cadastrarCliente(const Cliente& cliente);
    void cadastrarVeiculo(std::shared_ptr<Veiculo> veiculo, Cliente& cliente);
    void gerarOrdemDeServico(Cliente* cliente, Mecanico& mecanico, bool isManutencao, const std::string& motivo, double quilometragem);
    void visualizarOrdensPendentes();
    void marcarOrdemComoAprovada(int indice, Mecanico& mecanico);
    void visualizarOrdensExecutadas();
    void fecharOrdemDeServico(int indice);
    void listarClientes();
    void setNome(const std::string& novoNome);
    void setSenha(const std::string& novaSenha);
    Cliente& getCliente(int indice);
    void vizualizarOrdensFechadas();
    int getNumClientes() const;
    const std::vector<std::shared_ptr<OrdemDeServico>>& getOrdensServico() const;
};

#endif
