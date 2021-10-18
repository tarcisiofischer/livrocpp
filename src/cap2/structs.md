## Tipos definidos pelo usuário

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
