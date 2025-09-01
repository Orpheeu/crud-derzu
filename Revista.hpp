#pragma once
#include <iostream>
#include "Item.hpp"

class Revista : public Item 
{
    std::string mesRevista, edicaoRevista;
    static int  numRevistas;
    int idRevista = 0;

public:
    Revista(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem,
            std::string _mesRevista, std::string _edicaoRevista)
    :Item(_editoraItem, _precoItem, _categoriaItem){
        this->idRevista = ++numRevistas;
        this->mesRevista = _mesRevista;
        this->edicaoRevista = _edicaoRevista;
    }
    int getId() const {
        return idRevista;
    }
    void setId(int _idRevista) {
        idRevista = _idRevista;
    }
    //pega e coloca mês
    std::string getMes() {
        return mesRevista;
    }
    void setMes(std::string _mesRevista) {
        mesRevista = _mesRevista;
    }
    
    //pega e coloca 
    std::string getEdicao() {
        return edicaoRevista;
    }
    void setEdicao(std::string _edicaoRevista) {
        edicaoRevista = _edicaoRevista;
    }

    void exibirRevista() {
        std::cout << "ID: " << idRevista <<
        "\nNome: " << mesRevista << 
        "\nTipo de capa: " << edicaoRevista <<
        "\nEditora: " << getEditora() <<
        "\nPreço: " << getPreco() << 
        "\nCategoria: " << getCategoria() << "\n\n";
    }

    void exibir() override {
        exibirRevista();
    }
};
int Revista::numRevistas = 0;
