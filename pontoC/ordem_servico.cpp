#include "ordem_servico.hpp"
#include "cliente.hpp"
#include "mecanicos.hpp"
#include <iostream>
#include <stdexcept> // Para std::invalid_argument

OrdemServico::OrdemServico(Cliente* cliente, Mecanicos* mecanico, bool manutencao, std::string motivo, double quilometragem, int numero)
    : cliente(cliente), mecanico(mecanico), manutencao(manutencao), motivo(motivo), quilometragem(quilometragem), numero(numero),
      aprovada(false), finalizada(false), realizada(false) {
   if (numero < 0) {
    throw std::invalid_argument("Número de ordem inválido.");
   }   
}


OrdemServico::OrdemServico() 
    : cliente(nullptr), mecanico(nullptr), manutencao(false), motivo(""), quilometragem(0), numero(0),
      aprovada(false), finalizada(false), realizada(false) {}


Cliente* OrdemServico::getCliente() const {
    return cliente;
}

int OrdemServico::getNumero() const {
    return numero;
}

string OrdemServico::getMotivo() const {
    return motivo;
}

bool OrdemServico::foiAprovada() const {
    return aprovada;
}

bool OrdemServico::finalizar() const {
    return finalizada;
}

bool OrdemServico::foiExecutada() const {
    return realizada;
}

void OrdemServico::executar() {
    realizada = true;
}

void OrdemServico::aprovar() {
    aprovada = true;
}

void OrdemServico::fechar() {
    finalizada = true;
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
    return manutencao;
}

bool OrdemServico::isValid() const {
    return numero >= 0; 
}

void OrdemServico::setCliente(Cliente* cliente) {
    this->cliente = cliente;
}

void OrdemServico::setMecanico(Mecanicos* mecanico) {
    this->mecanico = mecanico;
}



void OrdemServico::setNumero(int numero) {
    if (numero < 0) {
        throw std::invalid_argument("Número de ordem inválido.");
    }
    this->numero = numero;
}
// Verificação de ponteiros antes do acesso
string OrdemServico::getMecanico() const {
    if (mecanico != nullptr) {
        return mecanico->getNome();
    } else {
        return "Mecânico não atribuído";
    }
}






OrdemServico& OrdemServico::operator=(const OrdemServico& other) { // Operador de atribuição
    if (this != &other) {
        // Liberar o cliente atual (se houver)
        delete cliente;
        // Clonar o cliente de 'other' (se 'other.cliente' não for nulo)
        cliente = (other.cliente != nullptr) ? new Cliente(*other.cliente) : nullptr;
        // Copiar outros membros
        manutencao = other.manutencao;
        motivo = other.motivo;
        quilometragem = other.quilometragem;
        aprovada = other.aprovada;
        realizada = other.realizada;
        finalizada = other.finalizada;
        servicos = other.servicos;
        precosServicos = other.precosServicos;
        pecas = other.pecas;
        precosPecas = other.precosPecas;
    }
    return *this;
}

ostream& operator<<(ostream& os, const OrdemServico& ordem) {
    os << "Ordem de Serviço para: " << ordem.getCliente()->getNome() << endl;
    os << "Motivo: " << ordem.motivo << endl;
    os << "Quilometragem: " << ordem.quilometragem << endl;
    os << "Serviços realizados:" << endl;
    for (size_t i = 0; i < ordem.servicos.size(); ++i) {
        os << "  - " << ordem.servicos[i] << " (R$ " << ordem.precosServicos[i] << ")" << endl;
    }
    os << "Peças utilizadas:" << endl;
    for (size_t i = 0; i < ordem.pecas.size(); ++i) {
        os << "  - " << ordem.pecas[i] << " (R$ " << ordem.precosPecas[i] << ")" << endl;
    }
    return os;
}