#include <iostream>

class Foo {
    public:
       Foo() {
           _bar = &aux;
       }
       int bar() { return *_bar; }
     private:
         int * _bar;
         int aux = 1;
};

Foo foo;

int main(int argc, char *argv[])
{
    std::cout << "Foo: " << foo.bar() << " bar." << std::endl;
    return 0;

    //apresenta a mensagem "Falha de segmentação (imagem do núcleo gravada)"
    //motivo: foi atribuído um valor inteiro para um ponteiro, porém ele deveria receber o endereço de memória de uma variável;
    //solução: implementada a variável "aux" do tipo inteiro que o ponteiro usará para apresentar o valor "1"; 

}