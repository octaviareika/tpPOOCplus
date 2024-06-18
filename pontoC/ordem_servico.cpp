#include "ordem_servico.hpp"
#include <iostream>

OrdemDeServico::OrdemDeServico(Cliente* cliente, Mecanico& mecanico, bool isManutencao, const std::string& motivo, double quilometragem)
    : cliente(cliente), mecanico(&mecanico), isManutencao(isManutencao), motivo(motivo), quilometragem(quilometragem), aprovada(false), executada(false), fechada(false) {}

void OrdemDeServico::imprimir() const {
    std::cout << "Cliente: " << cliente->getNome() << "\nMecânico: " << mecanico->getNome() << "\nMotivo: " << motivo << "\nQuilometragem: " << quilometragem << "\nAprovada: " << (aprovada ? "Sim" : "Não") << "\nExecutada: " << (executada ? "Sim" : "Não") << "\nFechada: " << (fechada ? "Sim" : "Não") << std::endl;
    std::cout << "Serviços:\n";
    for (const auto& servico : servicos) {
        std::cout << "  - " << servico.first << ": R$" << servico.second << std::endl;
    }
    std::cout << "Peças:\n";
    for (const auto& peca : pecas) {
        std::cout << "  - " << peca.first << ": R$" << peca.second << std::endl;
    }
}

void OrdemDeServico::aprovar() {
    aprovada = true;
}

void OrdemDeServico::executar() {
    if (aprovada) {
        executada = true;
        std::string descricao;
        double preco;
        int opcao;
        do {
            std::cout << "1. Adicionar serviço\n2. Adicionar peça\n3. Concluir execução\nEscolha uma opção: ";
            std::cin >> opcao;
            switch (opcao) {
                case 1:
                    std::cout << "Descrição do serviço: ";
                    std::cin.ignore();
                    std::getline(std::cin, descricao);
                    std::cout << "Preço do serviço: ";
                    std::cin >> preco;
                    adicionarServico(descricao, preco);
                    break;
                case 2:
                    std::cout << "Descrição da peça: ";
                    std::cin.ignore();
                    std::getline(std::cin, descricao);
                    std::cout << "Preço da peça: ";
                    std::cin >> preco;
                    adicionarPeca(descricao, preco);
                    break;
                case 3:
                    std::cout << "Execução concluída.\n";
                    break;
                default:
                    std::cout << "Opção inválida.\n";
            }
        } while (opcao != 3);
    } else {
        std::cout << "A ordem de serviço não foi aprovada ainda.\n";
    }
}

void OrdemDeServico::fechar() {
    if (executada) {
        fechada = true;
        std::cout << "Ordem de serviço fechada.\n";
    } else {
        std::cout << "A ordem de serviço não foi executada ainda.\n";
    }
}

void OrdemDeServico::adicionarServico(const std::string& descricao, double preco) {
    servicos.emplace_back(descricao, preco);
}

void OrdemDeServico::adicionarPeca(const std::string& descricao, double preco) {
    pecas.emplace_back(descricao, preco);
}
