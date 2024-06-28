#include "graph.h"
#include <queue>

bool DoThi::voHuong(){
	for (int i = 1; i <= dinh; i++)
	{
		for (int j = i + 1; j <= dinh; j++)
		{
			if (MTK[i][j] != MTK[j][i])
				return false;
		}
	}
	return true;
}

void DoThi::readMTK(string path){
	ifstream fileInput(path);
	if (!fileInput.is_open())
	{
		cout << "xay ra loi khi mo file!!!";
		return;
	}
	fileInput >> dinh;
	MTK.resize(dinh + 1, vector<int>(dinh + 1, 0));
	for (int i = 1; i <= dinh; i++)
	{
		for (int j = 1; j <= dinh; j++)
		{
			fileInput >> MTK[i][j];
			if (MTK[i][j] == 1)
				canh++;
		}
	}

	fileInput.close();
}

void DoThi::readDSC(string duongDan){
	ifstream fileInput(duongDan);

	if (!fileInput.is_open())
	{
		cout << "Khong the mo file: " << duongDan << endl;
		return;
	}
	DSC.clear();

	danhsachcanh Canh;
	// canh.dau = 0;
	// canh.cuoi = 0;
	// danhSachCanh.push_back(canh);
	fileInput >> dinh >> canh;
	for (int i = 0; i < canh; i++)
	{
		fileInput >> Canh.dau >> Canh.cuoi;
		DSC.push_back(Canh);
	}

	fileInput.close();
}

const void DoThi::inDSC(){
	cout << "Danh sach canh: " << endl;
	for (int i = 1; i <= dinh; i++)
	{
		for (int j = this->voHuong() ? i + 1 : 1; j <= dinh; j++)
		{
			if (MTK[i][j])
			{
				cout << i << ", " << j << endl;
			}
		}
	}
}

