# Funções

Para deixar partes do programa reutilizáveis, e para adicionar legibilidade ao código, utilizamos funções. Funções são pedaços de código que são definidas uma vez em um lugar, mas que podem ser reutilizadas quantas vezes quiser em outros lugares do código.

Elas servem para que não precisemos reescrever o mesmo código múltiplas vezes, e permitem que sigamos o princípio do _Não Se Repita_ ([Don't repeat yourself](https://pt.wikipedia.org/wiki/Don%27t_repeat_yourself) - DRY).

Funções podem ou não receper _parâmetros_, que são usados para levar informações de um escopo para outro. Os parâmetros são, por padrão, cópias das variáveis que são levadas ao escopo da função invocada, e eles aparecem entre parênteses após o nome da função, separados por vírgula.

Funções possuem também um valor de retorno, que possibilita capturar uma variável concebida dentro do escopo da função para o local onde ela foi chamada. Abaixo um exemplo de função:

```cpp
#include <iostream>

int calculate_sum(int a, int b)
{
   int sum = 0;
   for (int i = a; i <= b; ++i) {
       sum += i;
   }
   return sum;
}

int main()
{
   int a = 0;
   int b = 0;
   std::cout << "Digite o valor de A: ";
   std::cin >> a;
   std::cout << "Digite o valor de B: ";
   std::cin >> b;

   std::cout << "Sum [" << a << ", " << b << "] = " << calculate_sum(a, b) << std::endl;

   return 0;
}
```

No código acima, foi definida uma função `calculate_sum`, que necessita de dois parâmetros do tipo int `a` e `b`, e que efetua a soma dos valores de `a` a `b`, e retorna essa soma (por exemplo, se `a` for 2 e `b` for 5, a soma será 2 + 3 + 4 + 5, e o valor retornado será 14). O tipo de retorno de uma função é determinado em sua _assinatura_. A assinatura de uma função é o conjunto contendo seu nome, seu tipo e seus parâmetros, por exemplo, `int calculate_sum(int a, int b)`.

As funções devem ser pelo menos _declaradas_ antes de serem utilizadas. Por exemplo, se movermos a definição da função `calculate_sum` para baixo da função `main`, teriamos um erro de compilação. Existe uma distinção entre _declarar_ uma função e _definir_ uma função. Declarar uma função é apenas mostrar que ela existe, sem determinar seu funcionamento (ou seja, sem adicionar o corpo de código dela). Definir uma função é adicionar um corpo de código a uma declaração.

No exemplo acima, estamos definindo a função `calculate_sum`. Um exemplo de separação entre a declaração e a definição de função é mostrado abaixo.

```cpp
#include <iostream>

// Declaração da função `calculate_sum`
int calculate_sum(int a, int b);

int main()
{
   int a = 0;
   int b = 0;
   std::cout << "Digite o valor de A: ";
   std::cin >> a;
   std::cout << "Digite o valor de B: ";
   std::cin >> b;

   std::cout << "Sum [" << a << ", " << b << "] = " << calculate_sum(a, b) << std::endl;

   return 0;
}

// Definição da função `calculate_sum`
int calculate_sum(int a, int b)
{
   int sum = 0;
   for (int i = a; i <= b; ++i) {
       sum += i;
   }
   return sum;
}
```

Caso a função não retorne nenhum valor, é possível utilizar a palavra reservada `void`, conforme exemplo abaixo. Funções com tipo de retorno `void` podem (opcionalmente) omitir a chamada `return`, indicando o término da função. Enquanto funções com retornos específicos são particularmente úteis para obter o resultado de uma operação para que façamos algo com ele, funções do tipo `void` são particularmente úteis para executar uma ação. No exemplo anterior, queríamos obter um resultado, um número que representa uma soma, e fizemos algo mais com ele em `main()`. No exemplo seguinte, a única ação sendo executada é printar na tela o texto "Olá Mundo!", e não queremos fazer nenhuma operação com este texto depois que a função é executada.

```cpp
void say_hello()
{
   std::cout << "Olá Mundo!" << std::endl;

   // Opcional:
   // return
}
```
