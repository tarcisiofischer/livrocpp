Classes e Objetos
===

A base da programação orientada a objetos são os objetos. No contexto de C++ objetos são instâncias de classes, classes são abstrações que contém a descrição de quais atributos e métodos um objeto possui e atributos são variáveis internas de uma classe. Métodos são funções membro (__member functions__) de uma classe. Exemplo:

```c++
#include <iostream>

class Cachorro {
public:
    void latir()
    {
        std::cout << "Au! Au!!\n";
    }
};

int main()
{
    Cachorro bidu;
    bidu.latir();
    return 0;
}
```

No código acima, `Cachorro` é uma classe. O objeto `bidu` é uma instância da classe `Cachorro`. Como `Cachorro` possui o método `latir`, é possível invoca-lo por meio de `bidu.latir()`.

Métodos podem ser públicos (`public`), protegidos (`protected`) ou privados (`private`). Métodos e atributos privados não podem ser invocados fora do escopo da classe. Métodos e atributos protegidos podem ser invocados apenas no escopo da classe ou de classes filhas (Hierarquia de classes é tema do próximo capítulo). Métodos e atributos públicos podem ser acessados de dentro ou de fora do escopo da classe.

Sugere-se manter os atributos de uma classe como membros privados ou protegidos, e acessa-los apenas através de métodos, a fim de esconder os detalhes do objeto, e expondo apenas alguns métodos públicos. À isso da-se o nome de __encapsulamento__.

O construtor de uma classe é um método especial que possui o nome igual ao nome da classe e não possui retorno. O construtor da classe serve para inicializar os atributos internos e deixa-la em um estado utilizavel. Exemplo:

```c++
#include <iostream>
#include <string>

class Cachorro {
public:
    Cachorro(std::string const& nome)
        : nome(nome)
    {}

    void latir()
    {
        std::cout << "Au! Au!! Eu sou o " << this->nome << '\n';
    }

private:
    std::string nome;
};

int main()
{
    Cachorro bidu{"Bidu"};
    bidu.latir();
    return 0;
}
```

No exemplo acima `Cachorro(std::string const& nome)` é o construtor da classe `Cachorro`. Note que o construtor possui um parâmetro do tipo `std::string`. Dessa forma, para construir um `Cachorro` agora é necessário passar alguma string como parâmetro. Isso está sendo feito na linha `Cachorro bidu{"Bidu"};`. Essa linha está construindo uma instância da classe `Cachorro` de nome `bidu` e cuja variável interna `nome` terá o valor `Bidu`.

Note a sintaxe de construção do `Cachorro`:

```c++
    Cachorro(std::string const& nome)
        : nome(nome)
    {}
```

Note que o `: nome(nome)` está ANTES da abertura do escopo do corpo do construtor, ou seja, antes das chaves `{}`. Essa sintaxe possibilita que a construção do objeto seja feita antes de entrar no corpo do construtor. Isso se chama lista de inicialização (__initializer list__). Alternativamente poderia-se escrever

```c++
    Cachorro(std::string const& nome)
    {
        this->nome = nome;
    }
```

Onde `this` é uma variável especial que é um ponteiro para a própria instância da classe em questão. O uso de `this` é
opcional dentro do escopo da classe, de forma que é possível se referir à atributos da mesma diretamente.
O código acima altera o valor do membro `nome` para o valor contido na variável local `nome`. Diferente do código
anterior, `this->nome` primeiro é inicializado com valor vazio, para somente ser alterado dentro do corpo do construtor
de `Cachorro`.

Assim como qualquer outra variável em C++, instâncias de classes podem ser alocadas na pilha ou na heap. Para alocar uma instância na pilha, basta seguir o procedimento dos exemplos anteriores, copiado abaixo apenas para facilitar a leitura:

```c++
int main()
{
    Cachorro bidu{"Bidu"}; // <--- Alocado na pilha
    bidu.latir();
    return 0;
}
```

Por outro lado, para alocar na heap deve-se fazer uso da palavra reservada `new`, conforme exemplo abaixo. Tal qual explicado em capítulos anteriores toda memória alocada na heap deve ser desalocada pelo programador. No caso de variáveis inicializadas com `new` é necessário utilizar o `delete`.

```c++
int main()
{
    auto* bidu = new Cachorro{"Bidu"}; // <--- Alocado na heap
    bidu->latir();
    delete bidu;
    return 0;
}
```

Note que a sintaxe de acesso ao método `latir` mudou. Isso ocorre por que no exemplo acima `bidu` é um ponteiro para uma instância de `Cachorro`. Dessa forma o acesso ao método `latir` é feito com `->` ao invés de `.`. Alternativamente poderia-se de-referenciar o ponteiro. Porém, a sintaxe ficaria bastante esquisita e não é sugerida:

```c++
int main()
{
    auto* bidu = new Cachorro{"Bidu"}; // <--- Alocado na heap
    (*bidu).latir();
    delete bidu;
    return 0;
}
```

O objeto `bidu` será destruído no momento que `delete` é invocado. No caso da variável em pilha o objeto é destruido no momento que sair do escopo. Em ambos os casos é possível invocar um código especial de destrução do objeto. Esse código fica no método destrutor da classe que possui nome equivalente ao do construtor, porém, com o simbolo `~` como prefixo. O destrutor é útil quando é necessário liberar algum recurso obtido em algum momento da vida do objeto. Exemplo:

```c++
#include <iostream>
#include <string>

class Cachorro {
public:
    Cachorro(std::string const& nome)
        : nome(nome)
    {}

    ~Cachorro()
    {
        // Código executado no momento que o cachorro está sendo destruido
        std::cout << "Estou sendo destruido!!\n";
    }

    void latir()
    {
        std::cout << "Au! Au!! Eu sou o " << this->nome << '\n';
    }

private:
    std::string nome;
};

int main()
{
    Cachorro bidu{"Bidu"};
    bidu.latir();
    return 0;
}
```

Esses são os conceitos básicos de orientação a objetos necessários para iniciar um contato com o tema em linguagem C++. Os capítulos posteriores vão entrar em outros conceitos fundamentais e de extrema importância para a programação orientada a objetos. Por fim, é importante mencionar que programação orientada a objetos é um paradigma muito interessante e pode ajudar na solução de vários problemas. Porém, tenha sempre em mente que não é o único paradigma de programação e que nem sempre é o melhor para qualquer situação.
