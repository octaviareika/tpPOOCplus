#include <iostream>
#include "mecanicos.hpp"
using namespace std;

class Mecanicos {
private:
    string nome;
    string cpf;
    string ordemDeServico;

public:
    // Construtor padrão
    Mecanicos() {
        nome = "";
        cpf = "";
        ordemDeServico = "";
    }

    // Construtor com parâmetros
    Mecanicos(string nome, string cpf, string ordemDeServico) {
        this->nome = nome;
        this->cpf = cpf;
        this->ordemDeServico = ordemDeServico;
    }

    // Getters e Setters
    string getNome() const {
        return nome;
    }

    void setNome(const string& nome) {
        this->nome = nome;
    }

    string getCpf() const {
        return cpf;
    }

    void setCpf(const string& cpf) {
        this->cpf = cpf;
    }

    string getOrdemDeServico() const {
        return ordemDeServico;
    }

    void setOrdemDeServico(const string& ordemDeServico) {
        this->ordemDeServico = ordemDeServico;
    }
    void visualizarOrdensAbertas() const {
        cout << "Visualizando ordens de serviço abertas..." << endl;
        cout << "Ordem de serviço: " << ordemDeServico << endl;
    }
    void cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas) {
        cout << "Serviços executados cadastrados com sucesso para a ordem de serviço " << numeroOrdem << endl;
        cout << "Serviços realizados: " << servicosRealizados << endl;
        cout << "Valor dos serviços: " << valorServicos << endl;
        cout << "Peças utilizadas: " << pecasUtilizadas << endl;
        cout << "Valor das peças: " << valorPecas << endl;
    }
};