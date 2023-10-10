#ifndef COLA_H
#define COLA_H
#include <iostream>

using namespace std;

const int TAM = 100;


class alumno
{
private:
    string nombre;
    string nombreCarrera;
    int materiasAprobadas;
    float promedioGeneral;

public:
    alumno() : nombre(""), nombreCarrera(""), materiasAprobadas(0), promedioGeneral(0.0) {}
    alumno(string n, string nc, int ma, float pg) : nombre(n), nombreCarrera(nc), materiasAprobadas(ma), promedioGeneral(pg) {}

    void operator=(alumno& x)
    {
        nombre = x.nombre;
        nombreCarrera = x.nombreCarrera;
        materiasAprobadas = x.materiasAprobadas;
        promedioGeneral = x.promedioGeneral;
    }

    friend ostream& operator<<(ostream& os, const alumno& a)
    {
        os << "\n\t Nombre: " << a.nombre
           << "\n\t Carrera: " << a.nombreCarrera
           << "\n\t Materias Aprobadas: " << a.materiasAprobadas
           << "\n\t Promedio General: " << a.promedioGeneral;
        return os;
    }

    friend istream& operator>>(istream& o, alumno& a)
    {
        cout << "\tIngrese nombre del alumno: ";
        o >> a.nombre;
        cout << "\tIngrese nombre de la carrera: ";
        o >> a.nombreCarrera;
        cout << "\tIngrese cantidad de materias aprobadas: ";
        o >> a.materiasAprobadas;
        cout << "\tIngrese promedio general: ";
        o >> a.promedioGeneral;
        return o;
    }
};


class Cola
{
private:
    alumno datos[TAM];
    int ult;

public:
    Cola() : ult(-1) {}

    bool vacia() const { return ult == -1; }
    bool llena() const { return ult == TAM - 1; }
    int ultimo() const { return ult; }

    friend ostream& operator<<(ostream& os, Cola& c)
    {
        os << "\tContenido de la cola" <<endl;
        for (int i = 0; i <= c.ultimo(); i++)
        {
            os << c.datos[i] << endl;
        }
        return os;
    }

    void enqueue(alumno& elem)
    {
        if (!llena())
        {
            datos[++ult] = elem;
            cout << "\t¡Alumn@ agregado a la cola!." << endl;
        }
        else
        {
            cout << "\tLa cola está llena, no se puede agregar más alumnos." << endl;
        }
    }

alumno dequeue()
{
    if (!vacia())
    {
        alumno eliminado = datos[0];
        for (int i = 0; i < ult; i++)
        {
            datos[i] = datos[i + 1];
        }
        ult--;
        return eliminado;
    }
    else
    {
        cout << "\tLa cola está vacía, no se puede eliminar ningún alumno." << endl;
        return alumno();
    }
}

};


#endif // COLA_H
