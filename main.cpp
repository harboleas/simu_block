#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include "blocks.h"

using namespace std;

int main()
{

    Input in_1("signal1.txt");
    Input in_2("signal2.txt");

    Wire a;
    Wire b;
    Wire c;

    Monitor m1("Mon 1");
    Monitor m2("Mon 2");
    Monitor m3("Mon 3");

    in_1.Connect(&a);
    in_1.Connect(&c);
    in_2.Connect(&b);

    m1.Connect(&a);
    m2.Connect(&b);
    m3.Connect(&c);

    vector<Input *> inputs;
    inputs.push_back(&in_1);
    inputs.push_back(&in_2);

    vector<Monitor *> monitors;
    monitors.push_back(&m1);
    monitors.push_back(&m2);
    monitors.push_back(&m3);

    // Ciclo de simulacion
    for (int t = 0; t < 50; t++)
    {
        //update inputs
        for (Input *in : inputs)
            in->Update();

        //update monitors
        for (Monitor *mon : monitors)
            mon->Update();

        usleep(50000);
        // sube dos lineas
        cout << "\r\033[" << monitors.size() << "F";
    }

    for (Monitor *mon : monitors)
        mon->Update();

    return 0;
}

