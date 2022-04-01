# Instruções

Instruções em C++ são conceitos de alto nível e servem para dividir a execução do código em etapas. Elas não devem ser confundidas com as instruções de um processador.

Existem vários tipos de instruções, as mais comuns sendo as instruções de expressão (_expression statements_). Instruções de expressão, também chamadas expressões, são operações básicas como `x + 2`, `a + 5 * 3` e `pi = atan(i) * 4`, seguidas de um `;`. Ao declarar variáveis, nós utilizamos instruções de declaração (_declaration statements_), também chamadas declarações.

## Instruções compostas

Saber diferenciar todos os tipos de instrução é raramente necessário, mas as instruções compostas (_compound statements_) merecem atenção. Instruções compostas agrupam zero ou mais instruções em uma só.

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

Você verá, mais pra frente, muitos outros casos em que há a necessidade de utilizar esse tipo de instrução.
