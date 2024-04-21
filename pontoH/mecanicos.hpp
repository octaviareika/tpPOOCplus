#ifndef MECANICOS_HPP
#define MECANICOS_HPP

#include <iostream>
#include <string>
using namespace std;

class Mecanicos {
private:
    string nome;
    string cpf;
    string ordemDeServico;

public:
    // Construtor padrão
    Mecanicos();

    // Construtor com parâmetros
    Mecanicos(string nome, string cpf, string ordemDeServico);

    // Getters e Setters
    string getNome() const;
    void setNome(const string& nome);

    string getCpf() const;
    void setCpf(const string& cpf);

    string getOrdemDeServico() const;
    void setOrdemDeServico(const string& ordemDeServico);
    void cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas);
    // Outros métodos da classe
    void visualizarOrdensAbertas() const;
};

#endif
