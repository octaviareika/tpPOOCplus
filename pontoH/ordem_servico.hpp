#ifndef ORDEM_SERVICO_HPP
#define ORDEM_SERVICO_HPP

#include "cliente.hpp"
#include "mecanicos.hpp"
#include <string>
#include <vector>
class Cliente;
class Mecanico;
class OrdemDeServico {
private:
    Cliente* cliente;
    Mecanico* mecanico;
    bool isManutencao;
    std::string motivo;
    double quilometragem;
    bool aprovada;
    bool executada;
    bool fechada;
    std::vector<std::pair<std::string, double>> servicos;
    std::vector<std::pair<std::string, double>> pecas;

public:
    OrdemDeServico(Cliente* cliente, Mecanico& mecanico, bool isManutencao, const std::string& motivo, double quilometragem);
    void imprimir() const;
    void aprovar();
    void executar();
    void fechar();
    void adicionarServico(const std::string& descricao, double preco);
    void adicionarPeca(const std::string& descricao, double preco);

    friend class Vendedor;
    friend class Mecanico;
};

#endif
