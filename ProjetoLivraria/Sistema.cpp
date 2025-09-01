#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm> 

int Cliente::numClientes = 0;
int Livro::numLivros = 0;
int Revista::numRevistas = 0;

Sistema::Sistema() {}


void Sistema::salvarDados() {
    // salvar clientes
    std::ofstream arqClientes("clientes.txt");
    if (arqClientes.is_open()) {
        arqClientes << Cliente::getNumClientes() << std::endl;
        for (const auto& cliente : user) {
            arqClientes << cliente.getId() << ';' 
                        << cliente.getNome() << ';' 
                        << cliente.getCpf() << '\n';
        }
        arqClientes.close();
    } else {
        std::cerr << "ERRO: Nao foi possivel abrir o arquivo de clientes para salvar.\n";
    }

    // salvar itens (livros e revistas)
    std::ofstream arqItens("itens.txt");
    if (arqItens.is_open()) {
        arqItens << Livro::getNumLivros() << std::endl;
        arqItens << Revista::getNumRevistas() << std::endl;
        for (const auto& pItem : item) {
            arqItens << pItem->getTipo() << ';'; 
            pItem->salvar(arqItens); 
        }
        arqItens.close();
    } else {
        std::cerr << "ERRO: Nao foi possivel abrir o arquivo de itens para salvar.\n";
    }
    std::cout << "\nDados salvos com sucesso!\n";
}

