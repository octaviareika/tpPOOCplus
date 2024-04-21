#include <iostream>

#include "veiculo.hpp"
#include "cliente.hpp"
#include "vendedor.hpp"
#include "mecanicos.hpp"

// A tela inicial do sistema deve ter as seguintes opções:
// • Login (Para administrador, vendedor ou mecânico).
/*• Sair do sistema, não é necessário persistir as informações ao sair do sistema, ou seja, as
informações devem existir enquanto o sistema estiver rodando.
Caso o usuário logado seja o administrador deverão ser exibidas as seguintes opções:
• Editar dados de Vendedores.
• Editar dados de Mecânicos.
Caso o usuário logado seja um Vendedor deverão ser exibidas as seguintes opções:
• Cadastrar cliente e veículo.
• Gerar ordem de serviço.
• Visualizar ordens de serviço de orçamento pendentes de aprovação do cliente e marcar como
aprovadas.
• Visualizar ordens de serviço executadas e realizar o fechamento.
Caso o usuário logado seja um mecânico deverão ser exibidas as seguintes opções:
• Visualizar ordens de serviço abertas.
• Cadastrar serviços executados e peças utilizadas*/

int main(){
    cout << "Tela de login do sistema de oficina" << endl;
    cout << "1 - Login" << endl;
    cout << "2 - Sair do sistema" << endl;
    cout << "Digite a opção desejada: ";
    int opcao;
    cin >> opcao;

    if(opcao == 1){
        cout << "Digite o seu login: ";
        string login;
        cin >> login;
        cout << "Digite a sua senha: ";
        string senha;
        cin >> senha;

        if (login == "Admin" && senha == "Admin"){
            cout << "Bem vindo administrador" << endl;
            cout << "1 - Editar dados de Vendedores" << endl;
            cout << "2 - Editar dados de Mecânicos" << endl;
            cout << "Digite a opção desejada: ";
            int opcaoAdmin;
            cin >> opcaoAdmin;

            if(opcaoAdmin == 1){
                cout << "Editar dados de Vendedores" << endl;
            }else if(opcaoAdmin == 2){
                cout << "Editar dados de Mecânicos" << endl;
            }else{
                cout << "Opção inválida" << endl;
            }
        }else if (login == "Vendedor" && senha == "Vendedor"){
            cout << "Bem vindo vendedor" << endl;
            cout << "1 - Cadastrar cliente e veículo" << endl;
            cout << "2 - Gerar ordem de serviço" << endl;
            cout << "3 - Visualizar ordens de serviço de orçamento pendentes de aprovação do cliente e marcar como aprovadas" << endl;
            cout << "4 - Visualizar ordens de serviço executadas e realizar o fechamento" << endl;
            cout << "Digite a opção desejada: ";
            int opcaoVendedor;
            cin >> opcaoVendedor;

            if(opcaoVendedor == 1){
                cout << "Cadastrar cliente e veículo" << endl;
            }else if(opcaoVendedor == 2){
                cout << "Gerar ordem de serviço" << endl;
            }else if(opcaoVendedor == 3){
                cout << "Visualizar ordens de serviço de orçamento pendentes de aprovação do cliente e marcar como aprovadas" << endl;
            }else if(opcaoVendedor == 4){
                cout << "Visualizar ordens de serviço executadas e realizar o fechamento" << endl;
            }else{
                cout << "Opção inválida" << endl;
            }

    }else if (login == "Mecanico" && senha == "Mecanico"){
            cout << "Bem vindo mecânico" << endl;
            cout << "1 - Visualizar ordens de serviço abertas" << endl;
            cout << "2 - Cadastrar serviços executados e peças utilizadas" << endl;
            cout << "Digite a opção desejada: ";
            int opcaoMecanico;
            cin >> opcaoMecanico;

            if(opcaoMecanico == 1){
                cout << "Visualizar ordens de serviço abertas" << endl;
            }else if(opcaoMecanico == 2){
                cout << "Cadastrar serviços executados e peças utilizadas" << endl;
            }else{
                cout << "Opção inválida" << endl;
            }
        }else{
            cout << "Login ou senha inválidos" << endl;
        }

    }else if(opcao == 2){
        cout << "Saindo do sistema" << endl;

    return 0;
}
