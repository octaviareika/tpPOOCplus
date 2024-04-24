#include <iostream>
#include <string>
#include <vector>
#include "vendedor.hpp"
#include "cliente.hpp"
#include "mecanicos.hpp"
#include "veiculo.hpp"
#include "ordem_servico.hpp"

using namespace std;

int main() {
    Vendedor vendedor("Vendedor", "123456789");
    Mecanicos mecanico("Mecanico", "987654321");
    OrdemServico ordem;
    bool executando = true;

    while (executando) {
        cout << "Tela de login do sistema de oficina" << endl;
        cout << "1 - Login" << endl;
        cout << "2 - Sair do sistema" << endl;
        cout << "Digite a opção desejada: ";
        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cout << "Digite o seu login: ";
                string login;
                cin >> login;
                cout << "Digite a sua senha: ";
                string senha;
                cin >> senha;

                if (login == "Admin" && senha == "Admin") {
                    cout << "Bem vindo administrador" << endl;
                    while (true) {
                        cout << "1 - Editar dados de Vendedores" << endl;
                        cout << "2 - Editar dados de Mecânicos" << endl;
                        cout << "3 - Voltar ao menu principal" << endl;
                        cout << "Digite a opção desejada: ";
                        int opcaoAdmin;
                        cin >> opcaoAdmin;

                        if (opcaoAdmin == 1) {
                            // Editar dados de vendedores
                            cout << "Digite o novo nome do vendedor: ";
                            string novoNome;
                            cin >> novoNome;
                            vendedor.setNome(novoNome); 
                            cout << "Dados do vendedor atualizados com sucesso!" << endl;
                        } else if (opcaoAdmin == 2) {
                            // Editar dados de mecânicos
                            cout << "Digite o novo nome do mecânico: ";
                            string novoNome;
                            cin >> novoNome;
                            mecanico.setNome(novoNome);  
                            cout << "Dados do mecânico atualizados com sucesso!" << endl;
                        } else if (opcaoAdmin == 3) {
                            break;  // Voltar ao menu principal
                        } else {
                            cout << "Opção inválida" << endl;
                        }
                    }
                } else if (login == "Vendedor" && senha == "Vendedor") {
                    cout << "Bem vindo vendedor" << endl;
                    while (true) {
                        cout << "1 - Cadastrar cliente e veículo" << endl;
                        cout << "2 - Gerar ordem de serviço" << endl;
                        cout << "3 - Visualizar e aprovar ordens de serviço pendentes" << endl;
                        cout << "4 - Visualizar e fechar ordens de serviço executadas" << endl;
                        cout << "5 - Voltar ao menu principal" << endl;
                        cout << "Digite a opção desejada: ";
                        int opcaoVendedor;
                        cin >> opcaoVendedor;

                        if (opcaoVendedor == 1) {
                            cout << "Cadastrar cliente e veículo" << endl;
                            cout << "Digite o nome do cliente: ";
                            string nome;
                            cin >> nome;
                            cout << "Digite o CPF do cliente: ";
                            string cpf;
                            cin >> cpf;
                            cout << "Digite o endereço do cliente: ";
                            string endereco;
                            cin >> endereco;
                            cout << "Digite o telefone do cliente: ";
                            string telefone;
                            cin >> telefone;
                            cout << "Digite a marca do veículo: ";
                            string marca;
                            cin >> marca;
                            cout << "Digite o modelo do veículo: ";
                            string modelo;
                            cin >> modelo;
                            cout << "Digite o ano do veículo: ";
                            int ano;
                            cin >> ano;
                            cout << "Digite a placa do veículo: ";
                            string placa;
                            cin >> placa;
                            cout << "Digite a cor do veículo: ";
                            string cor;
                            cin >> cor;
                            cout << "Digite o preço do veículo: ";
                            double preco;
                            cin >> preco;
                            cout << "Digite a quilometragem do veículo: ";
                            double quilometragem;
                            cin >> quilometragem;
                            // Criar um objeto Veiculo com os dados fornecidos
                            Veiculo novoVeiculo(marca, modelo, placa, cor, ano, preco, quilometragem);
                            // Criar um objeto Cliente com os dados fornecidos
                            Cliente novoCliente(nome, cpf, endereco, telefone, novoVeiculo);
                            // Adicionar o cliente à lista de clientes do vendedor
                            vendedor.cadastrarCliente(novoCliente);
                            vendedor.cadastrarVeiculo(novoVeiculo, novoCliente);
                            cout << "Cliente e veículo cadastrados com sucesso!" << endl;
                        } else if (opcaoVendedor == 2) {
                            // Gerar ordem de serviço
                            vendedor.listarClientes();
                            int indiceCliente;
                            cout << "Digite o índice do cliente para gerar a ordem de serviço: ";
                            cin >> indiceCliente;
                            if (indiceCliente >= 0 && indiceCliente < vendedor.getNumClientes()) {
                                Cliente clienteSelecionado = vendedor.getCliente(indiceCliente); // Obter o cliente selecionado

                                string motivo;
                                int tipoOrdem;

                                cout << "Digite o motivo da ordem de serviço: ";
                                cin >> motivo;
                                cout << "Escolha o tipo de ordem de serviço:" << endl;
                                cout << "1 - Manutenção" << endl;
                                cout << "2 - Orçamento" << endl;
                                cin >> tipoOrdem;

                                bool isManutencao = (tipoOrdem == 1);

                                vendedor.gerarOrdemDeServico(clienteSelecionado, mecanico, isManutencao, motivo, clienteSelecionado.getVeiculo().getQuilometragem());
                            } else {
                                cout << "Índice de cliente inválido." << endl;
                            }
                        } else if (opcaoVendedor == 3) {
                            // Visualizar e aprovar ordens de serviço pendentes
                            vendedor.visualizarOrdensPendentes();
                            cout << "Digite o número da ordem de serviço que deseja aprovar: ";
                            int numeroOrdem;
                            cin >> numeroOrdem;
                            vendedor.marcarOrdemComoAprovada(numeroOrdem, mecanico);
                        } else if (opcaoVendedor == 4) {
                            // Visualizar e fechar ordens de serviço executadas
                            vendedor.visualizarOrdensExecutadas();
                            cout << "Digite o número da ordem de serviço que deseja fechar: ";
                            int numeroOrdem;
                            cin >> numeroOrdem;
                            vendedor.fecharOrdemDeServico(numeroOrdem);
                        } else if (opcaoVendedor == 5) {
                            break;  // Voltar ao menu principal
                        } else {
                            cout << "Opção inválida" << endl;
                        }
                    }
                } else if (login == "Mecanico" && senha == "Mecanico") {
                    cout << "Bem vindo mecânico" << endl;
                    while (true) {
                        cout << "1 - Visualizar ordens de serviço abertas" << endl;
                        cout << "2 - Cadastrar serviços executados e peças utilizadas" << endl;
                        cout << "3 - Voltar ao menu principal" << endl;
                        cout << "Digite a opção desejada: ";
                        int opcaoMecanico;
                        cin >> opcaoMecanico;

                        if (opcaoMecanico == 1) {
                            // Visualizar ordens de serviço abertas
                            mecanico.visualizarOrdensAbertas();
                        } else if (opcaoMecanico == 2) {
                            mecanico.visualizarOrdensAbertas();
                            // Cadastrar serviços executados e peças utilizadas
                            cout << "Digite o número da ordem de serviço que deseja atualizar: ";
                            int numeroOrdem;
                            cin >> numeroOrdem;
                            cout << "Descreva os serviços realizados: ";
                            string servicosRealizados;
                            cin.ignore();  // Limpar buffer do getline
                            getline(cin, servicosRealizados);
                            cout << "Informe o valor dos serviços: ";
                            double valorServicos;
                            cin >> valorServicos;
                            cout << "Descreva as peças utilizadas: ";
                            string pecasUtilizadas;
                            cin.ignore();  // Limpar buffer do getline
                            getline(cin, pecasUtilizadas);
                            cout << "Informe o valor das peças: ";
                            double valorPecas;
                            cin >> valorPecas;
                            mecanico.cadastrarServicosExecutados(numeroOrdem, servicosRealizados, valorServicos, pecasUtilizadas, valorPecas, vendedor);
                        } else if (opcaoMecanico == 3) {
                            break;  // Voltar ao menu principal
                        } else {
                            cout << "Opção inválida" << endl;
                        }
                    }
                } else {
                    cout << "Login ou senha inválidos" << endl;
                }
                break;
            }
            case 2: {
                executando = false;  // Encerrar o programa
                cout << "Saindo do sistema" << endl;
                break;
            }
            default: {
                cout << "Opção inválida" << endl;
                break;
            }
        }
    }

    return 0;
}