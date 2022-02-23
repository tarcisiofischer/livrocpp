Array
===

Um `std::array` é um container com um número pré-definido de dados de um certo tipo. O tipo e o tamanho do array devem
ser conhecidos em tempo de compilação. Isso significa que você não pode aumentar o tamanho do array a partir de um input
de usuário, por exemplo.

Uma das vantagens em utilizar `std::array` ao invés de arrays "crus" (por exemplo, `int[3]`), é que você pode passar `std::array`
como argumentos de funções, e retorna-los sem complicações. Além disso, `std::array` possui métodos de acesso à dados do array e algumas
operações auxiliares sobre ele.

Para declarar e definir um `std::array`, basta escolher um tipo (e.g. `int`, `float`, etc...) e um tamanho, conforme
exemplo abaixo:

```c++
#include <array>
#include <iostream>

int main()
{
    // Inicializa um array com 3 elementos. Os valores são '1', '2' e '3'.
    auto my_arr = std::array<int, 3>{1, 2, 3};
    for (int i = 0; i < my_arr.size(); ++i) {
        std::cout << "my_arr[" << i << "] = " << my_arr[i] << "\n";
    }

    // Preenche todo o array com o valor '42'    
    my_arr.fill(42);
    for (int i = 0; i < my_arr.size(); ++i) {
        std::cout << "my_arr[" << i << "] = " << my_arr[i] << "\n";
    }

    return 0;
}
```
