Input/Output (Entrada/Saída)
===

O termo `I/O` se refere aos dispositivos de Entrada (_Input_) e Saída (_Output_). Mais especificamente, essa seção traz
uma introdução para trabalhar com a leitura de dados do usuário pelo terminal (CMD), e a escrita de dados em terminal e
em arquivos de texto.

A forma mais comum de escrever texto em tela do terminal em C++ é a partir de `std::cout` ("Character Output"), e é a
forma como esse livro vem trazendo desde os primeiros capítulos. Para utilizar o `std::cout`, é necessário incluir o
_header_ `<iostream>`.

```c++
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; // Escreve "Hello World!" e pula uma linha (\n)
    return 0;
}
```

A sintaxe é diferente em relação às chamadas de função normalmente utilizada. Note que ao invés de `std::cout("texto")`,
deve-se escrever `std::cout << "texto";`. Isso se dá pela forma como `std::cout` foi implementado. Na verdade, ele é um
objeto que possui um `operator<<`, e não uma função. Essa informação é apenas a título de curiosidade, e não afeta o uso
do `std::cout`, porém, é o início da explicação sobre por que **não** é possível utilizar `std::cout` dessa forma: `"texto" >> std::cout`.

Não é necessário converter os dados para string para utilizar o `std::cout`. Ele consegue lidar com dados de outros
tipos, como `int` e `float`, por exemplo.

De forma semelhante, é possível ler dados do usuário a partir de `std::cin` ("Character input"), como no exemplo abaixo.
Os dados lidos podem ser de qualquer tipo primitivo ou string. Os dados podem ser separados por quebra de linha ou por
espaço.

```c++
#include <iostream>
#include <string>

int main()
{
    using namespace std::string_literals;
    std::cout << "Digite os 3 dados:\n";
    auto my_int = 0;
    auto my_float = 0.;
    auto my_string = ""s;

    std::cin >> my_int >> my_float >> my_string;

    std::cout << "Você digitou: " << my_int << ", " << my_float << ", " << my_string << "\n";

    return 0;
}
```

Note que, até agora, todos os programas apresentados guardavam suas variáveis em memória. Isso significa que, ao
reiniciar o programa, todos os cálculos com as variáveis são perdidos. Para persistir (guardar) dados em disco,
é possível utilizar o `fstream`, como no exemplo abaixo. Claro que isso é uma forma bastante primitiva de persistir
dados. É importante lembrar que existem softwares de banco de dados e bibliotecas de gerenciamento de arquivos muito
mais robustas. Mesmo assim, é interessante conhecer a biblioteca padrão, por ser uma alternativa válida para a
persistência de dados em algumas situações. É importante apenas entender que não é a única e não é necessariamente a
melhor ferramenta para resolver qualquer problema.

```c++
#include <iostream>
#include <fstream>
#include <string>

int main() {
    using namespace std::string_literals;

    auto filename = "arquivo.txt"s;
    auto file_stream = std::fstream(filename, std::ios::out);
    if (!file_stream.is_open()) {
        std::cout << "Failed to open " << filename << '\n';
        return -1;
    }

    auto variable = 1.234;
    file_stream << "Conteúdo do arquivo!\n"s;
    file_stream << variable;
    
    return 0;
}
```

O exemplo acima abre um arquivo chamado `arquivo.txt` em *modo de saída* (`std::ios::out`). O programa verifica se foi
possível abrir o arquivo e, caso negativo, gera uma mensagem e sai do programa. Uma vez aberto, escreve-se o conteúdo do
arquivo e uma variável do tipo float. Note que o arquivo não é explicitamente fechado (`close`). Isso por que o
`fstream` garante que o arquivo será fechado ao fim do escopo de vida do mesmo. Dessa forma, não é necessário fechar
o arquivo explicitamente. De forma análoga, é possível ler o conteúdo de um arquivo conforme exemplo abaixo.

```c++
#include <iostream>
#include <fstream>
#include <string>

int main() {
    using namespace std::string_literals;

    auto filename = "arquivo.txt"s;
    auto file_stream = std::fstream(filename, std::ios::in);
    if (!file_stream.is_open()) {
        std::cout << "Failed to open " << filename << '\n';
        return -1;
    }

    auto line = ""s;
    auto i = 1;
    while(!file_stream.eof()) {
        getline(file_stream, line);
        std::cout << "Linha " << i << ": " << line << '\n';
        i += 1;
    }

    return 0;
}
```

