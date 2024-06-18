#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>

class Veiculo;

class Cliente {
private:
    std::string nome;
    std::vector<Veiculo*> veiculos;

public:
    Cliente(const std::string& nome);
    
    std::string getNome() const;
    void adicionarVeiculo(Veiculo* veiculo);
    const std::vector<Veiculo*>& getVeiculos() const;
};

#endif
