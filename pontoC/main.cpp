#include <iostream>
#include <vector>
#include <string>
#include "vendedor.hpp"
#include "mecanicos.hpp"
#include "ordem_servico.hpp"
#include "cliente.hpp"
#include "veiculo.hpp"
#include "funcionarios.hpp"

// Classe para o administrador
class Administrador : public Funcionario {
public:
    Administrador(const std::string& nome, const std::string& senha) : Funcionario(nome, senha) {}
    void editarDados(std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos);
};

void Administrador::editarDados(std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos) {
    int opcao;
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
                std::cin >> novoNome;
                std::cout << "Nova senha: ";
                std::cin >> novaSenha;
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
                std::cin >> novoNome;
                std::cout << "Nova senha: ";
                std::cin >> novaSenha;
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
}

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

// Menu principal
void menuAdministrador(Administrador* admin, std::vector<Vendedor>& vendedores, std::vector<Mecanico>& mecanicos) {
    int opcao;
    do {
        std::cout << "1. Editar dados de Vendedores ou Mecânicos\n2. Sair\nEscolha uma opção: ";
        std::cin >> opcao;
        switch (opcao) {
            case 1:
                admin->editarDados(vendedores, mecanicos);
                break;
            case 2:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 2);
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
                std::cin >> nomeCliente;
                Cliente cliente(nomeCliente);
                vendedor->cadastrarCliente(cliente);
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
                Veiculo veiculo(marca, modelo, ano, quilometragem);
                vendedor->cadastrarVeiculo(veiculo, cliente);
                break;
            }
           case 2: {
            vendedor->listarClientes();
            int clienteIndice;
            std::cout << "Escolha um cliente: ";
            std::cin >> clienteIndice;
            if (clienteIndice > 0 && clienteIndice <= vendedor->getNumClientes()) {
                Cliente* cliente = &vendedor->getCliente(clienteIndice - 1);
                
                // Listar mecânicos disponíveis
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
                    double quilometragem;
                    
                    std::cout << "É manutenção? (1 para sim, 0 para não): ";
                    std::cin >> isManutencao;
                    std::cout << "Motivo: ";
                    std::cin.ignore();
                    std::getline(std::cin, motivo);
                    std::cout << "Quilometragem: ";
                    std::cin >> quilometragem;

                    // Gerar a ordem de serviço
                    vendedor->gerarOrdemDeServico(cliente, mecanico, isManutencao, motivo, quilometragem);

                    // Se for manutenção, marcar automaticamente como aprovada
                    if (isManutencao) {
                        const auto& ordensServico = vendedor->getOrdensServico();
                        vendedor->marcarOrdemComoAprovada(ordensServico.size(), mecanico);
                    }
                } else {
                    std::cout << "Mecânico inválido.\n";
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

int main() {
    std::vector<Administrador> administradores = {Administrador("admin", "1234")};
    std::vector<Vendedor> vendedores = {Vendedor("Vendedor", "Vendedor"), Vendedor("Vendedor1", "Vendedor1")};
    std::vector<Mecanico> mecanicos = {Mecanico("Mecanico", "Mecanico"), Mecanico("Mecanico1", "Mecanico1")};
    
    int opcao;
    do {
        std::cout << "1. Login\n2. Sair\nEscolha uma opção: ";
        std::cin >> opcao;
        if (opcao == 1) {
            Funcionario* usuarioLogado = login(administradores, vendedores, mecanicos);
            if (Administrador* admin = dynamic_cast<Administrador*>(usuarioLogado)) {
                menuAdministrador(admin, vendedores, mecanicos);
            } else if (Vendedor* vendedor = dynamic_cast<Vendedor*>(usuarioLogado)) {
                menuVendedor(vendedor, mecanicos);
            } else if (Mecanico* mecanico = dynamic_cast<Mecanico*>(usuarioLogado)) {
                menuMecanico(mecanico);
            }
        } else if (opcao == 2) {
            std::cout << "Saindo...\n";
        } else {
            std::cout << "Opção inválida.\n";
        }
    } while (opcao != 2);
    
    return 0;
}
