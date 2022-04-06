# Tipos definidos pelo usuário

Structs (estruturas) são uma forma de adicionar tipos novos ao programa (user-defined types). Eles fornecem mais semântica a grupos de variáveis que se relacionam de alguma forma, agrupando múltiplas _propriedades_ para que sejam usadas de uma vez.

No exemplo abaixo, uma estrutura de nome `Point` é definida entre as linhas 4 e 7. Ela possui dois membros: `x` e `y`, ambos do tipo primitivo `double`. Essas linhas definem um novo tipo de dado de nome `Point`, que pode ser utilizado em qualquer lugar do programa. As linhas 16 e 17 criam duas **instâncias** de duas variáveis com o novo tipo `Point`.

```cpp
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

   std::cout << "A distância entre os pontos p1 e p2 é " << calculate_distance(p1, p2) << std::endl;

   return 0;
}
```

Assim como qualquer outro tipo de variável, é possível utilizar o tipo `Point` como parâmetro para funções, como é o caso do exemplo acima, na linha 9.
A função `calculate_distance` necessita de dois parâmetros, `p1` e `p2`, ambos do tipo `Point` para ser invocada. Note que, ao invocar a função na linha 19, as duas variáveis `p1` e `p2` são copiadas para o escopo da função `calculate_distance`. Ou seja, se alterarmos os valores de `p1` e `p2` dentro do corpo da função `calculate_distance`, os valores de `p1` e `p2` presentes no escopo da função `main` não serão alteradas.

Note que, por `Point` ser um tipo como qualquer outro, é possível compor estruturas aninhadas. Por exemplo, considere o seguinte problema:
Você está desenvolvendo um jogo de plataforma, e precisa representar o personagem em um espaço bidimensional. O personagem possui uma
posição e um número de vidas. Utilizando a estrutura anterior para representar a posição, poderia-se escrever:

```cpp
using Life = unsigned int;

struct Player {
    Point position;
    Life life;
};
```

Como exemplo ilustrativo, utiliza-se aqui a palavra reservada `using` para criar um `type alias` (um "apelido" para um tipo qualquer).
Basicamente, dá-se um novo nome para um tipo que já existe. No exemplo acima, `Life` será equivalente ao tipo `unsigned int`, ou seja, um inteiro não negativo. Deste modo, toda vez que usarmos o tipo `Life`, estaremos criando, por trás dos panos, um `unsigned int`.

Outro modo de criarmos tipos definidos pelo usuário é por meio de _classes_, que veremos mais à frente.
