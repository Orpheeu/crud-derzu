#pragma once
#include <iostream>
#include <fstream> 
#include "Cliente.h"

class Item
{
    std::string editoraItem, precoItem, categoriaItem;
    Cliente* dono;

public:
    Item(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem){
        this->editoraItem = _editoraItem;
        this->precoItem = _precoItem;
        this->categoriaItem = _categoriaItem;
        this->dono = nullptr;
    }
    
    std::string getEditora() const { return editoraItem; } // adicionado const
    void setEditora(std::string _editoraItem) { editoraItem = _editoraItem; }
    std::string getPreco() const { return precoItem; } // adicionado const
    void setPreco(std::string _precoItem) { precoItem = _precoItem; }
    std::string getCategoria() const { return categoriaItem; } // adicionado const
    void setCategoria(std::string _categoriaItem) { categoriaItem = _categoriaItem; }

    virtual void exibir() {
        std::cout << "Editora: " << editoraItem <<
        "\nPreço: " << precoItem <<
        "\nCategoria: " << categoriaItem << std::endl;
    }

   
    virtual std::string getTipo() const = 0;
    virtual void salvar(std::ofstream& out) const = 0;
    virtual std::string getNomeParaBusca() const = 0; 
    virtual int getId() const = 0;

    virtual ~Item() = default;
};