void Sistema::carregarDados() {
    // carregar clientes
    std::ifstream arqClientes("clientes.txt");
    if (arqClientes.is_open()) {
        std::string linha;
        if (std::getline(arqClientes, linha) && !linha.empty()) {
            try { Cliente::setNumClientes(std::stoi(linha)); } catch(...) {}
        }
        while (std::getline(arqClientes, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string idStr, nome, cpf;
            std::getline(ss, idStr, ';');
            std::getline(ss, nome, ';');
            std::getline(ss, cpf, ';');
            user.emplace_back(std::stoi(idStr), nome, cpf);
        }
        arqClientes.close();
    }

    // carregar itens
    std::ifstream arqItens("itens.txt");
    if (arqItens.is_open()) {
        std::string linha;
        if (std::getline(arqItens, linha) && !linha.empty()) {
            try { Livro::setNumLivros(std::stoi(linha)); } catch(...) {}
        }
        if (std::getline(arqItens, linha) && !linha.empty()) {
            try { Revista::setNumRevistas(std::stoi(linha)); } catch(...) {}
        }

        while (std::getline(arqItens, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string tipo;
            std::getline(ss, tipo, ';');

            if (tipo == "LIVRO") {
                std::string idStr, ed, pr, cat, cap, aut, ano, nome;
                std::getline(ss, idStr, ';'); std::getline(ss, ed, ';'); std::getline(ss, pr, ';');
                std::getline(ss, cat, ';'); std::getline(ss, cap, ';'); std::getline(ss, aut, ';');
                std::getline(ss, ano, ';'); std::getline(ss, nome, '\n'); // lê até o fim da linha
                item.push_back(std::make_unique<Livro>(std::stoi(idStr), ed, pr, cat, cap, aut, ano, nome));
            } else if (tipo == "REVISTA") {
                std::string idStr, ed, pr, cat, mes, edicao;
                std::getline(ss, idStr, ';'); std::getline(ss, ed, ';'); std::getline(ss, pr, ';');
                std::getline(ss, cat, ';'); std::getline(ss, mes, ';'); std::getline(ss, edicao, '\n');
                item.push_back(std::make_unique<Revista>(std::stoi(idStr), ed, pr, cat, mes, edicao));
            }
        }
        arqItens.close();
    }
    std::cout << "Dados carregados do sistema anterior (se houver).\n";
}

// --- MÉTODOS CRUD PRINCIPAIS ---

void Sistema::cadastrarCliente(){
    std::string auxNome, auxCpf;
    std::cout << "\n--- Cadastro De Cliente ---\n";
    std::cout << "Nome: ";
    getline(std::cin, auxNome);
    std::cout << "CPF: ";
    getline(std::cin, auxCpf);
    user.emplace_back(auxNome, auxCpf);
    std::cout << "Cliente cadastrado com sucesso!\n";
}

void Sistema::cadastrarItem() {
    std::string escolha;
    std::cout << "\nQual tipo de item deseja cadastrar?\n";
    std::cout << "1. Livro\n";
    std::cout << "2. Revista\n";
    std::cout << "Opcao: ";
    getline(std::cin, escolha);

    if (escolha == "1") {
        std::string editora, preco, categoria, capa, autor, ano, nome;
        std::cout << "\n--- Cadastro De Livro ---\n";
        std::cout << "Titulo: "; getline(std::cin, nome);
        std::cout << "Autor: "; getline(std::cin, autor);
        std::cout << "Editora: "; getline(std::cin, editora);
        std::cout << "Preco: "; getline(std::cin, preco);
        std::cout << "Categoria: "; getline(std::cin, categoria);
        std::cout << "Ano: "; getline(std::cin, ano);
        std::cout << "Tipo de Capa: "; getline(std::cin, capa);
        item.push_back(std::make_unique<Livro>(editora, preco, categoria, capa, autor, ano, nome));
        std::cout << "Livro cadastrado com sucesso!\n";
    } else if (escolha == "2") {
        std::string editora, preco, categoria, mes, edicao;
        std::cout << "\n--- Cadastro De Revista ---\n";
        std::cout << "Edicao: "; getline(std::cin, edicao);
        std::cout << "Mes de publicacao: "; getline(std::cin, mes);
        std::cout << "Editora: "; getline(std::cin, editora);
        std::cout << "Preco: "; getline(std::cin, preco);
        std::cout << "Categoria: "; getline(std::cin, categoria);
        item.push_back(std::make_unique<Revista>(editora, preco, categoria, mes, edicao));
        std::cout << "Revista cadastrada com sucesso!\n";
    } else {
        std::cout << "Opcao invalida!\n";
    }
}

void Sistema::listarTodos() {
    std::cout << "\n--- LISTA DE TODOS OS ITENS ---\n";
    if (item.empty()) {
        std::cout << "Nenhum item cadastrado.\n";
    } else {
        for(const auto& pItem : item) {
            pItem->exibir();
        }
    }

    std::cout << "\n--- LISTA DE TODOS OS CLIENTES ---\n";
    if (user.empty()) {
        std::cout << "Nenhum cliente cadastrado.\n";
    } else {
        for(const auto& cliente : user) {
            cliente.exibir();
            std::cout << "\n";
        }
    }
}

void Sistema::buscarPorNome() {
    std::string nomeBusca;
    std::cout << "Digite o nome/titulo/edicao para buscar: ";
    getline(std::cin, nomeBusca);
    
    std::cout << "\n=== ITENS ENCONTRADOS ===\n";
    bool encontrou = false;
    for(const auto& pItem : item) {
        if(pItem->getNomeParaBusca().find(nomeBusca) != std::string::npos) {
            pItem->exibir();
            encontrou = true;
        }
    }
    if(!encontrou) {
        std::cout << "Nenhum item encontrado.\n";
    }
}

void Sistema::removerItem() {
    std::string nomeBusca;
    std::cout << "Digite o nome/titulo/edicao do item para remover: ";
    getline(std::cin, nomeBusca);
    
    std::vector<int> idsEncontrados;
    std::cout << "\n=== ITENS ENCONTRADOS ===\n";
    for(const auto& pItem : item) {
        std::string nomeItem = pItem->getNomeParaBusca();
        std::string buscaLower = nomeBusca;
        std::transform(nomeItem.begin(), nomeItem.end(), nomeItem.begin(), ::tolower);
        std::transform(buscaLower.begin(), buscaLower.end(), buscaLower.begin(), ::tolower);

        if(nomeItem.find(buscaLower) != std::string::npos) {
            std::cout << "ID [" << pItem->getId() << "] - " << pItem->getTipo() << ": " << pItem->getNomeParaBusca() << std::endl;
            idsEncontrados.push_back(pItem->getId());
        }
    }

    if(idsEncontrados.empty()) {
        std::cout << "Nenhum item encontrado com esse nome.\n";
        return;
    }

    std::cout << "\nDigite o ID do item que deseja remover (ou 0 para cancelar): ";
    int idParaRemover;
    std::cin >> idParaRemover;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (idParaRemover == 0) {
        std::cout << "Remocao cancelada.\n";
        return;
    }

    auto it = std::remove_if(item.begin(), item.end(), [idParaRemover](const std::unique_ptr<Item>& p){
        return p->getId() == idParaRemover;
    });

    if (it != item.end()) {
        item.erase(it, item.end());
        std::cout << "Item com ID " << idParaRemover << " removido com sucesso!\n";
    } else {
        std::cout << "ERRO: ID nao encontrado na lista de resultados.\n";
    }
}

void Sistema::gerarRelatorio() {
    std::cout << "\n=========== RELATORIO DO SISTEMA ===========\n";

    std::cout << "\nCLIENTES:\n";
    std::cout << " -> Quantidade de clientes cadastrados: " << user.size() << "\n";
    
    int qtdLivros = 0, qtdRevistas = 0;
    double valorTotal = 0.0;

    for (const auto& ptr : item) {
        if (dynamic_cast<Livro*>(ptr.get())) {
            qtdLivros++;
        }
        else if (dynamic_cast<Revista*>(ptr.get())) {
            qtdRevistas++;
        }
        try {
            valorTotal += std::stod(ptr->getPreco());
        } catch(const std::invalid_argument& e) {
        }
    }

    std::cout << "\nESTOQUE:\n";
    std::cout << " -> Quantidade de livros: " << qtdLivros << "\n";
    std::cout << " -> Quantidade de revistas: " << qtdRevistas << "\n";
    std::cout << " -> Quantidade total de itens: " << item.size() << "\n";
    printf(" -> Valor total aproximado do estoque: R$ %.2f\n", valorTotal);
    std::cout << "\n============================================\n";
}

void Sistema::alterarItem() {
    std::string escolha;
    std::cout << "\n--- MENU DE ALTERACAO ---\n";
    std::cout << "O que você deseja alterar?\n";
    std::cout << "1. Livro (por nome)\n";
    std::cout << "2. Revista (por Edicao)\n";
    std::cout << "3. Cliente (por nome)\n";
    std::cout << "---------------------------\n";
    std::cout << "Opcao: ";
    
    getline(std::cin, escolha);

    if (escolha == "1") {
        AlterarLivroPorNome();
    } else if (escolha == "2") {
        AlterarRevistaPorNome();
    } else if (escolha == "3") {
        AlterarClientePorNome();
    } else {
        std::cout << "Opcao invalida!\n";
    }
}

void Sistema::AlterarLivroPorNome(){
    std::string nomeBusca;
    std::cout << "Digite o nome do livro para alterar: ";
    getline(std::cin, nomeBusca);
    
    std::vector<Livro*> encontrados;
    std::cout << "\n=== LIVROS ENCONTRADOS ===\n";
    for(const auto& itemPtr : item) {
        Livro* livro = dynamic_cast<Livro*>(itemPtr.get());
        if(livro != nullptr && livro->getNome().find(nomeBusca) != std::string::npos) {
            std::cout << "[" << livro->getId() << "] " << livro->getNome() << " - " << livro->getAutor() << "\n";
            encontrados.push_back(livro);
        }
    }
    
    if(encontrados.empty()) {
        std::cout << "Nenhum livro encontrado.\n";
        return;
    }
    
    std::cout << "\nDigite o ID do livro para alterar: ";
    int idEscolhido;
    std::cin >> idEscolhido;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(auto livro : encontrados) {
        if(livro->getId() == idEscolhido) {
            alterarDadosLivro(*livro);
            return;
        }
    }
    std::cout << "ID invalido!\n";
}

void Sistema::AlterarRevistaPorNome(){
    std::string nomeBusca;
    std::cout << "Digite a edicao da revista para alterar: ";
    getline(std::cin, nomeBusca);
    
    std::vector<Revista*> encontrados;
    std::cout << "\n=== REVISTAS ENCONTRADAS ===\n";
    for(const auto& itemPtr : item) {
        Revista* revista = dynamic_cast<Revista*>(itemPtr.get());
        if(revista != nullptr && revista->getEdicao().find(nomeBusca) != std::string::npos) {
            std::cout << "[" << revista->getId() << "] " << revista->getEdicao() << " - " << revista->getEditora() << "\n";
            encontrados.push_back(revista);
        }
    }
    
    if(encontrados.empty()) {
        std::cout << "Nenhuma revista encontrada.\n";
        return;
    }
    
    std::cout << "\nDigite o ID da revista para alterar: ";
    int idEscolhido;
    std::cin >> idEscolhido;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(auto revista : encontrados) {
        if(revista->getId() == idEscolhido) {
            alterarDadosRevista(*revista);
            return;
        }
    }
    std::cout << "ID invalido!\n";
}

void Sistema::AlterarClientePorNome(){
    std::string nomeBusca;
    std::cout << "Digite o nome do cliente para alterar: ";
    getline(std::cin, nomeBusca);
    
    std::vector<Cliente*> encontrados;
    std::cout << "\n=== CLIENTES ENCONTRADOS ===\n";
    for(auto& cliente : user) { 
        if(cliente.getNome().find(nomeBusca) != std::string::npos) {
            std::cout << "[" << cliente.getId() << "] " << cliente.getNome() << " - " << cliente.getCpf() << "\n";
            encontrados.push_back(&cliente);
        }
    }
    
    if(encontrados.empty()) {
        std::cout << "Nenhum cliente encontrado.\n";
        return;
    }

    std::cout << "\nDigite o ID do cliente para alterar: ";
    int idEscolhido;
    std::cin >> idEscolhido;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for(auto clientePtr : encontrados) {
        if(clientePtr->getId() == idEscolhido) {
            alterarDadosCliente(*clientePtr);
            return;
        }
    }
    std::cout << "ID invalido!\n";
}

void Sistema::alterarDadosCliente(Cliente& cliente) {
    std::string novoValor;
    
    std::cout << "\nALTERANDO CLIENTE ID: " << cliente.getId() << " (deixe em branco para nao alterar)\n";
    
    std::cout << "Nome atual: " << cliente.getNome() << ". Novo nome: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) cliente.setNome(novoValor);
    
    std::cout << "CPF atual: " << cliente.getCpf() << ". Novo CPF: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) cliente.setCpf(novoValor);

    std::cout << "Cliente alterado com sucesso!\n";
}

void Sistema::alterarDadosLivro(Livro& livro) {
    std::string novoValor;
    
    std::cout << "\nALTERANDO LIVRO ID: " << livro.getId() << " (deixe em branco para nao alterar)\n";
    
    std::cout << "Titulo atual: " << livro.getNome() << ". Novo titulo: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) livro.setNome(novoValor);

    std::cout << "Autor atual: " << livro.getAutor() << ". Novo autor: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) livro.setAutor(static_cast<std::string>(novoValor));

    std::cout << "Editora atual: " << livro.getEditora() << ". Nova editora: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) livro.setEditora(novoValor);

    std::cout << "Preco atual: " << livro.getPreco() << ". Novo Preco: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) livro.setPreco(novoValor);

    std::cout << "Ano atual: " << livro.getAno() << ". Novo ano: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) livro.setAno(novoValor);

    std::cout << "Tipo de capa atual: " << livro.getCapa() << ". Novo tipo de capa: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) livro.setCapa(novoValor);

    std::cout << "Livro alterado com sucesso!\n";
}

void Sistema::alterarDadosRevista(Revista& revista) {
    std::string novoValor;

    std::cout << "\nALTERANDO REVISTA ID: " << revista.getId() << " (deixe em branco para nao alterar)\n";

    std::cout << "Edicao atual: " << revista.getEdicao() << ". Nova edicao: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) revista.setEdicao(novoValor);

    std::cout << "Mes atual: " << revista.getMes() << ". Novo mes: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) revista.setMes(novoValor);

    std::cout << "Editora atual: " << revista.getEditora() << ". Nova editora: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) revista.setEditora(novoValor);

    std::cout << "Preco atual: " << revista.getPreco() << ". Novo preco: ";
    getline(std::cin, novoValor);
    if (!novoValor.empty()) revista.setPreco(novoValor);

    std::cout << "Revista alterada com sucesso!\n";
}