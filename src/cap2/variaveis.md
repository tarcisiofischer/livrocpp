## Variáveis

C++ é uma linguagem de programação estaticamente tipada. Isso significa que todas as variáveis possuem um tipo, e o tipo da variável não muda, até que ela deixe de existir (nos referimos a isso como "tempo de vida", ou "_lifetime_", de uma variável). Em C++, a definição de uma variável se dá da seguinte forma:

```cpp
int main()
{
    int some_int = 8;
    float some_float = 9.2;
    char some_char = 'a';
    bool some_bool = true;

    return 0;
}
```

O tempo de vida de uma variável é delimitado por seu escopo. O escopo de uma variável é determinado pelo bloco que a contém, delimitado por chaves (`{}`). O exemplo anterior possui quatro variáveis, cada uma de um tipo diferente, e todas elas estão no escopo da função "main". Uma variável chega ao fim do seu tempo de vida ao final do escopo que a contém. Se uma variável está fora de qualquer escopo, ela é chamada de _variável global_.

Alternativamente, C++ moderno (do padrão C++11 em diante) traz uma sintaxe alternativa para definir o tipo das variáveis, por meio da palavra chave `auto`. Dessa forma, não é necessário explicitar o tipo das variáveis. Note que a variável ainda possui um tipo bem definido. A única diferença é que o tipo é determinado automaticamente em tempo de compilação, através de um processo chamado _inferência_:

```cpp
int main()
{
    auto some_int = 8;
    auto some_float = 9.2;
    auto some_char = 'a';
    auto some_bool = true;
}
```

Em C++, o tipo `string`, para representar textos, não é um tipo primitivo. Por isso, existe o tipo `std::string` na biblioteca padrão do C++ (_stdlib_). Para utilizá-lo, é necessário incluir o header `<string>`, da mesma forma que incluímos `<iostream>` anteriormente para podermos escrever na tela.

```cpp
#include <string>

int main()
{
    std::string some_string = "First string";
    
    // ... or, using `auto`:
    auto some_string_2 = std::string("Second string");

    // ... or using `auto` and string literals:
    using namespace std::string_literals;
    auto some_string_3 = "Third string"s; // Note the "s" after the string!
}
```

Note que um literal de texto entre aspas duplas como `"my string"` não é do tipo `std::string`.
Isto causa um pouco de confusão, e será melhor explicado adiante.
Por ora, mantenha em mente as formas de declarar vistas acima (Perceba o sufixo "s" no terceiro caso utilizando `auto`!)

