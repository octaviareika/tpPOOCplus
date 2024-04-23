#include <iostream>
#include "mecanicos.hpp"
#include "ordem_servico.hpp"
#include "vendedor.hpp"

// O mecânico deverá visualizar as ordens de serviço abertas e escolher uma para realizar o serviço, caso
// seja orçamento o serviço não deverá ser executado antes de prévia autorização por parte do cliente,
// para tal o vendedor deverá visualizar as ordens de serviço aguardando aprovação do cliente, contatar o
//cliente e verificar se o mesmo aprova

// Construtores
Mecanicos::Mecanicos() : Funcionarios("", "") {
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

// Outros métodos da classe
void Mecanicos::visualizarOrdensAbertas() const {
    cout << "Visualizando ordens de serviço abertas..." << endl;
    if(ordensDeServico.empty()) {
        cout << "Nenhuma ordem de serviço aberta." << endl;
        return;
    }
    int index = 0;
    for (const OrdemServico& ordem : ordensDeServico) { // ordensDeServico do mecanico
        if(!ordem.finalizar() && !ordem.foiExecutada()){
        cout << "Ordem de serviço " << index << ": " << ordem.getMotivo() << endl;
        index++;
    }
    }
}

//ok
void Mecanicos::cadastrarServicosExecutados(int numeroOrdem, const string& servicosRealizados, double valorServicos, const string& pecasUtilizadas, double valorPecas, Vendedor& vendedor) {
    if (numeroOrdem >= 0 && static_cast<size_t>(numeroOrdem) < ordensDeServico.size()) {
    cout << "Serviços executados cadastrados com sucesso para a ordem de serviço " << numeroOrdem << endl;
    cout << "Serviços realizados: " << servicosRealizados << endl;
    cout << "Valor dos serviços: " << valorServicos << endl;
    cout << "Peças utilizadas: " << pecasUtilizadas << endl;
    cout << "Valor das peças: " << valorPecas << endl;
    // Adiciona os serviços executados à ordem de serviço correspondente
    ordensDeServico[numeroOrdem].adicionarServico(servicosRealizados, valorServicos);
    ordensDeServico[numeroOrdem].adicionarPeca(pecasUtilizadas, valorPecas);
    ordensDeServico[numeroOrdem].executar();
    vendedor.receberOrdemDeServicoVendedor(ordensDeServico[numeroOrdem]);
    } else {
        cout << "Número de ordem inválido." << endl;
    }
}

void Mecanicos::receberOrdemDeServico(OrdemServico& ordem) { // vai receber ordem do vendedor
        if (ordem.foiAprovada()) {
            ordensDeServico.push_back(ordem); // Adiciona a ordem de serviço ao vetor de ordens de serviço do mecanico
        }//esse ordem de servico é do mecanico
}
