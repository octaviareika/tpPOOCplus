#include "ordem_servico.hpp"

OrdemServico::OrdemServico(Cliente cliente, bool manutencao, string motivo, double quilometragem)
    : cliente(cliente), manutencao(manutencao), motivo(motivo), quilometragem(quilometragem), aprovada(false), executada(false), ismanutencao(manutencao) {}


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
bool OrdemServico::isManutencao() const {
    return ismanutencao;
}

ostream& operator<<(ostream& os, const OrdemServico& ordem) {
    os << "Cliente: " << ordem.getCliente().getNome() << endl;
    os << "CPF: " << ordem.getCliente().getCpf() << endl;
    os << "Endereço: " << ordem.getCliente().getEndereco() << endl;
    os << "Telefone: " << ordem.getCliente().getTelefone() << endl;
    os << "Veículo: " << ordem.getCliente().getVeiculo().getMarca() << " " << ordem.getCliente().getVeiculo().getModelo() << " (" << ordem.getCliente().getVeiculo().getPlaca() << ")" << endl;
    os << "Ano: " << ordem.getCliente().getVeiculo().getAno() << endl;
    os << "Cor: " << ordem.getCliente().getVeiculo().getCor() << endl;
    os << "Motivo: " << ordem.getMotivo() << endl;
    os << "Quilometragem: " << ordem.quilometragem << endl; // Ajuste aqui se necessário
    os << "Manutenção: " << (ordem.isManutencao() ? "Sim" : "Não") << endl;
    os << "Aprovada: " << (ordem.foiAprovada() ? "Sim" : "Não") << endl;
    os << "Executada: " << (ordem.foiExecutada() ? "Sim" : "Não") << endl;
    return os;
}