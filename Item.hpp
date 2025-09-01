#pragma once
#include <iostream>
#include "Cliente.hpp"

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

    void setDono(Cliente* _dono) {
        dono = _dono; 
    }
    Cliente* getDono() const { 
        return dono; 
    }
    bool temDono() const { 
        return dono != nullptr; 
    }

    virtual void exibir() {
        std::cout << "Editora: " << editoraItem <<
        "Preço: " << precoItem <<
        "Categoria: " << categoriaItem;
        
        if (temDono()) {
            std::cout << "Dono: [ID " << dono->getId() << "] " << dono->getNome() << "\n";
        } else {
            std::cout << "Item disponível (sem dono)\n";
        }
    }

    virtual ~Item() = default;
};
