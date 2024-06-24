#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include <string>
#include <vector>
#include "funcionarios.hpp" 

// Forward declarations
class Vendedor;
class Mecanico;

// Classe para o administrador
class Administrador : public Funcionario {
public:
    Administrador(const std::string& nome, const std::string& senha);

    void editarDados(std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos);
};

#endif // ADMINISTRADOR_HPP
