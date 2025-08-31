#pragma once 
#include <iostream>
#include <string>


class Cliente 
{
    std::string cpf, nomeCliente;
    static int numClientes;
    int IdCliente;
    
public:
    Cliente(std::string _nomeCliente, std::string _cpf) {
        this->IdCliente= ++numClientes;
        this->nomeCliente = _nomeCliente;
        this->cpf = _cpf;
    }
    int getId() const {
        return IdCliente;
    }
    void setId(int _IdCliente) {
        IdCliente = _IdCliente;
    }
    std::string getCpf() const {
        return cpf;
    }
    void setCpf(std::string _cpf) {
        cpf = _cpf;
    }
    std::string getNome() const {
        return nomeCliente;
    }
    void setNome(std::string _nomeCliente) {
        nomeCliente = _nomeCliente;
    }
    void exibir() const {
        std::cout <<
        "ID: " << IdCliente <<
        "\nNome: " << nomeCliente <<
        "\nCPF: " << cpf << std::endl;
    }
};

int Cliente::numClientes = 0;