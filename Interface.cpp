#include <iostream>
#include <limits>
#include <ios>

#include "Produto.hpp"
#include "Inventario.hpp"
#include "Interface.hpp"

using namespace std;

int main(){
    Inventario inventario;
    while (true) {
        exibirMenu();
        int opcao;
        if (cin >> opcao) {
            Opcao seletor = static_cast<Opcao>(opcao);
            processarOpcao(seletor, &inventario);
            if (seletor == Opcao::SAIR) {
                break;
            }
        } else {
            cerr << "Valor inserido invalido. Por favor, insira um valor numerico.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}

// função para entrada de dados válidos (numéricos e positivos)
template <typename T>
void entradaValida(const string& atributo, T& variavel) {
    while (true) {
        cout << atributo << ": ";
        if (cin >> variavel && variavel > 0) { // verifica se o valor inserido é numérico e positivo
            break;
        }
        cin.clear(); // limpa a flag de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta todos os caracteres inválidos do buffer
        cerr << "Valor inserido invalido. Por favor, insira um valor numerico positivo.\n";
    }
}

// função para entrada de dados válidos (strings)
void entradaValidaString(const string& atributo, string& variavel) {
    while (true) {
        std::cout << atributo << ": ";
        cin.ignore(); // ignora o caractere de nova linha deixado no buffer pelo cin anterior
        if (std::getline(std::cin, variavel) && !variavel.empty()) { // verifica se a string inserida não está vazia
            break;
        }
    }
}

// função para entrada de dados válidos (inteiros)
void entradaValidaInt(const string& atributo, int& variavel) {
    while (true) {
        std::cout << atributo << ": ";
        if (std::cin >> variavel) { // verifica se o valor inserido é numérico
            break;
        }
        std::cin.clear(); // limpa a flag de erro
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta todos os caracteres inválidos do buffer
        std::cerr << "Valor inserido invalido. Por favor, insira um valor numerico valido.\n";
    }
}

// função para exibir o menu principal do programa
void exibirMenu() {
    cout << "\n"
         << "[1] Lista de produtos\n"
         << "[2] Procurar produto\n"
         << "[3] Adicionar produto\n"
         << "[4] Remover produto\n"
         << "[5] Atualizar quantidade\n"
         << "[6] Sair\n\n";
}

// função para procurar um produto no inventário
void procurarProduto(Inventario* inventario) {
    string nome;
    entradaValidaString("Nome", nome); // solicita o nome do produto a ser procurado

    Produto* produto = inventario->buscarProdutoPorNome(nome); // busca o produto pelo nome no inventário
    if(produto){
        produto->imprimeDetalhes(); // se encontrado, exibe seus detalhes
    } else {
        cout << "Produto nao encontrado.\n"; // se não encontrado, exibe uma mensagem informando
    }
}

// Função para adicionar um novo produto ao inventário
void adicionarProduto(Inventario* inventario) {
    cout << "\n";
    int codigoDeBarras;
    string nome;
    int quantidade;
    double preco;

    // Solicita e valida a entrada do usuário para as informações do produto
    entradaValida("Codigo de Barras", codigoDeBarras);
    entradaValidaString("Nome", nome);
    entradaValida("Quantidade", quantidade);
    entradaValida("Preco", preco);

    // Cria um novo produto com as informações fornecidas pelo usuário
    Produto produto;
    produto.setProduto(codigoDeBarras, nome, quantidade, preco);

    // Adiciona o produto ao inventário
    inventario->adicionaProduto(produto);
}

// Função para remover um produto do inventário
void removerProduto(Inventario* inventario) {
    string nome;

    // Solicita e valida a entrada do usuário para o nome do produto a ser removido
    entradaValidaString("Nome", nome);

    // Busca o produto pelo nome no inventário
    Produto* produto = inventario->buscarProdutoPorNome(nome);

    if(produto){
        // Remove o produto do inventário e exibe uma mensagem de sucesso
        inventario->removerProduto(*produto);
        cout << "Produto removido com sucesso.\n";
    } else {
        // Exibe uma mensagem de erro caso o produto não seja encontrado
        cout << "Produto nao encontrado.\n";
    }
}

// Função para atualizar a quantidade de um produto no inventário
void atualizarQuantidade(Inventario* inventario) {
    string nomeProduto;

    // Solicita e valida a entrada do usuário para o nome do produto a ter sua quantidade atualizada
    entradaValidaString("Nome do Produto", nomeProduto);
    if (inventario->buscarProdutoPorNome(nomeProduto) == nullptr) {
        cout << "Produto nao encontrado.\n";
        return;
    }

    // Busca o produto pelo nome no inventário
    Produto* produto = inventario->buscarProdutoPorNome(nomeProduto);
    
    int quantidade;

    // Solicita e valida a entrada do usuário para a quantidade a ser adicionada ou removida
    do {
        entradaValidaInt("Quantidade (positiva para adicionar, negativa para remover)", quantidade);
    } while (quantidade + produto->getQuantidade() < 0);
    
    // Atualiza a quantidade do produto no inventário e exibe uma mensagem de sucesso
    produto->atualizarQuantidade(quantidade);
    
    cout << "Quantidade atualizada com sucesso." << endl;
}

void processarOpcao(Opcao opcao, Inventario* inventario) {
    switch (opcao) {
        // Caso a opção escolhida seja "LISTAR_PRODUTOS", chama o método "listaDeProdutos" do objeto "inventario"
        case Opcao::LISTAR_PRODUTOS:
            inventario->listaDeProdutos();
            break;

        // Caso a opção escolhida seja "PROCURAR_PRODUTO", chama a função "procurarProduto" e passa o objeto "inventario" como argumento
        case Opcao::PROCURAR_PRODUTO:
            procurarProduto(inventario);
            break;
        
        // Caso a opção escolhida seja "ADICIONAR_PRODUTO", chama a função "adicionarProduto" e passa o objeto "inventario" como argumento
        case Opcao::ADICIONAR_PRODUTO:
            adicionarProduto(inventario); 
            break;

        // Caso a opção escolhida seja "REMOVER_PRODUTO", chama a função "removerProduto" e passa o objeto "inventario" como argumento
        case Opcao::REMOVER_PRODUTO:
            removerProduto(inventario);
            break;

        // Caso a opção escolhida seja "ATUALIZAR_QUANTIDADE", chama a função "atualizarQuantidade" e passa o objeto "inventario" como argumento
        case Opcao::ATUALIZAR_QUANTIDADE:
            atualizarQuantidade(inventario);
            break;

        // Caso a opção escolhida seja "SAIR", exibe a mensagem "Saindo..."
        case Opcao::SAIR:
            cout << "Saindo...\n";
            break;

        // Se a opção escolhida não for reconhecida, exibe uma mensagem de erro
        default:
            cerr << "Opcao invalida\n";
            break;
    }
}