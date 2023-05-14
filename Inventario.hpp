#pragma once

#include <vector>

#include "Produto.hpp"

class Inventario
{
private:
    std::vector<Produto> lista;

public:
    // Construtor padrão
    Inventario();

    // Lista todos os produtos do inventário
    void listaDeProdutos() const ;
    // Busca um produto por nome no inventário
    Produto* buscarProdutoPorNome(const std::string& nomeProduto);
    // Adiciona um produto ao inventário
    void adicionaProduto(const Produto& novoProduto);
    // Verifica se um produto já foi adicionado ao inventário
    bool produtoJaAdicionado(const Produto& novoProduto) const;
    // Remove um produto do inventário
    void removerProduto(const Produto& produtoARemover);
};


