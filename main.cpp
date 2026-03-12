#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
    fstream archivo_s1("signal1.txt");
    fstream archivo_s2("signal2.txt");

    vector<int> valores1;
    vector<int> valores2;
    int val;

    while (archivo_s1 >> val)
        valores1.push_back(val);

    while (archivo_s2 >> val)
        valores2.push_back(val);


    int t_max = min(valores1.size(), valores2.size());

    string o1 = "Monitor 1: ";
    string o2 = "Monitor 2: ";

    // Ciclo de simulacion
    for (int t = 0; t < t_max; t++)
    {
        //update inputs
        o1 += valores1[t] ? "-" : "_";
        o2 += valores2[t] ? "-" : "_";

        cout << o1 << endl;
        cout << o2 << endl;

        usleep(50000);
        // sube dos lineas
        cout << "\r\033[2F";
    }

    cout << o1 << endl;
    cout << o2 << endl;

    return 0;
}

