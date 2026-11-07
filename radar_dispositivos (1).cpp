#include <iostream>
using namespace std;

int main() {
    int estado[10];
    char entrada[100];
    bool valido;
    int n = 0;
    int ativos = 0;
    int inativos = 0;
    double percentual;

    cout << "=== RADAR DE DISPOSITIVOS DA REDE (SIMULACAO) ===" << "\n";

    valido = false;
    while (valido == false) {
        cout << "Quantidade de dispositivos (1 a 10): ";
        cin >> entrada;
        if (entrada[0] >= '1' && entrada[0] <= '9' && entrada[1] == '\0') {
            n = entrada[0] - '0';
            valido = true;
        } else if (entrada[0] == '1' && entrada[1] == '0' && entrada[2] == '\0') {
            n = 10;
            valido = true;
        } else {
            cout << "Entrada invalida! Digite apenas um numero de 1 a 10." << "\n";
        }
    }

    for (int i = 0; i < n; i++) {
        valido = false;
        while (valido == false) {
            cout << "Estado do dispositivo " << i + 1 << " (1 = ativo, 0 = inativo): ";
            cin >> entrada;
            if ((entrada[0] == '0' || entrada[0] == '1') && entrada[1] == '\0') {
                estado[i] = entrada[0] - '0';
                valido = true;
            } else {
                cout << "Entrada invalida! Digite apenas 0 ou 1." << "\n";
            }
        }
    }

    cout << "\n" << "--- Estados registrados ---" << "\n";
    for (int i = 0; i < n; i++) {
        cout << "Dispositivo " << i + 1 << ": ";
        if (estado[i] == 1) {
            cout << "ATIVO" << "\n";
        } else {
            cout << "INATIVO" << "\n";
        }
    }

    for (int i = 0; i < n; i++) {
        if (estado[i] == 1) {
            ativos = ativos + 1;
        } else {
            inativos = inativos + 1;
        }
    }

    percentual = (ativos * 100.0) / n;

    int p10 = (int)(percentual * 10 + 0.5);

    cout << "\n" << "====== PAINEL FINAL ======" << "\n";
    cout << "Total de dispositivos: " << n << "\n";
    cout << "Ativos: " << ativos << "\n";
    cout << "Inativos: " << inativos << "\n";
    cout << "Disponibilidade: " << p10 / 10 << "," << p10 % 10 << "%" << "\n";

    if (inativos >= 2) {
        cout << "ALERTA: 2 ou mais dispositivos indisponiveis!" << "\n";
    } else {
        cout << "Situacao normal: sem alerta." << "\n";
    }
    cout << "(Simulacao: valores digitados manualmente, sem checagem real de rede.)" << "\n";
}
