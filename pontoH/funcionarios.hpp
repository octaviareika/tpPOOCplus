#ifndef FUNCIONARIOS_HPP
#define FUNCIONARIOS_HPP

#include <string>

using namespace std;

class Funcionarios {
protected:
    string nome;
    string cpf;

public:
    // Construtores
    Funcionarios(); // Construtor padrão
    Funcionarios(string nome, string cpf); // Construtor com parâmetros

    // Métodos de acesso (getters)
    string getNome() const; // Método para obter o nome (constante)
    string getCpf() const;  // Método para obter o CPF (constante)

    // Métodos de modificação (setters)
    void setNome(string nome); // Método para definir o nome
    void setCpf(string cpf);   // Método para definir o CPF
};

#endif // FUNCIONARIOS_HPP
