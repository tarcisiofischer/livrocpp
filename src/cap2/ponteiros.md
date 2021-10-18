## Ponteiros e smart pointers

Quando definimos uma variável em um programa C++, ela é alocada em uma posição de memória do computador. Um "endereço" é a localização em memória virtual de uma variável.

Apenas para fins ilustrativos, imagine que toda a memória do seu computador é uma grande tabela. Cada item da tabela possui um endereço e um valor, como no exemplo abaixo. O código de exemplo captura o endereço da variável `a` e o coloca como valor da variável `b`: A linha 6 cria a variável `b`, do tipo `int*`, e inicializa essa variável com o endereço de memória da variável `a`.

```cpp
#include <iostream>
 
int main()
{
   int a = 1;
   int* b = &a;
 
   std::cout << b << std::endl;
 
   return 0;
}
```

```
| Endereço  | Valor     | Variável associada |
|---        |---        |---                 |
| 0x7ff0    | 1         | a                  |
| 0x7ff4    | 0x7ff0 	| b                  |
```

Os endereços na tabela estão em hexadecimal, pois é a forma comum de representar endereços de memória. São valores meramente ilustrativos, de forma que, caso você execute o programa no seu computador, irá ter resultados diferentes.

Apesar do uso do mesmo simbolo (`&`), nesse caso `&a` não é uma referência. Essa distinção é importante: Caso `&` esteja ao lado de um tipo (`int`, `double`, `Point`, etc...) tem-se uma referência. Por outro lado, caso `&` esteja ao lado do nome de uma variável (como no caso acima), lê-se "endereço de..." (no exemplo, "endereço de `a`").

O operador `*` aplicado à uma variável cujo tipo é um ponteiro, retorna o valor apontado por aquela variável, da seguinte forma:

```cpp
#include <iostream>
 
int main()
{
   int a = 1;
   int* b = &a;
   *b = 9;
   std::cout << a << std::endl;
   std::cout << b << std::endl;
   std::cout << *b << std::endl;
   return 0;
}
```

As variáveis criadas até agora nos exemplos desse livro são todas criadas numa região de memória denominada __stack__. O gerenciamento dessa memória é feito automaticamente, ou seja, as variáveis são criadas e alocadas na região da stack ao entrar em determinado escopo e, ao sair do mesmo, as variáveis são automaticamente removidas.

Outra forma de alocar memória é por meio das funções `malloc` e `new`. Em C++, sugere-se sempre utilizar `new` para alocação dinâmica de memória, ao invés de `malloc`, pois para instâncias de classes o `new` chama o construtor, fazendo a inicialização da variável, como será visto em capitulos posteriores.

Variáveis alocadas com `new` e `malloc` são colocadas em uma região de memória denominada __heap__. Diferente da stack, essas variáveis não são removidas automaticamente ao sairem do escopo corrente. O gerenciamento do tempo de vida desse tipo de variável deve ser feito pelo programador. O programador deve devolver a memória ao sistema operacional após término de uso da variável por meio da função `delete`, como no exemplo abaixo:

```cpp
#include <iostream>
 
int main()
{
   int* a = new int(3);
   std::cout << "a = " << *a << std::endl;
   delete a;
 
   return 0;
}
```

A linha 5 faz a alocação dinâmica de uma variável do tipo int, inicializada com valor 3, e atribui o endereço dessa variável alocada para a variável a de tipo `int*`. A linha 6 mostra o valor apontado por a. A linha 7 deleta (devolve a memória) alocada na linha 5. Não deve-se utilizar uma variável depois que foi feito a deleção da mesma. No caso de sistemas operacionais de propósito geral, como Windows e Linux, toda a memória alocada que não foi deletada é automaticamente devolvida no momento que o programa termina.

Gerenciar memória da heap não é um problema trivial. O mal gerenciamento da memória pode ocasionar em uma excessiva utilização da memória RAM, como é o caso dos vazamentos de memória (__memory leaks__), que é quando o programador "esquece" de devolver a memória.

Smart pointers são estruturas de dados que auxiliam no gerenciamento de dados alocados na heap. Basicamente, a estrutura aloca a variável na heap e, ao não ser mais utilizada, remove automaticamente a mesma. O exemplo abaixo é trivial, e apenas mostra o funcionamento da infraestrutura, mas não consegue captar o valor de seu uso. O uso de ponteiros e alocação dinâmica é especialmente relevante nos casos de interfaceamento com bibliotecas de baixo nível (por exemplo, funções C), ou no caso de uso de polimorfismo em programação orientada a objetos em C++, tema que será discutido posteriormente nesse livro.

```cpp
#include <iostream>
#include <memory>

int main()
{
   auto a = std::make_unique<int>(7);
 
   std::cout << "a = " << *a << std::endl;

   // delete will be automatically done
}
```
