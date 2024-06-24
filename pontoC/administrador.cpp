#include "administrador.hpp"
#include <iostream>
#include <string>
#include "vendedor.hpp"
#include "mecanicos.hpp"

Administrador::Administrador(const std::string& nome, const std::string& senha)
    : Funcionario(nome, senha) {
}

void Administrador::editarDados(std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos) {
    int opcao;
    do {
        std::cout << "1. Editar Vendedores\n2. Editar Mecânicos\n3. Sair\nEscolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                // Editar Vendedores
                for (size_t i = 0; i < vendedores.size(); ++i) {
                    std::cout << i + 1 << ". " << vendedores[i].getNome() << std::endl;
                }
                std::cout << "Escolha um vendedor para editar: ";
                int indice;
                std::cin >> indice;
                if (indice > 0 && static_cast<size_t>(indice) <= vendedores.size()) {
                    std::string novoNome, novaSenha;
                    std::cout << "Novo nome: ";
                    std::cin.ignore();
                    std::getline(std::cin, novoNome);
                    std::cout << "Nova senha: ";
                    std::getline(std::cin, novaSenha);
                    vendedores[indice - 1].setNome(novoNome);
                    vendedores[indice - 1].setSenha(novaSenha);
                } else {
                    std::cout << "Vendedor inválido.\n";
                }
                break;
            }
            case 2: {
                // Editar Mecânicos
                for (size_t i = 0; i < mecanicos.size(); ++i) {
                    std::cout << i + 1 << ". " << mecanicos[i].getNome() << std::endl;
                }
                std::cout << "Escolha um mecânico para editar: ";
                int indice;
                std::cin >> indice;
                if (indice > 0 && static_cast<size_t>(indice) <= mecanicos.size()) {
                    std::string novoNome, novaSenha;
                    std::cout << "Novo nome: ";
                    std::cin.ignore();
                    std::getline(std::cin, novoNome);
                    std::cout << "Nova senha: ";
                    std::getline(std::cin, novaSenha);
                    mecanicos[indice - 1].setNome(novoNome);
                    mecanicos[indice - 1].setSenha(novaSenha);
                } else {
                    std::cout << "Mecânico inválido.\n";
                }
                break;
            }
            case 3:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 3);
}
