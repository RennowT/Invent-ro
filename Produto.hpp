#pragma once

#include <string>

class Produto
{
private:
    int codigoDeBarras;
    std::string nome;
    int quantidade;
    double preco;

public:
    Produto(); // Construtor padrão
    ~Produto(); // Destrutor padrão

    // Sobrecarga do operador ==
    bool operator==(const Produto& other) const;

    // Getters e setters para cada atributo da classe
    int getCodigoDeBarras() const;
    void setCodigoDeBarras(int codigoDeBarras);
    std::string getNome() const;
    void setNome(std::string nome);
    int getQuantidade() const;
    void setQuantidade(int quantidade);
    double getPreco() const;
    void setPreco(double preco);
    
    // Método responsável por atribuir valores para os atributos de um objeto Produto.
    void setProduto(int codigoDeBarras, const std::string& nome, int quantidade, double preco);
    // Método para imprimir os detalhes do produto na tela
    void imprimeDetalhes() const;
    // Método para atualizar a quantidade de produtos no estoque
    void atualizarQuantidade(int quantidadAdicional);
};

