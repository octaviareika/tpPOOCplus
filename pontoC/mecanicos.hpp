#ifndef MECANICO_HPP
#define MECANICO_HPP

#include "funcionarios.hpp"
#include "ordem_servico.hpp"
#include <vector>
#include <memory>  // Para std::shared_ptr

class Mecanico : public Funcionario {
private:
    std::vector<std::shared_ptr<OrdemDeServico>> ordensDeServico;

public:
    Mecanico(const std::string& nome, const std::string& senha);
    void setNome(const std::string& novoNome);
    void setSenha(const std::string& novaSenha);
    void adicionarOrdem(std::shared_ptr<OrdemDeServico> ordem);
    void visualizarOrdensAprovadas();
    void executarOrdemDeServico(int indice);
};

#endif
