#include <iostream>
#include <vector>
#include <string>
#include "administrador.hpp"
#include "cliente.hpp"
#include "veiculo.hpp"
#include "ordem_servico.hpp"
#include "vendedor.hpp"
#include "mecanicos.hpp"

// Funções de login
Funcionario* login(std::vector<Administrador>& administradores, std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos) {
    std::string nome, senha;
    std::cout << "Nome: ";
    std::cin >> nome;
    std::cout << "Senha: ";
    std::cin >> senha;
    
    for (auto& admin : administradores) {
        if (admin.getNome() == nome && admin.autenticar(senha)) {
            return &admin;
        }
    }
    for (auto& vendedor : vendedores) {
        if (vendedor.getNome() == nome && vendedor.autenticar(senha)) {
            return &vendedor;
        }
    }
    for (auto& mecanico : mecanicos) {
        if (mecanico.getNome() == nome && mecanico.autenticar(senha)) {
            return &mecanico;
        }
    }
    
    std::cout << "Credenciais inválidas.\n";
    return nullptr;
}

void menuVendedor(Vendedor* vendedor, std::vector<Mecanico>& mecanicos) {
    int opcao;
    do {
        std::cout << "1. Cadastrar cliente e veículo\n2. Gerar ordem de serviço\n3. Visualizar ordens de serviço pendentes de aprovação\n4. Visualizar ordens de serviço executadas\n5. Fechar ordem de serviço\n6. Sair\nEscolha uma opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1: {
                std::string nomeCliente;
                std::cout << "Nome do cliente: ";
                std::cin.ignore();
                std::getline(std::cin, nomeCliente);
                // Cadastrar o cliente
                vendedor->cadastrarCliente(nomeCliente);
                std::string marca, modelo;
                int ano;
                double quilometragem;
                std::cout << "Marca do veículo: ";
                std::cin >> marca;
                std::cout << "Modelo do veículo: ";
                std::cin >> modelo;
                std::cout << "Ano do veículo: ";
                std::cin >> ano;
                std::cout << "Quilometragem do veículo: ";
                std::cin >> quilometragem;
                // Criar e cadastrar o veículo
                Veiculo veiculo(marca, modelo, ano, quilometragem);
                // Obter o último cliente cadastrado
                Cliente& cliente = vendedor->getCliente(vendedor->getNumClientes() - 1);
                vendedor->cadastrarVeiculo(std::make_shared<Veiculo>(veiculo), cliente);
                std::cout << "Cliente e veículo cadastrados com sucesso!\n";
                break;
            }
            case 2: {
                vendedor->listarClientes();
                int clienteIndice;
                std::cout << "Escolha um cliente: ";
                std::cin >> clienteIndice;

                if (clienteIndice > 0 && clienteIndice <= vendedor->getNumClientes()) {
                    Cliente* cliente = &vendedor->getCliente(clienteIndice - 1);

                    // Verificar se o cliente possui algum veículo
                    const std::vector<std::shared_ptr<Veiculo>>& veiculos = cliente->getVeiculos();

                    if (!veiculos.empty()) {
                        Veiculo* veiculoCliente = veiculos.front().get(); // Acessando o único veículo do cliente

                        double quilometragemVeiculo = veiculoCliente->getQuilometragem();

                        // Listar mecânicos disponíveis
                        std::cout << "Mecânicos disponíveis:\n";
                        for (size_t i = 0; i < mecanicos.size(); ++i) {
                            std::cout << i + 1 << ". " << mecanicos[i].getNome() << std::endl;
                        }

                        int mecanicoIndice;
                        std::cout << "Escolha um mecânico: ";
                        std::cin >> mecanicoIndice;

                        if (mecanicoIndice > 0 && static_cast<size_t>(mecanicoIndice) <= mecanicos.size()) {
                            Mecanico& mecanico = mecanicos[mecanicoIndice - 1];
                            bool isManutencao;
                            std::string motivo;

                            std::cout << "É manutenção? (1 para sim, 0 para não): ";
                            std::cin >> isManutencao;
                            std::cout << "Motivo: ";
                            std::cin.ignore();
                            std::getline(std::cin, motivo);

                            // Gerar a ordem de serviço
                            vendedor->gerarOrdemDeServico(cliente, mecanico, isManutencao, motivo, quilometragemVeiculo);

                            // Se for manutenção, marcar automaticamente como aprovada
                            if (isManutencao) {
                                const auto& ordensServico = vendedor->getOrdensServico();
                                vendedor->marcarOrdemComoAprovada(ordensServico.size(), mecanico);
                            }
                        } else {
                            std::cout << "Mecânico inválido.\n";
                        }
                    } else {
                        std::cout << "Este cliente não possui veículos cadastrados.\n";
                    }
                } else {
                    std::cout << "Cliente inválido.\n";
                }
                break;
            }
            case 3:
                vendedor->visualizarOrdensPendentes();
                int numeroOrdem;
                std::cout << "Escolha uma ordem para aprovar: ";
                std::cin >> numeroOrdem;
                vendedor->marcarOrdemComoAprovada(numeroOrdem, mecanicos[numeroOrdem - 1]);
                break;
            case 4:
                vendedor->visualizarOrdensExecutadas();
                break;
            case 5:
                vendedor->visualizarOrdensExecutadas();
                std::cout << "Escolha uma ordem para fechar: ";
                std::cin >> numeroOrdem;
                vendedor->fecharOrdemDeServico(numeroOrdem);
                break;
            case 6:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 6);
}

void menuMecanico(Mecanico* mecanico) {
    int opcao;
    do {
        std::cout << "1. Visualizar ordens de serviço abertas\n2. Cadastrar serviços executados e peças utilizadas\n3. Sair\nEscolha uma opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                mecanico->visualizarOrdensAprovadas();
                break;
            case 2: {
                mecanico->visualizarOrdensAprovadas();
                int numeroOrdem;
                std::cout << "Escolha uma ordem para detalhar os serviços: ";
                std::cin >> numeroOrdem;
                mecanico->executarOrdemDeServico(numeroOrdem);
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

// Função para o menu de login
void menuLogin(std::vector<Administrador>& administradores, std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos) {
    int opcao;
    do {
        std::cout << "1. Login\n2. Sair do programa\nEscolha uma opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1: {
                Funcionario* usuario = login(administradores, vendedores, mecanicos);
                if (usuario) {
                    if (Administrador* admin = dynamic_cast<Administrador*>(usuario)) {
                        admin->editarDados(vendedores, mecanicos);
                    } else if (Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario)) {
                        menuVendedor(vendedor, mecanicos);
                    } else if (Mecanico* mecanico = dynamic_cast<Mecanico*>(usuario)) {
                        menuMecanico(mecanico);
                    }
                }
                break;
            }
            case 2:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 2);
}

int main() {
    std::vector<Administrador> administradores = {Administrador("Admin", "Admin")};
    std::vector<Vendedor> vendedores = {Vendedor("Vendedor", "Vendedor"), Vendedor("Vendedor2", "Vendedor2"), Vendedor("Vendedor3", "Vendedor3")};
    std::vector<Mecanico> mecanicos = {Mecanico("Mecanico", "Mecanico"), Mecanico("Mecanico2", "Mecanico2"), Mecanico("Mecanico3", "Mecanico3")};
    menuLogin(administradores, vendedores, mecanicos);
    return 0;
}
