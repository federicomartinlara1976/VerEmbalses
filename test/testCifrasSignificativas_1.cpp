#include <iostream>    
#include <iomanip>

using namespace std;

int main () {
 
    float p = 8.5361478025119782429925187;         // Una Variable de Tipo FLOAT, si no
                                                // se le agrega ningún MODIFICADOR
                                                // muestra, por defecto,
                                                // 4 Cifras significativas ( Decimales )
                                                // más 1 de Redondeo
                                                //
                                                // Con MODIFICADOR de aumento de 
                                                // Cifras significativas muestra 
                                                // 7 Cifras
    
    
    /*double   d  =  3.14159265358979323846264;      // Lo mismo ocurre con una variable de
                                                // tipo DOUBLE
                                                //
                                                // Con MODIFICADOR de aumento de 
                                                // Cifras significativas muestra 
                                                // 15 Cifras
    
    
    long double dd  =  3.14159265358979323846264;  // Lo mismo ocurre con una variable de
                                                // tipo LONG DOUBLE
                                                //
                                                // Con MODIFICADOR de aumento de 
                                                // Cifras significativas muestra 
                                                // 19 Cifras							 */
    
    /*cout << f << endl;
    cout << d << endl;  
    cout << dd << endl;*/  
    
    cout.precision(35);
    cout << setw(35); 
    cout << p << endl;
    cout << setw(35);
    cout << fixed << p << endl;
    
    return 0;
} 
