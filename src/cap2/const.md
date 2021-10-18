## const, constexpr e consteval

Conforme apresentado no capítulo 2.6, o modificador `const` pode ser utilizado para criar constantes (variáveis com acesso apenas de leitura). Alterar uma variável que contém o modificador `const` causa um erro de compilação:

```cpp
int main()
{
    const int i = 10;
    i = 11; // Compile error: assignment of read-only variable ‘i’
    return 0;
}
```

Esse capítulo apresenta a diferença entre os modificadores `const`, `constexpr` e `consteval`, considerando seu uso em relação à variáveis e funções. O uso do modificador `constinit` e do modificador `const` em relação à métodos de classes será abordado apenas em capítulos posteriores.

Para compreender a diferença entre os modificadores, considere o seguinte código:

```cpp
#include <iostream>

int sum(int a, int b) // Case (a)
// constexpr int sum(int a, int b) // Case (b)
{
    int c = a + b;
    return c;
}

int main()
{
    const int a = 1;
    // int a = 1; // Case (c)
    int x = sum(a, 2);
    std::cout << x;
}
```

Ao invocar a função `sum`, a soma dos valores `a` e `b` será computada. Esse calculo será feito em __tempo de execução__. Isso significa que a soma será efetuada apenas quando o usuário executar o programa. Por outro lado, ao utilizar `constexpr` (introduzido no C++11) na função `sum`, a função potencialmente será executada em __tempo de compilação__, ou seja, o valor de `x` talvez seja computado no momento de compilação do programa, caso as tenha-se disponível as informações necessárias para tal.

Para compreender esse processo, é importante lembrar que todo código C++ é compilado, gerando um arquivo binário que contém o código de máquina. Esse arquivo binário contém instruções em linguagem de baixo nível, específica para cada processador. Mostra-se abaixo uma comparação de dois trechos de código de baixo nível gerados pelo exemplo anterior para os casos (a) sem o uso de `constexpr` e para o caso (b) com o uso de `constexpr`:

a) Sem o uso de `constexpr`:
```
mov     esi, 2
mov     edi, 1
call    sum(int, int)
mov     DWORD PTR [rbp-8], eax
```

b) Com o uso de `constexpr`:
```
mov     DWORD PTR [rbp-8], 3
```

Não se preocupe caso não compreenda totalmente os códigos de máquina apresentados acima. Eles apenas ilustram a diferença de código gerado. No caso (a), a linha `call sum(int, int)` mostra que a função `sum` será de fato invocada em tempo de execução. Já no caso (b), uma única linha é gerada, contendo o resultado (`3`) que foi, portanto, calculado em tempo de compilação e por isso aparece diretamente no código gerado.

É importante notar que `constexpr` só será executado em tempo de compilação caso seja possível conhecer todos os dados necessários para sua execução. Ainda no exemplo, considerando o caso (c), nota-se que utilizar uma variável não-`const` em uma função contendo o modificador `constexpr` ocasionará no seguinte código de máquina gerado:

c) Com uso de `constexpr`, porém, a variável `a` não é `const`
```
mov     DWORD PTR [rbp-4], 1
mov     eax, DWORD PTR [rbp-4]
mov     esi, 2
mov     edi, eax
call    sum(int, int)
mov     DWORD PTR [rbp-8], eax
```

Uma forma de evitar que uma função `constexpr` gere valores em tempo de execução inesperadamente, é utilizar `consteval` (a partir do C++20). Diferente de `constexpr`, `consteval` ocasiona em um erro de compilação caso não consiga processar a função em tempo de compilação. Por exemplo:

```cpp
#include <iostream>

consteval int sum(int a, int b)
{
    int c = a + b;
    return c;
}

int main()
{
    // int a = 1; // Case (a)
    constexpr int a = 1; // Case (b)
    // const int a = 1; // Case (c)
    int x = sum(a, 2);
    std::cout << x;
}
```

No exemplo acima, o caso (a) ocasionará em um erro de compilação. Os casos (b) e (c) geram o valor da variável `x` em tempo de compilação garantidamente. Note que, apesar dos casos (b) e (c) produzirem o mesmo código nesse caso, o uso de `const` e de `constexpr` não é equivalente, como será visto à seguir.

Basicamente, o modificador `const` aplicado à uma variável declara que aquela variável não será modificada em tempo de execução. O modificador `constexpr` aplicado à uma variável declara que aquela variável será computada em tempo de compilação e não será modificada em tempo de execução. Dessa forma, o caso (a) abaixo irá compilar normalmente, pois a variável `a` irá conter uma cópia constante da variável `var`, em tempo de execução. Já o caso (b) não irá compilar, pois a variável `a` não pode ser processada em tempo de compilação, visto que a variável `var` poderia ter sido modificada em algum momento no código.

```cpp
int main()
{
    int var = 1;

    const int a = var; // Case (a)
    // constexpr int a = var; // Case (b)
}
```
