# Capitulo 1: Um programa simples em C++

O objetivo desse capítulo é introduzir vários conceitos básicos de programação C++ para iniciantes, ao mesmo tempo. Para isso, inicia-se com o clássico código "Olá mundo", conforme abaixo. Apesar de simples, esse código tem muito à ensinar, como veremos. Copie o código abaixo para um arquivo de nome `ola_mundo.cc`, e salve em algum diretório do seu sistema.

```
#include <iostream>
 
int main()
{
   std::cout << "Olá Mundo!" << std::endl;
   return 0;
}
```

Em primeiro lugar, a diretiva `#include` é a forma de incluir em nosso código as declarações necessárias para utilizar código externo. Ao incluir o header `iostream`, temos acesso à função `cout`, dentro do namespace `std`, que serve para escrever dados na tela durante a execução do programa. Seguindo, encontramos a função `main`. Essa função define o ponto de partida de qualquer programa C++. Dentro da função `main`, encontramos a instrução `std::cout` seguida da mensagem "Olá Mundo", que será mostrada na linha de comando. Por fim, temos o retorno da função main. É importante retornar o valor `0`, indicando que o programa terminou com sucesso.

Para executar o programa, é preciso utilizar um programa chamado compilador, que executará um processo chamado compilação. A compilação é a tradução do código fonte para "código de maquina". Nesse caso, é a tradução do código escrito em linguagem C++ para código processável por nossos computadores. Tente modificar o programa, trocando a mensagem, removendo partes do código e recompilando, verificando os erros que acontecem. Não tenha medo de errar e nem de gerar erros de compilação. Acredite, eles vão acontecer mesmo quando você chegar a ser um usuário mais avançado!

Essa etapa é dependente de ambiente de trabalho que você está inserido. Apenas para fins ilustrativos, os comandos abaixo mostram o processo de compilação em ambiente Linux, utilizando o GCC.

```
$ g++ -o ola_mundo ola_mundo.cc
$ ./ola_mundo
Olá Mundo!
```


