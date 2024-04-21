#include <iostream>
#include "vendedor.hpp"
#include <vector>

using namespace std;

// Ao chegar à oficina o cliente será atendido por um vendedor que irá providenciar o seu cadastro bem
/// como de seu veículo, caso não exista, e em seguida gerar uma ordem de serviço para solicitação de
// orçamento ou manutenção


Vendedor::Vendedor(string nome, string cpf, string ordemDeServico) : Funcionarios(nome, cpf) {
    this->ordemDeServico = ordemDeServico;
}

string Vendedor::getOrdemDeServico() {
    return ordemDeServico;
}

void Vendedor::setOrdemDeServico(string ordemDeServico) { 
    this->ordemDeServico = ordemDeServico;
}

void Vendedor::visualizarOrdensDeServico() {
    cout << "Visualizando ordens de serviço..." << endl;
}

string Vendedor:: gerarOrdemDeServico() { // manutenção ou orçamento
    cout << "Gerando ordem de serviço...Qual será a ordem de serviço? " << endl;
    cin >> ordemDeServico; // gerar ordem de serviço
    return ordemDeServico;
}

void Vendedor::cadastrarCliente(Cliente cliente) {
    cout << "Cadastrando cliente..." << endl;
    clientes.push_back(cliente);

}