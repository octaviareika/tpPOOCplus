#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>

class Veiculo {
private:
    std::string marca;
    std::string modelo;
    int ano;
    double quilometragem;

public:
    Veiculo(const std::string& marca, const std::string& modelo, int ano, double quilometragem);
    
    std::string getMarca() const;
    std::string getModelo() const;
    int getAno() const;
    double getQuilometragem() const;
    void setQuilometragem(double quilometragem);
};

#endif
