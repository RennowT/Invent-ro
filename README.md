# Projeto de Inventário de Produtos
Este projeto é um inventário de produtos que permite que o usuário adicione, remova e atualize produtos, bem como procure produtos existentes no inventário.

## Funcionalidades
<p>O programa oferece as seguintes funcionalidades:</p>
* Listar todos os produtos no inventário.</br>
* Procurar um produto no inventário por nome.</br>
* Adicionar um novo produto ao inventário.</br>
* Remover um produto do inventário.</br>
* Atualizar a quantidade de um produto no inventário.</br>
* Sair do programa.</br>

## Funcionamento do código
<p>O programa principal é implementado no arquivo main.cpp e utiliza as classes Produto, Inventario e a função Interface para gerenciar a lista de produtos.</p>

<p>O programa inicia com um loop que exibe o menu principal para o usuário e processa a opção selecionada pelo usuário. A opção selecionada é processada na função processarOpcao que chama a função correspondente de acordo com a opção selecionada.</p>

<p>As funções entradaValida, entradaValidaString e entradaValidaInt são utilizadas para garantir que o usuário insira apenas valores válidos para o programa. A função exibirMenu exibe as opções do menu.</p>

<p>As funções adicionais procurarProduto, adicionarProduto, removerProduto e atualizarQuantidade implementam as funcionalidades correspondentes do inventário.  </p>

## Como utilizar
<p>Clone este repositório em sua máquina local e abra-o em sua IDE favorita. Certifique-se de que os arquivos de cabeçalho .hpp estão na mesma pasta que o arquivo main.cpp. Compile e execute o programa em sua máquina local.</p>

<p>Ao executar o programa, o usuário pode interagir com o menu principal e selecionar as opções correspondentes para gerenciar a lista de produtos.</p>
