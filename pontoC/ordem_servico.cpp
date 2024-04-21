#include "ordem_servico.hpp"

OrdemServico::OrdemServico(Cliente cliente, bool manutencao, string motivo, double quilometragem)
    : cliente(cliente), manutencao(manutencao), motivo(motivo), quilometragem(quilometragem), aprovada(false), executada(false) {}

Cliente OrdemServico::getCliente() const {
    return cliente;
}

string OrdemServico::getMotivo() const {
    return motivo;
}

bool OrdemServico::foiAprovada() const {
    return aprovada;
}

bool OrdemServico::foiExecutada() const {
    return executada;
}

void OrdemServico::aprovar() {
    aprovada = true;
}

void OrdemServico::fechar() {
    executada = true;
}

void OrdemServico::adicionarServico(const string& servico, double preco) {
    servicos.push_back(servico);
    precosServicos.push_back(preco);
}

void OrdemServico::adicionarPeca(const string& peca, double preco) {
    pecas.push_back(peca);
    precosPecas.push_back(preco);
}
