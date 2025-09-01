#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Cliente.h"
#include "Item.h"
#include "Livro.h"
#include "Revista.h"

class Sistema {
private:
    std::vector<Cliente> user;
    std::vector<std::unique_ptr<Item>> item;

    void alterarDadosCliente(Cliente& cliente);
    void alterarDadosLivro(Livro& livro);
    void alterarDadosRevista(Revista& revista);
    void AlterarLivroPorNome();
    void AlterarRevistaPorNome();
    void AlterarClientePorNome();

public:
    Sistema();

    void cadastrarCliente();
    void cadastrarItem(); // cadastro de livro e revista
    void listarTodos();
    void buscarPorNome();
    void alterarItem();
    void removerItem();
    void removerCliente();
    void gerarRelatorio();

    void salvarDados();
    void carregarDados();
};