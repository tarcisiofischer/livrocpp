# Capitulo 2: Sintaxe Básica

## 2.1. Variáveis

C++ é uma linguagem de programação estaticamente tipada. Isso significa que todas as variáveis possuem um tipo, e o tipo da variável não muda, até o fim de sua vida. Em C++, a definição de uma variável se dá da seguinte forma:

```
int main()
{
    int some_int = 8;
    float some_float = 9.2;
    char some_char = 'a';
    bool some_bool = true;

    return 0;
}
```

O tempo de vida de uma variável é delimitado por seu escopo. O escopo de uma variável é determinado pela última abertura de chaves mais próxima. O exemplo anterior possui quatro variáveis, cada uma de um tipo diferente, e todas elas estão no escopo da função "main". Toda variável é destruída quando sai do escopo que a contém. Se uma variável está fora de qualquer escopo, ela é chamada de variável global.

Alternativamente, C++ moderno traz uma sintaxe alternativa para definir o tipo das variáveis, por meio da palavra chave `auto`. Dessa forma, não é necessário explicitar o tipo das variáveis. Note que a variável ainda possui um tipo bem definido. A única diferença é que o tipo é determinado automaticamente em tempo de compilação:

```
int main()
{
    auto some_int = 8;
    auto some_float = 9.2;
    auto some_char = 'a';
    auto some_bool = true;

    return 0;
}
```

O tipo `string` não é um tipo primitivo no C++. Dessa forma, para utilizar uma `string`, é necessário incluir o header `<string>` da biblioteca padrão do C++ (STL - Standart Template Library).

```
int main()
{
    std::string some_string = "my string";
    auto some_other_string = "other string";

    return 0;
}
```

## 2.2 Estruturas de controle

Estruturas de controle auxiliam a desenvolver algoritmos (sequencias de passos para resolver determinado problema). A estrutura if..else if..else permite mudar o fluxo de execução de um programa, dependendo de uma condição pré-estabelecida. O exemplo abaixo introduz também uma forma de ler dados de input do usuário. Na linha 5, a variável age é inicializada com o valor 0. Porém, na linha 6, a função std::cin permite o usuário que estiver executando o programa a modificar o valor de age. Dessa forma, o real valor de age será conhecido apenas ao executar o programa.

```
#include <iostream>
 
int main()
{
   int age = 0;
   std::cin >> age;
 
   std::cout << "Sua idade é " << age << std::endl;
   if (age <= 12) {
       std::cout << "Você é uma criança!" << std::endl;
   } else if (age > 50) {
       std::cout << "Você é velho!" << std::endl;
   } else {
       std::cout << "Tenha um bom dia." << std::endl;
   }
 
   return 0;
}
```

No exemplo, a linha 8 sempre será executada, depois de o usuário colocar o valor de age. Porém, a linha 11 será executada apenas se (if) a variável age tiver um valor superior à 50. Teste o programa com vários valores de idade. Em específico, observe os casos onde age = 12 e age = 50.

As estruturas de controle `while` e `for` servem para repetir um bloco de código até que uma condição seja satisfeita. No exemplo abaixo, o programa pergunta se o usuário deseja aprender C++. Enquanto (`while`) a resposta não for `s` (sim) nem `n` (não), a mesma pergunta aparecerá para o usuário.

```
#include <iostream>
 
int main()
{
   char answer = 0;
   while (answer != 's' && answer != 'n') {
       std::cout << "Você deseja aprender C++? [s/n]: ";
       std::cin >> answer;
   }
 
   if (answer == 's') {
       std::cout << "Esse é o espírito!" << std::endl;
   } else {
       std::cout << "Que triste..." << std::endl;
   }
 
   return 0;
}
```

O laço “for” é apenas uma facilidade de execução, que acaba adicionando mais legibilidade ao código, colocando tanto a inicialização quanto o teste de continuidade e uma atualização de uma variável-alvo na mesma linha. Ou seja, tudo que é feito com um laço "for" pode também ser feito com um laço "while" e vice versa. A diferença é que, em alguns casos, a leitura do código fica mais natural com um ou com outro. No código abaixo, o laço for itera com valores de `i = a` até valor de `i = b`, somando 1 ao valor de `i` a cada iteração. Uma forma alternativa e mais compacta de escrever `i = i + 1` seria escrever `i++`.

```
// Calculate the sum of the natural numbers that are present in a given interval [A, B] 
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

## 2.3 Funções

Para deixar partes do programa reutilizável, ou para adicionar legibilidade ao código, utilizamos funções. Funções extraem parcelas do código para fora do local onde ela é utilizada. Funções podem ou não receper parâmetros, que são usados para levar informações de um escopo para outro. Os parâmetros são, por padrão, cópias das variáveis que são levadas ao escopo da função invocada. Funções possuem também um valor de retorno, que possibilita capturar uma variável concebida dentro do escopo da função para o local onde ela foi invocada. Abaixo um exemplo de função:

```
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

No código acima, foi definida uma função `calculate_sum`, que efetua a soma dos valores entre `a` até `b`, inclusive, e retorna essa soma. O tipo de retorno de uma função é determinado em sua assinatora. A assinatura de uma função é o conjunto contendo seu nome, seu tipo e seus parâmetros, por exemplo, `int calculate_sum(int a, int b)`. As funções devem ser pelo menos declaradas antes de serem utilizadas. Por exemplo, se movermos a definição da função calculate\_sum para baixo da função main, teriamos um erro de compilação. Existe uma distinção entre declarar uma função e definir uma função. Declarar uma função é apenas mostrar que ela existe, sem determinar seu funcionamento (Ou seja, sem adicionar o corpo de código dela). Definir uma função é adicionar um corpo de código à uma declaração. No exemplo acima, estamos definindo a função calculate\_sum. Um exemplo de separação entre a declaração e a definição de função é mostrado abaixo.

```
#include <iostream>
 
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
 
int calculate_sum(int a, int b)
{
   int sum = 0;
   for (int i = a; i <= b; ++i) {
       sum += i;
   }
   return sum;
}
```

Caso a função não retorne nenhum valor, é possível utilizar a palavra reservada `void`:

```
void say_hello()
{
   std::cout << "Ola Mundo!" << std::endl;
}
```

