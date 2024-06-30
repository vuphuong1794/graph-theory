#include <iostream>
#include <vector>
#include <fstream>
#include "graph.h"

using namespace std;

int main()
{
    DoThi* g = new DoThi();
    //g->readMTK("dothi.txt");
    //g->readMTK("dothihaiphia.txt");
    //g->readMTK("dothiEuler.txt");
    //g->readMTK("dsctomtk.txt");
    //g->readDSC("dothidanhsachcanh.txt");
    g->inDSC();
    g->inDSK();
    if (g->voHuong())
    {
        int tongBac = g->tongBac();
        cout << "Tong bac cua do thi: " << tongBac << endl;
        int bacCuaDinh = g->bac(1);
        cout << "Tong bac cua dinh 1: " << bacCuaDinh << endl;
    }
    else
    {
        int tongBanBacRa = g->tongBanBacRa();
        int tongBanBacVao = g->tongBanBacVao();
        int x1 = g->banBacRa(2);
        int x2 = g->banBacVao(2);
        cout << "tong ban bac ra: " << x1 << endl;
        cout << "tong ban bac vao: " << x2 << endl;
    }
    
    if (g->dayDu())
        cout << "Do thi day du" << endl;
    if (g->vong())
        cout << " Do thi vong" << endl;
    if (g->haiphia())
        cout << " Do thi hai phia" << endl;

    g->dfs(1);
    g->bfs(1);
    g->soThanhPhanLienThong();
    
    if (g->coChutTrinhEuler()) {
        g->euler(1);
    }
    if (g->coChutTrinhHamliton()) {
        g->Hamilton(1);
    }
    g->prim(4);
}
