#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>
#include <vector>
#include "transaccion.h"
using namespace std;

class Cuenta {
protected: 
    string nombre;
    double saldo;
    vector<Transaccion> transacciones; // Vector para almacenar las transacciones

public: 
    virtual ~Cuenta() {}
    Cuenta(string _nombre, double _saldoInicial); // Constructor
    void depositar(double cantidad);
    void retirar(double cantidad);
    double obtenerSaldo() const;
    string obtenerNombre() const;
    void agregarTransaccion(const Transaccion& nuevaTransaccion);
    void mostrarHistorialTransacciones() const;
};

Cuenta::Cuenta(string _nombre, double _saldoInicial) : nombre(_nombre), saldo(_saldoInicial) {
    // Asegúrate de que el saldo inicial no sea negativo
    if (_saldoInicial < 0) {
        cout << "Saldo inicial no puede ser negativo. Se establecerá en 0." << endl;
        saldo = 0;
    }
}

void Cuenta::depositar(double cantidad) {
    if (cantidad > 0) {
        saldo += cantidad;
        transacciones.emplace_back("fecha_actual", cantidad, "Depósito", "Deposito", nombre);
    } else {
        cout << "Cantidad a depositar no puede ser negativa." << endl;
    }
}

void Cuenta::retirar(double cantidad) {
    if (cantidad > 0 && cantidad <= saldo) {
        saldo -= cantidad;
        transacciones.emplace_back("fecha_actual", cantidad, "Retiro", "Retiro", nombre);
    } else {
        cout << "No se puede retirar una cantidad mayor al saldo o negativa." << endl;
    }
}

double Cuenta::obtenerSaldo() const {
    return saldo;
}

string Cuenta::obtenerNombre() const {
    return nombre;
}

void Cuenta::agregarTransaccion(const Transaccion& nuevaTransaccion) {
    transacciones.push_back(nuevaTransaccion);
}

void Cuenta::mostrarHistorialTransacciones() const {
    for (const auto& transaccion : transacciones) {
        transaccion.mostrarDetalles();
    }
}

#endif // CUENTA_H