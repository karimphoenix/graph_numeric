#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    string input_f = "input.txt";

    vector<int> old_g, new_g;

    ifstream line;

    line.open("input.txt");

    int x, y;

    int maxim_len = 0;
    int count_edge = 0;
    int edges = 0;

    old_g.reserve(2);

    while (line >> x >>  y){
//       "sum = x
        if  (x >= maxim_len) maxim_len = x;
        if  (y >= maxim_len) maxim_len = y;

        old_g.resize(maxim_len);
        //edges++;
        //if  (y < x) count_edge++;
        old_g[y-1] += 1;
    }
    line.close();

    int maxim = -1;
    int k = 0;
    new_g.resize(maxim_len);

    for (int i = 0; i < maxim_len; ++i){
        for (int j = 0; j < maxim_len; ++j)
            if (old_g[j] > maxim){
                maxim = old_g[j];
                k = j;
            }
        new_g[i] = k+1;
        maxim = -1;
        old_g[k] = -1;

    }

    line.open("input.txt");
    ofstream line_log;
    line_log.open("log.txt");

    while (line >> x >> y){
        line_log << new_g[x-1] << ' ' << new_g[y-1] << endl;
    }

    line.close();
    line_log.close();

    line.open("log.txt");
    while (line >> x >> y)
        if (y < x) count_edge++;
    line.close();

    /*
    cout << count_edge << endl;


    for (int i = 0; i < maxim_len; ++i)
        cout << new_g[i] << ' ';
    */
    ofstream line_res;
    line_res.open("result.txt");
    line_res << count_edge << endl;
    for (int i = 0; i < maxim_len; ++i)
        line_res << i+1 << ' ' << new_g[i] << endl;

    cout << count_edge;
    //cout << "Hello world!" << endl;
    return 0;
}
