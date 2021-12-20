## Map

`std::map` é a primeira estrutura de dados que será abordada nesse livro. Pense em uma estrutura de dados como uma `struct` que guarda informações para consultas, e que algumas estruturas organizam os dados de uma maneira específica para que as consultas sejam mais rápidas.

Toda estrutura de dados é diferente uma da outra, e mais apta para resolver um problema do que outro, por exemplo, todas as coisas que são feitas com `std::map` podem ser feitas com `std::vector` (estrutura exibida posteriormente), mas dependendo do que seja, fazer com `std::map` pode ser mais fácil e simples, ou mais difícil e complicado.

`std::map` é uma estrutura de dados que mapeia um dado à outro. Ele é formado por vários pares de chave (`key`) e valor (`value`), depois de montado, dada uma chave, a estrutura deverá retornar qual é o valor único que foi atribuído àquela chave.

Considere a seguinte tabela de dados como exemplo:

| Nome      | Idade |
|-----------|-------|
| `"Alice"` | 20    |
| `"Bruno"` | 30    |
| `"Carol"` | 40    |
| `"Júlia"` | 50    |
| `"Pedro"` | 50    |

Vamos criar um `std::map` vazio, adicionar cada linha dessa tabela, e então, dado um nome, quermos ter certeza que a estrutura vai retornar a idade correta.

```cpp
#include <iostream>
#include <map>
#include <string>

int main()
{
    // An empty map
    std::map<std::string, int> ages;
    // Adding the data
    ages["Alice"] = 20;
    ages["Bruno"] = 30;
    ages["Carol"] = 40;
    ages["Júlia"] = 50;
    ages["Pedro"] = 50;

    // Outputs: "Alice tem 20 anos."
    std::cout << "Alice tem " << ages["Alice"] << " anos.\n";

    // Outputs: "Pedro tem 50 anos."
    std::cout << "Pedro tem " << ages["Pedro"] << " anos.\n";

    ages["Pedro"] = 51;
    // "Pedro agora tem 51 anos."
    std::cout << "Pedro agora tem " << ages["Pedro"] << " anos.\n";


    return 0;
}
```

Para declarar essa estrutura, é necessário explicitar os tipos de dados das chaves e dos valores, com a seguinte sintaxe:

```cpp
std::map<K, V>
```

Isso representa um `map` que possui chaves do tipo `K` e valores do tipo `V`, no exemplo acima o mapa foi declarado da seguinte forma:

```cpp
std::map<std::string, int> ages;
```

Nesse caso, `K=std::string` e `V=int`, então `std::map<std::string, int>` mapeia pares de string e inteiros.

Também é possível iterar em todos os elementos do `map`:

```cpp
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
