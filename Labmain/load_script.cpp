#include <iostream>
#include <string>
#include <cstdio>
#include "load_script.h"

using namespace std;

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado


void load_script(const char* filename, bool show_script = false)
{
    if (!consoleBox) // Validación de que consoleBox está inicializado
    {
        cerr << "Error: consoleBox no está inicializado." << endl;
        return;
    }

    if (!filename || strlen(filename) == 0) // Validación de la entrada filename
    {
        cerr << "Error: el nombre del archivo es inválido o vacío." << endl;
        return;
    }

    string script;
    FILE* f = nullptr;

    try
    {
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "Error de apertura de archivo: " << filename << endl;
            return;
        }

        char buf[4001];
        memset(buf, 0, sizeof(buf)); // Inicializar el buffer para evitar problemas de memoria

        int c;
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0; // Null-terminator para evitar problemas al anexar a `script`
            script.append(buf, c); // Añade solo los bytes leídos
        }

        if (ferror(f)) // Comprobar si hubo un error de lectura
        {
            cerr << "Error durante la lectura del archivo." << endl;
            fclose(f);
            return;
        }

        fclose(f);
        f = nullptr;

        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }

        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const exception& e)
    {
        cerr << "Excepción capturada: " << e.what() << endl;
        if (f)
            fclose(f);
    }
    catch (...)
    {
        cerr << "Error desconocido durante la lectura del archivo." << endl;
        if (f)
            fclose(f);
    }
}
void load_script()
{
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}