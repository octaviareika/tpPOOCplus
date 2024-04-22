#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP

#include <string> 

using namespace std;

class Funcionarios {
protected:
    string nome;
    string cpf;

public:
    // Construtor da classe Funcionarios
    Funcionarios(string nome, string cpf);

    // Métodos de acesso (getters)
    string getNome() const; // Método para obter o nome (constante)
    string getCpf() const;  // Método para obter o CPF (constante)

    // Métodos de modificação (setters)
    void setNome(string nome); // Método para definir o nome
    void setCpf(string cpf);   // Método para definir o CPF
};

// Implementação inline dos métodos de acesso (getters)
inline string Funcionarios::getNome() const {
    return nome;
}

inline string Funcionarios::getCpf() const {
    return cpf;
}

#endif // FUNCIONARIOS_HPP
