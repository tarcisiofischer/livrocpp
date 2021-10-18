## Vector

`std::vector` permite o programador a criar um vetor com um tamanho dinâmico de elementos. Em outras palavras, é uma estrutura que permite inserir e remover elementos de uma lista em tempo de execução. No exemplo abaixo, A linha 3 inclui o header `<vector>`, para que seja possível utilizar a estrutura de dados `std::vector`. A linha 17 cria uma instancia de um `vector`. Os elementos desse `vector` serão do tipo `Point`. Ou seja, não será possível colocar inteiros, doubles, ou variáveis de nenhum outro tipo nesse `vector`. O `vector` foi inicializado sem elementos e, nas linhas 19 e 20, dois elementos são adicionados utilizando o método `push_back`.

```cpp
#include <iostream>
#include <cmath>
#include <vector>
 
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
   std::vector<Point> points;
 
   points.push_back(Point{1.2, 3.4});
   points.push_back(Point{4.5, 5.6});
 
   std::cout << "A distância entre os pontos é " << calculate_distance(points[0], points[1]) << std::endl;
 
   return 0;
}
```

A linha 22 usa a função `calculate_distance`, mas passa como parâmetros os elementos cujos índices são 0 e 1 no `vector`. Tenha cuidado para nunca acessar o `vector` com indices que não foram populados. Para saber a quantidade de elementos de um vector, é possível utilizar o método `size()`. Para remover o último elemento adicionado, é possível utilizar o método `pop_back()`.
