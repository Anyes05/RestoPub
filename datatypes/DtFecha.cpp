#include "DtFecha.h"
#include <stdexcept>

// Implementación de la función esBisiesto
bool DtFecha::esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

DtFecha::DtFecha(int dia, int mes, int anio){
    // Validar año
    if (anio < 1999 || anio > 2025) { // Puedes ajustar el rango de años según tus necesidades.
        throw std::invalid_argument("Año inválido. Debe estar entre 1900 y 2100.");
    }
    this->anio = anio;

    // Validar mes
    if (mes < 1 || mes > 12) {
        throw std::invalid_argument("Mes inválido. Debe estar entre 1 y 12.");
    }
    this->mes = mes;

    // Validar día
    int diasEnMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (esBisiesto(anio)) {
        diasEnMes[2] = 29; // Febrero en año bisiesto
    }

    if (dia < 1 || dia > diasEnMes[mes]) {
        throw std::invalid_argument("Día inválido para el mes y año dados.");
    }
    this->dia = dia;
}

DtFecha::DtFecha(){
    this->anio = 0;
    this->dia = 0;
    this->mes = 0;
}

int DtFecha::setDia(int dia){
    return this->dia = dia;
}

int DtFecha::setMes(int mes){
    return this->mes = mes;
}

int DtFecha::setAnio(int anio){
    return this->anio = anio;
}

int DtFecha::getDia(){
    return this->dia;
}

int DtFecha::getMes(){
    return this->mes;
}

int DtFecha::getAnio(){
    return this->anio;
}

bool DtFecha::validar(){
    // Verificar año válido (puedes ajustar los límites según sea necesario)
    if (anio < 1900 || anio > 2100) 
    {
        throw invalid_argument("Año no válido");
    }

    // Verificar mes válido
    if (mes < 1 || mes > 12)
    {
        throw invalid_argument("Mes no válido");
    }

    // Verificar días válidos para el mes
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))  // Año bisiesto
    {
        diasPorMes[1] = 29;  // Febrero tiene 29 días
    }

    if (dia < 1 || dia > diasPorMes[mes - 1])
    {
        throw invalid_argument("Día no válido para el mes");
    }

    return true;
}

