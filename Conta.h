#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>

//Este � o arquivo  .h � onde existem apenas as declara��es dos atributos e m�todos da classe. Aqui n�o existem as defini��e, implementa��es das fun��es,
//pois isso ser� feito no arquivo .cpp. � a separa��o do O QU� (.h) do COMO (.cpp)

class Conta
{
//indica que o acesso a estes membro abaixo de private:
//s� ser� opermitido de dentro do c�digo da classe
private:
    std::string Banco;
    int Agencia;
    int NumConta;
    std::string Titular;
    double Saldo{ 0.0 };
//indica que os membros abaixo podem ser acessados pelos objetos da classe Conta fora do c�digo da classe Conta.
public:
    //Construtor com par�metro. Desta forma podemos criar objetos e j� enviar
    //argumetos para serem inivalizafos nos atributos(vari�veis) do objeto

    //O construtor padr�o ou default � simplismente um construtor vazio
    Conta();
    //Este construtor � criado autom�ticamente pelo compilador se VoC� n�o criar
    //UM CONSTRUTOR para sua classe.
    //Contudp como criamos abaixo um construto o compilador deixou de criar
    //o construtor e por isso n�o mais como objetos sem ser atrav�s deste
    // construtos abaixo
    //e a� precisaria enviar arqgumentos iniciais.


    Conta(std::string Banco, int Agencia, int NumConta, std::string Titular, double Saldo);
    ~Conta();
    bool Sacar(double Valor);
    void Depositar(double Valor);
    //Neste caso o par�metro Destino recebe apenas uma c�pia
    //do valor do objeto. Ele n�o tem como alterar o objeto
    //pois s� recebeu uma c�pia dele
    //Logo podemos usar o conceito de refer�ncia para passar a referencia do objeto
    //com isso Destino vai poder alterar este objeto pois ser� realizada uma passagem de argumentos
    // por Refer�ncia e n�o mais por valor
    void Transferir(Conta &Destino, double Valor);
    double ConsultarSaldo();
    std::string GetBanco();
    int GetAgencia();
    int GetNumConta();
    std::string GetTitular();
    void GetEnderecoThis();
    void SetBanco(std::string Banco);
    void SetAgencia(int Agencia);
    void SetTitular(std::string Titular);
    void SetNumConta(int NumConta);


};

#endif // CONTA_H
