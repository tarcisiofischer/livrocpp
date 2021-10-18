## Map

`std::map` é uma estrutura de dados que permite mapear dois dados de forma eficiente. Ele é formado por vários pares de chave (`key`) e valor (`value`). É necessário explicitar os tipos de dados sendo mapeados, ou seja, `std::map<K, V>` mapeia dados do tipo `K` em dados do tipo `V`. Por exemplo, se `K=double` e `V=int`, então `std::map<double, int>` mapeia valores do tipo double em valores do tipo `int`. A sintaxe é como o exemplo:

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
