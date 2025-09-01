#pragma once
#include <iostream>
#include <fstream>
#include "Item.h"

class Revista : public Item 
{
    std::string mesRevista, edicaoRevista;
    static int numRevistas;
    int idRevista = 0;

public:
    Revista(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem,
            std::string _mesRevista, std::string _edicaoRevista)
    : Item(_editoraItem, _precoItem, _categoriaItem) {
        this->idRevista = ++numRevistas;
        this->mesRevista = _mesRevista;
        this->edicaoRevista = _edicaoRevista;
    }
    
    // alterado
    Revista(int _id, std::string _editora, std::string _preco, std::string _categoria,
            std::string _mes, std::string _edicao)
    : Item(_editora, _preco, _categoria) {
        this->idRevista = _id;
        this->mesRevista = _mes;
        this->edicaoRevista = _edicao;
    }

    int getId() const override { return idRevista; }
    void setId(int _idRevista) { idRevista = _idRevista; }
    std::string getEdicao() const { return edicaoRevista; }
    void setEdicao(std::string _edicaoRevista) { edicaoRevista = _edicaoRevista; }
    std::string getMes() const { return mesRevista; }
    void setMes(const std::string& novoMes) { mesRevista = novoMes; }

    void exibir() override {
        std::cout << "--- REVISTA ---\n";
        std::cout << "ID: " << idRevista <<
        "\nEdição: " << edicaoRevista << 
        "\nMês de publicação: " << mesRevista <<
        "\nEditora: " << getEditora() <<
        "\nPreço: " << getPreco() << 
        "\nCategoria: " << getCategoria() << "\n\n";
    }

    
    // implementação dos métodos virtuais da classe Item
    std::string getTipo() const override { return "REVISTA"; }
    std::string getNomeParaBusca() const override { return getEdicao(); } 

    void salvar(std::ofstream& out) const override {
        out << getId() << ';' << getEditora() << ';' << getPreco() << ';' << getCategoria() << ';'
            << mesRevista << ';' << edicaoRevista << '\n';
    }
    
    static int getNumRevistas() { return numRevistas; }
    static void setNumRevistas(int num) { numRevistas = num; }
};

