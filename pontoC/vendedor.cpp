#include <iostream>
#include "vendedor.hpp"
#include <vector>

using namespace std;

// Ao chegar à oficina o cliente será atendido por um vendedor que irá providenciar o seu cadastro bem
/// como de seu veículo, caso não exista, e em seguida gerar uma ordem de serviço para solicitação de
// orçamento ou manutenção


Vendedor::Vendedor(string nome, string cpf, string ordemDeServico) : Funcionarios(nome, cpf) {
    this->ordemDeServico = ordemDeServico;
}


OrdemServico gerarOrdemDeServico(Cliente cliente, bool manutencao, string motivo, double quilometragem);

OrdemServico Vendedor::gerarOrdemDeServico(Cliente cliente, bool manutencao, string motivo, double quilometragem) {
    OrdemServico ordem(cliente, manutencao, motivo, quilometragem);
    ordensDeServico.push_back(ordem);
    cout << "Ordem de serviço gerada com sucesso!" << endl;
    return ordem; // Retornar a ordem de serviço criada
}


void Vendedor::visualizarOrdensPendentes() {
    cout << "Ordens de serviço de orçamento pendentes de aprovação:" << endl;
    for (int i = 0; i < ordensDeServico.size(); i++) {
        if (!ordensDeServico[i].foiAprovada()) {
            cout << i + 1 << ". " << ordensDeServico[i].getCliente().getNome() << " - " << ordensDeServico[i].getMotivo() << endl;
        }
    }
}

void Vendedor::marcarOrdemComoAprovada(int indice) {
    if (indice >= 0 && indice < ordensDeServico.size()) {
        ordensDeServico[indice].aprovar();
        cout << "Ordem de serviço aprovada com sucesso!" << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}

void Vendedor::visualizarOrdensExecutadas() {
    cout << "Ordens de serviço executadas:" << endl;
    for (const auto& ordem : ordensDeServico) {
        if (ordem.foiExecutada()) {
            cout << ordem << endl;
        }
    }
}

ostream& operator<<(ostream& os, const OrdemServico& ordem) {
    os << "Nome: " << ordem.getCliente().getNome() << endl;
    os << "CPF: " << ordem.getCliente().getCpf() << endl;
    os << "Endereço: " << ordem.getCliente().getEndereco() << endl;
    os << "Telefone: " << ordem.getCliente().getTelefone() << endl;
    os << "Veículo: " << ordem.getCliente().getVeiculo().getMarca() << endl;
    os << "Modelo: " << ordem.getCliente().getVeiculo().getModelo() << endl;
    os << "Placa: " << ordem.getCliente().getVeiculo().getPlaca() << endl;
    os << "Ano: " << ordem.getCliente().getVeiculo().getAno() << endl;
    os << "Cor: " << ordem.getCliente().getVeiculo().getCor() << endl;
    os << "Ordem de serviço: " << ordem << endl;// ordem que o cliente quer
    return os;
}
 

void Vendedor::fecharOrdemDeServico(int indice) {
    if (indice >= 0 && indice < ordensDeServico.size()) {
        ordensDeServico[indice].fechar();
        cout << "Ordem de serviço fechada com sucesso!" << endl;
    } else {
        cout << "Índice inválido." << endl;
    }
}
void Vendedor::cadastrarCliente(Cliente cliente) {
    cout << "Cadastrando cliente..." << endl;
    clientes.push_back(cliente);

}

void Vendedor::cadastrarVeiculo(Cliente cliente) {
    cout << "Cadastrando veículo..." << endl;
    cout << "Digite a marca do veiculo: ";
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
}