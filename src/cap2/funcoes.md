## Funções

Para deixar partes do programa reutilizáveis, e para adicionar legibilidade ao código, utilizamos funções. Funções extraem parcelas do código para fora do local onde ela é utilizada.

Funções podem ou não receper parâmetros, que são usados para levar informações de um escopo para outro. Os parâmetros são, por padrão, cópias das variáveis que são levadas ao escopo da função invocada.

Funções possuem também um valor de retorno, que possibilita capturar uma variável concebida dentro do escopo da função para o local onde ela foi invocada. Abaixo um exemplo de função:

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

No código acima, foi definida uma função `calculate_sum`, que efetua a soma dos valores entre `a` até `b` (inclusive), e retorna essa soma. O tipo de retorno de uma função é determinado em sua assinatora. A assinatura de uma função é o conjunto contendo seu nome, seu tipo e seus parâmetros, por exemplo, `int calculate_sum(int a, int b)`.

As funções devem ser pelo menos declaradas antes de serem utilizadas. Por exemplo, se movermos a definição da função `calculate_sum` para baixo da função `main`, teriamos um erro de compilação. Existe uma distinção entre declarar uma função e definir uma função. Declarar uma função é apenas mostrar que ela existe, sem determinar seu funcionamento (Ou seja, sem adicionar o corpo de código dela). Definir uma função é adicionar um corpo de código à uma declaração.

No exemplo acima, estamos definindo a função `calculate_sum`. Um exemplo de separação entre a declaração e a definição de função é mostrado abaixo.

```cpp
#include <iostream>

// Function declaration
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

// Function definition
int calculate_sum(int a, int b)
{
   int sum = 0;
   for (int i = a; i <= b; ++i) {
       sum += i;
   }
   return sum;
}
```

Caso a função não retorne nenhum valor, é possível utilizar a palavra reservada `void`, conforme exemplo abaixo. Funções com tipo de retorno `void` podem (opcionalmente) omitir a chamada `return`.

```cpp
void say_hello()
{
   std::cout << "Ola Mundo!" << std::endl;

   // Unnecessary:
   // return
}
```
