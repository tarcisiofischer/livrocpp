# Biblioteca padrão do C++ (Parte 1)

A STL (Standard Template Library) é uma parte da “biblioteca padrão do C++”, ou seja, uma coleção de funções, estruturas e classes prontas para serem utilizadas. A coleção de funcionalidades é bastante grande, e não se pretende passar por todas elas nesse capítulo. Porém, a medida que o livro avança, serão introduzidas partes da biblioteca, que podem auxiliar a resolver problemas pontuais.

## 3.1 Vector

`std::vector` permite o programador a criar um vetor com um tamanho dinâmico de elementos. Em outras palavras, é uma estrutura que permite inserir e remover elementos de uma lista em tempo de execução. No exemplo abaixo, A linha 3 inclui o header `<vector>`, para que seja possível utilizar a estrutura de dados `std::vector`. A linha 17 cria uma instancia de um `vector`. Os elementos desse `vector` serão do tipo `Point`. Ou seja, não será possível colocar inteiros, doubles, ou variáveis de nenhum outro tipo nesse `vector`. O `vector` foi inicializado sem elementos e, nas linhas 19 e 20, dois elementos são adicionados utilizando o método `push_back`.

```
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


## 3.2 Map

`std::map` é uma estrutura de dados que permite mapear dois dados de forma eficiente. Ele é formado por vários pares de chave (`key`) e valor (`value`). É necessário explicitar os tipos de dados sendo mapeados, ou seja, `std::map<K, V>` mapeia dados do tipo `K` em dados do tipo `V`. Por exemplo, se `K=double` e `V=int`, então `std::map<double, int>` mapeia valores do tipo double em valores do tipo `int`. A sintaxe é como o exemplo:

```
#include <iostream>
#include <map>

int main()
{
    std::map<int, bool> my_map;
    my_map[3] = true;
    my_map[7] = false;

    for (auto const& [key, value] : my_map) {
        std::cout << key << ": " << value << std::endl;
    }

    std::cout << my_map[3] << std::endl;
    std::cout << my_map.at(3) << std::endl;

    // With [], values will be added if they are not present
    std::cout << my_map[9] << std::endl;
    // With .at(), will throw exception if value not present
    std::cout << my_map.at(8) << std::endl;

    return 0;
}
```

