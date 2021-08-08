//Na fun��o main() iremos instanciar objetos
//desta forma ela precisa incluir as declara��es da classe Conta
#include "Conta.h"
#include <iostream>


int main()
{//Aqui come�a o escopo de main
    {
        //Criamos um objeto ContaCliente01 do tipo Conta
        //Est� alocado na  Stack
        Conta Cliente00;
        //como  esta forma o objeto seria criado com o construtor autom�tico
        //conhecido por construtor Padr�o ou Defult
        Conta ContaCliente01("Itau", 2222, 5555, "Marcos", 100000);
        //Ahora vai funcionar, pois temos os argumentos para o construtor


        //Criamos um objeto ContaCliente02 do tipo Conta
        //Est� alocado na  Stack
        Conta ContaCliente02;
        //Errp desaparece pois agora tem o construtor vazio, padr�o default
        //
        //Os objetos foram criados(instanciados) e colocados na mem�ria RAM
        //Abaixo o debug mostraestes objetos e os valores atuais dos atributos(das vari�veus)  deles

        std::cout << "Endere�o mem�ria Objeto ContaCliente01: " << &ContaCliente01 << "\n";
        ContaCliente01.GetEnderecoThis();

        std::cout << "Endere�o mem�ria Objeto ContaCliente02: " << &ContaCliente02 << "\n";
        ContaCliente02.GetEnderecoThis();


        ContaCliente01.SetBanco("BRADESCO");
        //Astring "BRADESCO" Foi eviada como argumento para fun��o SetrBanco
        ContaCliente01.SetAgencia(1234);
        ContaCliente01.SetNumConta(9999);
        ContaCliente01.SetTitular("Fulano");
        ContaCliente01.Depositar(14690);
        ContaCliente01.Sacar(1500);

        ContaCliente02.SetBanco("BANCO DO BRASIL");
        ContaCliente02.SetAgencia(5678);
        ContaCliente02.SetNumConta(1111);
        ContaCliente02.SetTitular("Beltrano");

        //o objeto ContaCliente02 ser� enviado como argumento para a fun��o transferir
        ContaCliente01.Transferir(ContaCliente02, 2000);
        ContaCliente02.Sacar(500);
        ContaCliente02.Sacar(5000);


    }
    // depois daqui ser� chamado o destrutor
    system("PAUSE");

    return 0;
} // aqui termina
//destrutor s� ser� chamado no fim do escopo!
