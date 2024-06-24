#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct danhsachcanh {
    int dau;
    int cuoi;
};

class DoThi
{
private:
    int dinh;
    int canh;
    vector<int> ke[1005];
    bool visited[1005];
    int truoc[1005];
    vector<vector<int>> MTK; 
    vector<danhsachcanh> DSC;
    vector<vector<int>> DSK;

public:
    //kiem tra
    bool voHuong();
    bool dayDu();
    bool haiphia();
    bool coChuTrinhDon();
    bool euler();

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
    int soThanhPhanLienThong();
    void lietKeThanhPhanLienThong();
    void lietKeCTHamilton();

};



