//precisamos incluir o arquivo .h relativo a classe Conta
//Para que este arquivo Conta.cpp possa "Enxergar" as
//declara��es da classe Conta.h
#include "Conta.h"
#include <iostream>
#include <string>

//Voc� pode usar o construtor padr�o para j�iniciar os atributos do objeto
//com algum valor padr�o e eviatar lixo de mem�ria
Conta::Conta()
{
    //aqui mais uma vez o this est� implicito
    //seria o mesmo que:
    this->Banco = " ";
    this->Agencia = 0;
    this->NumConta = 0;
    this->Titular = " ";
    this->Saldo = 0.0;
    std::cout << "\nDestrutpr Objeto Endereco: " << this << " executado!\n";

}

Conta::Conta(std::string Banco, int Agencia, int NumConta, std::string Titular, double Salario)
{
    this->Banco = Banco;
    this->Agencia = Agencia;
    this->NumConta = NumConta;
    this->Titular = Titular;
    this->Saldo = Saldo;
    std::cout << "\nDestrutpr Objeto Endereco: " << this << " executado!\n";

}

Conta::~Conta()
{
    std::cout << "\nDestrutpr Objeto Endereco: " << this << " executado!\n";
}

//Aqui o operador escopo:: est� indicando que a fun��o/
// M�todo sacar pertence a classe Conta e que este c�digo
// a seguir vai implementar a fun��o Sacar
bool Conta::Sacar(double Valor)
{
    //Se o valor do Saldo no Objeto for menor que o valor a ser sacado, ele n�o poderar sacar
    if(Saldo < Valor)
    {
        std::cout << "\nSaldo Insuficiente!" << "\n";
        std::cout << "Seu Saldo Atual: R$ " << ConsultarSaldo() << "\n";
        return false;
    }
    else
    {

        //Sen�o ele poder� sacar
        //Temos que diminuir o saldo
        Saldo = Saldo - Valor;
        std::cout << "\nSeu Saldo Ataual: R$ " << ConsultarSaldo() << "\n";
        return true;
    }
}

void Conta::Depositar(double Valor)
{
    Saldo += Valor; //o mesmo que Saldo = Saldo + Valor;
    std::cout << "\nDep�sito de R$ " << Valor << "\nEfetuafo com sucesso!\n";
}

// A fun��o recebe como argumnto para seus par�metros um Objeto do tipo Conta e um double.

//Aqui o para�metro Destino ir� receber este double
void Conta::Transferir(Conta &Destino, double Valor)
//isso � o mesmo que colocar Conta &Destino = ContaCliente02
//ou seja ser� uma refer�ncia para o objeto do tipo conta que neste caso � ContaCliente02
{
    if(Saldo < Valor)
    {
        std::cout << "\nSaldo Insuficiente\n";
    }
    else
    {
        //Aqui Destino estar� com o objeto passado para a fun��o
        //Logo vair chamar o m�todo Depositar desta objeto
        Destino.Depositar(Valor);
        //Depos de depositar voc� deve retirar este valor depoistado do saldo
        Saldo -= Valor;
        std::cout << "\n*********Dados***********\n";
        std::cout << "\nTitular: " << Destino.GetTitular() << "\n";
        std::cout << "Banco: " << Destino.GetBanco() << "\n";
        std::cout << "Agencia: " << Destino.GetAgencia() << "\n";
        std::cout << "Conta: " << Destino.GetNumConta() << "\n";
        std::cout << "Transferencia Realizada com Sucesso!\n";
        std::cout << "Seu Saldo Atual: R$ " << ConsultarSaldo() << "\n";
    }
}

double Conta::ConsultarSaldo()
{
    return Saldo;
}

std::string Conta::GetBanco()
{
    return Banco;
}
int Conta::GetAgencia()
{
    return Agencia;
}
int Conta::GetNumConta()
{

    return NumConta;
}
std::string Conta::GetTitular()
{
    //assim como aqui tamb�m est� implicito
    return this->Titular;
    //No geral n�o colocamos this
    //Somente quando for necess�rio!
}
void Conta::GetEnderecoThis()
{
    std::cout << "\nThis contem dentro o endereco: " << this << "\n";
}
//e foi recebida no par�metro Banco
void Conta::SetBanco(std::string Banco)
{
    //Como o compilador vai saber se Banco � vari�vel local ou a atributo da
    // classe Conta?
    //Se this � um ponteiro para chegar no apontado pelo ponteiro temos
    //*this , mas como this � um ponteiro para um objeto ele precisa usar a nota��o ponto,
    //para acessar os atributos deste objeto

    //Agora o compiloador sabe que Banco � a vari�vel local que recebeu o argumento strig
    //e que deve ser colocado no atributo Banco do objeto apontado por this
    //Contudo no graral usa-se a nota��o flecha

    this->Banco = Banco;
    //Aqui o atributo do objeto cujo o ende�o est� em this ir� receber o valor que est� em Banco
    //que � "BRADESCO"

}

void Conta::SetAgencia(int Agencia)
{
    this->Agencia = Agencia;

}

void Conta::SetNumConta(int NumConta)
{
    this->NumConta = NumConta;
}

//Neste caso precisampos do this pois o moe dos parametros s�o iguais

void Conta::SetTitular(std::string Titular)
{
    //aqui n�o precisaria pois os nome s�o diferentes
    //Mas como o compilado sabe que o Titular pertence ao objeto que est� executando a fun��o
    //Est� implicito neste caso o this
    this->Titular = Titular;
}
