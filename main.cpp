//#include <iostream>
//#include <vector>
//#include <fstream>
//#include "DoThi.h"
//
//using namespace std;
//
//int main()
//{
//    DoThi* g = new DoThi();
//    /*g->docMTK("./doThiCoHuong.txt");*/
//    // g->docMtk("./doThiVoHuong.txt");
//    // g->docMtk("./doThiDayDu.txt");
//    // g->docMtk("./doThiVong.txt");
//    g->docMtk("./doThiHaiPhia.txt");
//    g->docMtk("./thanhPhanLienThong.txt");
//    g->inDSC();
//    g->inDSK();
//    if (g->voHuong())
//    {
//        int tongBac = g->tongBac();
//        cout << "Tong bac cua do thi: " << tongBac << endl;
//        int bacDinh1 = g->bac(1);
//        cout << "Tong bac cua dinh 1: " << bacDinh1 << endl;
//    }
//    else
//    {
//        int tongBanBacRa = g->tongBanBacRa();
//        int tongBanBacVao = g->tongBanBacVao();
//        int x1 = g->banBacRa(2);
//        int x2 = g->banBacVao(2);
//    }
//    if (g->dayDu())
//        cout << endl << "Do thi day du" << endl << endl;
//    if (g->vong())
//        cout << endl << "Do thi vong" << endl << endl;
//    if (g->haiPhia())
//        cout << endl << "Do thi hai phia" << endl << endl;
//
//    g->dfs(1);
//    g->bfs(1);
//    int tplt = g->soThanhPhanLienThong();
//    cout << endl
//        << "So thanh phan lien thong la: " << tplt << endl;
//    g->lietKeThanhPhanLienThong();
//}
