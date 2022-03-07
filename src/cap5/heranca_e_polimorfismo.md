Herança e Polimorfismo
===

Chama-se _herança_ o mecanismo que permite a uma classe herdar membros (métodos
e atributos) de outra classe. Tal mecanismo permite reaproveitar código comum entre classes filhas. Porém, uma vantagem
ainda mais importante é a possibilidade de criar _interfaces_.

A sintaxe para a criação de uma classe base é mostrada no exemplo abaixo. A classe `ClasseFilha` estende a classe
`ClasseMae`. Em outras palavras, a classe `ClasseFilha` é formada por todos os seus atributos e métodos mais todos
os da classe `ClasseMae`.

```c++
#include <iostream>
#include <string>

class ClasseMae {
public:
    ClasseMae(int atributo_1)
        : atributo_1(atributo_1)
        , atributo_privado('z')
    {}

    void metodo_1()
    {
        std::cout << "O metodo 1 foi invocado!\n";
    }

protected:
    int atributo_1;
private:
    char atributo_privado;
};

class ClasseFilha : public ClasseMae {
public:
    ClasseFilha(int atributo_1, double atributo_2)
        : ClasseMae(atributo_1)
        , atributo_2(atributo_2)
    {}

    void metodo_2()
    {
        std::cout << "O metodo 2 foi invocado!";
    }

private:
    double atributo_2;
};

int main()
{
    ClasseMae objeto_1{1};
    objeto_1.metodo_1();

    ClasseFilha objeto_2{1, 2.2};
    objeto_2.metodo_1();
    objeto_2.metodo_2();

    return 0;
}
```

O exemplo é extremamente simples, e serve apenas para ilustrar a sintaxe de herança em C++ e iniciar um contato do leitor
sobre esses aspectos da linguagem. Note que ambas as instâncias `objeto_1` e `objeto_2` podem invocar o método
`metodo_1`, e apenas a instância da classe `ClasseFilha` pode invocar o método `metodo_2`. Isso ocorre porque `objeto_2`
é uma instância da classe `ClasseFilha`, que possui tanto os métodos e atributos de `ClasseMae` quanto àqueles
referentes à própria classe `ClasseFilha`.

O construtor da classe `ClasseFilha` precisa invocar o construtor da classe mãe (`ClasseMae`) de forma a construir
corretamente a mesma. A sintaxe para a construção da classe mãe é mostrada no exemplo acima. A classe `ClasseFilha` possui
um construtor que contém uma lista de inicialização onde o construtor da classe mãe é invocado. Caso a
classe mãe não tivesse um construtor definido (se estivesse sendo utilizado o construtor padrão), não seria
necessário invoca-lo explicitamente como no exemplo acima.

Além disso, é possível reescrever um método da classe mãe, de forma a alterar seu funcionamento, na classe filha.
Considere o exemplo abaixo. A classe `ClasseMae` possui agora um método publico _virtual_ chamado `metodo_virtual`, e a
classe `ClasseFilha` possui um método de mesmo nome com o modificador `override`. Esse modificador é opcional e está
disponível apenas em versões mais atuais da linguagem. É uma boa prática de programação adiciona-lo, a fim de manter uma
consistência entre classe base e classe filha.

```c++
#include <iostream>

class ClasseMae {
public:
    virtual void metodo_virtual()
    {
        std::cout << "Comportamento da classe mae.\n";
    }
};

class ClasseFilha : public ClasseMae {
public:
    void metodo_virtual() override
    {
        std::cout << "Outro comportamento!!\n";
    }
};

void executar_algoritmo(ClasseMae& objeto)
{
    // ... Imagine um algoritmo aqui ...
    objeto.metodo_virtual();
}

int main()
{
    ClasseMae objeto_1;
    executar_algoritmo(objeto_1);

    ClasseFilha objeto_2;
    executar_algoritmo(objeto_2);

    return 0;
}
```

Note que a função `executar_algoritmo` recebe como parâmetro uma referência para um objeto da classe `ClasseMae`. Ainda assim,
na função `main`, uma instância da classe `ClasseFilha` é enviada como parâmetro. Sempre é possível utilizar instâncias de
classes filhas como parâmetros para referências ou ponteiros para sua classe mãe. O método `executar_algoritmo` vai se
comportar de forma diferente, dependendo do tipo de objeto sendo recebido como parâmetro. Sendo mais específico, para o
caso do exemplo acima a primeira chamada de `executar_algoritmo(objeto_1)` resultará no texto escrito
`Comportamento da classe mae.`,  enquanto a segunda chamada `executar_algoritmo(objeto_2)` resultará no texto
`Outro comportamento!!`. Essa característica se chama _Polimorfismo_.

