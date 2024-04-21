#ifndef MECANICOS_HPP
#define MECANICOS_HPP

#include <iostream>

#include "funcionarios.hpp"
#include "vendedor.hpp"
using namespace std;

// Caso o usuário logado seja um mecânico deverão ser exibidas as seguintes opções:
// • Visualizar ordens de serviço abertas.
// • Cadastrar serviços executados e peças utilizadas.

class Mecanicos : public Funcionarios {

    private:
    string ordemDeServico;

    public:
    Mecanicos(string nome, string cpf, string ordemDeServico);
    string getOrdemDeServico();
    void setOrdemDeServico(string ordemDeServico);
    void visualizarOrdensDeServico() override;
    void cadastrarServicosExecutados();
    void cadastrarPecasUtilizadas();
    

};

#endif