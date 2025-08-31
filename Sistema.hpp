#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Cliente.hpp"
#include "Livro.hpp"
#include "Revista.hpp"
#include "Item.hpp"

class Sistema {
    std::vector<Cliente> user;
    std::vector<std::unique_ptr<Item>> item;
    //utiliza polimorfismo para criar um vetor de ponteiros da classe item 
    //que pode ser utilizado para suas subclasses atraves de make_unique

public:
    void cadastrarCliente(){
        std::string auxNome, auxCpf, aux = "1";
        
        while(aux!="0") {
            system("cls");
            
            std::cout << "Cadastro De Cliente\n\n";
            std::cout << "Nome: ";
            std::cin.ignore();
            getline(std::cin, auxNome);
            std::cout << "CPF: ";
            getline(std::cin, auxCpf);
    
            user.push_back(Cliente(auxNome, auxCpf));
            std::cout << "[LOG] Cadastro concluído com sucesso" << std::endl;
            std::cout << "Deseja um novo cadastro?\n\n [1] Sim\n [2] Não";
            getline(std::cin, aux);
        }
    }
    void CadastrarLivro(){

        std::string auxEditora, auxPreco, auxCategoria  ;
        std::string auxCapa, auxAutor, auxAno, auxNome;
        std::string aux = "1";
        
        while(aux!="0") {
            system("cls");
            
            std::cout << "Cadastro De Livro\n\n";
            std::cout << "Título: ";
            std::cin.ignore();
            getline(std::cin, auxNome);
            std::cout << "Editora: ";
            getline(std::cin, auxEditora);
            std::cout << "Preço: ";
            getline(std::cin, auxPreco);
            std::cout << "Categoria: ";
            getline(std::cin, auxCategoria);
            std::cout << "Autor: ";
            getline(std::cin, auxAutor);
            std::cout << "Ano: ";
            getline(std::cin, auxAno);
            std::cout << "Capa: ";
            getline(std::cin, auxCapa);
    
    
            item.push_back(std::make_unique<Livro>(auxEditora, auxPreco, auxCategoria,
                            auxCapa, auxAutor, auxAno, auxNome));
            std::cout << "[LOG] Cadastro concluído com sucesso" << std::endl;
            std::cout << "Deseja um novo cadastro?\n\n [1] Sim\n [2] Não";
            getline(std::cin, aux);
        }
    }
    void CadastrarRevista(){

        std::string auxEditora, auxPreco, auxCategoria  ;
        std::string auxMes, auxEdicao;
        std::string aux = "1";
        
        while(aux!="0") {
            system("cls");
            
            std::cout << "Cadastro De Revista\n\n";
            std::cout << "Edição: ";
            std::cin.ignore();
            getline(std::cin, auxEdicao);
            std::cout << "Editora: ";
            getline(std::cin, auxEditora);
            std::cout << "Preço: ";
            getline(std::cin, auxPreco);
            std::cout << "Categoria: ";
            getline(std::cin, auxCategoria);
            std::cout << "Mês de publicação: ";
            getline(std::cin, auxMes);
            std::cout << "Ano: ";
    
    
            item.push_back(std::make_unique<Revista>(auxEditora, auxPreco, auxCategoria,
                            auxEdicao, auxMes));
            std::cout << "[LOG] Cadastro concluído com sucesso" << std::endl;
            std::cout << "Deseja um novo cadastro?\n\n [1] Sim\n [2] Não";
            getline(std::cin, aux);
        }
    }

    void ListarClientes(){
        std::cout << "Lista de Clientes\n\n";
        
        if(user.empty()){
            std::cout << "[LOG] Lista Vazia\n\n";
            system("pause>null");
            return;
        }

        for(auto& aux:user) {
            std::cout << "[" << aux.getId() << "] - " << aux.getNome() << std::endl;
            std::cout << "CPF: " << aux.getCpf() << "\n\n";
        }
    }

    void pesquisarPorNome(const std::string &nomeBusca) {

        std::string escolha;

        std::cout << "O que deseja pesquisar? \n\n[1] Livro \n[2] Revista \n[3] Cliente";
        std::cin >> escolha;
        std::cin.ignore();

        std::cout << "\n=== PESQUISA PARCIAL: \"" << nomeBusca << "\" ===\n";
        bool encontrou = false;


        if(escolha == "1") {
            for (const auto& itens: item) {
    
                Livro* livro = dynamic_cast<Livro*>(itens.get());
    
                if (livro != nullptr) { 
                    if (livro->getNome().find(nomeBusca) != std::string::npos) {
                        livro->exibir();
                        encontrou = true;
                    }
                }
            }
            
            if (!encontrou) {
                std::cout << "Nenhum livro encontrado contendo \"" << nomeBusca << "\".\n";
            }
        } else if(escolha == "2") {
            for (const auto& itens: item) {
    
                Revista* revista = dynamic_cast<Revista*>(itens.get());
    
                if (revista != nullptr) { 
                    if (revista->getEditora().find(nomeBusca) != std::string::npos) {
                        revista->exibir();
                        encontrou = true;
                    }
                }
            }
            
            if (!encontrou) {
                std::cout << "Nenhuma revista encontrado contendo \"" << nomeBusca << "\".\n";
            } 
        } else if (escolha == "3") {

            for (const auto& cliente : user) {
                if (cliente.getNome().find(nomeBusca) != std::string::npos) {
                    cliente.exibir();
                    encontrou = true;
                }
            }
            
            if (!encontrou) {
                std::cout << "Nenhum cliente encontrado contendo \"" << nomeBusca << "\".\n";
            }
        }
    }
    
