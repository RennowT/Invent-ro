#include <iostream>

#include "Produto.hpp"

// Construtor padrão
Produto::Produto(): codigoDeBarras(0), quantidade(0), preco(0.0) {}

// Destrutor padrão
Produto::~Produto() {}

// Sobrecarga do operador ==
bool Produto::operator==(const Produto& other) const {
    return (this->codigoDeBarras == other.codigoDeBarras) && 
           (this->nome == other.nome) &&
           (this->quantidade == other.quantidade) &&
           (this->preco == other.preco);
}

// Getters e setters para cada atributo da classe
int Produto::getCodigoDeBarras() const { return codigoDeBarras; }
void Produto::setCodigoDeBarras(int codigo) { this->codigoDeBarras = codigoDeBarras; }

std::string Produto::getNome() const { return nome; }
void Produto::setNome(std::string nome) { this->nome = nome; }

int Produto::getQuantidade() const { return quantidade; }
void Produto::setQuantidade(int quantidade) { this->quantidade = quantidade; }

double Produto::getPreco() const { return preco; }
void Produto::setPreco(double preco) { this->preco = preco; }

// Método responsável por atribuir valores para os atributos de um objeto Produto.
void Produto::setProduto(int codigoDeBarras, const std::string& nome, int quantidade, double preco) {
    this->codigoDeBarras = codigoDeBarras;
    this->nome = nome;
    this->quantidade = quantidade;
    this->preco = preco;
}

// Método para imprimir os detalhes do produto na tela
void Produto::imprimeDetalhes() const{
    std::cout << "\n"
              << "Codigo de Barras: " << getCodigoDeBarras() << "\n"
              << "Nome: " << getNome() << "\n"
              << "Quantidade: " << getQuantidade() << "\n"
              << "Preco: " << getPreco() << "\n";
}

// Método para atualizar a quantidade de produtos no estoque
void Produto::atualizarQuantidade(int quantidadAdicional){
    quantidade += quantidadAdicional;
}