const void DoThi::inDSK(){
	cout << "Danh sach ke: " << endl;
	for (int i = 1; i <= dinh; i++)
	{
		cout << i << ": ";
		for (int j = 1; j <= dinh; j++)
		{
			if (MTK[i][j])
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
}

void DoThi::mtkToDsc(){
	cout << "ma tran ke to danh sach ke: ";
	vector<pair<int, int>> edge;
	for (int i = 1; i <= dinh; i++) {
		for (int j = 1; j <= dinh; j++) {
			if (MTK[i][j]) {
				if (voHuong()) {
					// Đối với đồ thị vô hướng, chỉ thêm cạnh một lần
					if (i < j) {
						DSC.push_back({ i, j });
					}
				}
				else {
					// Đối với đồ thị có hướng, thêm tất cả các cạnh
					DSC.push_back({ i, j });
				}
			}
			if (MTK[i][j] && i < j) {
				edge.push_back({ i, j });
			}
		}
	}
	cout << endl;
	for (auto it : edge) {
		cout << it.first << " " << it.second << endl;
	}
};

void DoThi::mtkToDsk(){
	DSK.clear();
	DSK.resize(dinh + 1);
	for (int i = 1; i <= dinh; i++) {
		for (int j = 1; j <= dinh; j++) {
			if (MTK[i][j])
			{
				DSK[i].push_back(j);
				if (this->voHuong())
				{
					DSK[j].push_back(i);
				}
			}
		}
	}
}

void DoThi::dscToDsk() {

	// Khởi tạo danh sách kề
	DSK.clear();
	DSK.resize(dinh + 1);

	// Duyệt qua danh sách cạnh
	for (const auto& canh : DSC) {
		// Thêm đỉnh đích vào danh sách kề của đỉnh nguồn
		DSK[canh.dau].push_back(canh.cuoi);

		// Nếu đồ thị vô hướng, thêm đỉnh nguồn vào danh sách kề của đỉnh đích
		if (voHuong()) {
			DSK[canh.cuoi].push_back(canh.dau);
		}
	}

	// In ra danh sách kề (để kiểm tra)
	cout << "Danh sach ke:" << endl;
	for (int i = 1; i <= dinh; i++) {
		cout << i << ": ";
		for (int x : DSK[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

int DoThi::bac(int Dinh){
	int dem = 0;
	if (Dinh < 1 || Dinh > dinh)
		return -1;
	for (int j = 1; j <= dinh; j++)
	{
		if (MTK[dinh][j])
			dem++;
	}
	return dem;
}

int DoThi::tongBac(){
	int result = 0;
	for (int i = 1; i <= dinh; i++)
	{
		result += bac(i);
	}
	return result;
}

int DoThi::banBacRa(int dinh){
	int tong = 0;
	for (int j = 1; j <= dinh; j++)
	{
		tong += MTK[dinh][j];
	}
	return tong;
}

int DoThi::tongBanBacRa(){
	int tong = 0;
	for (int i = 1; i <= dinh; i++)
	{
		tong += banBacRa(i);
	}
	return tong;
}

int DoThi::banBacVao(int dinh){
	int tong = 0;
	for (int i = 1; i <= dinh; i++)
	{
		tong += MTK[i][dinh];
	}
	return tong;
}

int DoThi::tongBanBacVao(){
	int tong = 0;
	for (int i = 1; i <= dinh; i++)
	{
		tong += banBacRa(i);
	}
	return tong;
}

bool DoThi::dayDu(){
	for (int i = 1; i <= dinh; i++)
		for (int j = i + 1; j <= dinh; j++)
			if (MTK[i][j] == 0)
				return false;
	return true;
}

bool DoThi::haiphia() {
	mtkToDsk();
	memset(color, -1, sizeof(color));
	for (int i = 1; i <= dinh; i++) {
		if (color[i] == -1) {
			if (!bfsHaiPhia(i)) {
				return false;
			}
		}
	}
	return true;
}

void DoThi::dfs(int dinh){
	if (dinh < 1 || dinh > this->dinh) {
		cout << "Dinh khong hop le!" << endl;
		return;
	}
    mtkToDsk();
    vector<bool> visited(this->dinh + 1, false);
    cout << "DFS(" << dinh << ") = ";
    dfsUtil(dinh, visited);
    cout << endl;
}

void DoThi::dfsUtil(int dinh, vector<bool>& visited){
	cout << dinh;
	visited[dinh] = true;
	bool first = true;
	for (int x : DSK[dinh]) {
		if (!visited[x]) {
			if (first) {
				cout << ", ";
				first = false;
			}
			dfsUtil(x, visited);
		}
	}
}

void DoThi::dfsLienthong(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int x : DSK[u]) {
		if (!visited[x]) {
			dfsLienthong(x);
		}
	}
}

void DoThi::soThanhPhanLienThong() {
	mtkToDsk();
	int res = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= dinh; i++) {
		if (!visited[i]) {
			res++;
			cout << "cac dinh thuoc thanh phan lien thong thu: " << res << " :\n";
			dfsLienthong(i);
			cout << endl;
		}
	}
	//liet ke thanh phan lien thong
	if (res == 1) {
		cout << "Do thi lien thong!\n";
	}
	else cout << "Do thi khong lien thong!\n";
	cout << "so thanh phan lien thong: " << res << endl;
}


void DoThi::bfs(int dinh){
    queue<int> q;
    vector<bool> visited(this->dinh + 1, false);
    q.push(dinh);
    visited[dinh] = true;
    cout << "BFS(" << dinh << ") = ";
	while (!q.empty()) {
		int v = q.front(); //lay dinh o dau hang doi
		q.pop();
		cout << v << " ";
		for (int x : DSK[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
	cout << endl;
}

bool DoThi::bfsHaiPhia(int u) {
	//0: red, 1: blue
	queue<int> q;
	q.push(u);
	color[u] = 0; //0: red
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : ke[v]) {
			if (color[x] == -1) {
				color[x] = 1 - color[v];
			}
			else if (color[x] == color[v]) return false;
		}
	}
	return true;
}

