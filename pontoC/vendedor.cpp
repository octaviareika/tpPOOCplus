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

string Vendedor:: gerarOrdemDeServico() { // manutenção ou orçamento
    cout << "Gerando ordem de serviço...Qual será a ordem de serviço? " << endl;
    cin >> ordemDeServico; // gerar ordem de serviço
    return ordemDeServico;
}


void Vendedor::visualizarOrdensDeServico(){
    cout << "Visualizando ordens de serviço..." << endl;
    for (int i = 0; i < clientes.size(); i++) {
        cout << "Nome: " << clientes[i].getNome() << endl;
        cout << "CPF: " << clientes[i].getCpf() << endl;
        cout << "Endereço: " << clientes[i].getEndereco() << endl;
        cout << "Telefone: " << clientes[i].getTelefone() << endl;
        cout << "Veículo: " << clientes[i].getVeiculo().getMarca() << endl;
        cout << "Modelo: " << clientes[i].getVeiculo().getModelo() << endl;
        cout << "Placa: " << clientes[i].getVeiculo().getPlaca() << endl;
        cout << "Ano: " << clientes[i].getVeiculo().getAno() << endl;
        cout << "Cor: " << clientes[i].getVeiculo().getCor() << endl;
        cout << "Ordem de serviço: " << ordemDeServico << endl;// ordem que o cliente quer
        cout << "Ordem de serviço aprovadas: " << clientes[i].getAprovacao() << endl;
    }
}
void Vendedor::cadastrarCliente(Cliente cliente) {
    cout << "Cadastrando cliente..." << endl;
    clientes.push_back(cliente);

}