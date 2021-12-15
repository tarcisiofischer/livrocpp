# namespaces

Considere o seguinte cenário: Você está ajudando no desenvolvimento de um software de um painel digital para uma loja.
O painel mostra mensagens de promoções primárias da loja e, agora, deseja-se adicionar um painel secundário para exibir
promoções secundárias. Você foi designado à implementar uma função que toma como parâmetro uma mensagem e à mostra no
novo painel. Para tal, você começa a escrever o código:

```cpp
void write(std::string const& message)
{
    // ...
}
```

Para sua surpresa, já existe uma outra função com exatamente a mesma assinatura, e você recebe o seguinte erro de
compilação: `error: redefinition of 'void write(string)'`. De fato, existe um problema de ambiguidade: Ambas funções
foram criadas para o mesmo propósito: escrever uma mensagem em um display. Porém, o display em questão é diferente
dependendo do contexto. Existem várias maneiras de resolver tal problema. Uma possibilidade é dividir as implementações
em `namespaces` diferentes.

Um `namespace` é uma estrutura que pode conter classes, funções e variáveis. Eles não servem apenas para desambiguar
uma função ou classe, mas também para organizar o projeto. Eles são estruturas opcionais, e não é raro encontrar
bibliotecas e aplicativos escritos em C++ que são implementados sem o uso de `namespaces`.

Para resolver o problema comentado, poderia-se escrever o código anterior da seguinte forma:

```cpp
namespace main_display {
    void write(std::string const& message)
    {
        // ... Implementação do display principal
    }
}

namespace secondary_display {
    void write(std::string const& message)
    {
        // ... Implementação do display secundário
    }
}
```

Para usar uma ou outra implementação, é necessário explicitar o `namespace` ao chamar a função, da seguinte forma:
`main_display::write("...exemplo...");`. Um código de exemplo é mostrado abaixo:

```cpp
int main()
{
    main_display::write("Mensagem no display principal");
    secondary_display::write("Mensagem no display secundário");

    return 0;
}
```

O `namespace` mais comum nos programas C++ é o `std` (namespace relacionado à biblioteca padrão). Inclusive, ele
apareceu já nos primeiros capítulos desse livro, para utilizar a função `cout`:

```cpp
#include <iostream>
 
int main()
{
    std::cout << "Ola mundo!" << std::endl;
    return 0;
}
```

No caso de você utilizar muitas funções e estruturas de dentro de um mesmo `namespace`, é possível utilizar `using` para
evitar a repetição do prefixo do namespace em questão, como no exemplo abaixo. Note, porém, que o uso de `using` no
escopo global é **desencorajado** em alguns casos, pois pode afetar parcelas de código indesejadamente. Esse ponto será
discutido novamente em capítulos posteriores desse livro.

```cpp
#include <iostream>

// Sugere-se evitar `using` global
// using namespace std;

int main()
{
    // `using` dentro do escopo de alguma função é preferível
    using namespace std;
    cout << "Ola mundo!" << endl;
    
    return 0;
}
```
