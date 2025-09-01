#pragma once
#include <iostream>
#include <fstream> 
#include "Cliente.h"

class Item
{
    std::string editoraItem, precoItem, categoriaItem, disponibilidade;
    Cliente* dono;

public:
    Item(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem){
        this->editoraItem = _editoraItem;
        this->precoItem = _precoItem;
        this->categoriaItem = _categoriaItem;
        this->disponibilidade = "Disponivel";
        this->dono = nullptr;
    }
    
    std::string getEditora() const { return editoraItem; }
    void setEditora(std::string _editoraItem) { editoraItem = _editoraItem; }
    std::string getPreco() const { return precoItem; }
    void setPreco(std::string _precoItem) { precoItem = _precoItem; }
    std::string getCategoria() const { return categoriaItem; }
    void setCategoria(std::string _categoriaItem) { categoriaItem = _categoriaItem; }
    
    std::string getDisponibilidade() const { return disponibilidade; }
    void setDisponibilidade(std::string _disponibilidade) { disponibilidade = _disponibilidade; }
    
    void setDono(Cliente* _dono) { 
        dono = _dono; 
        if(dono != nullptr) {
            disponibilidade = "Vendido";
        } else {
            disponibilidade = "Disponivel";
        }
    }
    Cliente* getDono() const { return dono; }
    bool temDono() const { return dono != nullptr; }

    virtual void exibir() {
        std::cout << "Editora: " << editoraItem <<
        "\nPreco: " << precoItem <<
        "\nCategoria: " << categoriaItem <<
        "\nStatus: " << disponibilidade;
        
        if(temDono()) {
            std::cout << "\nDono: " << dono->getNome() << " (CPF: " << dono->getCpf() << ")";
        }
        std::cout << std::endl;
    }

    virtual std::string getTipo() const = 0;
    virtual void salvar(std::ofstream& out) const = 0;
    virtual std::string getNomeParaBusca() const = 0; 
    virtual int getId() const = 0;

    virtual ~Item() = default;
};