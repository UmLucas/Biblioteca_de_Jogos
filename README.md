# Documentação do Código

## Introdução

Este código implementa um sistema simples de biblioteca de jogos, onde os usuários podem visualizar jogos disponíveis, fazer login, cadastrar novos usuários, comprar jogos, depositar saldo e visualizar a lista de jogos comprados. O programa é desenvolvido em C++ e utiliza ANSI escape codes para adicionar cores ao texto no terminal.

## Diagrama de Classes

<!--
plaintext
+-----------------+          +------------------+
|   Jogo          |          |    Usuario       |
+-----------------+          +------------------+
| int id_jogo     |          | string nome      |
| string nome     |          | string senha     |
| double preco    |          | vector<Jogo> jogosComprados |
+-----------------+          | double saldo     |
                             +------------------+
                             |                  |
                             +------------------+
                             |
                             |         +------------------------+
                             +-------->| BibliotecaJogos        |
                             |         +------------------------+
                             |         | vector<Jogo> jogosDisponiveis |
                             |         | Usuario usuarioLogado          |
                             |         +-----------------------------+
                             |         | void mensagemColorida(...)    |
                             |         | void listarJogosDisponiveis() |
                             |         | void fazerLogin(...)           |
                             |         | void cadastrarUsuario(...)     |
                             |         | void comprarJogo(...)          |
                             |         | void listarJogosComprados()    |
                             |         | void depositarSaldo(...)      |
                             +-------->|                             |
                                       +-----------------------------+


## Descrição dos Objetos e Métodos

### Classe Jogo

Representa um jogo disponível na biblioteca.

#### Atributos:
- int id_jogo: Identificador único do jogo.
- string nome: Nome do jogo.
- double preco: Preço do jogo.

### Classe Usuario

Representa um usuário no sistema.

#### Atributos:
- string nome: Nome do usuário.
- string senha: Senha do usuário.
- vector<Jogo> jogosComprados: Lista dos jogos comprados pelo usuário.
- double saldo: Saldo disponível na conta do usuário.

### Classe BibliotecaJogos

Representa a biblioteca de jogos e controla as operações disponíveis.

#### Atributos:
- vector<Jogo> jogosDisponiveis: Lista dos jogos disponíveis na biblioteca.
- Usuario usuarioLogado: Usuário que está atualmente logado no sistema.

#### Métodos Públicos:
- void mensagemColorida(const string &mensagem, const string &cor) const: Exibe uma mensagem colorida no terminal.
- void listarJogosDisponiveis() const: Lista os jogos disponíveis.
- void fazerLogin(const string &usuario, const string &senha): Realiza o login de um usuário.
- void cadastrarUsuario(const string &usuario, const string &senha): Cadastra um novo usuário.
- void comprarJogo(const int &idjogo): Permite que o usuário compre um jogo.
- void listarJogosComprados() const: Lista os jogos comprados pelo usuário.
- void depositarSaldo(double valor): Adiciona saldo à conta do usuário.

### Função imprimirMoldura(int largura)

Imprime uma moldura no terminal com a largura especificada.

### Função menuComprarJogo(BibliotecaJogos &biblioteca, string &usuario)

Implementa o menu de compras, permitindo que o usuário compre jogos, liste jogos comprados e deposite saldo.

### Função MenuLogin()

Implementa o menu principal, permitindo que o usuário liste jogos, faça login, crie uma conta ou saia do programa.

### Função main()

Inicia o programa chamando a função MenuLogin().
