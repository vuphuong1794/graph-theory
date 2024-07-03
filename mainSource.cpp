#include <iostream>
#include <vector>
#include <fstream>
#include "graph.h"

using namespace std;

int main() {
    int choice;
    DoThi* g = new DoThi();
    do {
        cout << endl;
        cout << "-------------------------------------------------\n";
        cout << "(0) thoat" << endl;
        cout << "(1) cac chuc nang: " << endl;
        cout << "- inDSC, inDSK, in tong bac cua do thi" << endl;
        cout << " - kiem tra loai do thi" << endl;
        cout << " - bfs, dfs, euler, hamilton" << endl;
        cout << " - so thanh phan lien thong, liet ke" << endl;
        cout << "(2) Prim" << endl;
        cout << "(3) Kruskal" << endl;
        cout << "(4) dijkstra" << endl;
        cout << "(5) bellmanford" << endl;
        cout << "(6) fulkerson" << endl;
        cout << "-------------------------------------------------\n";
        cout << "nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            //g->readMTK("dothi.txt");
            //g->readMTK("dothihaiphia.txt");
            g->readMTK("dothiEuler.txt");
            //g->readMTK("dsctomtk.txt");
            g->inDSC();
            g->inDSK();
            if (g->voHuong()) {
                int tongBac = g->tongBac();
                cout << "Tong bac cua do thi: " << tongBac << endl;
                int bacCuaDinh = g->bac(1);
                cout << "Tong bac cua dinh 1: " << bacCuaDinh << endl;
            }
            else {
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
            break;
        case 2:
            g->readDSC("dothidanhsachcanh.txt");
            g->prim(4);
            break;
        case 3:
            g->readDSC("kruskal.txt");
            g->kruskal();
            break;
        case 4:
            g->readDSC("dijkstra.txt");
            g->dijkstra(1);
            break;
        case 5: 
            cout << "tinh nang dang trong giai doan phat trien!\n";
            break;
        case 6: 
            cout << "tinh nang dang trong giai doan phat trien!\n";
            break;
        default:
            cout << "nhap khong hop le!" << endl;
            break;
        }
    } while (choice != 0);

    delete g;
    return 0;
}
