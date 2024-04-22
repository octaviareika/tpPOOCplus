#include <iostream>
#include "ordem_servico.hpp"
#include "vendedor.hpp"
#include <vector>

using namespace std;

// Ao chegar à oficina o cliente será atendido por um vendedor que irá providenciar o seu cadastro bem
/// como de seu veículo, caso não exista, e em seguida gerar uma ordem de serviço para solicitação de
// orçamento ou manutenção

Vendedor::Vendedor() : Funcionarios("", "") {
}

Vendedor::Vendedor(string nome, string cpf) : Funcionarios(nome, cpf) {}
void Vendedor::setNome(string nome) {
    this->nome = nome;
}

string Vendedor::getNome() const {
    return nome;
}

OrdemServico Vendedor::gerarOrdemDeServico(const Cliente& cliente, bool isManutencao, string motivo, double quilometragem) {
    OrdemServico ordem(cliente, isManutencao, motivo, quilometragem);
    ordensDeServico.push_back(ordem);
    cout << "Ordem de serviço gerada com sucesso!" << endl;
    return ordem;
}

void Vendedor::visualizarOrdensPendentes() {
    cout << "Ordens de serviço de orçamento pendentes de aprovação:" << endl;
    for (size_t i = 0; i < ordensDeServico.size(); i++) {
        if (ordensDeServico[i].isManutencao() == false && !ordensDeServico[i].foiAprovada()) {
            cout << i + 1 << ". " << ordensDeServico[i].getCliente().getNome() << " - " << ordensDeServico[i].getMotivo() << endl;
            
        }
    }
}

void Vendedor::marcarOrdemComoAprovada(int indice) {
    if (indice >= 0 && static_cast<size_t>(indice) < ordensDeServico.size()) {
        ordensDeServico[static_cast<size_t>(indice)].aprovar();
        cout << "Ordem de serviço aprovada com sucesso!" << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}


void Vendedor::visualizarOrdensExecutadas() {
    cout << "Ordens de serviço executadas:" << endl;
    for (const auto& ordem : ordensDeServico) {
        if (ordem.foiExecutada()) {
            cout << ordem << endl; // Aqui é onde o operador << será chamado para imprimir a OrdemServico
        }
    }
}

void Vendedor::fecharOrdemDeServico(int indice) {
    if (indice >= 0 && static_cast<size_t>(indice) < ordensDeServico.size()) {
        ordensDeServico[static_cast<size_t>(indice)].fechar();
        cout << "Ordem de serviço fechada com sucesso!" << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void Vendedor::cadastrarCliente(Cliente cliente) {
    cout << "Cadastrando cliente..." << endl;
    clientes.push_back(cliente);

}

void Vendedor::cadastrarVeiculo(Veiculo veiculo, Cliente cliente) {
    clientes.back().setVeiculo(veiculo);
    cout << "Veículo cadastrado com sucesso para o cliente " << cliente.getNome() << "!" << endl;
}
