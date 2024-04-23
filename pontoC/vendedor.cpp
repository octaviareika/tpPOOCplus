#include <iostream>
#include "ordem_servico.hpp"
#include "vendedor.hpp"
#include "cliente.hpp"
#include <vector>

using namespace std;

// Ao chegar à oficina o cliente será atendido por um vendedor que irá providenciar o seu cadastro bem
/// como de seu veículo, caso não exista, e em seguida gerar uma ordem de serviço para solicitação de
// orçamento ou manutenção

Vendedor::Vendedor() : Funcionarios("", "") {
}

Vendedor::Vendedor(string nome, string cpf) : Funcionarios(nome, cpf) {}

void Vendedor::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Vendedor::getNome() const {
    return nome;
}

OrdemServico Vendedor::gerarOrdemDeServico(Cliente& cliente, bool isManutencao, const std::string& motivo, double quilometragem) {
    OrdemServico ordem(&cliente, isManutencao, motivo, quilometragem); // Cria uma nova ordem de serviço
    ordensDeServico.push_back(ordem); // Adiciona a ordem de serviço ao vetor de ordens de serviço
    cliente.adicionarOrdemServico(ordem);  // Adiciona a ordem de serviço ao cliente
    std::cout << "Ordem de serviço gerada com sucesso!" << std::endl;
    return ordem;
}

// ok
void Vendedor::visualizarOrdensPendentes() {
    std::cout << "Ordens de serviço de orçamento pendentes de aprovação: " << std::endl;
    for (size_t i = 0; i < ordensDeServico.size(); i++) {
        if (!ordensDeServico[i].isManutencao() && !ordensDeServico[i].foiAprovada() && !ordensDeServico[i].foiExecutada() && !ordensDeServico[i].finalizar()) {
            std::cout << i << ". " << ordensDeServico[i].getCliente()->getNome() << " - " << ordensDeServico[i].getMotivo() << std::endl;
        }
    }
}

//ok
void Vendedor::marcarOrdemComoAprovada(int indice, Mecanicos& mecanico) { // numOrdem = indice
    if (indice >= 0 && static_cast<size_t>(indice) < ordensDeServico.size()) { // Verifica se o índice é válido
        ordensDeServico[static_cast<size_t>(indice)].aprovar(); // Aprova a ordem de serviço 
        mecanico.receberOrdemDeServico(ordensDeServico[static_cast<size_t>(indice)]);
        std::cout << "Ordem de serviço aprovada com sucesso!" << std::endl;
    } else {
        std::cout << "Índice inválido." << std::endl;
    }
}

void Vendedor::visualizarOrdensExecutadas() {
    std::cout << "Ordens de serviço executadas:" << std::endl;
    int index = 0;
    for (const auto& ordem : ordensDeServico) {
        if (ordem.foiExecutada() && !ordem.finalizar()) {
            std::cout << index << ". " << ordem << std::endl; // Chama o operador << para imprimir a OrdemServico
            index++;
        }
    }
}


void Vendedor::cadastrarCliente(const Cliente& cliente) {
    clientes.push_back(cliente); // Adiciona o cliente ao vetor de clientes
}

void Vendedor::cadastrarVeiculo(const Veiculo& veiculo, const Cliente& cliente) {
    clientes.back().setVeiculo(veiculo); // Define o veículo para o último cliente adicionado
}

void Vendedor::listarClientes() const {
    cout << "Lista de Clientes:" << endl;
    for (size_t i = 0; i < clientes.size(); i++) {
        cout << "Índice: " << i << ", Nome: " << clientes[i].getNome() << ", CPF: " << clientes[i].getCpf() << endl;
    }
}

int Vendedor::getNumClientes() const {
    return clientes.size();  // Retorna o número de clientes
}

const Cliente& Vendedor::getCliente(int indice) const {
    if (indice >= 0 && static_cast<size_t>(indice) < clientes.size()) {
        return clientes[indice]; // Retorna a referência constante para o cliente no índice fornecido
    } else {
        throw runtime_error("Índice de cliente inválido"); // Lança uma exceção para índice inválido
    }
}
void Vendedor::receberOrdemDeServicoVendedor(OrdemServico& ordem) {
    if(ordem.foiExecutada()) {
        ordensDeServico.push_back(ordem);
    }
}

void Vendedor::fecharOrdemDeServico(int indice) {
    if (indice >= 0 && static_cast<size_t>(indice) < ordensDeServico.size()) {
        ordensDeServico[static_cast<size_t>(indice)].fechar();
        std::cout << "Ordem de serviço fechada com sucesso!" << std::endl;
    } else {
        std::cout << "Índice inválido." << std::endl;
    }
}
