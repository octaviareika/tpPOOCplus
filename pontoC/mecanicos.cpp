#include <iostream>
#include "mecanicos.hpp"
#include "ordem_servico.hpp"
<<<<<<< HEAD
=======
#include "vendedor.hpp"
>>>>>>> testezin

// O mecânico deverá visualizar as ordens de serviço abertas e escolher uma para realizar o serviço, caso
// seja orçamento o serviço não deverá ser executado antes de prévia autorização por parte do cliente,
// para tal o vendedor deverá visualizar as ordens de serviço aguardando aprovação do cliente, contatar o
//cliente e verificar se o mesmo aprova

// Construtores
Mecanicos::Mecanicos() : Funcionarios("", "") {
    nome = "";
    cpf = "";
}

Mecanicos::Mecanicos(string nome, string cpf)
    : Funcionarios(nome, cpf){
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


<<<<<<< HEAD


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
=======
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
       // Vendedor::marcarOrdemComoAprovada(0, *this); // Aprova a ordem de serviço
        if (ordem.foiAprovada()) {
            ordensDeServico.push_back(ordem); // Adiciona a ordem de serviço ao vetor de ordens de serviço do mecanico
        }//esse ordem de servico é do mecanico
>>>>>>> testezin
}
