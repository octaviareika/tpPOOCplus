#include <iostream>
#include "cliente.hpp"
#include "vendedor.hpp"
#include "mecanicos.hpp"
#include "veiculo.hpp"
#include "ordem_servico.hpp"
using namespace std;

int main() {
    Vendedor vendedor;
    Mecanicos mecanico;

    cout << "Tela de login do sistema de oficina" << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Sair do sistema" << endl;
    cout << "Digite a opção desejada: ";
    int opcao;
    cin >> opcao;

    if (opcao == 1) {
        cout << "Digite o seu login: ";
        string login;
        cin >> login;
        cout << "Digite a sua senha: ";
        string senha;
        cin >> senha;

        if (login == "Admin" && senha == "Admin") {
            cout << "Bem vindo administrador" << endl;
            cout << "1 - Editar dados de Vendedores" << endl;
            cout << "2 - Editar dados de Mecânicos" << endl;
            cout << "Digite a opção desejada: ";
            int opcaoAdmin;
            cin >> opcaoAdmin;

            if (opcaoAdmin == 1) {
                cout << "Editar dados de Vendedores" << endl;
                cout << "Digite o novo nome do vendedor: ";
                string novoNome;
                cin >> novoNome;
                vendedor.setNome(novoNome); 
                cout << "Dados do vendedor atualizados com sucesso!" << endl;
            } else if (opcaoAdmin == 2) {
                cout << "Editar dados de Mecânicos" << endl;
                cout << "Digite o novo nome do mecânico: ";
                string novoNome;
                cin >> novoNome;
                mecanico.setNome(novoNome);  
                cout << "Dados do mecânico atualizados com sucesso!" << endl;
            } else {
                cout << "Opção inválida" << endl;
            }
        } else if (login == "Vendedor" && senha == "Vendedor") {
            cout << "Bem vindo vendedor" << endl;
            cout << "1 - Cadastrar cliente e veículo" << endl;
            cout << "2 - Gerar ordem de serviço" << endl;
            cout << "3 - Visualizar e aprovar ordens de serviço de orçamento pendentes" << endl;
            cout << "4 - Visualizar ordens de serviço executadas e realizar o fechamento" << endl;
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
                // Criar um objeto Veiculo com os dados fornecidos
                Veiculo novoVeiculo(marca, modelo, placa, cor, ano, preco);
                // Criar um objeto Cliente com os dados fornecidos
                Cliente novoCliente(nome, cpf, endereco, telefone, novoVeiculo);
                // Adicionar o cliente à lista de clientes do vendedor
                vendedor.cadastrarCliente(novoCliente);
                cout << "Cliente e veículo cadastrados com sucesso!" << endl;
            } else if (opcaoVendedor == 2) {
            cout << "Gerar ordem de serviço" << endl;
            cout << "Digite o motivo da ordem de serviço: ";
            string motivo;
            cin.ignore(); // Limpar o buffer do cin antes de getline
            getline(cin, motivo);
            cout << "Digite a quilometragem do veículo: ";
            double quilometragem;
            cin >> quilometragem;
            cout << "Escolha o tipo de ordem de serviço:" << endl;
            cout << "1 - Manutenção" << endl;
            cout << "2 - Orçamento" << endl;
            int tipoOrdem;
            cin >> tipoOrdem;
            // Criar uma nova ordem de serviço com base no tipo selecionado
            Cliente cliente; 
            bool isManutencao = (tipoOrdem == 1);
            vendedor.gerarOrdemDeServico(cliente, isManutencao, motivo, quilometragem);
            cout << "Ordem de serviço gerada com sucesso!" << endl;
            } else if (opcaoVendedor == 3) {
                cout << "Visualizar e aprovar ordens de serviço de orçamento pendentes" << endl;
                vendedor.visualizarOrdensPendentes();
                cout << "Digite o número da ordem de serviço que deseja aprovar: ";
                int numeroOrdem;
                cin >> numeroOrdem;
                vendedor.marcarOrdemComoAprovada(numeroOrdem);
                cout << "Ordem de serviço aprovada com sucesso!" << endl;

            } else if (opcaoVendedor == 4) {
                cout << "Visualizar ordens de serviço executadas e realizar o fechamento" << endl;
                vendedor.visualizarOrdensExecutadas();
                cout << "Digite o número da ordem de serviço que deseja fechar: ";
                int numeroOrdem;
                cin >> numeroOrdem;
                vendedor.fecharOrdemDeServico(numeroOrdem);
                cout << "Ordem de serviço fechada com sucesso!" << endl;

            } else {
                cout << "Opção inválida" << endl;
            }

        } else if (login == "Mecanico" && senha == "Mecanico") {
            cout << "Bem vindo mecânico" << endl;
            cout << "1 - Visualizar ordens de serviço abertas" << endl;
            cout << "2 - Cadastrar serviços executados e peças utilizadas" << endl;
            cout << "Digite a opção desejada: ";
            int opcaoMecanico;
            cin >> opcaoMecanico;

            if (opcaoMecanico == 1) {
                cout << "Visualizar ordens de serviço abertas" << endl;
                mecanico.visualizarOrdensAbertas();
            } else if (opcaoMecanico == 2) {
                cout << "Cadastrar serviços executados e peças utilizadas" << endl;
                cout << "Digite o número da ordem de serviço que deseja atualizar: ";
                int numeroOrdem;
                cin >> numeroOrdem;
                cout << "Descreva os serviços realizados: ";
                string servicosRealizados;
                cin >> servicosRealizados;
                cout << "Informe o valor dos serviços: ";
                double valorServicos;
                cin >> valorServicos;
                cout << "Descreva as peças utilizadas: ";
                string pecasUtilizadas;
                cin >> pecasUtilizadas;
                cout << "Informe o valor das peças: ";
                double valorPecas;
                cin >> valorPecas;
                mecanico.cadastrarServicosExecutados(numeroOrdem, servicosRealizados, valorServicos, pecasUtilizadas, valorPecas);
                cout << "Serviços e peças cadastrados com sucesso para a ordem de serviço!" << endl;
            } else {
                cout << "Opção inválida" << endl;
            }
        } else {
            cout << "Login ou senha inválidos" << endl;
        }
    } else if (opcao == 2) {
        cout << "Saindo do sistema" << endl;
    }

    return 0;
}
