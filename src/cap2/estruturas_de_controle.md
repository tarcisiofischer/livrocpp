## Estruturas de controle

### A estrutura "`if`" / "`else if`" / "`else`"

Estruturas de controle são construções da linguagem que nos permitem fazer coisas mais complexas do que apenas executar instruções de maneira sequencial. A primeira que veremos é a estrutura `if`/`else if`/`else`. Ela nos permite tomar decisões e executar instruções diferentes dada uma ou mais condições. No exemplo abaixo, temos um programa simples que informa o preço que um cliente deve pagar em um cinema onde:

- Clientes abaixo de 10 anos de idade não pagam.
- Clientes acima de 50 anos pagam meia-entrada.
- Demais clientes pagam o valor normal da entrada.

```cpp
#include <iostream>

int main()
{
   int age = 0;
   double const price = 20.0;
   std::cout << "Insira sua idade: ";
   std::cin >> age;

   std::cout << "Sua idade é " << age << '\n';

   if (age <= 10) {
       std::cout << "Você não precisa pagar!\n";
   } else if (age > 50) {
       std::cout << "Você paga apenas " << price/2 << "!\n";
   } else {
       std::cout << "Você paga " << price << ".\n";
   }
}
```

O exemplo acima introduz também uma forma de ler dados de entrada providenciados pelo usuário. Note que a variável `age` é inicializada com o valor 0. Porém, a linha `std::cin >> age;` permite ao usuário que estiver executando o programa informar um novo valor para `age`. Desta forma, o valor de `age` que será utilizado pelo programa será conhecido apenas durante a execução.

No exemplo, a linha 10 sempre será executada, depois que o usuário informar o valor de age. Porém, a linha 13 será executada apenas se (`if`) a variável `age` tiver um valor abaixo de 10. A construção `else if` permite fazer um novo teste caso o teste anterior falhe, ou seja, a condição não seja verdadeira. Por outro lado, utilizar apenas `else` faz com que, caso nenhuma das condições anteriores tenha sido satisfeita, o código dentro do bloco seguinte execute garantidamente. Experimente alterar o valor de `age` para fazer com que o programa siga cada uma das possibilidades.

### As estruturas `while` e `for`

As estruturas de controle `while` e `for` servem para repetir um bloco de código até que uma condição seja satisfeita. No exemplo abaixo, o programa pergunta se o usuário deseja aprender C++. Enquanto (`while`) a resposta não for `s` (sim) nem `n` (não), a mesma pergunta aparecerá para o usuário. Uma vez que o usuário der uma resposta válida, um `if` imprime a reação correspondente à resposta do usuário.

```cpp
#include <iostream>

int main()
{
   char answer = '\0';

   while (answer != 's' && answer != 'n') {
       std::cout << "Você deseja aprender C++? [s/n]: ";
       std::cin >> answer;
   }

   if (answer == 's') {
       std::cout << "Esse é o espírito!\n";
   } else {
       std::cout << "Que triste...\n";
   }
}
```

Em geral, usamos o laço `while` quando não existe uma definição clara de quantas vezes precisamos rodar o laço, apenas uma condição de continuidade que deve eventualmente tornar-se falsa.

O laço `for` adiciona legibilidade ao código quando temos uma inicialização e um passo que deve ser executado em toda iteração do laço. Tudo que é feito com um laço `for` pode também ser feito com um laço `while`, e vice versa. A diferença entre eles é que, em alguns casos, a leitura do código fica mais natural com um ou com outro. Ao contrário do `while`, o `for` se presta mais quando sabemos exatamente quantas vezes precisamos repetir as operações. No código abaixo, o laço `for` itera com valores de `i = a` até valor de `i = b`, somando 1 ao valor de `i` a cada iteração. Uma forma alternativa e mais compacta de escrever `i = i + 1` seria escrever `++i`.

```cpp
#include <iostream>

int main()
{
   int a = 0;
   int b = 0;

   std::cout << "Digite o valor de A: ";
   std::cin >> a;

   std::cout << "Digite o valor de B: ";
   std::cin >> b;

   int sum = 0;

   for (int i = a; i <= b; i = i + 1) {
       sum += i;
   }

   std::cout << "Sum [" << a << ", " << b << "] = " << sum << std::endl;

   return 0;
}
```
