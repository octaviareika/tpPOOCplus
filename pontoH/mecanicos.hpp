#ifndef MECANICOS_HPP
#define MECANICOS_HPP

#include <iostream>
#include "funcionarios.hpp"
#include "ordem_servico.hpp"
#include "vendedor.hpp"
#include <string>
#include <vector>
using namespace std;
class Vendedor;
class Mecanicos : public Funcionarios{
private:
    vector<OrdemServico> ordensDeServico;

public:
    // Construtores
    Mecanicos();
    Mecanicos(string nome, string cpf);

    // Getters e Setters

    string getNome() const;
    void setNome(const string& nome);
    string getCpf() const;
    void setCpf(const string& cpf);
    // Outros métodos da classe
    void visualizarOrdensAbertas() const;
    void cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas, Vendedor& vendedor);
    void receberOrdemDeServico(OrdemServico& ordem);
    

};

#endif