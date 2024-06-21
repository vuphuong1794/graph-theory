#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct DSC {
    int dau;
    int cuoi;
};

class DoThi
{
private:
    int soDinh;
    int soCanh;
    vector<vector<int>> maTranKe;
    vector<DSC> danhSachCanh;
    vector<vector<int>> danhSachKe;
public:
    //read
    void docMtk(string location);
    void docDsc(string loction);
    //convert
    void mtkToDsc();
    void mtkToDsk();
    void dscToDsk();
    void dscToMtk();
    void dskToMtk();
    void dskToDsc();
    //print
    const void inDSC();
    const void inDSK();

    int bac(int dinh);
    int tongBac();
    int banBacRa(int dinh);
    int tongBanBacRa();
    int banBacVao(int dinh);
    int tongBanBacVao();

    bool dayDu();

    //chua xong
    bool vong();
    bool dfsVong(int dinh, int cha, vector<bool>& tham);

    bool haiPhia();
    bool bfsHaiPhia(int u, vector<int>& mauSac);


    void dfs(int dinh);
    void dfsUtil(int dinh, vector<bool>& tham);
    void bfs(int dinh);
    void bfsLienThong(int dinh, vector<bool>& tham, string yeucau);

    int soThanhPhanLienThong();
    void lietKeThanhPhanLienThong();
};



