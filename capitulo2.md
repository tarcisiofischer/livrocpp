# Capitulo 2: Sintaxe Básica

## 2.1. Variáveis

C++ é uma linguagem de programação estaticamente tipada. Isso significa que todas as variáveis possuem um tipo, e o tipo da variável não muda, até que ela deixe de existir (nos referimos a isso como "tempo de vida", ou "_lifetime_", de uma variável). Em C++, a definição de uma variável se dá da seguinte forma:

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

O tempo de vida de uma variável é delimitado por seu escopo. O escopo de uma variável é determinado pelo bloco que a contém, delimitado por chaves (`{}`). O exemplo anterior possui quatro variáveis, cada uma de um tipo diferente, e todas elas estão no escopo da função "main". Uma variável chega ao fim do seu tempo de vida ao final do escopo que a contém. Se uma variável está fora de qualquer escopo, ela é chamada de _variável global_.

Alternativamente, C++ moderno (do padrão C++11 em diante) traz uma sintaxe alternativa para definir o tipo das variáveis, por meio da palavra chave `auto`. Dessa forma, não é necessário explicitar o tipo das variáveis. Note que a variável ainda possui um tipo bem definido. A única diferença é que o tipo é determinado automaticamente em tempo de compilação, através de um processo chamado _inferência_:

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

Em C++, o tipo `string`, para representar textos, não é um tipo primitivo. Por isso, existe o tipo `std::string` na biblioteca padrão do C++ (_stdlib_). Para utilizá-lo, é necessário incluir o header `<string>`, da mesma forma que incluímos `<iostream>` anteriormente para podermos escrever na tela.

```
#include <string>

int main()
{
    std::string some_string = "my string";

    // ou, alternativamente

    using namespace std::string_literals;
    auto some_other_string = "other string"s;

    return 0;
}
```

Note que um literal de texto entre aspas duplas como `"my string"` não é do tipo `std::string`. Isto causa um pouco de confusão, e será melhor explicado adiante. Por ora, mantenha em mente as formas de declarar vistas acima.


## 2.2 Estruturas de controle

Estruturas de controle auxiliam a desenvolver algoritmos (sequências de passos para resolver determinado problema). A estrutura if..else if..else permite mudar o fluxo de execução de um programa, dependendo de uma condição pré-estabelecida. O exemplo abaixo introduz também uma forma de ler dados de input do usuário. Na linha 5, a variável age é inicializada com o valor 0. Porém, na linha 6, a função std::cin permite o usuário que estiver executando o programa a modificar o valor de age. Dessa forma, o real valor de age será conhecido apenas ao executar o programa.

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

## 2.4 Tipos definidos pelo usuário

Structs (estruturas) são uma forma de adicionar tipos novos ao programa (user defined types). São uma forma de adicionar mais semântica à grupos de variáveis que se relacionam de alguma forma.
No exemplo abaixo, uma estrutura de nome `Point` é definida entre as linhas 4 e 7. Ela possui dois membros: `x` e `y`, ambos do tipo primitivo `double`. Essas linhas definem um novo tipo de dado de nome `Point`, que pode ser utilizado em qualquer lugar do programa. As linhas 16 e 17 instanciam 2 variáveis com o novo tipo `Point`.

```
#include <iostream>
#include <cmath>

struct Point {
   double x;
   double y;
};

double calculate_distance(Point p1, Point p2)
{
   return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main()
{
   Point p1{1.1, 2.7};
   Point p2{3.7, 4.4};

   std::cout << "A distancia entre os pontos p1 e p2 é " << calculate_distance(p1, p2) << std::endl;

   return 0;
}
```

Assim como qualquer outro tipo de variável, é possível adicionar `Point` como parâmetro para funções, como é o caso do exemplo acima, na linha 9. A função `calculate_distance` necessita de dois parâmetros, `p1` e `p2`, ambos do tipo `Point` para ser invocada. Note que, ao invocar a função na linha 19, as duas variáveis `p1` e `p2` são copiadas para o escopo da função `calculate_distance`. Ou seja, se alterarmos os valores de `p1` e `p2` dentro do corpo da função `calculate_distance`, os valores de `p1` e `p2` presentes no escopo da função `main` não serão alteradas.


## 2.5 Referências

Referências permitem criar "apelidos" para variáveis, isto é, uma referência para uma variável acessa o valor daquela variável, nomeada de outra forma. Considere o código abaixo, onde é criada uma referência de nome "b" para uma variável de nome "a". Utiliza-se o simbolo "&" junto ao tipo da variável para declarar uma referência. Diferente de uma variável "comum", alterar o valor da referência altera o valor da variável referenciada. Portanto, no exemplo abaixo, o resultado vai ser a mensagem `a = 7, b = 7`.

```
#include <iostream>

int main()
{
    int a = 1;
    int& b = a;

    b = 7;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
```

Como uma referência é um "apelido" para outra variável, é impossível criar uma referência para um valor (Por exemplo, `int& b = 9;` não faz sentido, e ocasiona em um erro de compilação). É possível usar referências também na passagem de parâmetros de funções. Quando não são utilizadas referências nos parâmetros de uma função, as variáveis são copiadas para o escopo da função. Referências passadas por parâmetro e modificadas dentro do escopo de uma função alteram o valor da variável original de onde foi chamada, como mostra o exemplo abaixo.

