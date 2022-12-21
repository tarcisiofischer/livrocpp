# Objetos

**Não se confunda. Este capítulo utiliza o termo _objeto_ no contexto geral de
programação orientada a objetos. Em C++ esse termo possui outro significado, mas
não nos aprofundaremos nele agora.**

Na programação orientada a objetos (POO), funções e dados podem ser unidos para
formar o que chamamos objetos. Comumente, essas funções são chamadas _métodos_,
e esses dados são chamados _campos_. Enquanto na programação procedural uma
função normalmente tem acesso apenas aos seus argumentos e ao estado global do
programa, em POO um método tem, adicionalmente, acesso ao objeto ao qual
pertence.

Como exemplo, imagine uma função _depositar_ que deposita dinheiro em um cofre.
Para funcionar, ela precisa saber quanto dinheiro e em qual cofre depositar.
Essas informações podem ser enviadas como dois parâmetros: cofre e quantia. Para
depositar R$ 10 no cofre _c_, precisamos chamar a função e fornecer os
argumentos _c_ e 10. Na linguagem C, isso seria `depositar(c, 10)`. Isso é um
exemplo de programação procedural.

Em POO, _c_ seria um objeto contendo o método _depositar_ e o campo _v_ (que
representa o valor total armazenado). Como um método tem acesso ao seu objeto,
não é necessário fornecer _c_ ou _v_; apenas o valor 10. Em C++ isso seria
`c.depositar(10)`. O método, então, incrementaria o campo _v_ de _c_ (`c.v`)
em 10.

Enquanto na programação procedural não há associação concreta entre _c_ e
_depositar_, em POO um objeto está fortemente ligado às operações que podem ser
realizadas com ele. Adicionalmente, o método _depositar_ não pode ser acessado
sem _c_. Isso reduz o número de identificadores em um programa e a chance de
dois nomes entrarem em conflito: outro objeto pode ter um método com o mesmo
nome, sem causar nenhum problema.
