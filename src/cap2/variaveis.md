# Variáveis

Uma variável é um meio de armazenar valores e atribuir nomes a eles; de modo mais técnico, variáveis são um espaço de memória no seu computador usado para guardar informações, que podem ser de vários _tipos_: números, caracteres, texto, entre outros. Graças a isso, diz-se que C++ é uma linguagem de programação _tipada_.

Em C++, todas as variáveis possuem um tipo, e o tipo da variável _não muda_, até que ela deixe de existir (nos referimos a isso como o "tempo de vida", ou "_lifetime_", de uma variável). Diz-se então que C++ é uma linguagem de programação _estaticamente_ tipada.

Variáveis são definidas da seguinte forma:

```cpp
int main()
{
    int some_int = 8;
    // A variávei de nome some_int é do tipo inteiro (int) e possui o valor 8
    float some_float = 9.2;
    // A variávei de nome some_float é do tipo ponto flutuante (float) e possui o valor 9.2
    char some_char = 'a';
    // A variávei de nome some_int é do tipo caractere (char) e possui o valor 'a'
    bool some_bool = true;
    // A variávei de nome some_int é do tipo booleano (bool) e possui o valor true

    return 0;
}
```

O tempo de vida de uma variável é delimitado por seu escopo. O escopo de uma variável é determinado pelo bloco que a contém, delimitado por chaves (`{}`). O exemplo anterior possui quatro variáveis, cada uma de um tipo diferente, e todas elas estão no escopo da função "main". Uma variável chega ao fim do seu tempo de vida ao final do escopo que a contém. Se uma variável está fora de qualquer escopo, ela é chamada de _variável global_.

Alternativamente, C++ moderno (do padrão C++11 em diante) traz uma sintaxe alternativa para definir o tipo das variáveis, por meio da palavra chave `auto`. Dessa forma, não é necessário explicitar o tipo das variáveis. Note que a variável ainda possui um tipo bem definido. A única diferença é que o tipo é determinado automaticamente em tempo de compilação (compile time), através de um processo chamado _inferência_:

```cpp
int main()
{
    auto some_int = 8;
    auto some_float = 9.2;
    auto some_char = 'a';
    auto some_bool = true;
}
```

Em C++, o tipo `string`, para representar textos, não é um tipo primitivo. Para isso, existe o tipo `std::string` na biblioteca padrão do C++ (_stdlib_). Para utilizá-lo, é necessário incluir o header `<string>`, da mesma forma que incluímos `<iostream>` anteriormente para podermos escrever na tela.

```cpp
#include <string>

int main()
{
    std::string some_string = "First string";
    
    // ... alternativamente, usando `auto`:
    auto some_string_2 = std::string("Second string");

    // ... ou, usando `auto` e `string literals`:
    using namespace std::string_literals;
    auto some_string_3 = "Third string"s; // Note o `s` após a string!
}
```

Note que um _literal de texto_ entre aspas duplas como `"my string"` não é do tipo `std::string`.
Isto causa um pouco de confusão, e será melhor explicado adiante.
Por ora, mantenha em mente as formas de declarar vistas acima (perceba o sufixo "s" no terceiro caso utilizando `auto`!)
