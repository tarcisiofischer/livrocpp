# Instruções

Não confunda instruções do C++ com instruções de uma ISA, instruções em C++ são conceitos de alto nível e servem para dividir a execução do código em etapas.

Existem vários tipos de instruções, as mais comuns sendo as instruções de expressão (_expression-statements_). Instruções de expressão são, simplesmente, operações como `x + 2`, `a + 5 * 3` e `pi = atan(i) * 4`, seguidas de um `;`. Ao declarar variáveis, nós utilizamos instruções de declaração (_declaration-statements_).

## Instruções compostas

Saber diferenciar todos os tipos de instrução é raramente necessário, mas as instruções compostas (_compound-statements_) merecem atenção. Instruções compostas agrupam zero ou mais instruções em uma só.

O corpo de uma função comum, por exemplo, é uma instrução composta:

```c
int main()
{ // Início da instrução composta
    int x = 2;
    int y = 3;
    int z = x + y;

    return 0;
} // Fim da instrução composta
```

Você verá, em frente, muitos outros casos em que há a necessidade de utilizar esse tipo de instrução.
