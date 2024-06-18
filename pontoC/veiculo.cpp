#include "veiculo.hpp"

Veiculo::Veiculo(const std::string& marca, const std::string& modelo, int ano, double quilometragem) 
    : marca(marca), modelo(modelo), ano(ano), quilometragem(quilometragem) {}

std::string Veiculo::getMarca() const {
    return marca;
}

std::string Veiculo::getModelo() const {
    return modelo;
}

int Veiculo::getAno() const {
    return ano;
}

double Veiculo::getQuilometragem() const {
    return quilometragem;
}

void Veiculo::setQuilometragem(double quilometragem) {
    this->quilometragem = quilometragem;
}
