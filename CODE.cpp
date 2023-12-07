#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Jogo { // estrutura de jogo
private:
    int id_jogo;
    string nome;
    double preco;

public:
    Jogo(int _id, string _nome, double _preco) : id_jogo(_id), nome(_nome), preco(_preco) {}

    int getId() const { return id_jogo; } // mostra id do jogp
    string getNome() const { return nome; } // mostra o nome do jogo
    double getPreco() const { return preco; } // mostra o preço do jogo
};

class Conta {  //estrutura de conta
private:
    string nome;
    string senha;
    double saldo;

public:
    Conta(string _nome, string _senha) : nome(_nome), senha(_senha), saldo(0.0) {}

    string getNome() const { return nome; } //função para mostrar nome

    bool validarSenha(const string& _senha) const { //função para validar senha digitada
      return senha == _senha;
    }

    void depositar(double valor) { // função para depositar
        saldo += valor;
        cout << "Valor depositado com sucesso!" << endl;
    }

    double getSaldo() const { return saldo; } //Mostrar saldo

    void debitar(double valor) { // função para debitar na hora de comprar o jogo
        saldo -= valor;
    }
};

void cadastrarConta(vector<Conta>& contas) { //acessa o vetor conta e define como contas
    string nome, senha;
    cout << "Criar uma nova conta:" << endl;
    cout << "Nome de usuario: ";
    cin >> nome;
    cout << "Senha: ";
    cin >> senha;

    contas.push_back(Conta(nome, senha)); // push_back puxa para a ultima posicao do vetor
    cout << "Conta criada com sucesso!" << endl;
}

Conta* fazerLogin(vector<Conta>& contas) { // acessa o vetor conta e define como contas
    string nome, senha;
    cout << "Fazer login:" << endl;
    cout << "Nome de usuario: ";
    cin >> nome;
    cout << "Senha: ";
    cin >> senha;

    for (auto& conta : contas) {
        if (conta.getNome() == nome && conta.validarSenha(senha)) { 
            return &conta; // Retorna o endereço da conta encontrada
        }
    }
    cout << "Nome de usuario ou senha incorretos." << endl;
    return nullptr; // Se a conta não for encontrada
}


void mostrarJogosDisponiveis(const vector<Jogo>& jogosDisponiveis) {// acessa o vetor jogo e define como jogosDisponiveis
    cout << "\nJogos Disponiveis:" << endl;
    for (const auto& jogo : jogosDisponiveis) {
        cout << "ID: " << jogo.getId() << " - Nome: " << jogo.getNome() << " - Preco: R$" << jogo.getPreco() << endl; // usa os gets la encimas
    }
}

void depositar(Conta* conta) { // ta pegando o ponteiro da conta passada
    double valor;
    cout << "Digite o valor a ser depositado: R$";
    cin >> valor;

    conta->depositar(valor);
}

void comprar(Conta* conta, const vector<Jogo>& jogosDisponiveis) { //pega o ponteiro da conta passada e passa o vetor de jogo como jogosdisponiveis
    int idJogo;
    cout << "Digite o ID do jogo que deseja comprar: ";
    cin >> idJogo;

    for (auto& jogo : jogosDisponiveis) {
        if (jogo.getId() == idJogo) {
            if (conta->getSaldo() >= jogo.getPreco()) {
                conta->debitar(jogo.getPreco());
                cout << "Produto comprado com sucesso!" << endl;
                cout << "Jogo comprado: " << jogo.getNome() << endl;
                cout << "Saldo restante: R$" << conta->getSaldo() << endl;
                return;
            } else {
                cout << "Saldo insuficiente para comprar o produto." << endl;
                return;
            }
        }
    }
    cout << "Jogo não encontrado." << endl;
}

void mostrarSaldo(Conta* conta) { //mostra o saldo
    cout << "Seu saldo atual é: R$" << conta->getSaldo() << endl;
}


int main() {
    vector<Conta> contas;
    vector<Jogo> jogosDisponiveis = {
        Jogo(1, "The Witcher 3", 199.99),
        Jogo(2, "Cyberpunk 2077", 207.70),
        Jogo(3, "Assassin's Creed Valhalla", 299.99)
    };

    bool executando = true;
    Conta* contaLogada = nullptr; // define o ponteiro como null

    while (executando) {
        cout << "\n1. Criar conta\n2. Fazer login\n3. Depositar\n4. Comprar\n5. Mostrar Jogos Disponiveis\n6. Mostrar Saldo\n7. Sair\n" << endl; // menu
        int opcao;
        cout << "Digite a opcao desejada: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarConta(contas); // chama o cadastrarconta e passa o contas
                break;
            case 2:
                contaLogada = fazerLogin(contas); // passa para conta logada o return da função fazerlogin
                if (contaLogada != nullptr) {
                    cout << "Login bem-sucedido!" << endl;
                } else {
                    cout << "Nome de usuario ou senha incorretos." << endl;
                }
                break;
              case 3:        
                if (contaLogada != nullptr) { //passa o ponteiro nulo
                    depositar(contaLogada); // chama a função depositar
                } else {
                    cout << "Faça login primeiro." << endl;
                }
                break;
            case 4:
                if (contaLogada != nullptr) { //passa o ponteiro nulo
                    comprar(contaLogada, jogosDisponiveis); // chamada de função
                } else {
                    cout << "Faça login primeiro." << endl;
                }
                break;
            case 5:
                mostrarJogosDisponiveis(jogosDisponiveis); //mostra jogos disponiveis
                break;
            case 6:
                if (contaLogada != nullptr) {
                  mostrarSaldo(contaLogada);//mostrar saldo e passa a conta logada
                } else {
                  cout << "Faça login primeiro." << endl;
                }
                break;
            case 7:
                executando = false;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    }

    return 0;
}
