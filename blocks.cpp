#include "blocks.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//////////////////////////////////
Input::Input(string filename)
{
    t = 0;
    fstream arch(filename);
    int val;

    while (arch >> val)
        values.push_back(val);
}

void Input::Connect(Wire *a)
{
    out_connections.push_back(a);
}

void Input::Update()
{
    if (t < values.size())
        for (Wire *wire : out_connections)
            wire->value = values[t];
    t++;
}
//////////////////////////////////////

Wire::Wire()
{
    value = 0;
}


//////////////////////////////////////

Monitor::Monitor(string name)
{
    this->name = name;
    mon_out = name + ": ";
    in_connection = nullptr;
}

void Monitor::Connect(Wire *a)
{
    in_connection = a;
}

void Monitor::Update()
{
    if (in_connection != nullptr)
        mon_out += (in_connection->value ? "-" : "_");
    else
        mon_out += "x";

    cout << mon_out << endl;
}