Também é possível ler o conteúdo de um arquivo caracter por caracter. Para isso, poderia-se utilizar o método
`file_stream.get(l);`, com `l` sendo do tipo `char`. Cada forma de leitura tem suas vantagens e desvantagens, e seu uso
vai depender do problema que se está tentando resolver.

### Estudo de Caso: Input de dados para juizes online

Existem vários sites na internet para exercitar a prática de programação e algoritmos. Esses sites são conhecidos como
"juizes online", por exemplo, [UVa](https://onlinejudge.org/) e [Spoj](https://www.spoj.com/). Nesses sites, é comum
encontrar problemas com um formato bastante específico de inputs de exemplo. Essa subseção traz um breve tutorial para
iniciantes em C++, em relação a como poderia-se fazer a leitura dos dados para esse tipo de problema.

Para o exercício, considere o problema [PRIME1](https://www.spoj.com/problems/PRIME1/) do Spoj, copiado (e traduzido)
abaixo, para referência:

> Peter deseja gerar todos os números primos para seu sistema. Você deve ajuda-lo.
> Gere todos os números primos entre dois números dados.
>
> **Entrada**
>
> A entrada inicia com um número `t`, que representa o número de testes (t <= 10).
> Cada uma das `t` próximas linhas contém dois números, `m` e `n`, separados por espaços.
>
> **Saída**
> 
> Para cada caso de teste, escreva na tela todos os primos `p` onde `m <= p <= n`.
> Cada número primo deve ser escrito em uma linha diferente. Casos de teste devem ser separados por uma linha em branco.
>
> **Exemplo**
>
> Entrada: \
> 2 \
> 1 10 \
> 3 5
>
> Saída: \
> 2 \
> 3 \
> 5 \
> 7
>
> 3 \
> 5

O objetivo aqui não é resolver o problema completamente, mas apenas se preocupar com a leitura dos dados. A entrada de
dados segue um padrão bem definido, conforme exemplo. A primeira linha contém apenas um número, que deve ser lido na
variável `t`. As `t` linhas seguintes devem conter pares de números `(m, n)`.

Conforme visto anteriormente, é possível fazer a leitura dos dados a partir do `std::cin`. Dessa forma, para recuperar
o valor de `t` é possível simplesmente fazer:

```c++
#include <iostream>

int main() {
    auto t = 0;
    std::cin >> t;
    std::cout << "CASOS DE TESTE: " << t << '\n';

    return 0;
}
```

A seguir, para fazer a leitura dos pares `m` e `n`, é possível utilizar um `for` com um contador de `i = 0` até `t`.
Enquanto esse contador não chegar no valor de `t`, lê-se um novo par de valores. Assume-se que os valores serão dois
números válidos separados.

```c++
#include <iostream>

int main() {
    auto t = 0;
    std::cin >> t;
    std::cout << "CASOS DE TESTE: " << t << '\n';

    for (auto i = 0; i < t; ++i) {
        auto n = 0;
        auto m = 0;
        std::cin >> n >> m;

        std::cout << "Processando dados: (" << n << ", " << m << ")\n";
        // ... resto do código ...
    }

    return 0;
}
```

Uma curiosidade interessante é que, no linux, é possível redirecionar o conteúdo de um arquivo texto, de forma que ele
sirva de entrada para um programa. Por exemplo, digamos que você compile o arquivo acima e gere um executável chamado
`programa`. Ao invés de executar esse programa e digitar as entradas dos dados manualmente, é possível criar um arquivo
(por exemplo, `input.txt`) cujo conteúdo é conforme dado abaixo, e redirecionar o conteúdo desse arquivo para a entrada
do programa `programa`, da seguinte forma: `./programa < input.txt`.

```
2
1 10
3 5
```

O resultado da execução é dado abaixo. Essa é uma forma rápida de manter arquivos de teste para problemas de maratona de
programação e juizes online.

```
$ ./programa < input.txt 
CASOS DE TESTE: 2
Processando dados: (1, 10)
Processando dados: (3, 5)
```