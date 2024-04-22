#include <iostream>
#include "mecanicos.hpp"
#include "ordem_servico.hpp"


// Construtores
Mecanicos::Mecanicos() {
    nome = "";
    cpf = "";
    ordemDeServico = "";
}

Mecanicos::Mecanicos(string nome, string cpf, string ordemDeServico)
    : Funcionarios(nome, cpf), ordemDeServico(ordemDeServico) {
    this->ordemDeServico = ordemDeServico;
    this->nome = nome;
    this->cpf = cpf;
}

// Getters e Setters
string Mecanicos::getNome() const {
    return nome;
}

void Mecanicos::setNome(const string& nome) {
    this->nome = nome;
}

string Mecanicos::getCpf() const {
    return cpf;
}

void Mecanicos::setCpf(const string& cpf) {
    this->cpf = cpf;
}

string Mecanicos::getOrdemDeServico() const {
    return ordemDeServico;
}

void Mecanicos::setOrdemDeServico(const string& ordemDeServico) {
    this->ordemDeServico = ordemDeServico;
}



void Mecanicos::cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas) {
    // Encontrar a ordem de serviço pelo número
    for (OrdemServico& ordem : ordensEmExecucao) {
        if (ordem.getNumeroOrdem() == numeroOrdem) {
            // Adicionar os serviços realizados
            ordem.adicionarServico(servicosRealizados, valorServicos);
            // Adicionar as peças utilizadas
            ordem.adicionarPeca(pecasUtilizadas, valorPecas);
            // Encerrar a execução do método após encontrar a ordem
            return;
        }
    }
    throw runtime_error("Ordem de serviço não encontrada com o número especificado.");
}

void Mecanicos::visualizarOrdensAbertas() const {
    cout << "Ordens de serviço em aberto:" << endl;
    for (const OrdemServico& ordem : ordensEmExecucao) {
        // Exibir informações básicas da ordem de serviço
        cout << "Número: " << ordem.getNumeroOrdem() << endl;
        cout << "Cliente: " << ordem.getCliente()->getNome() << endl;
        cout << "Motivo: " << ordem.getMotivo() << endl;
        cout << "Manutenção: " << (ordem.isManutencao() ? "Sim" : "Não") << endl;
        cout << "Aprovada: " << (ordem.foiAprovada() ? "Sim" : "Não") << endl;
        cout << endl;
    }
}

void Mecanicos::adicionarOrdemServico(OrdemServico* ordem) {
    ordensEmExecucao.push_back(*ordem);
    cout << "Ordem de serviço adicionada para execução." << endl;
}
void Mecanicos::moverOrdemParaExecutadas(int numeroOrdem) {
    // Encontrar a ordem de serviço com base no número fornecido
    OrdemServico* ordem = buscarOrdemPorNumero(ordensEmExecucao, numeroOrdem);
    if (ordem) {
        // Marcar a ordem como executada
        ordem->foiExecutada();
        std::cout << "Ordem de serviço movida para o estado de 'executada'." << std::endl;
    } else {
        std::cerr << "Erro: ordem de serviço não encontrada." << std::endl;
    }
}

OrdemServico* Mecanicos::buscarOrdemPorNumero(vector<OrdemServico>& ordens, int numeroOrdem) {
    for (OrdemServico& ordem : ordens) {
        if (ordem.getNumeroOrdem() == numeroOrdem) {
            return &ordem;
        }
    }
    return nullptr;
}
