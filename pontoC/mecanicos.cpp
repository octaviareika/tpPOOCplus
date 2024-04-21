#include <iostream>
#include "mecanicos.hpp"
using namespace std;

Mecanicos::Mecanicos(string nome, string cpf, string ordemDeServico) : Funcionarios(nome, cpf) {
    this->ordemDeServico = ordemDeServico;
}

string Mecanicos::getOrdemDeServico() {
    return this->ordemDeServico;
}

void Mecanicos::setOrdemDeServico(string ordemDeServico) {
    this->ordemDeServico = ordemDeServico;
}

// O mecânico deverá visualizar as ordens de serviço abertas e escolher uma para realizar o serviço, caso
//seja orçamento o serviço não deverá ser executado antes de prévia autorização por parte do cliente,
// para tal o vendedor deverá visualizar as ordens de serviço aguardando aprovação do cliente, contatar o
//cliente e verificar se o mesmo aprova, caso seja aprovada ela deverá retornar a fila de ordens de
// serviços e poderá ser executada pelo mesmo mecânico ou por outro mecânico, caso o cliente não
//autorize deverá ser encerrada.

void Mecanicos::visualizarOrdensDeServico() {
    cout << "Ordens de serviço abertas: " << this->ordemDeServico << endl;
    if (this->getOrdemDeServico() == "Orçamento") {
        cout << "Serviço não executado" << endl;
    } else {
        cout << "Serviço executado" << endl;
    }
}