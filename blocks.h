#ifndef BLOCKS
#define BLOCKS

#include <vector>
#include <string>

using namespace std;

class Wire
{
public:
    Wire();
    int value;
};

class Input
{
public:
    Input(string filename);
    void Connect(Wire *a);
    void Update();

private:
    vector<int> values;
    int t;
    vector<Wire *> out_connections;
};


class Monitor
{
public:
    Monitor(string name);
    void Connect(Wire *a);
    void Update();

private:
    Wire *in_connection;
    string name;
    string mon_out;
};

#endif
