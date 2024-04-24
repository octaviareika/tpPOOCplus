#ifndef MECANICOS_HPP
#define MECANICOS_HPP

#include <iostream>
#include "funcionarios.hpp"
#include "ordem_servico.hpp"
<<<<<<< HEAD
#include <string>
#include <vector>
class OrdemServico;
using namespace std;

class Mecanicos : public Funcionarios {
private:
    string ordemDeServico;
    vector<OrdemServico> ordensEmExecucao;
=======
#include "vendedor.hpp"
#include <string>
#include <vector>
using namespace std;
class Vendedor;
class Mecanicos : public Funcionarios{
private:
    vector<OrdemServico> ordensDeServico;
>>>>>>> testezin

public:
    // Construtores
    Mecanicos();
    Mecanicos(string nome, string cpf);

    // Getters e Setters
<<<<<<< HEAD
    string getOrdemDeServico() const;
    void setOrdemDeServico(const string& ordemDeServico);
=======

>>>>>>> testezin
    string getNome() const;
    void setNome(const string& nome);
    string getCpf() const;
    void setCpf(const string& cpf);

    // Outros métodos da classe
<<<<<<< HEAD
    void adicionarOrdemServico(OrdemServico* ordem);
    void visualizarOrdensAbertas() const; 
    void cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas);
    void moverOrdemParaExecutadas(int ordem);
    OrdemServico* buscarOrdemPorNumero(vector<OrdemServico>& ordens, int numeroOrdem);;
=======
    void visualizarOrdensAbertas() const;
    void cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas, Vendedor& vendedor);
    void receberOrdemDeServico(OrdemServico& ordem);
    

>>>>>>> testezin
};

#endif
