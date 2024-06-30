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

void DoThi::readDSC(string duongDan) {
	ifstream fileInput(duongDan);

	if (!fileInput.is_open()) {
		cout << "Khong the mo file: " << duongDan << endl;
		return;
	}

	// Xóa dữ liệu cũ
	DSC.clear();
	for (int i = 0; i <= dinh; ++i) {
		adj[i].clear();
	}
	memset(used, false, sizeof(used));

	// Đọc số đỉnh và số cạnh
	fileInput >> dinh >> canh;

	// Đọc thông tin từng cạnh
	for (int i = 0; i < canh; i++) {
		int x, y, w;
		fileInput >> x >> y >> w;

		// Thêm cạnh vào danh sách cạnh
		DSC.push_back({ x, y });

		// Thêm cạnh vào danh sách kề
		adj[x].push_back({ y, w });
		adj[y].push_back({ x, w });  // Nếu là đồ thị vô hướng
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

void DoThi::mtkToDsc() {
	DSC_w.clear();  // Xóa danh sách cạnh cũ

	for (int i = 1; i <= dinh; i++) {
		for (int j = i + 1; j <= dinh; j++) {  // Chỉ duyệt nửa trên của ma trận
			if (MTK[i][j] != 0) {
				DSC_w.push_back({ i, j, MTK[i][j] });
			}
		}
	}

	// In danh sách cạnh
	cout << dinh << " " << DSC_w.size() << endl;  // In số đỉnh và số cạnh
	for (const auto& canh : DSC_w) {
		cout << canh.x << " " << canh.y << " " << canh.w << endl;
	}
}

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
	DSK.clear();
	DSK.resize(dinh + 1);
	for (const auto& canh : DSC) {
		DSK[canh.dau].push_back(canh.cuoi);
		memset(used, false, sizeof(used));
		if (voHuong()) {
			DSK[canh.cuoi].push_back(canh.dau);
		}
	}
	cout << "Danh sach ke:" << endl;
	for (int i = 1; i <= dinh; i++) {
		cout << i << ": ";
		for (int x : DSK[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}

void DoThi::dscToMtk() {
	// Khởi tạo ma trận kề với tất cả các phần tử là 0
	MTK.clear();
	MTK.resize(dinh + 1, vector<int>(dinh + 1, 0));

	// Điền trọng số vào ma trận kề
	for (const auto& canh : DSC_w) {
		MTK[canh.x][canh.y] = canh.w;
		MTK[canh.y][canh.x] = canh.w;  // Vì là đồ thị vô hướng
	}

	// In ma trận kề
	cout << "Ma tran ke:\n";
	for (int i = 1; i <= dinh; i++) {
		for (int j = 1; j <= dinh; j++) {
			cout << MTK[i][j] << " ";
		}
		cout << "\n";
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

bool DoThi::vong()
{
    if (dinh < 3)
        return false;
    for (int u = 1; u <= dinh; u++)
        if (bac(u) != 2)
            return false;
    if (stplt != 1)
        return false;
    vector<bool> tham(dinh + 1, false);
    for (int u = 1; u <= dinh; u++)
    {
        if (!tham[u])
            if (dfsVong(u, -1, tham))
                return true;
    }
    return false;
}

bool DoThi::coChutTrinhEuler() {
	if (!voHuong()) {
		return false;  // Đồ thị phải vô hướng
	}

	// Kiểm tra tính liên thông
	soThanhPhanLienThong();
	if (stplt != 1) {
		return false;  // Đồ thị phải liên thông
	}

	// Kiểm tra bậc của các đỉnh
	for (int i = 1; i <= dinh; i++) {
		if (bac(i) % 2 != 0) {
			return false;  // Tất cả các đỉnh phải có bậc chẵn
		}
	}

	return true;
}

bool DoThi::coChutTrinhHamliton() {
	for (int i = 1; i <= dinh; i++) {
		if(degree[i] < dinh / 2) return false;
	}
	return true;
} 

void DoThi::euler(int v) {
	stack<int> st;
	vector<int> EC;
	st.push(v);

	while (!st.empty()) {
		int x = st.top();
		bool found = false;

		for (int y = 1; y <= dinh; y++) {
			if (MTK[x][y] > 0) {
				st.push(y);
				MTK[x][y]--;
				MTK[y][x]--; // Giảm cạnh cho đồ thị vô hướng
				found = true;
				break;
			}
		}

		if (!found) {
			st.pop();
			EC.push_back(x);
		}
	}

	reverse(EC.begin(), EC.end());
	cout << "Chu trinh Euler: ";
	for (int x : EC) {
		cout << x << " ";
	}
	cout << endl;
}

void DoThi::Hamilton(int start) {
	mtkToDsk();
	vector<int> path;
	vector<bool> visited(dinh + 1, false);
	path.push_back(start);
	visited[start] = true;

	if (HamiltonUtil(start, path, visited)) {
		cout << "Chu trinh Hamilton: ";
		for (int v : path) {
			cout << v << " ";
		}
		cout << start << endl;
	}
	else {
		cout << "Khong tim thay chu trinh Hamilton." << endl;
	}
}

bool DoThi::HamiltonUtil(int v, vector<int>& path, vector<bool>& visited) {
	if (path.size() == dinh) {
		// Kiểm tra nếu có cạnh nối đỉnh cuối với đỉnh đầu
		if (MTK[v][path[0]] == 1) {
			return true;
		}
		return false;
	}

	for (int i = 1; i <= dinh; i++) {
		if (MTK[v][i] == 1 && !visited[i]) {
			visited[i] = true;
			path.push_back(i);

			if (HamiltonUtil(i, path, visited)) {
				return true;
			}

			visited[i] = false;
			path.pop_back();
		}
	}

	return false;
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

bool DoThi::dfsVong(int dinh, int u, vector<bool>& visited)
{
    visited[dinh] = true;
    for (int i : DSK[dinh])
    {
        if (!visited[i] && dfsVong(i, dinh, visited)) 
            return true;
        else if (i != u) 
            return true;
    }
    return false;
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
	stplt = res;
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

void DoThi::prim(int start) {
	//mtkToDsc();
	vector<Canh> MST;
	vector<bool> used(dinh + 1, false);
	vector<int> key(dinh + 1, INT_MAX);
	vector<int> parent(dinh + 1, -1);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	key[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		if (used[u]) continue;
		used[u] = true;

		for (auto& edge : adj[u]) {
			int v = edge.first;
			int weight = edge.second;

			if (!used[v] && weight < key[v]) {
				parent[v] = u;
				key[v] = weight;
				pq.push({ key[v], v });
			}
		}
	}

	int totalWeight = 0;
	for (int i = 1; i <= dinh; i++) {
		if (parent[i] != -1) {
			MST.push_back({ parent[i], i, key[i] });
			totalWeight += key[i];
		}
	}

	cout << "Tong trong so cay khung nho nhat: " << totalWeight << endl;
	cout << "Cac canh cua cay khung nho nhat:" << endl;
	for (Canh e : MST) {
		cout << e.x << " - " << e.y << " : " << e.w << endl;
	}
}
