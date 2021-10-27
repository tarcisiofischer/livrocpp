Gerenciamento de pacotes
===

Como visto, o processo de compilação passa por diferentes estágios até a criação de um arquivo executável. A separação
de funções, variáveis, constantes e outras entidades em artefatos (arquivos `.hpp`, `.a`, `.so` etc...) possibilita o
compartilhamento de código.

Por exemplo, se um programador A cria um _módulo_ de um software escrito em C++ que é capaz de criar uma janela
(interface gráfica), esse mesmo módulo pode ser utilizado por um programador B em outro projeto, desde que o programador A
tenha utilizado alguma das ferramentas apresentadas nessa seção.

Uma possibilidade, seria de o programador A ter criado uma biblioteca estática e prover esses arquivos binários e os arquivos
`.hpp` associados para o programador B. Dessa forma, o programador A pode criar um _pacote_, contendo a biblioteca que
pode ser enviado ao programador B, e que contém todos os arquivos necessários para que o programador B possa criar
seus programas.

Alguns exemplos de bibliotecas incluem: Qt (criação de programas com interface gráfica), Boost (contém
várias funções auxiliares), GoogleTest (automatização de testes), entre muitas outras.

O problema é que, em geral, para gerenciar e utilizar essas bibliotecas, normalmente o programador precisa ter algum
conhecimento específico da biblioteca (normalmente obtém-se o conhecimento por meio da leitura dos manuais de cada uma
delas). Uma alternativa interessante para utilizar as bibliotecas é o uso do software `CMake`, abordado em outra seção
desse livro.

Um segundo problema que ocorre é que é possível que as bibliotecas tenham sido criadas utilizando outras bibliotecas.
Essa sequência de dependências pode ocasionar em problemas de compilação e execução que são dificeis de se lidar. Daí
vem a necessidade de um gerenciador de pacotes. Gerenciadores de pacote são ferramentas que auxiliam no processo de
download, automatizam o processo de instalação, e cuidam das dependências entre os pacotes e o seu programa.

O intuito dessa seção não é fazer propaganda nem ensinar uma ferramenta específica. Ao invés disso, apenas apontam-se os
problemas e algumas possíveis ferramentas que podem ser utilizadas para resolve-los, que incluem:

- Conan
- Conda
- apt - Advanced Package Tool
- vcpkg
