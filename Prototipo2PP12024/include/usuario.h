#ifndef USUARIO_H
#define USUARIO_H

#include<iostream>

using std::string;

class usuarios
{
    public:
        usuarios();
      //  virtual ~usuarios();
        bool loginUsuarios();
        void menuUsuarios();
        bool buscar(string user, string passw);
        string getNombre();
        string setNombre(string nombre);

    protected:

    private:
		string id;
		string name;
		string pass;
};

#endif // USUARIO_H
