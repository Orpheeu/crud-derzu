#include <iostream>
#include "Sistema.hpp"

int main(){
    Sistema sistema;
    std::string opcao = "1";
    
    std::cout << "=== BEM-VINDO AO SISTEMA CRUD ===\n\n";
    std::cout << "[LOG] Sistema iniciado com sucesso\n";
    system("pause>null");
    
    while(opcao != "7") {
        system("cls");
        std::cout << "=== SISTEMA CRUD ===\n\n";
        std::cout << "[1] Inserir\n";
        std::cout << "[2] Listar todos\n";
        std::cout << "[3] Exibir um (pesquisar por nome)\n";
        std::cout << "[4] Alterar (pesquisar por nome)\n";
        std::cout << "[5] Remover (pesquisar por nome)\n";
        std::cout << "[6] Exibir Relatório\n";
        std::cout << "[7] Sair\n\n";
        std::cout << "Escolha uma opção: ";
        
        std::cin >> opcao;
        
        if(opcao == "1") {
            std::string aux;
            system("cls");
            std::cout << "=== INSERIR ===\n\n";
            std::cout << "[1] Cliente\n";
            std::cout << "[2] Livro\n";
            std::cout << "[3] Revista\n";
            std::cout << "Escolha: ";
            std::cin >> aux;
            
            if(aux == "1") {
                sistema.cadastrarCliente();
            } else if(aux == "2") {
                sistema.CadastrarLivro();
            } else if(aux == "3") {
                sistema.CadastrarRevista();
            }
        } else if(opcao == "2") {
            system("cls");
            sistema.ListarClientes();
            system("pause>null");
        } else if(opcao == "3") {
            std::string aux;
            system("cls");
            std::cout << "=== EXIBIR UM ===\n\n";
            std::cout << "[1] Cliente\n";
            std::cout << "[2] Livro/Revista\n";
            std::cout << "Escolha: ";
            std::cin >> aux;
            
            if(aux == "1") {
                sistema.ExibirCliente();
            } else if(aux == "2") {
                std::string nomeBusca;
                std::cout << "Digite o nome para buscar: ";
                std::cin.ignore();
                getline(std::cin, nomeBusca);
                sistema.pesquisarPorNome(nomeBusca);
                system("pause>null");
            }
        } else if(opcao == "4") {
            std::string aux;
            system("cls");
            std::cout << "=== ALTERAR ===\n\n";
            std::cout << "[1] Cliente\n";
            std::cout << "[2] Livro\n";
            std::cout << "[3] Revista\n";
            std::cout << "Escolha: ";
            std::cin >> aux;
            
            if(aux == "1") {
                sistema.AlterarClientePorNome();
            } else if(aux == "2") {
                sistema.AlterarLivroPorNome();
            } else if(aux == "3") {
                sistema.AlterarRevistaPorNome();
            }
            system("pause>null");
        } else if(opcao == "5") {
            std::string aux;
            system("cls");
            std::cout << "=== REMOVER ===\n\n";
            std::cout << "[1] Cliente\n";
            std::cout << "Escolha: ";
            std::cin >> aux;
            
            if(aux == "1") {
                sistema.RemoverClientePorNome();
            }
            system("pause>null");
        } else if(opcao == "6") {
            system("cls");
            std::cout << "=== RELATÓRIO DO SISTEMA ===\n\n";
            std::cout << "Total de clientes cadastrados: " << std::endl;
            std::cout << "Total de itens cadastrados: " << std::endl;
            std::cout << "\n[LOG] Relatório exibido com sucesso" << std::endl;
            system("pause>null");
        }
    }
    
    std::cout << "\n[LOG] Programa finalizado com sucesso\n";
    system("pause>null");
    
    return 0;
}