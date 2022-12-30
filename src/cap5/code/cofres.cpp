// NOTE: Não utiliza switch pois o livro ainda não introduziu

// ANCHOR: all
// ANCHOR: includes
#include <cstdlib> // EXIT_SUCCESS
#include <iostream>
// ANCHOR_END: includes

// ANCHOR: cofre
class Cofre
{
    int valor;

public:
    void Depositar(int val) { valor += val; }

    int Esvaziar()
    {
        int valor_old{valor};
        valor = 0;
        return valor_old;
    }
};
// ANCHOR_END: cofre

// ANCHOR: main
int main()
{
    Cofre cof{};

    while (true)
    {
        std::cout << "Selecione uma opção:\n"
                     "\t(D)epositar R$ 5\n"
                     "\t(E)svaziar\n"
                     "\t(S)air\n\n";

        char op;
        if (!(std::cin >> op))
            break;

        if (op == 'd' || op == 'D')
            cof.Depositar(5);
        else if (op == 'e' || op == 'E')
            std::cout << "O cofre tinha R$ " << cof.Esvaziar() << ". ";
        else if (op == 's' || op == 'S')
            break;
        else
            std::cout << "Opção inválida. ";
    }

    return EXIT_SUCCESS;
}
// ANCHOR_END: main
// ANCHOR_END: all
