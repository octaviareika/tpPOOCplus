#include <iostream>
#include "ordem_servico.hpp"
#include "vendedor.hpp"
#include "funcionarios.hpp"
#include "mecanicos.hpp"
#include "cliente.hpp"
#include <vector>
#include <stdexcept> 
using namespace std;

// Ao chegar à oficina o cliente será atendido por um vendedor que irá providenciar o seu cadastro bem
/// como de seu veículo, caso não exista, e em seguida gerar uma ordem de serviço para solicitação de
// orçamento ou manutenção

Vendedor::Vendedor() : Funcionarios("", ""), mecanico(*new Mecanicos()){
}

Vendedor::Vendedor(const string& nome, const string& cpf, Mecanicos& mecanico)
    : Funcionarios(nome, cpf), mecanico(mecanico) {
}

void Vendedor::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Vendedor::getNome() const {
    return nome;
}

<<<<<<< HEAD
OrdemServico* Vendedor::gerarOrdemDeServico(Cliente& cliente, bool isManutencao, const string& motivo, double quilometragem) {
    // Gerar um número de ordem único (por exemplo, usando um contador estático)
    static int numeroOrdemCounter = 1;
    int numeroOrdem = numeroOrdemCounter++;
    // Criar uma nova instância de OrdemServico no heap (usando new)
    OrdemServico* ordem = new OrdemServico(&cliente, isManutencao, motivo, quilometragem, numeroOrdem);
    // Adicionar a ordem de serviço ao cliente
    cliente.adicionarOrdemServico(*ordem);
    // Adicionar a ordem de serviço à lista de ordensDeServico do Vendedor
    ordensDeServico.push_back(*ordem);
    // Retornar o ponteiro para a ordem de serviço criada
    return ordem;
}


=======
OrdemServico Vendedor::gerarOrdemDeServico(Cliente& cliente, Mecanicos& mecanico, bool isManutencao, const std::string& motivo, double quilometragem) {
    OrdemServico ordem(&cliente, isManutencao, motivo, quilometragem); // Cria uma nova ordem de serviço
    ordensDeServico.push_back(ordem); // Adiciona a ordem de serviço ao vetor de ordens de serviço
    cliente.adicionarOrdemServico(ordem);  // Adiciona a ordem de serviço ao cliente
    std::cout << "Ordem de serviço gerada com sucesso!" << std::endl;
    if (isManutencao) {
        ordem.aprovar(); // Aprova a ordem de serviço automaticamente se for manutenção
        mecanico.receberOrdemDeServico(ordem);
    }
    return ordem;
}

// ok
>>>>>>> testezin
void Vendedor::visualizarOrdensPendentes() {
    std::cout << "Ordens de serviço de orçamento pendentes de aprovação: " << std::endl;
    for (size_t i = 0; i < ordensDeServico.size(); i++) {
        if (!ordensDeServico[i].isManutencao() && !ordensDeServico[i].foiAprovada() && !ordensDeServico[i].foiExecutada() && !ordensDeServico[i].finalizar()) {
            std::cout << i << ": " << ordensDeServico[i].getCliente()->getNome() << " - " << ordensDeServico[i].getMotivo() << std::endl;
        }
    }
}

//ok
void Vendedor::marcarOrdemComoAprovada(int indice, Mecanicos& mecanico) { // numOrdem = indice
    if (indice >= 0 && static_cast<size_t>(indice) < ordensDeServico.size()) { // Verifica se o índice é válido
        ordensDeServico[static_cast<size_t>(indice)].aprovar(); // Aprova a ordem de serviço 
        mecanico.receberOrdemDeServico(ordensDeServico[static_cast<size_t>(indice)]);
        std::cout << "Ordem de serviço aprovada com sucesso!" << std::endl;
        enviarOrdemParaMecanico(&ordensDeServico[static_cast<size_t>(indice)]);
    } else {
        std::cout << "Índice inválido." << std::endl;
    }
}

void Vendedor::visualizarOrdensExecutadas() {
    std::cout << "Ordens de serviço executadas:" << std::endl;
     for (size_t i = 0; i < ordensDeServico.size(); i++) {
        if (ordensDeServico[i].foiExecutada() && !ordensDeServico[i].finalizar()) {
            std::cout << "Ordem número: "<< i-1 << ". " << ordensDeServico[i]<< std::endl; // Chama o operador << para imprimir a OrdemServico
        }
    }
}
void Vendedor::cadastrarCliente(const Cliente& cliente) {
    clientes.push_back(cliente); // Adiciona o cliente ao vetor de clientes
}
void Vendedor::cadastrarVeiculo(const Veiculo& veiculo, const Cliente& cliente) {
    clientes.back().setVeiculo(veiculo); // Define o veículo para o último cliente adicionado
}

void Vendedor::listarClientes() const {
    cout << "Lista de Clientes:" << endl;
    for (size_t i = 0; i < clientes.size(); i++) {
        cout << "Índice: " << i << ", Nome: " << clientes[i].getNome() << ", CPF: " << clientes[i].getCpf() << endl;
    }
}

int Vendedor::getNumClientes() const {
    return clientes.size();  // Retorna o número de clientes
}

const Cliente& Vendedor::getCliente(int indice) const {
    if (indice >= 0 && static_cast<size_t>(indice) < clientes.size()) {
        return clientes[indice]; // Retorna a referência constante para o cliente no índice fornecido
    } else {
        throw runtime_error("Índice de cliente inválido"); // Lança uma exceção para índice inválido
    }
}
<<<<<<< HEAD

void Vendedor::enviarOrdemParaMecanico(OrdemServico* ordem) {
    // Verifica se o objeto 'ordem' é válido
    if (ordem) {
        // Envia a ordem de serviço para o Mecanicos associado ao Vendedor
        mecanico.adicionarOrdemServico(ordem);
        std::cout << "Ordem de serviço enviada para o mecânico." << std::endl;
    } else {
        std::cerr << "Erro: ordem de serviço inválida." << std::endl;
    }
}

OrdemServico* Vendedor::getOrdemDeServico(int numeroOrdem) {
    for (auto& ordem : ordensDeServico) {
        if (ordem.getNumeroOrdem() == numeroOrdem) {
            return &ordem;
        }
    }
    return nullptr;
}
=======
void Vendedor::receberOrdemDeServicoVendedor(OrdemServico& ordem) {
    if(ordem.foiExecutada()) {
        ordensDeServico.push_back(ordem);
    }
}

   void Vendedor::fecharOrdemDeServico(int indice) {
    if (indice >= 0 && static_cast<size_t>(indice)+1 < ordensDeServico.size()) {
        ordensDeServico[static_cast<size_t>(indice)+1].fechar();
        std::cout << "Ordem de serviço fechada com sucesso!" << std::endl;
    } else {
        std::cout << "Índice inválido." << std::endl;
    }
}

>>>>>>> testezin
