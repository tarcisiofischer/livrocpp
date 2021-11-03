String
===

Strings são estruturas de dados que representam sequências de elementos, sendo o mais comum a sequência de caracteres
(`char`). A biblioteca padrão provê uma série de funcionalidades para lidar com strings, a partir do _header_ `<string>`.

É importante notar que sequências de caracteres dentro de aspas duplas (`"`) não são do tipo `string` em C++. Considere
o exemplo abaixo:

```c++
#include <string>

int main()
{
    auto word = "Exemplo"; // *Não* é do tipo std::string
    auto other_word = std::string("Outro Exemplo"); // É do tipo std::string

    // (A partir de C++14)
    using namespace std::string_literals;
    auto yet_another_word = "Mais um exemplo"s; // É do tipo std::string

    return 0;
}
```

`word` não é do tipo `std::string`. Isso por que C++ não possui `string` como tipo primitivo da linguagem. Ao invés
disso, `word` possui tipo `const char[8]`, que representa um "array de 8 elementos do tipo `char`" (7 caracteres na
palavra "Exemplo" + 1 caracter de fim de texto, representado por `\0`).
Por outro lado, `other_word` e `yet_another_word` são do tipo `std::string`.

A vantagem de utilizar `std::string` ao invés de `const char[]`, é que ela provê várias funções e métodos de manipulação
e extração de dados para strings. Por exemplo, é possível concatenar duas `std::string`s utilizando o operador `+`, mas
não é possível fazer o mesmo com `const char[]`:

```c++
#include <string>
#include <iostream>

int main()
{
    using namespace std::string_literals;
    auto string1 = "Hello "s;
    auto string2 = "World"s;
    auto string3 = string1 + string2;
    std::cout << string3 << "\n"; // Mostra "Hello World"
    
    // O código abaixo produz um erro de compilação, pois não é possível
    // somar duas variáveis do tipo `const char*`:
    // auto var1 = "Hello ";
    // auto var2 = "World";
    // auto var3 = var1 + var2; // ERRO de compilação
    
    return 0;
}
```

A partir desse momento, utiliza-se a palavra "string" para denotar `std::string`.

É possível converter strings de/para os tipos primitivos `int` e `float`, por meio de funções auxiliares. Esse tipo de
conversão é especialmente útil para traduzir inputs de usuário em dados numéricos. Exemplo:

```c++
#include <string>
#include <iostream>

int main()
{
    using namespace std::string_literals;
    auto value1 = "12"s;
    auto value2 = "7"s;
    auto string3 = value1 + value2; // Produz "127" (com tipo string)
    auto value3 = std::stoi(value1) + std::stoi(value2); // Produz 19 (com tipo int)
    std::cout << string3 << ", " << value3 << "\n"; // Mostra 127, 19

    return 0;
}
```

Para converter strings para floats, pode-se utilizar `std::stof`. Para converter `int` e `float` para strings, pode-se
utilizar `std::to_string`. Uma lista extensa de funcionalidades para `std::sring` está [disponível aqui](https://en.cppreference.com/w/cpp/header/string).
