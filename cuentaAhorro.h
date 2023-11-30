#ifndef CUENTA_AHORRO_H
#define CUENTA_AHORRO_H

#include "cuenta.h"
#include "cuentaDebito.h"

class CuentaAhorro : public Cuenta {
private:    
    double tasaInteres;
public:
     CuentaAhorro(string _nombre, double _saldoInicial) : Cuenta(_nombre, _saldoInicial) {}

    double calcularSaldoProximoAnio() const {
        return obtenerSaldo() * 1.04; // Asumiendo un interés del 4%
    }

    // Recibe transferencias desde una cuenta genérica (podría ser de débito)
    void recibirTransferencia(double cantidad, Cuenta& cuentaDebito) {
        if (cuentaDebito.obtenerSaldo() >= cantidad) {
            cuentaDebito.retirar(cantidad); // Retirar de la cuenta de origen
            this->depositar(cantidad);      // Depositar en la cuenta de ahorro
        } else {
            cout << "Saldo insuficiente en la cuenta de origen para realizar la transferencia." << endl;
        }
    }
};

#endif // CUENTA_AHORRO_H
