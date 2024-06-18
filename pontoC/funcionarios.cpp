#include "funcionarios.hpp"

Funcionario::Funcionario(const std::string& nome, const std::string& senha) : nome(nome), senha(senha) {}

std::string Funcionario::getNome() const {
    return nome;
}

void Funcionario::setNome(const std::string& novoNome) {
    nome = novoNome;
}

bool Funcionario::autenticar(const std::string& senha) const {
    return this->senha == senha;
}
