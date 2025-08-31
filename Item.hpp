#pragma once
#include <iostream>

class Item
{
    std::string editoraItem, precoItem, categoriaItem;

public:
    Item(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem){
        this->editoraItem = _editoraItem;
        this->precoItem = _precoItem;
        this->categoriaItem = _categoriaItem;
    }
    
    //pega e coloca editora
    std::string getEditora() {
        return editoraItem;
    }
    void setEditora(std::string _editoraItem) {
        editoraItem = _editoraItem;
    }
    
    //pega e coloca preço
    std::string getPreco() {
        return precoItem;
    }
    void setPreco(std::string _precoItem) {
        precoItem = _precoItem;
    }

    //pega e coloca preço
    std::string getCategoria() {
        return categoriaItem;
    }
    void setCategoria(std::string _categoriaItem) {
        categoriaItem = _categoriaItem;
    }

    virtual void exibir() {
        std::cout << "Editora: " << editoraItem <<
        "Preço: " << precoItem <<
        "Categoria: " << categoriaItem;
    }

    virtual ~Item() = default;
};
