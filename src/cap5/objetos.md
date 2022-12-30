# Objetos e classes

## O que é um objeto?

---

**Não se confunda. Este capítulo utiliza o termo _objeto_ no contexto geral de
programação orientada a objetos. Em C++ esse termo possui outro
significado**[^cpp-obj]

---

Na programação orientada a objetos (POO), funções e dados podem ser unidos para
formar o que chamamos objetos. Comumente, essas funções são chamadas _métodos_,
e esses dados são chamados _atributos_. Enquanto na programação procedural uma
função normalmente tem acesso apenas aos seus parâmetros, variáveis locais e ao
estado do programa, em POO um método tem, adicionalmente, acesso ao objeto ao
qual pertence.

| Acesso a...                                                  | Função em programação procedural | Método em POO |
| ------------------------------------------------------------ | :------------------------------: | :-----------: |
| Estado global do programa                                    |                ✓                 |       ✓       |
| Parâmetros                                                   |                ✓                 |       ✓       |
| Variáveis declaradas em seu corpo                            |                ✓                 |       ✓       |
| Objeto ao qual pertence (incluindo seus métodos e atributos) |          Não aplicável           |       ✓       |

Como exemplo, imagine uma função _Depositar_ que deposita dinheiro em um cofre.
Para funcionar, ela precisa saber quanto dinheiro e em qual cofre depositar.
Essas informações podem ser enviadas como dois parâmetros: cofre e quantia. Para
depositar R$ 10 no cofre _cof_, precisamos chamar a função e fornecer os
argumentos _cof_ e 10. Isso é um exemplo de programação procedural.

Aqui está um código C aplicando o que foi dito acima:

```c
#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS

typedef struct
{
    int valor;
} Cofre;

void Depositar(Cofre *cofre, int quantia) { cofre->valor += quantia; }

int main(void)
{
    Cofre cof = {0};
    Depositar(&cof, 10);

    printf("Valor: R$ %d\n", cof.valor);

    return EXIT_SUCCESS;
}
```

Em POO, _cof_ pode ser implementado como um objeto contendo o método _Depositar_
e o atributo _valor_ (que representa o valor total armazenado). Como um método
tem acesso ao seu objeto, não é necessário fornecer _cof_; apenas o valor 10.
Veremos um exemplo logo abaixo.

Enquanto na programação procedural não há associação concreta entre _cof_ e
_Depositar_, em POO um objeto está fortemente ligado às operações que podem ser
realizadas com ele. Adicionalmente, o método _Depositar_ não pode ser acessado
sem _cof_. Isso reduz o número de identificadores em um programa e a chance de
dois nomes entrarem em conflito: outro objeto pode ter um método com o mesmo
nome, sem causar nenhum problema.

<!-- prettier-ignore -->
[^cpp-obj]: Uma definição aproximada de objeto em C++ é uma entidade que
representa um valor. Tanto instâncias de classes quanto variáveis de tipos
simples e valores temporários são objetos.

## Classes

Em C++ utiliza-se o estilo de POO baseado em classes. Nesse estilo, objetos são
categorizados por classes: os atributos e métodos existentes em determinado
objeto são definidos por sua classe. Isso reduz a duplicação de código, já que
vários objetos podem possuir a mesma classe.

Para definir uma classe em C++, utilizamos a palavra-chave `class`:

```cpp
class Cofre {};
```

A classe acima não define nenhum atributo. Atributos em C++ são representados
por _variáveis membro_. Para declarar a variável membro `valor`, devemos
especificar seu tipo:

```cpp
class Cofre
{
    int valor;
};
```

Métodos em C++ são chamados _funções membro_. Definiremos as funções membro
`Depositar` e `Esvaziar`:

```cpp
{{#include code/cofres.cpp:cofre}}
```

A palavra-chave `public` é um _especificador de acesso_; falaremos sobre isso
logo.

Uma classe em C++ é um tipo. Para criamos cofres podemos declarar variáveis de
tipo `Cofre`:

```cpp
Cofre cof1;
Cofre cof2;
```

Dizemos que `cof1` e `cof2` são _instâncias_ de `Cofre`. Cada instância possui
sua própria cópia de cada variável membro, então `cof1.Esvaziar()` esvazia
apenas `cof1`.

Para botar essa classe em prática, aqui está um programa completo como exemplo:

```cpp
{{#include code/cofres.cpp:all}}
```
