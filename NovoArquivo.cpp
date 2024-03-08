#include <iostream>
#include <vector>

class Bilheteria {
    std::vector<std::vector<bool>> poltronas;
    std::vector<int> precos = {50, 30, 15};
public:
    Bilheteria(int fileiras, int colunas) : poltronas(fileiras + 1, std::vector<bool>(colunas + 1, false)) {}

    bool reservarPoltrona(int fileira, int coluna) {
        if (fileira <= 0 || fileira > poltronas.size() - 1 || coluna <= 0 || coluna > poltronas[1].size() - 1) {
            std::cout << "Namero de poltrona invalido.\n";
            std::cout << fileira << std::endl;
            std::cout << coluna << std::endl;
            return false;
        }
        if (poltronas[fileira][coluna]) {
            std::cout << "Poltrona ja reservada.\n";
            return false;
        }
        poltronas[fileira][coluna] = true;
        std::cout << "Poltrona reservada com sucesso.\n";
        std::cout << fileira << std::endl;
        std::cout << coluna << std::endl;
        return true;
    }

    void mostrarOcupacao() {
        for (int i = 1; i < poltronas.size(); ++i) {
            for (int j = 1; j < poltronas[i].size(); ++j) {
                std::cout << (poltronas[i][j] ? '#' : '.');
            }
            std::cout << '\n';
        }
    }

    void mostrarFaturamento() {
        int ocupadas = 0;
        int faturamento = 0;
        for (int i = 1; i < poltronas.size(); ++i) {
            for (int j = 1; j < poltronas[i].size(); ++j) {
                if (poltronas[i][j]) {
                    ++ocupadas;
                    faturamento += precos[i / 5];
                }
            }
        }
        std::cout << "Quantidade de poltronas ocupadas: " << ocupadas << '\n';
        std::cout << "Faturamento: R$ " << faturamento << ",00\n";
    }
};

int main() {
	setlocale (LC_ALL,"");
    Bilheteria bilheteria(15, 40);
    int opcao, fileira, coluna;
    while (true) {
        std::cout << "0. Finalizar\n1. Reservar poltrona\n2. Mostrar ocupa��o\n3. Mostrar faturamento\n";
        std::cin >> opcao;
        switch (opcao) {
        case 0:
            return 0;
        case 1:
            std::cout << "Digite a fileira e a coluna: ";
            std::cin >> fileira >> coluna;
            bilheteria.reservarPoltrona(fileira, coluna);
            break;
        case 2:
            bilheteria.mostrarOcupacao();
            break;
        case 3:
            bilheteria.mostrarFaturamento();
            break;
        default:
            std::cout << "Opcao invalida.\n";
        }
    }
    return 0;
}
