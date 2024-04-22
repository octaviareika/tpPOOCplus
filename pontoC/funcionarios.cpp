#include "funcionarios.hpp"

// Construtor padrão da classe Funcionarios
Funcionarios::Funcionarios() {
    nome = ""; // Inicializa o nome como uma string vazia
    cpf = "";  // Inicializa o CPF como uma string vazia
}

// Construtor da classe Funcionarios com parâmetros
Funcionarios::Funcionarios(string nome, string cpf) {
    this->nome = nome; // Inicializa o nome com o valor passado por parâmetro
    this->cpf = cpf;   // Inicializa o CPF com o valor passado por parâmetro
}

// Método getter para obter o nome (constante)
string Funcionarios::getNome() const {
    return nome;
}

// Método getter para obter o CPF (constante)
string Funcionarios::getCpf() const {
    return cpf;
}

// Método setter para definir o nome
void Funcionarios::setNome(string nome) {
    this->nome = nome;
}

// Método setter para definir o CPF
void Funcionarios::setCpf(string cpf) {
    this->cpf = cpf;
}
