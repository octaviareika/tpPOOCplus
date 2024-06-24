#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>
#include <memory> // Adicionado para usar smart pointers

class Veiculo;

class Cliente {
private:
    std::string nome;
    std::vector<std::shared_ptr<Veiculo>> veiculos; // Usar shared_ptr

public:
    // Construtor que inicializa o nome do cliente
    Cliente(const std::string& nome);
    
    // Retorna o nome do cliente
    std::string getNome() const;
    
    // Adiciona um veículo à lista de veículos do cliente
    void adicionarVeiculo(std::shared_ptr<Veiculo> veiculo);
    
    // Retorna a lista de veículos do cliente
    const std::vector<std::shared_ptr<Veiculo>>& getVeiculos() const;
};

#endif
