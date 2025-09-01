#pragma once
#include <iostream>
#include "Item.hpp"

class Livro : public Item
{
    std::string capaLivro, autorLivro, anoLivro, nomeLivro;
    static int numLivros;
    int idLivro = 0;


public:
    Livro(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem,
            std::string _capaLivro, std::string _autorLivro, std::string _anoLivro, std::string _nomeLivro)
    :Item(_editoraItem, _precoItem, _categoriaItem){
        this->idLivro = ++numLivros;
        this->capaLivro = _capaLivro;
        this->autorLivro = _autorLivro;
        this->anoLivro = _anoLivro;
        this->nomeLivro = _nomeLivro;
    }
    int getId() const {
        return idLivro;
    }
    void setId(int _idLivro) {
        idLivro = _idLivro;
    }
    //pega e coloca capa
    std::string getCapa() {
        return capaLivro;
    }
    void setCapa(std::string _capaLivro) {
        capaLivro = _capaLivro;
    }
    
    //pega e coloca autor
    std::string getAutor() {
        return autorLivro;
    }
    void setAutor(std::string _autorLivro) {
        autorLivro = _autorLivro;
    }
    
    //pega e coloca ano
    std::string getAno() {
        return anoLivro;
    }
    void setAno(std::string _anoLivro) {
        anoLivro = _anoLivro;
    }

    //pega e coloca nome
    std::string getNome() {
        return nomeLivro;
    }
    void setNome(std::string _nomeLivro) {
        nomeLivro = _nomeLivro;
    }

    void exibirLivro() {
        std::cout << "Nome: " << nomeLivro << 
        "\nTipo de capa: " << capaLivro <<
        "\nAutor: " << autorLivro <<
        "\nAno de publicação: " << anoLivro << 
        "\nEditora: " << getEditora() <<
        "\nPreço: " << getPreco() << 
        "\nCategoria: " << getCategoria() << "\n\n";
    }

    void exibir() override {
        exibirLivro();
    }

};

int Livro::numLivros = 0;
