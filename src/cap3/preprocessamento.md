Pré-processamento
===

O pré-processador cuida de resolver todas as macros disponíveis no programa.
Macros são os comandos que iniciam com `#`, tais como `#include` e `#define`.
Para o escopo dessa seção, explicaremos o uso de quatro macros: `#include`, `#define`, `#ifdef` e `#ifndef`.

Na verdade, já usamos `#include` algumas vezes desde o início desse livro, mas não sabiamos exatamente seu funcionamento.
Basicamente, o que esse comando faz é buscar o conteúdo de um arquivo e inclui-lo (copia-lo) no local do `#include`.
Considere o seguinte exemplo: imagine que você tem um projeto com 2 arquivos, `main.cpp` e `sum.hpp`. Esse
último contém uma função auxiliar `int sum(int a, int b)`, e você gostaria de utilizar essa função no `main.cpp`. Isso pode
ser feito utilizando o `#include`:

`sum.hpp`
```cpp
int sum(int a, int b)
{
    return a + b;
}
```

`main.cpp`
```cpp
#include <iostream>
#include "sum.hpp"

int main()
{
    std::cout << sum(2, 3) << std::endl;
    return 0;
}
```

Note a diferença entre os dois `includes`: O primeiro utiliza `<nome do arquivo>`, enquanto o segundo utiliza
`"nome do arquivo"`. A diferença é que enquanto `""` busca o arquivo à ser incluído a partir da pasta corrente (ou seja,
a mesma pasta onde reside o arquivo `main.cpp`, nesse caso), utilizar `<>` faz com que o pré-processador busque o arquivo
em algumas pastas pré-determinadas, como é o caso dos diretórios padrão do sistema.

Existe um problema que, usualmente, um arquivo pode depender de outro que pode já ter sido incluído previamente.
Por exemplo, se existirem dois arquivos, `a.hpp` e `b.hpp`, onde `a.hpp` inclui `b.hpp` e vice versa, teriamos uma
recursão de inclusões impossível de resolver. Por isso, utiliza-se _include guards_ para evitar esse problema, como no
exemplo abaixo.

Ao incluir-se o arquivo `a.hpp` em `main.cpp`, o conteúdo do arquivo `a.hpp` irá ser copiado. Em `a.hpp`,
o pré-processador irá verificar a existência da macro `__A_HPP`. Como ela não existe (`#ifndef`), ela será definida (`#define`),
e o conteúdo de `a.hpp` será totalmente copiado. Dessa forma, o arquivo `b.hpp` será incluído. Aqui, o mesmo procedimento
irá ocorrer, sendo definida uma variável `__B_HPP`. Porém, ao incluir `a.hpp` de dentro de `b.hpp`, percebe-se que, agora,
a macro `__A_HPP` está definida. Sendo assim, o `ifndef` do arquivo `a.hpp` percebe que não precisa processar novamente
o mesmo arquivo.

`main.cpp`
```cpp
#include "a.hpp"

int main()
{
    return 0;
}
```

`a.hpp`
```cpp
#ifndef __A_HPP
#define __A_HPP

#include "b.hpp"

#endif
```

`b.hpp`
```cpp
#ifndef __B_HPP
#define __B_HPP

#include "a.hpp"

#endif
```

O processo de inclusão de arquivos `hpp` é muito importante para a modularização de código.
Em C++, é comum separar a _declaração_ das funções, classes e estruturas em arquivos `.hpp`, e a _definição_ das mesmas
em arquivos `.cc` ou `.cpp`. Exceto em alguns casos específicos, como no uso de templates (será visto apenas em
capítulos mais avançados).

Erros de pré-processamento ocorrem na primeira etapa do processo de compilação. Para exemplificar, considere o exemplo
abaixo, e imagine que não existe o arquivo `some_file.hpp`. O erro no `gcc` é `a.cc:1:10: fatal error: some_file.hpp: No such file or directory`.
Isso significa que o arquivo não existe ou que ele existe, mas não está na pasta correta para que seja encontrado. É
muito importante que se tenha isso bem conhecido, visto que esse conhecimento auxilia na resolução de problemas no processo
de compilação.

```cpp
#include "some_file.hpp"

int main()
{
    return 0;
}
```

Macros também podem ser utilizadas como "funções" modificadas em tempo de compilação. Esse tema não vai ser discutido em
profundidade nesse capítulo, e sugere-se não utilizar macros para executar esse tipo de rotina em tempo de compilação.
Apenas a titulo de exemplo, seria possível definir a seguinte macro:

```cpp
#include <iostream>
#define POW2(x) x*x

int main()
{
    std::cout << POW2(4) << std::endl;

    return 0;
}
```

A macro toma como parâmetro um valor `x` não tipado e troca o código por `x*x`. Para visualizar esse efeito, no `gcc`,
é possível compilar o arquivo acima com `gcc -E main.cpp`, produzindo algo semelhante ao arquivo pré-processado abaixo.
Note que a compilação não gerou um executável nesse caso, pois a opção `-E` orienta o compilador a parar o processo de
compilação após a etapa de pré-processamento.

```cpp
// ... other contents here ...
int main()
{
    std::cout << 4*4 << std::endl;

    return 0;
}
```

Apesar de parecer útil, a utilização de macros traz vários problemas. Por exemplo, veja o que aconteceria se chamassemos
`POW2(4 + 1)`:

```cpp
int main()
{
    std::cout << 4 + 1*4 + 1 << std::endl;

    return 0;
}
```

O resultado seria `4 + 1 * 4 + 1`, ou seja, `9` (Ao invés de `25`, como seria o esperado). Isso acontece por que as
macros não são equivalentes à chamadas de função. Lembre-se você está apenas criando macros que copiam valores de um
lado para outro. Uma possível solução para esse caso seria de adicionar parênteses à macro: `#define POW2(x) (x)*(x)`,
resultando em:

```cpp
int main()
{
    std::cout << (4 + 1)*(4 + 1) << std::endl;

    return 0;
}
```

De qualquer forma, orienta-se a criar funções simples do C++ e, possívelmente, utilizar `constexpr` em casos semelhantes
à esses.