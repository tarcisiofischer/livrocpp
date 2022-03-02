Herança e Polimorfismo
===

Chama-se _herança_ o mecanismo que permite uma classe herdar membros (métodos
e atributos) de outra classe. Tal mecanismo permite reaproveitar código comum entre classes filhas. Porém, uma vantagem
ainda mais importante é a possibilidade de criar _interfaces_.

A sintaxe para a criação de uma classe base é mostrada no exemplo abaixo. A classe `Cachorro` estende a classe `Animal`,
ou seja, a classe `Cachorro` é formada por todos os atributos e métodos da classe `Animal` mais todos os atributos e
métodos da própria classe `Cachorro`.

```c++
#include <iostream>
#include <string>

class Animal {
public:
    Animal(std::string const& nome) : nome(nome) {};

    void escreve_nome()
    {
        std::cout << this->nome << '\n';
    }

private:
    std::string nome;
};

class Cachorro : public Animal {
public:
    Cachorro(std::string const& nome) : Animal(nome) {}

    void latir()
    {
        std::cout << "Au Au!\n";
    }
};

int main()
{
    Animal sherlock{"Sherlock"};
    sherlock.escreve_nome();

    Cachorro hulk{"Hulk"};
    hulk.escreve_nome();
    hulk.latir();

    return 0;
}
```

O exemplo é extremamente simples, e serve apenas para ilustrar a sintaxe de herança em C++ e iniciar um contato do leitor
sobre esses aspectos da linguagem. Note que apesar de ambas instâncias `sherlock` e `hulk` conterem o método
`escreve_nome`, apenas a instância da classe `Cachorro` pode invocar o método `latir`. Isso ocorre por que `hulk` é uma
instância da classe `Cachorro`, que possui tanto os métodos e atributos de `Animal` quanto àqueles referentes à própria
classe `Cachorro`.

O construtor da classe `Cachorro` precisa invocar o construtor da classe mãe (nesse caso `Animal`) de forma a construir
corretamente a mesma. A sintaxe para a construção da classe mãe é mostrada no exemplo acima. A classe `Cachorro` possui
um construtor que por sua vez contém uma lista de inicialização e, nela, o construtor da classe mãe é invocado. Caso a
classe mãe não tivesse um construtor definido (ou seja, se estivesse sendo utilizado o construtor padrão), não seria
necessário invoca-lo explicitamente como no exemplo acima.

Além disso, é possível reescrever um método da classe mãe, de forma a alterar seu funcionamento, na classe filha.
Considere o exemplo abaixo. A classe `Animal` possui agora um método publico _virtual_ chamado `fazer_barulho`, e a
classe `Cachorro` possui um método de mesmo nome com o modificador `override`. Esse modificador é opcional e está
disponível apenas em versões mais atuais da linguagem. É uma boa prática de programação adiciona-lo, a fim de manter uma
consistência entre classe base e classe filha.

```c++
#include <iostream>
#include <string>

class Animal {
public:
    Animal(std::string const& nome) : nome(nome) {};

    virtual void fazer_barulho()
    {
        std::cout << "*barulho desconhecido*\n";
    }

private:
    std::string nome;
};

class Cachorro : public Animal {
public:
    Cachorro(std::string const& nome) : Animal(nome) {}

    void fazer_barulho() override
    {
        std::cout << "Au Au!\n";
    }
};

void mexer_na_moita(Animal& animal)
{
    animal.fazer_barulho();
}

int main()
{
    Animal sherlock{"Sherlock"};
    mexer_na_moita(sherlock);

    Cachorro hulk{"Hulk"};
    mexer_na_moita(hulk);

    return 0;
}
```

Note que a função `mexer_na_moita` recebe como parâmetro uma referência para um objeto da classe `Animal`. Ainda assim,
na função `main`, uma instância da classe `Cachorro` é enviada como parâmetro. Sempre é possível utilizar instâncias de
classes filhas como parâmetros para referências ou ponteiros para a classe mãe da mesma. O método `fazer_barulho` vai se
comportar de forma diferente, dependendo do tipo de objeto sendo recebido como parâmetro. Sendo mais específico, para o
caso do exemplo acima a primeira chamada de `mexer_na_moita(sherlock)` resultará no texto escrito `*barulho desconhecido*`,
enquanto a segunda chamada `mexer_na_moita(hulk)` resultará no texto `Au Au!`. Essa característica se chama
_Polimorfismo_.

Um aspecto muito importante de se ter em mente é que no caso da ausência do `virtual` na classe mãe, o polimorfismo do
exemplo não acontecerá conforme esperado. Basicamente a ausência de `virtual` ignora a funcionalidade que possibilita a
invocação correta do método da classe filha, quando a mesma é passada por parâmetro como uma classe base, como no
exemplo. Em outras palavras, a remoção de `virtual` (e por consequência a remoção de `override`) no exemplo resultaria
em ambas chamadas retornarem o texto `*barulho desconhecido*`.

Uma classe pode possuir métodos virtuais sem implementação, como no próximo exemplo. Esse tipo de classe não pode ser
instanciada. Ou seja, não é possível construir um objeto cujo tipo seja uma classe com métodos sem implementação.
Classes que contenham todos os métodos virtuais e sem implementação são chamadas _interfaces_. Classes que contenha
pelo menos um método com implementação são chamadas _abstratas_. Portanto, no exemplo abaixo, a classe `Animal` é uma
interface.

```c++
#include <iostream>

class Animal {
public:
    virtual void fazer_barulho() = 0;
};

class Cachorro : public Animal {
public:
    void fazer_barulho() override {
        std::cout << "Au Au!\n";
    }
};

class Gato : public Animal {
public:
    void fazer_barulho() override {
        std::cout << "Miau!\n";
    }
};

void mexer_na_moita(Animal& animal)
{
    animal.fazer_barulho();
}

int main()
{
    Cachorro hulk;
    mexer_na_moita(hulk);

    Gato bolinha;
    mexer_na_moita(bolinha);

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

Para desenhar um conjunto de elementos gráficos na tela poderiamos ter uma interface em comum para eles, e determinar
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

Utiliza-se um `std::vector` de `unique_ptr` no exemplo pois não é possível criar um `std::vector<ElementoGrafico>` (Pois
trata-se de uma interface) e nem um `std::vector<ElementoGrafico&>` (Pois não é possível criar um vector de referencias).
A última alternativa seria `std::vector<ElementoGrafico*>`, que funcionaria normalmente, exceto pelo fato de que seria
necessário fazer o gerenciamento da memória de alguma forma. Para delegar esse gerenciamento, decide-se utilizar os
_smart pointers_ - nesse caso `unique_ptr` - de forma a simplificar o código final.
