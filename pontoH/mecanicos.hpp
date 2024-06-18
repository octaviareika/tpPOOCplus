#ifndef MECANICO_HPP
#define MECANICO_HPP

#include "funcionarios.hpp"
#include "ordem_servico.hpp"
#include <vector>
class OrdemDeServico;
class Mecanico : public Funcionario {
private:
    std::vector<OrdemDeServico*> ordensDeServico;

public:
    Mecanico(const std::string& nome, const std::string& senha);
    void setNome(const std::string& novoNome);
    void setSenha(const std::string& novaSenha);
    void adicionarOrdem(OrdemDeServico& ordem);
    void visualizarOrdensAprovadas();
    void executarOrdemDeServico(int indice);
};

#endif
