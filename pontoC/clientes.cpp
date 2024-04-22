#include <iostream>
#include "cliente.hpp"
#include "ordem_servico.hpp"
#include <vector>
using namespace std;
Cliente::Cliente() : ordemDeServiçoAprovada(false) {
}
Cliente::Cliente(string nome, string cpf, string endereco, string telefone, Veiculo veiculo) {
    this->nome = nome;
    this->cpf = cpf;
    this->endereco = endereco;
    this->telefone = telefone;
    this->veiculo = veiculo;
}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getCpf() const {
    return cpf;
}

string Cliente::getEndereco() {
    return endereco;
}

string Cliente::getTelefone() {
    return telefone;
}

void Cliente::setNome(string nome) {
    this->nome = nome;
}

void Cliente::setCpf(string cpf) {
    this->cpf = cpf;
}

void Cliente::setEndereco(string endereco) {
    this->endereco = endereco;
}

void Cliente::setTelefone(string telefone) {
    this->telefone = telefone;
}

void Cliente::setVeiculo(Veiculo veiculo) {
    this->veiculo = veiculo;
}

Veiculo Cliente::getVeiculo() {
    return veiculo;
}

bool Cliente::getAprovacao() {
    return ordemDeServiçoAprovada;
}

void Cliente::setAprovacao(bool ordemDeServicoAprovacao) {
    this->ordemDeServiçoAprovada = ordemDeServicoAprovacao;
}

void Cliente::adicionarOrdemServico(const OrdemServico& ordem) {
    ordensServico.push_back(ordem); // Adiciona a ordem de serviço ao vetor de ordens do cliente
}