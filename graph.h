#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

struct danhsachcanh {
    int dau;
    int cuoi;
};

struct Canh {
    int x, y, w;
};

class DoThi
{
private:
    int dinh;
    int canh=0;
    int stplt = 0;
    bool visited[1005];
    int truoc[1005];
    int color[1001];
    int degree[1001];
    bool used[1001];
    vector<int> ke[1005];
    vector<vector<int>> MTK; 
    vector<danhsachcanh> DSC;
    vector<Canh> DSC_w;
    vector<vector<int>> DSK;
    vector<pair<int, int>> adj[1001];
public:
    //kiem tra
    bool voHuong();
    bool dayDu();
    bool haiphia();
    bool vong();
    bool bfsHaiPhia(int dinh);
    bool dfsVong(int dinh, int u, vector<bool>& visited);
    bool coChutTrinhEuler();
    bool coChutTrinhHamliton();

    //doc
    void readMTK(string path);
    void readDSC(string path);

    //in
    const void inDSC();
    const void inDSK();

    //chuyen doi cac phuong phap
    void mtkToDsc();
    void mtkToDsk();
    void dscToDsk();
    void dscToMtk();

    //tinh toan
    int bac(int dinh);
    int tongBac();
    int banBacRa(int dinh);
    int tongBanBacRa();
    int banBacVao(int dinh);
    int tongBanBacVao();
    void dfs(int dinh);
    void bfs(int dinh);
    void dfsUtil(int dinh, vector<bool>& tham);
    void dfsLienthong(int dinh);
    void soThanhPhanLienThong();
    void euler(int v);
    void Hamilton(int dinh);
    bool HamiltonUtil(int v, vector<int>& path, vector<bool>& visited);
    void prim(int dinh);
};



