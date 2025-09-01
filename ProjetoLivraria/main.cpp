#include <iostream>
#include <string>
#include <limits>
#include "Sistema.h"
#include "Sistema.cpp"

void exibirMenu() {
    std::cout << "\n--- MENU LIVRARIA ---\n";
    std::cout << "1. Cadastrar Item (Livro/Revista)\n";
    std::cout << "2. Cadastrar Cliente\n";
    std::cout << "3. Listar Todos\n";
    std::cout << "4. Buscar Item (por nome/titulo/edicao)\n";
    std::cout << "5. Alterar Item\n";
    std::cout << "6. Remover Item\n";
    std::cout << "7. Exibir Relatorio\n";
    std::cout << "8. Sair\n";
    std::cout << "------------------------\n";
    std::cout << "Escolha uma opcao: ";
}

int main() {
    Sistema sistema;
    sistema.carregarDados(); 

    int opcao;

    do {
        exibirMenu();
        std::cin >> opcao;
        

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcao = 0; 
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }


        switch (opcao) {
            case 1:
                sistema.cadastrarItem();
                break;
            case 2:
                sistema.cadastrarCliente();
                break;
            case 3:
                sistema.listarTodos();
                break;
            case 4:
                sistema.buscarPorNome();
                break;
             case 5:
                sistema.alterarItem();
                break;
            case 6:
                sistema.removerItem();
                break;
            case 7:
                 sistema.gerarRelatorio();
                break;
            case 8:
                std::cout << "Saindo e salvando dados...\n";
                break;
            default:
                std::cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 8); 

    sistema.salvarDados();

    return 0;
}