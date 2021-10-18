# Capitulo 1: Um programa simples em C++

## Olá mundo: Uma versão pragmática

O objetivo deste capítulo é introduzir vários conceitos básicos de programação C++ para iniciantes, ao mesmo tempo. Para isso, inicia-se com o clássico código "Olá mundo", conforme abaixo. Apesar de simples, esse código tem muito à ensinar, como veremos. Copie o código abaixo para um arquivo de nome `ola_mundo.cpp`, e salve em algum diretório do seu sistema.

```cpp
#include <iostream>

int main()
{
   std::cout << "Olá Mundo!\n";
   return 0;
}
```

Em primeiro lugar, a diretiva `#include` é a forma de incluir em nosso código as declarações necessárias para utilizar código externo. Ao incluir o header `iostream`, temos acesso à função `cout`, dentro do namespace `std`, que serve para escrever dados na tela durante a execução do programa. Seguindo, encontramos a função `main`. Essa função define o ponto de partida de qualquer programa C++. Dentro da função `main`, encontramos a instrução `std::cout` seguida da mensagem "Olá Mundo", que será mostrada na linha de comando. Por fim, temos o retorno da função main. É importante retornar o valor `0`, que significa, por convenção, que o programa terminou com sucesso.

Para executar o programa, é preciso utilizar um programa chamado _compilador_, que executará um processo chamado _compilação_. Este processo é a tradução do código fonte para "código de maquina". No caso de C++, é a tradução do código escrito na linguagem para código executável por nossos computadores. Tente modificar o programa, trocando a mensagem, removendo partes do código e recompilando, verificando os erros que acontecem. Não tenha medo de errar e nem de gerar erros de compilação. Acredite, eles vão acontecer mesmo quando você estiver usando a linguagem com fluência.

Esta etapa é dependente do ambiente de trabalho que você está utilizando. Apenas para fins ilustrativos, os comandos abaixo mostram o processo de compilação em ambiente Linux, utilizando o GCC.

```
$ g++ -o ola_mundo ola_mundo.cpp
$ ./ola_mundo
Olá Mundo!
```

## Olá mundo: Uma versão completa

Apesar do capítulo anterior ser suficiente para um primeiro contato com C++, talvez não fique claro outros aspectos ortogonais à linguagem, tais como escolhas de organização do código e do aspecto cultural do código. Desta forma, nosso primeiro projeto começa utilizando a linha de comando para instalar as ferramentas necessárias para a criação de um projeto. Os comandos aqui utilizados serão focados na `command line interface` (cli) do Unix. Caso você utilize Windows, o Mingw pode ser utilizado.

### Configurações de ambiente

Nesta parte serão abordados os programas necessários para ter um "Olá mundo" funcional. O primeiro programa que precisamos instalar é o `git` - um sistema de versionamento de código. Seu propósito é que não precisemos perder tempo no futuro buscando informação sobre o código em e-mails, Google Docs ou pendrives (por exemplo). Iniciaremos um repositório git na pasta de projetos e iremos criar um projeto em C++ utilizando o **CMake**.

Se você utiliza:
* Mac
    - Instale o `XCode Command Line Tools`
* Windows
    - vá em `www.git-scm.com` e baixe o instalador para windows
* Linux / BSD
    - Utilize o gerenciador de pacotes da sua distribuição para instalar o git
        - Debian, Ubuntu e derivados: apt
        - Fedora e derivados: dnf
        - Arch e derivados: pacman
        - Outras: Verifique na documentação de sua distribuição como fazer a instalação

Após ter o `git` instalado, precisamos abrir uma área para nosso projeto. Abra um terminal, ou prompt de comandos. No Linux você tem as opções de `konsole`, `gnome-terminal`, `xterm`, `urxvt` e muitos outros. No Windows o programa vem junto com a instalação do `git`. Já no Mac, o programa se chama `terminal`, mas você pode também instalar um substituto melhor chamado `iterm2`.

Este livro segue a seguinte notação:

* Linhas iniciando por `$`: Usuário não-administrador
* Linhas iniciando por `#`: Usuário administrador
* `~`: Pasta 'inicial' (home) do usuário

Alguns comandos básicos para o terminal:

* `pwd`: Retorna o endereço da pasta que você está nesse momento
* `cd`: Muda de pasta ("Change Directory")
* `mkdir`: Cria uma pasta ("Make Directory")
* `touch`: Cria um arquivo
* `ls`: Lista os arquivos da pasta corrente
* `tree`: Exibe as pastas em forma de arvore

Sugere-se criar uma pasta de projetos dentro da pasta inicial do seu usuário, conforme exemplo:

