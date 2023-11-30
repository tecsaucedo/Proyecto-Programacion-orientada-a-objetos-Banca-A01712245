#include <iostream>
#include <vector>
#include <string>
#include "cuentaDebito.h"
#include "cuentaCredito.h"
#include "cuentaAhorro.h"
#include "transaccion.h"

using namespace std;

int main() {
    string nombreDebito, nombreCredito, nombreAhorro;
    double saldoInicialDebito, saldoInicialCredito, SaldoInicialAhorro;

    // Solicitar datos para CuentaDebito
    cout << "Ingrese el nombre para la cuenta de débito: ";
    cin >> nombreDebito;
    cout << "Ingrese el saldo inicial para la cuenta de débito: ";
    cin >> saldoInicialDebito;

    // Crear CuentaDebito
    CuentaDebito cuentaDebito(nombreDebito, saldoInicialDebito);

    // Solicitar datos para CuentaCredito
    cout << "Ingrese el nombre para la cuenta de crédito: ";
    cin >> nombreCredito;
    cout << "Ingrese el límite de crédito para la cuenta de crédito: ";
    cin >> saldoInicialCredito;

    // Crear CuentaCredito con saldo inicial de 0
    CuentaCredito cuentaCredito(nombreCredito, saldoInicialCredito);

    // Solicitar nombre para CuentaAhorro
    cout << "Ingrese el nombre para la cuenta de ahorro: ";
    cin >> nombreAhorro;

    // Crear CuentaAhorro con saldo inicial de 0
    CuentaAhorro cuentaAhorro(nombreAhorro, 0);

    // Pruebas simples para verificar la funcionalidad
    cout << "Saldo inicial de la cuenta de débito: " << cuentaDebito.obtenerSaldo() << endl;
    cout << "Límite de crédito de la cuenta de crédito: " <<cuentaCredito.obtenerSaldo() << endl;
    cout << "Saldo inicial de la cuenta de ahorro: " << cuentaAhorro.obtenerSaldo() << endl;

    int opcion;
    do {
        cout << "Menú de opciones:\n";
        cout << "1. Depositar/Retirar\n";
        cout << "2. Obtener saldo (Débito)\n";
        cout << "3. Obtener saldo (Ahorro)\n";
        cout << "4. Obtener límite de crédito\n";
        cout << "5. Comprar con crédito\n";
        cout << "6. Pagar Deuda (crédito)\n";
        cout << "7. Ver Deuda\n";
        cout << "8. Transferir a cuenta de ahorro\n";
        cout << "9. Calcular ahorros próximo año\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                int opcionTransaccion;
            cout << "1. Depositar\n";
            cout << "2. Retirar\n";
            cout << "Seleccione una opción para la transacción: ";
            cin >> opcionTransaccion;

            double monto;
            cout << "Ingrese el monto: ";
            cin >> monto;

            if (monto <= 0) {
                cout << "El monto debe ser mayor que 0." << endl;
                break;
            }

            switch (opcionTransaccion) {
                case 1:
                    // Depositar
                    cuentaDebito.depositar(monto);
                    cout << "Depósito realizado. Nuevo saldo: " << cuentaDebito.obtenerSaldo() << endl;
                    // Aquí debes registrar la transacción en el historial
                    break;
                case 2:
                    // Retirar
                    if (cuentaDebito.obtenerSaldo() >= monto) {
                        cuentaDebito.retirar(monto);
                        cout << "Retiro realizado. Nuevo saldo: " << cuentaDebito.obtenerSaldo() << endl;
                        // Aquí debes registrar la transacción en el historial
                    } else {
                        cout << "Saldo insuficiente." << endl;
                    }
                    break;
                default:
                    cout << "Opción no válida." << endl;
            }
                break;
            case 2:{
                double saldo = cuentaDebito.obtenerSaldo();
                cout << "El saldo de la cuenta de débito es: " << saldo << endl;
                break;
            }
            case 3:{
                double saldo = cuentaAhorro.obtenerSaldo();
                cout << "El saldo de la cuenta de ahorro es: " << saldo << endl;
                break;
            }
            case 4:{
                double saldo = cuentaCredito.obtenerSaldo();
                cout << "Su límite de crédito es: " << saldo << endl;
                break;
            }
            case 5:{
                double montoCompra;
                cout << "Ingrese el monto de la compra: ";
                cin >> montoCompra;
                if (montoCompra > 0) {
                    cuentaCredito.comprar(montoCompra);
                } else {
                    cout << "El monto de la compra debe ser mayor que 0." << endl;
                }

                double deudaActual = cuentaCredito.obtenerDeuda();
                cout << "La deuda actual de la tarjeta de crédito es: " << deudaActual << endl;
                break;
            }
            case 6:{
                double montoPago;
                cout << "Ingrese el monto que desea pagar de la deuda de crédito: ";
                cin >> montoPago;

                if (montoPago > 0) {
                    cuentaCredito.pagarDeuda(montoPago, cuentaDebito);
                } else {
                    cout << "El monto a pagar debe ser mayor que 0." << endl;
                }
                break;
                double deudaActual = cuentaCredito.obtenerDeuda();
                cout << "La deuda actual de la tarjeta de crédito es: " << deudaActual << endl;
            }
            case 7:{
                double deudaActual = cuentaCredito.obtenerDeuda();
                cout << "La deuda actual de la tarjeta de crédito es: " << deudaActual << endl;
                break;
            }
            case 8:{
                double montoTransferencia;
                cout << "Ingrese el monto que desea transferir a la cuenta de ahorro: ";
                cin >> montoTransferencia;

                if (montoTransferencia > 0) {
                    cuentaAhorro.recibirTransferencia(montoTransferencia, cuentaDebito);
                } else {
                cout << "El monto a transferir debe ser mayor que 0." << endl;
                }

                double saldo = cuentaAhorro.obtenerSaldo();
                cout << "El saldo de la cuenta de ahorro es: " << saldo << endl;
                break;
            }
            case 9:{
                double saldoProximoAnio = cuentaAhorro.calcularSaldoProximoAnio();
                cout << "El saldo estimado de la cuenta de ahorro para el próximo año es: " << saldoProximoAnio << endl;
                break;
            }
            case 10:{
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default:{
                cout << "Opción no válida. Intente de nuevo." << endl;
            }
        }
    } while (opcion != 10);
    return 0;
}
