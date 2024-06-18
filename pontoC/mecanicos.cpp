#include "mecanicos.hpp"
#include <iostream>

Mecanico::Mecanico(const std::string& nome, const std::string& senha) : Funcionario(nome, senha) {}

void Mecanico::adicionarOrdem(OrdemDeServico& ordem) {
    ordensDeServico.push_back(&ordem);
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
    if (size_t (indice) > 0 && size_t(indice) <= ordensDeServico.size()) {
        ordensDeServico[indice - 1]->executar();
    } else {
        std::cout << "Ordem de serviço inválida.\n";
    }
}

void Mecanico::setNome(const std::string& novoNome) {
    nome = novoNome;
}

void Mecanico::setSenha(const std::string& novaSenha) {
    senha = novaSenha;
}