```
$ mkdir Projetos
$ mkdir Projetos/OlaMundo
$ cd Projetos/OlaMundo
$ pwd
/home/user/Projetos/OlaMundo
```

Utiliza-se o git para criar um novo repositório dentro da pasta recém criada (veja abaixo). Você pode verificar a existência de uma nova pasta chamada `.git` utilizando o comando `ls`. As opções `-al` servem para exibir arquivos ocultos (`-a`) e para exibir os arquivo em uma lista vertical (`-l`).

```
$ pwd
/home/user/Projetos/OlaMundo
$ git init .
Initialized empty Git repository in /home/user/Projetos/OlaMundo/.git/
$ ls -al
total 12
drwxr-xr-x 3 user user 4096 Nov  9 16:53 .
drwxr-xr-x 3 user user 4096 Nov  9 16:48 ..
drwxr-xr-x 7 user user 4096 Nov  9 16:51 .git
```

Neste momento, é importante iniciar uma estrutura básica de projeto, com arquivos que não necessariamente compõem o código fonte. Mesmo sendo um código exemplo, algumas padronizações são importantes em qualquer código porque assim outros programadores saibam por onde começar a olhar o seu projeto. Crie o arquivo `README.md` (O nome `README.md` é reconhecido por diversas ferramentas de gerenciamento de código). O formato `.md` significa `Markdown` e é um formato de texto puro que tem alguma informação sobre a formatação do conteúdo.

```
$ touch README.md
$ ls -la
total 12
drwxr-xr-x 3 user user 4096 Nov  9 17:11 .
drwxr-xr-x 3 user user 4096 Nov  9 16:48 ..
drwxr-xr-x 7 user user 4096 Nov  9 17:01 .git
-rw-r--r-- 1 user user    0 Nov  9 17:11 README.md
```

Utilize algum "editor de texto pra programação" pra escrever algo no arquivo criado. Evite editores como Word, Office, LibreOffice ou Wordpad, pois esses não são editores de texto cru, e portanto não trabalham normalmente com arquivos de texto simples. Também evite editores de texto simples demais, como o Notepad. Alguns editores sugeridos:

* Visual Studio Code: https://code.visualstudio.com
* Atom: https://www.atom.io
* Kate: https://www.kate-editor.org
* Emacs: https://www.gnu.org/emacs
* Vim: https://www.vim.org

O arquivo deve conter informações básicas do projeto, como seu titulo, uma breve descrição, autor, informações de como compilar o projeto, bibliotecas e ferramentas dependentes, e qualquer outras informações relevantes para outros desenvolvedores. Exemplo:

```
# Projeto: Olá mundo

Esse projeto serve como esboço do que é necessário para começar
a trabalhar com C++ no mundo real.
```

o `#` Cria uma linha de cabeçalho, que é o título do arquivo, e parágrafos são espaçados com uma linha em branco. Este livro está sendo escrito em markdown, e o resultado final é o que você está lendo! Adicione o arquivo ao seu repositório:

```
$ pwd
/home/user/Projetos/OlaMundo
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

nothing added to commit but untracked files present (use "git add" to track)
```

Perceba a linha `Untracked files:`, essa é a lista de arquivos que o git ainda não está gerenciando. Precisamos adicionar o arquivo no índice de arquivos gerenciados pelo git:

```
$ pwd
/home/user/Projetos/OlaMundo
$ git add README.md

$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md
```

O comando executado não adicionou nada ao repositório, apenas adicionou o arquivo à `Staging Area`, que é a área onde os arquivos ficam preparados para serem adicionados em uma revisão. A seguir, commitamos o arquivo com uma mensagem descrevendo o que foi feito, da seguinte forma:

```
$ git commit -m "Adicionado arquivo Readme."
[master (root-commit) 478f2b6] Adicionado arquivo Readme.
 1 file changed, 6 insertions(+)
 create mode 100644 README.md
```

A configuração do projeto pode ser feita utilizando o `CMake`. O `CMake` é um gerenciador padrão para projetos em C++, e serve para traduzir as informações do código fonte, a sua organização em arquivos, e quais subprojetos você está fazendo dentro de seu código, para as ferramentas da linguagem - como `compiladores`, `debuggers`, `IDEs`. Assim, prepare um arquivo chamado `CMakeLists.txt` juntamente com uma pasta chamada `src` (source), onde ficará o código fonte do projeto.

```
$ pwd
/home/user/Projetos/OlaMundo
$ touch CMakeLists.txt
$ mkdir src
$ touch src/main.cpp
$ touch src/CMakeLists.txt
```

O sistema de arquivos no momento é esse:

```
.
├── CMakeLists.txt
├── README.md
└── src
    ├── CMakeLists.txt
    └── main.cpp
```

