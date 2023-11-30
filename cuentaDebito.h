#ifndef CUENTA_DEBITO_H
#define CUENTA_DEBITO_H

#include "cuenta.h"
#include "cuentaCredito.h"
#include "cuentaAhorro.h"

class CuentaDebito : public Cuenta {
public:
    CuentaDebito(string _nombre, double _saldoInicial) : Cuenta(_nombre, _saldoInicial) {}

    // Método para pagar deuda de una CuentaCredito
    void pagarDeudaCredito(double cantidad, CuentaCredito& cuentaCredito) {
        if (saldo >= cantidad) {
            cuentaCredito.pagarDeuda(cantidad, *this);
        } else {
            cout << "Saldo insuficiente para pagar la deuda de crédito." << endl;
        }
    }

    // Método para transferir dinero a una CuentaAhorro
    void transferirACuentaAhorro(double cantidad, CuentaAhorro& cuentaAhorro) {
        if (saldo >= cantidad) {
            retirar(cantidad);
            cuentaAhorro.depositar(cantidad);
        } else {
            cout << "Saldo insuficiente para transferir a la cuenta de ahorro." << endl;
        }
    }
};

#endif // CUENTA_DEBITO_H
