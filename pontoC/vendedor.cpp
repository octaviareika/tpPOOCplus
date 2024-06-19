#include "vendedor.hpp"
#include <iostream>

Vendedor::Vendedor(const std::string& nome, const std::string& senha) : Funcionario(nome, senha) {}

void Vendedor::cadastrarCliente(const Cliente& cliente) {
    clientes.push_back(cliente);
}

void Vendedor::cadastrarVeiculo(Veiculo& veiculo, Cliente& cliente) {
    cliente.adicionarVeiculo(&veiculo);
}

void Vendedor::gerarOrdemDeServico(Cliente* cliente, Mecanico& mecanico, bool isManutencao, const std::string& motivo, double quilometragem) {
    OrdemDeServico ordem(cliente, mecanico, isManutencao, motivo, quilometragem);
    ordensDeServico.push_back(ordem);
}

void Vendedor::visualizarOrdensPendentes() {
    for (size_t i = 0; i < ordensDeServico.size(); ++i) {
        if (!ordensDeServico[i].aprovada) {
            std::cout << i + 1 << ". ";
            ordensDeServico[i].imprimir();
        }
    }
}

void Vendedor::marcarOrdemComoAprovada(int indice, Mecanico& mecanico) {
    if (indice > 0 && static_cast<size_t>(indice) <= ordensDeServico.size()) {
        ordensDeServico[indice - 1].aprovar();
        mecanico.adicionarOrdem(ordensDeServico[indice - 1]);
    } else {
        std::cout << "Ordem de serviço inválida.\n";
    }
}

void Vendedor::visualizarOrdensExecutadas() {
    for (size_t i = 0; i < ordensDeServico.size(); ++i) {
        if (ordensDeServico[i].executada && !ordensDeServico[i].fechada) {
            std::cout << i + 1 << ". ";
            ordensDeServico[i].imprimir();
        }
    }
}

void Vendedor::fecharOrdemDeServico(int indice) {
    if (indice > 0 && static_cast<size_t>(indice) <= ordensDeServico.size()) {
        ordensDeServico[indice - 1].fechar();
    } else {
        std::cout << "Ordem de serviço inválida.\n";
    }
}

void Vendedor::listarClientes() {
    for (size_t i = 0; i < clientes.size(); ++i) {
        std::cout << i + 1 << ". " << clientes[i].getNome() << std::endl;
    }
}

Cliente& Vendedor::getCliente(int indice) {
    return clientes[indice];
}

int Vendedor::getNumClientes() const {
    return clientes.size();
}

void Vendedor::setNome(const std::string& novoNome) {
    nome = novoNome;
}

void Vendedor::setSenha(const std::string& novaSenha) {
    senha = novaSenha;
}

const std::vector<OrdemDeServico>& Vendedor::getOrdensServico() const {
    return ordensDeServico;
}