Perceba que existem 2 arquivos `CMakeLists.txt`. O que está na pasta raiz do projeto irá definir as configurações de base, e irá adicionar a pasta `src` no projeto. O conteúdo do arquivo na pasta raiz deve ser conforme segue:

```
cmake_minimum_required(VERSION 3.19)
project(OlaMundo CXX)

add_subdirectory(src)
```

Onde a primeira linha define a versão minima de CMake necessária para trabalhar com o projeto. A segunda linha especifica o nome do projeto para o CMake. A última linha adiciona a pasta `src` ao projeto. Nessa pasta, encontra-se outro arquivo `CMakeLists.txt`, contendo configurações de compilação.

```
add_executable(HelloWorld)

target_sources(
    HelloWorld
    PRIVATE
        main.cpp
)

target_compile_features(
    HelloWorld
    PRIVATE
        cxx_std_17
)
```

O comando `add_executable` determina que esse projeto irá gerar um executável `HelloWorld`. Esse executável será gerado a partir da compilação dos arquivos determinados em `target_sources` (Ou seja, o arquivo `main.cpp`). Por fim, `target_compile_features` especifica as "features" necessárias para produzir o executável. No exemplo, utiliza-se a versão C++17 para a compilação do projeto. Sugere-se verificar a tabela encontrada no [https://en.cppreference.com/w/cpp/compiler_support](cppreference) para verificar as features disponíveis em cada versão do C++, para os compiladores mais comuns. Por fim, o conteúdo do arquivo `src/main.cpp` é mostrado abaixo.

```cpp
#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "Olá mundo!\n";
    return EXIT_SUCCESS;
}
```

A única diferenca deste código para milhares de códigos de outros livros é a adição do header `cstdlib` para o `EXIT_SUCCESS`. `cstdlib` possui `EXIT_SUCCESS` e `EXIT_FAILURE` para indicar quando algo deu errado ou não, e mesmo que não modifique o funcionamento do código (`EXIT_SUCCESS` é definido como `0`), é uma forma de explicitar o valor de retorno ao leitor.

Para determinar como o CMake irá configurar nossos projetos, é sugerido criar uma configuração base. A partir da versão 3.19, o `CMake` possui um comando `--preset` que utiliza uma configuração pre-determinada. Crie um arquivo chamado `CMakePresets.json`, na pasta raiz do projeto:

```
{
    "version": 1,
    "cmakeMinimumRequired": {
      "major": 3,
      "minor": 19,
      "patch": 0
    },
    "configurePresets": [
        {
            "name": "debug",
            "displayName": "Compilacao Debug",
            "description": "Compila em modo debug usando make",
            "generator": "Unix Makefiles",
            "binaryDir": "${sourceDir}/build/debug",
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Debug"
            }
        },
        {
            "name": "release",
            "displayName": "Compilacao Release",
            "description": "Compila em modo release utilizando o Ninja",
            "generator": "Ninja",
            "binaryDir": "${sourceDir}/build/release",
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Release"
            }
        }
    ]
}
```

Com essa configuração criamos dois geradores:

- Debug (Utilizando Unix Makefiles): A escolha do Unix Makefiles para o gerador de Debug é por ele ser sequencial, onde cada arquivo espera sua vez para ser compilado, facilitando a identificação de erros.
- Release (Utilizando Ninja): A escolha do Ninja possibilita uma compilação paralela.

Por fim, para configurar o projeto utilizando o preset escolhido:

```
$ pwd
/home/user/Projetos/OlaMundo
$ ls
CMakeLists.txt  CMakePresets.json  README.md  src
$ cmake . --list-presets
Available presets:

  "debug"   - Compilacao Debug
  "release" - Ninja

$ cmake . --preset=debug
Preset CMake variables:

  CMAKE_BUILD_TYPE="Debug"

-- The C compiler identification is GNU 10.2.0
-- The CXX compiler identification is GNU 10.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/user/Projetos/helloworld/build/debug
```

A última linha indica onde os arquivos de build do projeto foram gerados. Esta se refere à linha definida em `binaryDir` no arquivo de preset. Para compilar o programa, deve-se executar `cmake --build`. Por exemplo, para compilar o projeto em debug:

```
$ cmake --build ./build/debug
Scanning dependencies of target HelloWorld
[ 50%] Building CXX object src/CMakeFiles/HelloWorld.dir/main.cpp.o
[100%] Linking CXX executable HelloWorld
[100%] Built target HelloWorld
```

O objetivo desse capítulo foi dar uma longa introdução à C++ considerando várias ferramentas comuns em ambiente de trabalho profissional. Para maiores detalhes em relação às ferramentas, sugere-se buscar as documentação das mesmas, pois a explicação detalhada de cada uma foge do escopo desse livro.
