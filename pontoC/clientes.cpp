#include "cliente.hpp"
#include "veiculo.hpp"

Cliente::Cliente(const std::string& nome) : nome(nome) {}

std::string Cliente::getNome() const {
    return nome;
}

void Cliente::adicionarVeiculo(Veiculo* veiculo) {
    veiculos.push_back(veiculo);
}

const std::vector<Veiculo*>& Cliente::getVeiculos() const {
    return veiculos;
}
