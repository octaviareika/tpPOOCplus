#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <iostream>

using namespace std;

class Veiculo {
    private:
    string marca;
    string modelo;
    string placa;
    string cor;
    int ano;
    double preco;

    public:
    Veiculo(string marca, string modelo, string placa, string cor, int ano, double preco);
    string getMarca();
    string getModelo();
    string getPlaca();
    string getCor();
    int getAno();
    double getPreco();
    void setMarca(string marca);
    void setModelo(string modelo);
    void setPlaca(string placa);
    void setCor(string cor);
    void setAno(int ano);
    void setPreco(double preco);
    

};

#endif
