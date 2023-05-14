#include <iostream>
#include <algorithm>

#include "Inventario.hpp"

Inventario::Inventario() {} // Construtor padrão

// Lista todos os produtos do inventário
void Inventario::listaDeProdutos() const {
    if (lista.empty()) {
        std::cout << "Inventario vazio.\n";
        return;
    }

    for (const auto& produto : lista) {
        produto.imprimeDetalhes();
    }
}

// Busca um produto por nome no inventário
Produto* Inventario::buscarProdutoPorNome(const std::string& nomeProduto) {
    for (auto& produto : lista) {
        if (produto.getNome() == nomeProduto) {
            return &produto;
        }
    }
    return nullptr;
}

// Adiciona um produto ao inventário
void Inventario::adicionaProduto(const Produto& novoProduto) {
    if (produtoJaAdicionado(novoProduto)) {
        std::cout << "Produto ja adicionado.\n";
        return;
    }

    lista.push_back(novoProduto);
    std::cout << "Produto adicionado.\n";
}

// Verifica se um produto já foi adicionado ao inventário
bool Inventario::produtoJaAdicionado(const Produto& novoProduto) const {
    for (const auto& produto : lista) {
        if (produto.getCodigoDeBarras() == novoProduto.getCodigoDeBarras()) {
            return true;
        }
    }
    return false;
}

// Remove um produto do inventário
void Inventario::removerProduto(const Produto& produtoARemover) {
    auto it = std::find(lista.begin(), lista.end(), produtoARemover);
    if (it != lista.end()) {
        lista.erase(it);
    }
}
