#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
#include <string>
using namespace std;

class Transaccion {
private:
    string fecha;
    double monto;
    string descripcion;
    string tipo;

public:
    // Constructor para inicializar una transacción
    Transaccion(string _fecha, double _monto, string _descripcion, string _tipo, string _cuentaNombre) 
    : fecha(_fecha), monto(_monto), descripcion(_descripcion), tipo(_tipo) {}

    void mostrarDetalles() const {
        cout << "Fecha: " << fecha << ", Monto: " << monto << ", Descripción: "
             << descripcion << ", Tipo: " << tipo << ", Cuenta: " << endl;
    }
    
    // Getters
    string obtenerFecha() const { return fecha; }
    double obtenerMonto() const { return monto; }
    string obtenerDescripcion() const { return descripcion; }
    string obtenerTipo() const { return tipo; }

    // Setters
    void cambiarFecha(string _fecha) { fecha = _fecha; }
    void cambiarMonto(double _monto) { monto = (_monto >= 0) ? _monto : 0.0; }
    void cambiarDescripcion(string _descripcion) { descripcion = _descripcion; }
    void cambiarTipo(string _tipo) { tipo = _tipo; }
};

#endif // TRANSACCION_H
