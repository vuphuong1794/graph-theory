//#include "DoThi.h"
//#include <queue>
//
//void DoThi::docMtk(string duongDan)
//{
//    ifstream file(duongDan);
//    if (!file.is_open())
//    {
//        cout << "File chua mo duoc";
//        return;
//    }
//    file >> soDinh;
//    maTranKe.resize(soDinh + 1);
//    for (int i = 1; i <= soDinh; i++)
//    {
//        maTranKe[i].resize(soDinh + 1);
//        for (int j = 1; j <= soDinh; j++)
//        {
//            file >> maTranKe[i][j];
//            if (maTranKe[i][j] == 1)
//                soCanh++;
//        }
//    }
//
//    file.close();
//}
//
//void DoThi::docDsc(string duongDan)
//{
//    ifstream fi(duongDan);
//
//    if (!fi.is_open())
//    {
//        cout << "Khong the mo file: " << duongDan << endl;
//        return;
//    }
//
//    danhSachCanh.clear();
//
//    dsc canh;
//    // canh.dau = 0;
//    // canh.cuoi = 0;
//    // danhSachCanh.push_back(canh);
//    fi >> soDinh >> soCanh;
//    for (int i = 0; i < soCanh; i++)
//    {
//        fi >> canh.dau >> canh.cuoi;
//        danhSachCanh.push_back(canh);
//    }
//
//    fi.close();
//}
//
//void DoThi::mtkToDsk()
//{
//    danhSachKe.resize(soDinh + 1);
//    for (int i = 1; i <= soDinh; i++)
//        for (int j = i + 1; j <= soDinh; j++)
//            if (maTranKe[i][j])
//            {
//                danhSachKe[i].push_back(j);
//                if (this->voHuong())
//                {
//                    danhSachKe[j].push_back(i);
//                }
//            }
//}
//
//// void DoThi::dscToDsk()
////{
////     //mac dinh la do thi vo huong
////     danhSachCanh.clear();
////
////     docDsc("./danhsachcanh.txt");
////
////     danhSachKe.clear();
////     danhSachKe.resize(soDinh + 1);
////
////     /*inDSC();*/
////     for (const dsc& canh : danhSachCanh) {
////         if (canh.dau != 0 && canh.cuoi != 0) {
////             cout << "(" << canh.dau << ", " << canh.cuoi << ")" << endl;
////             danhSachKe[canh.dau].push_back(canh.cuoi);
////             /*if (this->voHuong())
////                 danhSachKe[canh.cuoi].push_back(canh.dau);*/
////         }
////     }
////     /*inDSK();*/
//// }
//
//const void DoThi::inDSC()
//{
//    cout << "Danh sach canh: " << endl;
//    for (int i = 1; i <= soDinh; i++)
//    {
//        for (int j = this->voHuong() ? i + 1 : 1; j <= soDinh; j++)
//        {
//            if (maTranKe[i][j])
//            {
//                cout << "(" << i << ", " << j << ")" << endl;
//            }
//        }
//    }
//}
//
//const void DoThi::inDSK()
//{
//    cout << "Danh sach ke: " << endl;
//    for (int i = 1; i <= soDinh; i++)
//    {
//        cout << i << ": ";
//        for (int j = 1; j <= soDinh; j++)
//        {
//            if (maTranKe[i][j])
//            {
//                cout << j << " ";
//            }
//        }
//        cout << endl;
//    }
//}
//
//bool DoThi::voHuong()
//{
//    for (int i = 1; i <= soDinh; i++)
//    {
//        for (int j = i + 1; j <= soDinh; j++)
//        {
//            if (maTranKe[i][j] != maTranKe[j][i])
//                return false;
//        }
//    }
//    return true;
//}
//
//int DoThi::bac(int dinh)
//{
//    if (dinh < 1 || dinh > soDinh)
//        return -1;
//
//    int count = 0;
//    for (int j = 1; j <= soDinh; j++)
//    {
//        if (maTranKe[dinh][j])
//            count++;
//    }
//    return count;
//}
//
//int DoThi::tongBac()
//{
//    int tong = 0;
//    for (int i = 1; i <= soDinh; i++)
//    {
//        tong += bac(i);
//    }
//    return tong;
//}
//
//int DoThi::banBacRa(int dinh)
//{
//    int tong = 0;
//    for (int j = 1; j <= soDinh; j++)
//    {
//        tong += maTranKe[dinh][j];
//    }
//    return tong;
//}
//
//int DoThi::tongBanBacRa()
//{
//    int tong = 0;
//    for (int i = 1; i <= soDinh; i++)
//    {
//        tong += banBacRa(i);
//    }
//    return tong;
//}
//
//int DoThi::banBacVao(int dinh)
//{
//    int tong = 0;
//    for (int i = 1; i <= soDinh; i++)
//    {
//        tong += maTranKe[i][dinh];
//    }
//    return tong;
//}
//
//int DoThi::tongBanBacVao()
//{
//    int tong = 0;
//    for (int i = 1; i <= soDinh; i++)
//    {
//        tong += banBacRa(i);
//    }
//    return tong;
//}
//
//bool DoThi::dayDu()
//{
//    for (int i = 1; i <= soDinh; i++)
//        for (int j = i + 1; j <= soDinh; j++)
//            if (maTranKe[i][j] == 0)
//                return false;
//    return true;
//}
//
//bool DoThi::vong()
//{
//    // 2 điều kiện:
//    //  tất cả các đỉnh phải có bậc bằng 2
//    //  Đồ thị liên thông và chỉ có 1 chu trình
//    if (soDinh < 3)
//        return false;
//    for (int u = 1; u <= soDinh; u++)
//        if (bac(u) != 2)
//            return false;
//    if (this->soThanhPhanLienThong() != 1)
//        return false;
//    vector<bool> tham(soDinh + 1, false);
//    for (int u = 1; u <= soDinh; u++)
//    {
//        if (!tham[u])
//            if (dfsVong(u, -1, tham))
//                return true;
//    }
//    return false;
//}
//
//bool DoThi::dfsVong(int dinh, int cha, vector<bool>& tham)
//{
//    tham[dinh] = true;
//    for (int hangXom : danhSachKe[dinh])
//    {
//        if (!tham[hangXom] && dfsVong(hangXom, dinh, tham)) // đệ quy
//            return true;
//        else if (hangXom != cha) // điều kiện dừng
//            return true;
//    }
//    return false;
//}
//
//bool DoThi::haiPhia()
//{
//    mtkToDsk();
//    vector<int> mauSac(soDinh + 1, -1);
//    for (int u = 1; u <= soDinh; u++) {
//        if (mauSac[u] == -1) { // Kiểm tra TPLT nhưng phải: Chỉ bắt đầu BFS nếu u chưa được thăm
//            if (!bfsHaiPhia(u, mauSac)) {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//// 0: RED, 1: BLUE, -1: Chưa thăm
//bool DoThi::bfsHaiPhia(int u, vector<int>& mauSac)
//{
//    queue<int> q;
//    q.push(u);
//    mauSac[u] = 0;
//    while (!q.empty())
//    {
//        int v = q.front();
//        q.pop();
//        for (int x : danhSachKe[v])
//        {
//            if (mauSac[x] == -1)
//            {
//                mauSac[x] = 1 - mauSac[v]; // màu của v = 1 => màu của x = 0, màu của v = 0 => màu của x = 1;
//            }
//            else if (mauSac[x] == mauSac[v])
//                return false;
//        }
//    }
//    return true;
//}
//
//void DoThi::dfs(int dinh)
//{
//    mtkToDsk();
//    /*dscToDsk();*/
//    vector<bool> tham(soDinh + 1, false);
//    cout << "dfs(" << dinh << ") = ";
//    dfsUtil(dinh, tham);
//    cout << endl;
//}
//
//void DoThi::dfsUtil(int dinh, vector<bool>& tham)
//{
//    cout << dinh << ", ";
//    tham[dinh] = true;
//    for (int x : danhSachKe[dinh])
//        if (!tham[x])
//            dfsUtil(x, tham);
//}
//
//void DoThi::bfs(int dinh)
//{
//    // Buoc khoi tao
//    queue<int> hangDoi;
//    vector<bool> tham(soDinh + 1, false);
//    hangDoi.push(dinh);
//    tham[dinh] = true;
//    cout << "bfs(" << dinh << ") = ";
//
//    // Buoc lap
//    while (!hangDoi.empty())
//    {
//        int dinh_dau = hangDoi.front();
//        hangDoi.pop();
//        cout << dinh_dau << ", ";
//        for (int x : danhSachKe[dinh_dau])
//            if (!tham[x])
//            {
//                tham[x] = true;
//                hangDoi.push(x);
//            }
//    }
//    cout << endl;
//}
//
//void DoThi::bfsLienThong(int dinh, vector<bool>& tham, string yeucau)
//{
//    // Buoc khoi tao
//    queue<int> hangDoi;
//    hangDoi.push(dinh);
//    tham[dinh] = true;
//
//    // Buoc lap
//    while (!hangDoi.empty())
//    {
//        int dinhDau = hangDoi.front();
//        if (yeucau == "in")
//            cout << dinhDau << ", ";
//        hangDoi.pop();
//        for (int x : danhSachKe[dinhDau])
//            if (!tham[x])
//            {
//                tham[x] = true;
//                hangDoi.push(x);
//            }
//    }
//}
//
//int DoThi::soThanhPhanLienThong()
//{
//    int dem = 0;
//    vector<bool> tham(soDinh + 1, false);
//    for (int i = 1; i <= soDinh; i++)
//    {
//        if (!tham[i])
//        {
//            ++dem;
//            bfsLienThong(i, tham, "dem");
//        }
//    }
//    return dem;
//}
//
//void DoThi::lietKeThanhPhanLienThong()
//{
//    int dem = 0;
//    vector<bool> tham(soDinh + 1, false);
//    for (int i = 1; i <= soDinh; i++)
//    {
//        if (!tham[i])
//        {
//            ++dem;
//            cout << "Cac dinh thuoc thanh phan lien thong thu " << dem << " la: ";
//            bfsLienThong(i, tham, "in");
//            cout << endl;
//        }
//    }
//}
