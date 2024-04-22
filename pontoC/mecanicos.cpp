#include <iostream>
#include "mecanicos.hpp"


// Construtores
Mecanicos::Mecanicos() {
    nome = "";
    cpf = "";
    ordemDeServico = "";
}

Mecanicos::Mecanicos(string nome, string cpf, string ordemDeServico)
    : Funcionarios(nome, cpf), ordemDeServico(ordemDeServico) {
    this->ordemDeServico = ordemDeServico;
    this->nome = nome;
    this->cpf = cpf;
}

// Getters e Setters
string Mecanicos::getNome() const {
    return nome;
}

void Mecanicos::setNome(const string& nome) {
    this->nome = nome;
}

string Mecanicos::getCpf() const {
    return cpf;
}

void Mecanicos::setCpf(const string& cpf) {
    this->cpf = cpf;
}

string Mecanicos::getOrdemDeServico() const {
    return ordemDeServico;
}

void Mecanicos::setOrdemDeServico(const string& ordemDeServico) {
    this->ordemDeServico = ordemDeServico;
}

// Outros métodos da classe
void Mecanicos::visualizarOrdensAbertas() const {
    cout << "Visualizando ordens de serviço abertas..." << endl;
    cout << "Ordem de serviço: " << ordemDeServico << endl;
}

void Mecanicos::cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas) {
    cout << "Serviços executados cadastrados com sucesso para a ordem de serviço " << numeroOrdem << endl;
    cout << "Serviços realizados: " << servicosRealizados << endl;
    cout << "Valor dos serviços: " << valorServicos << endl;
    cout << "Peças utilizadas: " << pecasUtilizadas << endl;
    cout << "Valor das peças: " << valorPecas << endl;
}