Um aspecto muito importante de se ter em mente é que no caso da ausência do `virtual` na classe mãe, o polimorfismo do
exemplo não acontecerá conforme esperado. Basicamente a ausência de `virtual` ignora a funcionalidade que possibilita a
invocação correta do método da classe filha, quando a mesma é passada por parâmetro como uma classe base, como no
exemplo. Em outras palavras, a remoção de `virtual` (e por consequência a remoção de `override`) no exemplo resultaria
que __as duas__ chamadas retornarem o texto `Comportamento da classe mae.`.

Uma classe pode possuir métodos virtuais sem implementação, como no próximo exemplo. Classes com pelo menos um método
virtual sem implementação não podem ser instanciadas. Ou seja, não é possível construir um objeto cujo tipo seja uma
classe com métodos sem implementação. Classes que contenham todos os métodos virtuais e sem implementação são chamadas
_interfaces_. Classes que contenham pelo menos um método com implementação são chamadas _abstratas_. Portanto, no
exemplo abaixo a classe `ClasseInterface` é uma interface.

```c++
#include <iostream>

class ClasseInterface {
public:
    virtual void metodo_a() = 0;
};

class ClasseConcreta_A : public ClasseInterface {
public:
    void metodo_a() override {
        std::cout << "Metodo A invocado pela classe concreta A!\n";
    }
};

class ClasseConcreta_B : public ClasseInterface {
public:
    void metodo_a() override {
        std::cout << "Metodo A invocado pela classe concreta B!\n";
    }
};

void executar_algoritmo(ClasseInterface& objeto)
{
    objeto.metodo_a();
}

int main()
{
    ClasseConcreta_A objeto_1;
    executar_algoritmo(objeto_1);

    ClasseConcreta_B objeto_2;
    executar_algoritmo(objeto_2);

    return 0;
}
```

Um exemplo prático do uso de polimorfismo é mostrado a seguir. Imagine que tenhamos um sistema com vários elementos
gráficos: retangulos, circulos, triangulos... Cada estrutura é representada por uma classe com as informações pertinentes.
Por exemplo:

```c++
class Retangulo {
private:
    Vetor posicao;
    double largura;
    double altura;
};

class Circulo {
private:
    Vetor posicao;
    double raio;
};
```

Para desenhar um conjunto de elementos gráficos na tela poderíamos ter uma interface em comum para eles, e determinar
um método para cada classe desenhar-se:

```c++
class ElementoGrafico {
public:
    virtual void desenhar() const = 0;
};

class Retangulo : ElementoGrafico {
public:
    void desenhar() const override { /*...*/ }
/*...*/
};
```

Por fim, no programa principal é possível ter um vetor de `ElementoGrafico`, e considerando que cada um deles sabe se
desenhar, o código final fica:

```c++
void desenhar_tela(std::vector<std::unique_ptr<ElementoGrafico>> const& elementos)
{
    for (auto const& elemento : elementos) {
        elemento->desenhar();
    }
}
```

O código completo é apresentado abaixo. O código apresentado é apenas ilustrativo, visto que ele não desenha nada de
fato na tela, ele apenas escreve textos no terminal.

```c++
#include <iostream>
#include <vector>
#include <memory>

struct Vetor {
    double x;
    double y;
};

class ElementoGrafico {
public:
    virtual void desenhar() const = 0;
};

class Retangulo : public ElementoGrafico {
public:
    void desenhar() const override
    {
        std::cout << "Desenhando o retangulo!\n";
    }

private:
    Vetor posicao;
    double largura;
    double altura;
};

class Circulo : public ElementoGrafico {
public:
    void desenhar() const override
    {
        std::cout << "Desenhando o circulo!\n";
    }

private:
    Vetor posicao;
    double raio;
};

void desenhar_tela(std::vector<std::unique_ptr<ElementoGrafico>> const& elementos)
{
    for (auto const& elemento : elementos) {
        elemento->desenhar();
    }
}

int main()
{
    auto elementos = std::vector<std::unique_ptr<ElementoGrafico>>{};
    elementos.push_back(std::make_unique<Circulo>());
    elementos.push_back(std::make_unique<Retangulo>());

    desenhar_tela(elementos);    
}
```

Utiliza-se um `std::vector` de `unique_ptr` no exemplo, pois não é possível criar um `std::vector<ElementoGrafico>` (Pois
trata-se de uma _interface_) e nem um `std::vector<ElementoGrafico&>` (Pois não é possível criar um `vector` de referências).
A última alternativa seria `std::vector<ElementoGrafico*>`, que funcionaria normalmente, exceto pelo fato de que seria
necessário fazer o gerenciamento da memória de alguma forma. Para delegar esse gerenciamento, decide-se utilizar os
_smart pointers_ (nesse caso `unique_ptr`) de forma a simplificar o código final.
