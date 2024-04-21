#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <iostream>
#include "funcionarios.hpp"
#include "cliente.hpp"
#include <vector>

// Caso o usuário logado seja um Vendedor deverão ser exibidas as seguintes opções:
// • Cadastrar cliente e veículo.
// • Gerar ordem de serviço.
// • Visualizar ordens de serviço de orçamento pendentes de aprovação do cliente e marcar como
// aprovadas.
// • Visualizar ordens de serviço executadas e realizar o fechamento.

using namespace std;

class Vendedor : public Funcionarios {
    private:
    string ordemDeServico;
    // cadastrar cliente
    vector <Cliente> clientes;

    public:
    Vendedor(string nome, string cpf, string ordemDeServico);
    string getOrdemDeServico();
    void setOrdemDeServico(string ordemDeServico);
    void visualizarOrdensDeServico();
    
    void cadastrarCliente(Cliente cliente);
    void cadastrarVeiculo(Cliente cliente); // cadastrar veiculo por meio de cliente cadastrado
    string gerarOrdemDeServico();
    void marcarAprovadas();
    void fecharOrdemDeServico();
    

};


#endif