    void alterarClientePorId() {
        if (user.empty()) {
            std::cout << "Nenhum cliente cadastrado!\n";
            return;
        }

        int id;
        std::cout << "\nDigite o ID do cliente para alterar: ";
        std::cin >> id;
        std::cin.ignore();

        for (auto& cliente : user) {
            if (cliente.getId() == id) {
                alterarDadosCliente(cliente);
                return;
            }
        }

        std::cout << "Cliente com ID " << id << " não encontrado!\n";
    }

    void alterarLivroPorId() {
        if (item.empty()) {
            std::cout << "Nenhum livro cadastrado!\n";
            return;
        }


        int id;
        std::cout << "\nDigite o ID do livro para alterar: ";
        std::cin >> id;
        std::cin.ignore();

        // Procura livro pelo ID
        for (auto& itemPtr : item) {
            Livro* livro = dynamic_cast<Livro*>(itemPtr.get());
            if (livro != nullptr && livro->getId() == id) {
                alterarDadosLivro(*livro);
                return;
            }
        }

        std::cout << "Livro com ID " << id << " não encontrado!\n";
    }

    void alterarRevistaPorId() {
        if (item.empty()) {
            std::cout << "Nenhuma revista cadastrada!\n";
            return;
        }


        int id;
        std::cout << "\nDigite o ID da revista para alterar: ";
        std::cin >> id;
        std::cin.ignore();

        // Procura revista pelo ID
        for (auto& itemPtr : item) {
            Revista* revista = dynamic_cast<Revista*>(itemPtr.get());
            if (revista != nullptr && revista->getId() == id) {
                alterarDadosRevista(*revista);
                return;
            }
        }

        std::cout << "Revista com ID " << id << " não encontrado!\n";
    }

    void alterarDadosCliente(Cliente& cliente) {
        std::string novoNome, novoCpf;
        
        std::cout << "\nALTERANDO CLIENTE ID: " << cliente.getId() << "\n";
        std::cout << "Nome atual: " << cliente.getNome() << "\n";
        std::cout << "Novo nome: ";
        getline(std::cin, novoNome);
        
        std::cout << "CPF atual: " << cliente.getCpf() << "\n";
        std::cout << "Novo CPF: ";
        getline(std::cin, novoCpf);

        if (!novoNome.empty()) {
            cliente.setNome(novoNome);
        }
        if (!novoCpf.empty()) {
            cliente.setCpf(novoCpf);
        }

        std::cout << "Cliente alterado com sucesso!\n";
    }

    void alterarDadosLivro(Livro& livro) {
        std::string novoValor;
        
        std::cout << "\nALTERANDO LIVRO ID: " << livro.getId() << "\n";
        
        std::cout << "Título atual: " << livro.getNome() << "\n";
        std::cout << "Novo título: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            livro.setNome(novoValor);
        }

        std::cout << "Autor atual: " << livro.getAutor() << "\n";
        std::cout << "Novo autor: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            livro.setAutor(novoValor);
        }

        std::cout << "Editora atual: " << livro.getEditora() << "\n";
        std::cout << "Nova editora: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            livro.setEditora(novoValor);
        }

        std::cout << "Preço atual: " << livro.getPreco() << "\n";
        std::cout << "Novo Preço: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            livro.setPreco(novoValor);
        }

        std::cout << "Ano atual: " << livro.getAno() << "\n";
        std::cout << "Novo ano: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            livro.setAno(novoValor);
        }

        std::cout << "Tipo de capa atual: " << livro.getCapa() << "\n";
        std::cout << "Novo tipo de capa: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            livro.setCapa(novoValor);
        }

        std::cout << "Livro alterado com sucesso!\n";
    }

    void alterarDadosRevista(Revista& revista) {
        std::string novoValor;
        
        std::cout << "\nALTERANDO REVISTA ID: " << revista.getId() << "\n";
        
        std::cout << "Edição atual: " << revista.getEdicao() << "\n";
        std::cout << "Nova edição: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            revista.setEdicao(novoValor);
        }

        std::cout << "Editora atual: " << revista.getEditora() << "\n";
        std::cout << "Nova editora: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            revista.setEditora(novoValor);
        }

        std::cout << "Preço atual: " << revista.getPreco() << "\n";
        std::cout << "Novo Preço: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            revista.setPreco(novoValor);
        }

        std::cout << "Categoria atual: " << revista.getCategoria() << "\n";
        std::cout << "Nova categoria: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            revista.setCategoria(novoValor);
        }

        std::cout << "Mês atual: " << revista.getMes() << "\n";
        std::cout << "Novo mês: ";
        getline(std::cin, novoValor);
        if (!novoValor.empty()) {
            revista.setMes(novoValor);
        }
        std::cout << "Revista alterada com sucesso!\n";
    }
};
