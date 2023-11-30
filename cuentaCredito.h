#ifndef CUENTA_CREDITO_H
#define CUENTA_CREDITO_H

#include "cuenta.h"
#include "cuentaDebito.h"

class CuentaCredito : public Cuenta {
private:
    double deuda; // Deuda actual en la cuenta de crédito

public:
    CuentaCredito(string _nombre, double _saldoInicial);
    void comprar(double cantidad);
    void pagarDeuda(double cantidad, Cuenta& cuentaDebito); // Método para pagar la deuda desde una cuenta de débito
    double obtenerDeuda() const; // Getter para la deuda actual
};

CuentaCredito::CuentaCredito(string _nombre, double _saldoInicial) 
    : Cuenta(_nombre, _saldoInicial), deuda(0) {}

void CuentaCredito::comprar(double cantidad) {
    if (cantidad <= saldo - deuda) {
        deuda += cantidad; // Aumenta la deuda
        // Considera registrar esta transacción
    } else {
        cout << "Límite de crédito excedido." << endl;
    }
}

void CuentaCredito::pagarDeuda(double cantidad, Cuenta& cuentaDebito) {
    if (cantidad <= cuentaDebito.obtenerSaldo() && cantidad <= deuda) {
        cuentaDebito.retirar(cantidad); // Descuenta el pago de la cuenta de débito
        deuda -= cantidad; // Disminuye la deuda en la cuenta de crédito
        // Considera registrar esta transacción
    } else {
        cout << "No hay suficientes fondos en la cuenta de débito o el monto excede la deuda." << endl;
    }
}

double CuentaCredito::obtenerDeuda() const {
    return deuda;
}

#endif // CUENTA_CREDITO_H
