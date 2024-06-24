#include "cliente.hpp"
#include "veiculo.hpp"

// Construtor que inicializa o nome do cliente
Cliente::Cliente(const std::string& nome) : nome(nome) {}

// Retorna o nome do cliente
std::string Cliente::getNome() const {
    return nome;
}

// Adiciona um veículo à lista de veículos do cliente
void Cliente::adicionarVeiculo(std::shared_ptr<Veiculo> veiculo) {
    veiculos.push_back(veiculo);
}

// Retorna a lista de veículos do cliente
const std::vector<std::shared_ptr<Veiculo>>& Cliente::getVeiculos() const {
    return veiculos;
}
