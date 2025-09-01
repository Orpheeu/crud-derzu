#pragma once
#include <iostream>
#include <fstream>
#include "Item.h"

class Livro : public Item
{
    std::string capaLivro, autorLivro, anoLivro, nomeLivro;
    static int numLivros;
    int idLivro = 0;

public:
   
    Livro(std::string _editoraItem, std::string _precoItem, std::string _categoriaItem,
          std::string _capaLivro, std::string _autorLivro, std::string _anoLivro, std::string _nomeLivro)
    : Item(_editoraItem, _precoItem, _categoriaItem) {
        this->idLivro = ++numLivros;
        this->capaLivro = _capaLivro;
        this->autorLivro = _autorLivro;
        this->anoLivro = _anoLivro;
        this->nomeLivro = _nomeLivro;
    }

   
    std::string getCapa() const { return capaLivro; }
    void setCapa(const std::string& capa) { capaLivro = capa; }
    void setAutor(const std::string& autor) { autorLivro = autor; }
    std::string getAno() const { return anoLivro; }
    void setAno(const std::string& ano) { anoLivro = ano; }
    void setNome(const std::string& nome) { nomeLivro = nome; }

    Livro(int _id, std::string _editora, std::string _preco, std::string _categoria,
          std::string _capa, std::string _autor, std::string _ano, std::string _nome)
    : Item(_editora, _preco, _categoria) {
        this->idLivro = _id;
        this->capaLivro = _capa;
        this->autorLivro = _autor;
        this->anoLivro = _ano;
        this->nomeLivro = _nome;
    }

    int getId() const override { return idLivro; }
    void setId(int _idLivro) { idLivro = _idLivro; }
    std::string getNome() const { return nomeLivro; }
    std::string getAutor() const { return autorLivro; }
    
    void exibir() override {
        std::cout << "--- LIVRO ---\n";
        std::cout << "ID: " << idLivro << "\n";
        std::cout << "Título: " << nomeLivro << 
        "\nTipo de capa: " << capaLivro <<
        "\nAutor: " << autorLivro <<
        "\nAno de publicação: " << anoLivro << 
        "\nEditora: " << getEditora() <<
        "\nPreço: " << getPreco() << 
        "\nCategoria: " << getCategoria() << "\n\n";
    }
    // implementação dos métodos virtuais da classe Item
    std::string getTipo() const override { return "LIVRO"; }
    std::string getNomeParaBusca() const override { return nomeLivro; }

    void salvar(std::ofstream& out) const override {
        out << "ID: " << getId() << ';' << "Editora: " << getEditora() << ';' << "Preço: " << getPreco() << ';' << "Categoria: " << getCategoria() << ';'
            << "Tipo de capa: " << capaLivro << ';' << "Autor: " << autorLivro << ';' << "Ano: " << anoLivro << ';' << "Nome: " << nomeLivro << '\n';
    }

    static int getNumLivros() { return numLivros; }
    static void setNumLivros(int num) { numLivros = num; }
};