```
#include <iostream>

void wont_change_data(int a)
{
    a = 1;
}

void will_change_data(int& a)
{
    a = 1;
}

int main()
{
    int my_a = 8;
    std::cout << my_a << std::endl;

    wont_change_data(my_a);
    std::cout << my_a << std::endl;

    will_change_data(my_a);
    std::cout << my_a << std::endl;
}
```

Outro exemplo pode observado no código abaixo. Imagine que `Matrix` é uma estrutura de dados que representa uma matriz 100x100. A função `sum_elements` soma todos os elementos dessa matriz. O loop na função `main` foi criado sintéticamente para representar muitas chamadas da função `sum_elements`. Para cada invocação da função `sum_elements`, uma instância da estrutura de dados `Matrix` é copiada para o contexto da função, apenas para somar o valor de cada um de seus elementos.

```
/**
 * Sum of elements in a given 100x100 Matrix.
 * :param Matrix matrix:
 * :returns double:
 */
double sum_elements(Matrix matrix)
{
    double sum = 0.;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main()
{
    // ...
    double total_sum = 0.;
    for (int i = 0; i < 1000000; ++i) {
        total_sum += sum_elements(matrix);
    }
    std::cout << "Total Sum = " << total_sum << std::endl;

    return 0;
}
```

Uma forma de evitar a cópia dessa estrutura de dados é utilizando uma referência para uma `Matrix`, ou seja, trocando a assinatura da função para `double sum_elements(Matrix& matrix)`. Apesar de resolver o problema das cópias desnecessárias, a solução mencionada não é ideal, pois passando uma referência à estrutura `Matrix`, os dados da estrutura podem ser modificados dentro do escopo da função. Normalmente, é interessante evitar funções com esse tipo de "efeito colateral" ("side-effects"), pois a medida que o projeto cresce, isso pode gerar um problema de mantenabilidade. Para ter noção do quanto essas cópias fazem diferença nesse caso, considere a comparação abaixo, extraída a partir de benchmark feito no site [Quick Bench](https://quick-bench.com/).

![Benchmark](images/benchmark-ref.png)

Existem sim alguns programas que usam referências como parâmetros de funções e modificam seus dados. Não há problemas em fazer isso, desde que seja bem documentado ou seja óbvio ao leitor. Por exemplo, no caso acima, não é esperado que uma função de nome `sum_elements` altere os elemento da matriz, porém em uma função chamada `void sum_one_to_all_elements_in(Matrix& m)` fica mais claro que todos os elementos da matriz serão alterados.

Uma alternativa para evitar o problema comentado é o uso do modificador `const`, que faz com que a "variável" em questão seja constante, ou seja, não possa ser alterada durante a execução do programa. Antes de partir para seu uso no caso da função `sum_elements`, considere o uso de `const` em um exemplo mais simples:

```
#include <iostream>

int main()
{
   double const a = 8;
   a = 9; // Compile error
}
```

O código acima não irá compilar. Isso por que a variável "a" é uma constante, ou seja, não se pode alterar seu valor, como se está tentando fazer na linha 6. Casos comuns de uso de `const` são, por exemplo, as variáveis matemáticas `PI` e `e`. O modificador `const` pode também ser utilizado em conjunto com referências, criando-se referências constantes, ou seja, não é possível alterar o valor da variável referenciada.

```
#include <iostream>

int main()
{
   double a = 8;
   double const& b = a;
   a = 9; // OK. a is non-const (b is also 9 now)
   b = 7; // Compile error. b is a const reference.
}
```

O código acima não irá compilar. O motivo é que não se pode alterar o valor de "a" por meio da referencia "b", pois ela é uma referência `const`. Um detalhe importante a se comentar, é que o modificador `const` se aplica sempre ao tipo à sua esquerda. Se não houver nada à esquerda, ele se aplica ao tipo à direita. Dessa forma temos:

- `double const& my_data`: Cria uma referência para um `const double`
- `const double& my_data`: Cria uma referência para um `const double` (Igual à anterior)
- `double &const my_data`: Erro de compilação, pois não faz sentido ter uma "referencia const", visto que referencias não são modificáveis

Por fim, voltando ao problema da matriz, quando escrevemos `double sum_elements(Matrix& matrix)`, evitamos que a matriz seja copiada, e isso é um ponto positivo, em termos de performance. Porém, introduzimos um possível problema: Se a matriz for modificada dentro do escopo da função `sum_elements`, então a matriz do escopo da função `main` também será modificada. Por convenção, não esperamos que ninguém vá de fato modificar os elementos da matriz naquela função. É possível garantir isso utilizando `const&`, isto é, se alguém por engano alterar a variável matrix de dentro da função `sum_elements`, um erro de compilação ocorrerá. A assinatura da função fica da seguinte forma: `double sum_elements(Matrix const& matrix)`, e nenhuma outra modificação é necessária.
