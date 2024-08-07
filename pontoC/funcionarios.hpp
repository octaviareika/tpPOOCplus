#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>

class Funcionario {
protected:
    std::string nome;
    std::string senha;

public:
    Funcionario(const std::string& nome, const std::string& senha);
    virtual ~Funcionario() = default;
    
    std::string getNome() const;
    void setNome(const std::string& novoNome);
    bool autenticar(const std::string& senha) const;
};

#endif
