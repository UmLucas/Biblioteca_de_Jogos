# Documentação do Código

## Introdução

Este código implementa um sistema simples de compra de jogos, onde os usuários podem criar contas, fazer login, depositar saldo, comprar jogos, visualizar jogos disponíveis, visualizar o saldo e sair do programa. O programa é desenvolvido em C++ e utiliza classes para representar jogos e contas de usuários.

## Diagrama de Classes

```plaintext
+---------------------+     +---------------------+
|        Jogo         |     |        Conta        |
+---------------------+     +---------------------+
| - int id_jogo       |     | - string nome       |
| - string nome       |     | - string senha      |
| - double preco      |     | - double saldo      |
| + getId() const     |     | + getNome() const   |
| + getNome() const   |     | + validarSenha(...) |
| + getPreco() const  |     | + depositar(...)    |
+---------------------+     | + getSaldo() const  |
                            | + debitar(...)      |
                            +---------------------+
```

## Descrição dos Objetos e Métodos

### Classe `Jogo`

Representa um jogo disponível para compra.

#### Atributos:
- `int id_jogo`: Identificador único do jogo.
- `string nome`: Nome do jogo.
- `double preco`: Preço do jogo.

#### Métodos Públicos:
- `int getId() const`: Retorna o identificador do jogo.
- `string getNome() const`: Retorna o nome do jogo.
- `double getPreco() const`: Retorna o preço do jogo.

### Classe `Conta`

Representa a conta de um usuário no sistema.

#### Atributos:
- `string nome`: Nome do usuário.
- `string senha`: Senha do usuário.
- `double saldo`: Saldo disponível na conta.

#### Métodos Públicos:
- `string getNome() const`: Retorna o nome do usuário.
- `bool validarSenha(const string& _senha) const`: Valida a senha do usuário.
- `void depositar(double valor)`: Adiciona saldo à conta.
- `double getSaldo() const`: Retorna o saldo disponível na conta.
- `void debitar(double valor)`: Debita um valor do saldo da conta.

### Função `cadastrarConta(vector<Conta>& contas)`

Solicita informações do usuário para criar uma nova conta e a adiciona ao vetor de contas.

### Função `fazerLogin(vector<Conta>& contas)`

Solicita informações do usuário para realizar o login e retorna o endereço da conta logada ou `nullptr` se o login falhar.

### Função `mostrarJogosDisponiveis(const vector<Jogo>& jogosDisponiveis)`

Exibe no console a lista de jogos disponíveis.

### Função `depositar(Conta* conta)`

Solicita o valor a ser depositado e realiza o depósito na conta fornecida.

### Função `comprar(Conta* conta, const vector<Jogo>& jogosDisponiveis)`

Permite que o usuário compre um jogo disponível, debitando o valor do saldo.

### Função `mostrarSaldo(Conta* conta)`

Exibe no console o saldo atual da conta.

### Função `main()`

Inicia o programa, oferecendo opções ao usuário para criar conta, fazer login, depositar, comprar jogos, visualizar jogos disponíveis, visualizar o saldo e sair do programa.
