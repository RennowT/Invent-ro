#pragma once

#include <string>

#include "enumOpcao.hpp"
#include "Inventario.hpp"

void exibirMenu();
void processarOpcao(Opcao opcao, Inventario* inventario);

void adicionarProduto(Inventario* inventario);
void adicionarProduto(Inventario* inventario);
void removerProduto(Inventario* inventario);
void atualizarQuantidade(Inventario* inventario);

template <typename T>
void entradaValida(const std::string& atributo, T& variavel);
void entradaValidaString(const std::string& atributo, std::string& variavel);
void entradaValidaInt(const std::string& atributo, int& variavel);