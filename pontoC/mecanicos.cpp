#include "mecanicos.hpp"
#include <iostream>

Mecanico::Mecanico(const std::string& nome, const std::string& senha) : Funcionario(nome, senha) {}

void Mecanico::adicionarOrdem(std::shared_ptr<OrdemDeServico> ordem) {
    ordensDeServico.push_back(ordem);
}

void Mecanico::visualizarOrdensAprovadas() {
    for (size_t i = 0; i < ordensDeServico.size(); ++i) {
        if (ordensDeServico[i]->aprovada && !ordensDeServico[i]->executada) {
            std::cout << i + 1 << ". ";
            ordensDeServico[i]->imprimir();
        }
    }
}

void Mecanico::executarOrdemDeServico(int indice) {
    if (indice > 0 && static_cast<size_t>(indice) <= ordensDeServico.size()) {
        ordensDeServico[indice - 1]->executar();
    } else {
        std::cout << "Ordem de serviço inválida.\n";
    }
}

void Mecanico::setNome(const std::string& novoNome) {
    Funcionario::setNome(novoNome);
}

void Mecanico::setSenha(const std::string& novaSenha) {
    senha = novaSenha;
}
