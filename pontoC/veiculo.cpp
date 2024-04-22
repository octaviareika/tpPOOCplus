#include <iostream>
#include <vector>
#include "cliente.hpp"
#include "veiculo.hpp"
#include "ordem_servico.hpp"

using namespace std;

Veiculo::Veiculo(string marca, string modelo, string placa, string cor, int ano, double preco) {
    this->marca = marca;
    this->modelo = modelo;
    this->placa = placa;
    this->cor = cor;
    this->ano = ano;
    this->preco = preco;
    //this->quilometragem = quilometragem;
}

Veiculo::Veiculo() {
    this->marca = "";
    this->modelo = "";
    this->placa = "";
    this->cor = "";
    this->ano = 0;
    this->preco = 0;
    
}

string Veiculo::getMarca() {
    return marca;
}

string Veiculo::getModelo() {
    return modelo;
}

string Veiculo::getPlaca() {
    return placa;
}

string Veiculo::getCor() {
    return cor;
}

int Veiculo::getAno() {
    return ano;
}

double Veiculo::getPreco() {
    return preco;
}

void Veiculo::setMarca(string marca) {
    this->marca = marca;
}

void Veiculo::setModelo(string modelo) {
    this->modelo = modelo;
}

void Veiculo::setPlaca(string placa) {
    this->placa = placa;
}

void Veiculo::setCor(string cor) {
    this->cor = cor;
}

void Veiculo::setAno(int ano) {
    this->ano = ano;
}

void Veiculo::setPreco(double preco) {
    this->preco = preco;
}
void Veiculo::setQuilometragem(double quilometragem) {
    this->quilometragem = quilometragem;
}

double Veiculo::getQuilometragem() {
    return quilometragem;
}



