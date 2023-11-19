#include <iostream>
#include <cstring>
#include <fstream>
#include <climits>
#include <queue>
#define MAX 9999
using namespace std;

void input(int a[][100],int &n);
void output(int a[][100],int n);
void inputFile(int a[][100],int &n);
void addvertex(int a[][100],int &n);
void changeVertexInfo(int a[][100], int n);
void addEdge(int a[][100], int n);
void printVertexEdge(int a[][100], int n);
void displayVertexEdgeInfo(int a[][100], int n);
void changeWeight(int a[][100], int n);
void dfsTraversal(int a[][100], int n, int vertex, bool visited[]);
void dfsTraversalWrapper(int a[][100], int n, int startVertex);
void bfsTraversal(int a[][100], int n, int startVertex);
int Begin();
char parent[100];
void createGraph();
void dijkstra(int a[][100], int n);
int minDistance(int dist[], bool sptSet[], int n);
void printSolution(int dist[], int parent[], int n, char src, char dest);
void printPath(int parent[], int j);
int kteuler(int B[],int n);
void euler(int a[][100], int n);
bool isEdgeValid(int a[][100], int n, int v, int w);
void timChuTrinhEuler(int a[][100],int n);
void primMST(int a[][100], int n);
int minKey(int key[], bool mstSet[], int n);
void printMST(int a[][100], int parent[], int n);
int fordFulkerson(int a[][100], int s, int t);
bool bfs(int rGraph[][100], int n, int s, int t, int parent[]);


int startVertex;
int maxFlow;
int a[100][100],n,chooseBegin,chooseGraph;
char source, sink;
char vertex[100];
int main() {
	chooseBegin = Begin();
	
	switch(chooseBegin) {
		case -1 : return 0;
		case 0 : system("cls");
				main();
				break;
		case 1 : createGraph();
				main();
				break;
		case 2 : output(a,n);
				main();
				break;
		case 3 : addvertex(a,n);
				main();
				break;
		case 4 : changeVertexInfo(a, n);
				main();
    			break;
    	case 5 : addEdge(a, n);
				main();
    			break;
    	case 6 : printVertexEdge(a, n);
				main();
    			break;
    	case 7:
            	displayVertexEdgeInfo(a, n);
            	main();
            	break;
        case 8:
	            changeWeight(a, n);
	            main();
	            break;
	    case 9:
	            dijkstra(a, n);
	            main();
	            break;
	    case 10:
	            cout << "Enter the starting vertex for BFS traversal: ";
	            cin >> startVertex;
	            bfsTraversal(a, n, startVertex);
	            main();
	            break;
        case 11:
	            cout << "Enter the starting vertex for DFS traversal: ";
	            cin >> startVertex;
	            dfsTraversalWrapper(a, n, startVertex);
	            main();
	            break;
	    case 12:
	            euler(a, n);
	            main();
	            break;
	    case 13:
	            primMST(a, n);
	            main();
	            break;
	    case 14:
		{
		    cout << "Nhap dinh nguon cho thuat toan Ford-Fulkerson: ";
		    cin >> source;
		    cout << "Nhap dinh dich cho thuat toan Ford-Fulkerson: ";
		    cin >> sink;
		
		    int srcIndex = -1;
		    int destIndex = -1;
		    for (int i = 0; i < n; i++)
		    {
		        if (vertex[i] == source)
		        {
		            srcIndex = i;
		        }
		        if (vertex[i] == sink)
		        {
		            destIndex = i;
		        }
		    }
		
		    if (srcIndex == -1 || destIndex == -1)
		    {
		        cout << "Mot hoac ca hai dinh khong ton tai trong do thi!" << endl;
		        main();
		        break;
		    }
		
		    cout << "Dong chay lon nhat la: " << fordFulkerson(a, srcIndex, destIndex) << endl;
		
		    // Go back to main menu
		    main();
		    break;
		}

		default : cout << "Vui long chon so hop le !!!\n"; 
				main();
		
	}
	return 0;
}
void createGraph() {
	do {
		cout << "Chon cach nhap ma tran ke: " << endl;
		cout << "1.Nhap bang tay" << endl;
		cout << "2.Nhap bang file" << endl;
		cin >> chooseGraph;
	}while(chooseGraph !=1 && chooseGraph !=2);
	if(chooseGraph==1) {
		input(a,n);	
	}
	else {
		inputFile(a,n);
	}
}

int Begin() {
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "CHAO MUNG DEN VOI CHUONG TRINH DO THI GRAPH\n";
		cout << "-1.Thoat chuong trinh\n";
		cout << "0.Xoa man hinh\n";
		cout << "1.Tao do thi\n";
		cout << "2.Xuat ma tran ke\n";
		cout << "3.Them 1 dinh\n";
		cout << "4.Thay doi thong tin dinh\n" ;
		cout << "5.Them canh\n";
		cout << "6.Xuat cac ten dinh, ten canh\n";
		cout << "7. Xuat thong tin cua dinh va canh\n";
		cout << "8.Thay doi trong so cua canh\n";
		cout << "9.Duong di ngan nhat tu dinh v den w\n";
		cout << "10.Duyet do thi theo chieu rong\n";
		cout << "11.Duyet do thi theo chieu sau\n";
		cout << "12.Kiem tra chu trinh Euler\n";
		cout << "13. Cay khung be nhat\n";
		cout << "14. Dong chay lon nhat \n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "LUA CHON CUA BAN LA : ";
		cin >> chooseBegin;
	return chooseBegin;
}

bool bfs(int rGraph[][100], int n, int s, int t, int parent[]) {
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return (visited[t] == true);
}

int fordFulkerson(int a[][100], int s, int t) {
    int u, v;
    int rGraph[n][100];
    for (u = 0; u < n; u++)
        for (v = 0; v < 100; v++)
            rGraph[u][v] = a[u][v];

    int parent[n];
    int max_flow = 0;

    // Updating the residual values of edges
    while (bfs(rGraph, n, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        // Adding the path flows
        max_flow += path_flow;
    }

    return max_flow;
}

void primMST(int a[][100], int n) {
    int parent[100];   
    int key[100];      
    bool mstSet[100];  

    for (int i = 0; i < n; i++) {
        key[i] = MAX;    
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);

        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (a[u][v] && !mstSet[v] && a[u][v] < key[v]) {
                parent[v] = u;
                key[v] = a[u][v];
            }
        }
    }

    printMST(a, parent, n);
}

int minKey(int key[], bool mstSet[], int n) {
    int min = MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int a[][100], int parent[], int n) {
    cout << "Cay khung be nhat:\n";
    for (int i = 1; i < n; i++) {
        cout << "Canh: " << vertex[parent[i]] << " - " << vertex[i] << " co trong so: " << a[i][parent[i]] << endl;
    }
}



void euler(int a[][100], int n) {
	int B[n];
	
	for(int i=0;i<n;i++) {
		B[i]=0;
		for(int j=0;j<n;j++) {
			B[i] +=a[i][j];
		}
	}
	int kq = kteuler(B,n);
	if(kq) {
		cout << "Do thi co chu trinh euler\n";
		timChuTrinhEuler(a,n);
	}
	else cout << "Do thi khong co chu trinh euler\n";
}

void timChuTrinhEuler(int a[][100], int n) {
    int aCopy[100][100];
    memcpy(aCopy, a, sizeof(aCopy));
    char CE[MAX];
    char stack[MAX];
    int top = 1;
    stack[top] = vertex[0]; 
    int dCE = 0;
    do {
        char v = stack[top];
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (vertex[i] == v) {
                x = i;
                break;
            }
        }
        int hasNextEdge = 0;
        for (int w = 0; w < n; w++) {
            if (aCopy[x][w] == 1) {
                top++;
                stack[top] = vertex[w];
                aCopy[x][w] = 0;
                aCopy[w][x] = 0;
                hasNextEdge = 1;
                break;
            }
        }
        if (!hasNextEdge) {
            dCE++;
            CE[dCE] = v;
            top--;
        }
    } while (top != 0);
    cout << "Chu trinh euler la:\n";
    for (int x = dCE; x > 1; x--) {
        cout << CE[x] << " --> ";
    }
    cout << CE[1] << endl;
}


int kteuler(int B[],int n) {
	for(int i=0;i<n;i++) {
		if(B[i]%2==1) return false;
	}
	return true;
}

void printVertexEdge(int a[][100], int n) {
	cout << "Cac dinh la: ";
	for(int i=0;i<n;i++) {
		cout << vertex[i] << ", ";
	}
	cout << endl;
	cout << "Cac canh la: ";
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(a[i][j] == 1) {
				cout << vertex[i] << vertex[j] << ", ";
			}
		}
	}
	cout << endl;
}
void dijkstra(int a[][100], int n) {
    char src, dest;

    cout << "Nhap dinh nguon: ";
    cin >> src;
    cout << "Nhap dinh dich: ";
    cin >> dest;

    int dist[100];
    bool sptSet[100];
    int parent[100];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    int srcIndex = -1, destIndex = -1;
    for (int i = 0; i < n; i++) {
        if (vertex[i] == src) {
            srcIndex = i;
        }
        if (vertex[i] == dest) {
            destIndex = i;
        }
    }

    if (srcIndex == -1 || destIndex == -1) {
        cout << "Dinh nguon hoac dinh dich khong ton tai trong do thi!" << endl;
        return;
    }

    dist[srcIndex] = 0;
    parent[srcIndex] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);

        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && a[u][v] && dist[u] != INT_MAX && dist[u] + a[u][v] < dist[v]) {
                dist[v] = dist[u] + a[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[destIndex] != INT_MAX) {
        cout << "Duong di ngan nhat tu dinh " << src << " den dinh " << dest << " la: " << src;;
        printPath(parent, destIndex);
        cout << " voi tong trong so la " << dist[destIndex] << endl;
    } else {
        cout << "Khong co duong di tu dinh " << src << " den dinh " << dest << endl;
    }
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << " -> " << vertex[j];
}
int minDistance(int dist[], bool sptSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}



void addEdge(int a[][100], int n) {
    char sourceVertex, destinationVertex;
    int sourceIndex = -1, destinationIndex = -1;

    cout << "Nhap ten dinh nguon: ";
    cin >> sourceVertex;
    cout << "Nhap ten dinh dich: ";
    cin >> destinationVertex;

    for (int i = 0; i < n; i++) {
        if (vertex[i] == sourceVertex) {
            sourceIndex = i;
        }
        if (vertex[i] == destinationVertex) {
            destinationIndex = i;
        }
    }

    if (sourceIndex == -1 || destinationIndex == -1) {
        cout << "Mot hoac ca hai dinh khong ton tai trong do thi!" << endl;
        return;
    }

    a[sourceIndex][destinationIndex] = 1; 
    a[destinationIndex][sourceIndex] = 1; 

    cout << "Them canh thanh cong!" << endl;
}


void addvertex(int a[][100],int &n) {
	if(n<100) {
		n++;
		cout << "Nhap ten dinh moi: ";
		cin >> vertex[n-1];
		//nhap ma tran
			cout << "Nhap tinh chat ke cua dinh " << vertex[n-1] << " voi dinh khac (co(1), khong(0)): \n";
			for(int i=0;i<n;i++)
			{
				cout << "Voi dinh " << vertex[i] << " :";
				cin >> a[i][n-1];
				a[n-1][i] = a[i][n-1];
			}
	}
}


void inputFile(int a[][100],int &n) {
	ifstream iFile;
	iFile.open("lienketke.txt");
	if(iFile.is_open()) {
		iFile >>n;
		for(int i = 0; i < n; i++) {
			iFile >> vertex[i];
		}
		for(int i = 0; i < n; i++) {
			for(int j=0; j < n ; j++) {
				iFile >> a[i][j];
			}
		}
		iFile.close();
		cout << "Doc file thanh cong !!\n";
	}
	else {
		cout << "Loi, khong mo duoc file !!\n";
	}
}
void changeVertexInfo(int a[][100], int n) 
{
     char oldVertexName;
    cout << "Nhap ten dinh can thay doi thong tin: ";
    cin >> oldVertexName;

    int vertexIndex = -1;
    for (int i = 0; i < n; i++) {
        if (vertex[i] == oldVertexName) {
            vertexIndex = i;
            break;
        }
    }

    if (vertexIndex == -1) {
        cout << "Dinh khong ton tai trong do thi!" << endl;
        return;
    }

    char newVertexName;
    cout << "Nhap ten moi cho dinh " << oldVertexName << ": ";
    cin >> newVertexName;

    vertex[vertexIndex] = newVertexName; 

    cout << "Nhap thong tin moi cho dinh " << newVertexName << ": ";

    for (int i = 0; i < n; i++) {
        cin >> a[vertexIndex][i]; 
        a[i][vertexIndex] = a[vertexIndex][i]; 
    }

    cout << "Thay doi thong tin va ten cua dinh " << oldVertexName << " thanh cong!" << endl;
    cout << endl;
}

void input(int a[][100],int &n) {
	do {
		cout << "Nhap so luong dinh cua do thi : ";
		cin >>n;
	}while(n<=0||n>100);
	cout << "Nhap " << n << " ten cac dinh cua do thi theo thu tu : ";
	for(int i=0;i<n;i++)
	{
		cin >> vertex[i];
	}
	//nhap ma tran
	for(int i=0;i<n;i++)
	{
		cout << "Nhap tinh chat ke cua cac dinh voi dinh " << vertex[i] << " co(1), khong(0) : ";
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
		}
	}
}
void displayVertexEdgeInfo(int a[][100], int n) 
{
    char vertexName;
    cout << "Nhap ten dinh can xuat thong tin: ";
    cin >> vertexName;

    int vertexIndex = -1;
    for (int i = 0; i < n; i++) {
        if (vertex[i] == vertexName) {
            vertexIndex = i;
            break;
        }
    }

    if (vertexIndex == -1) {
        cout << "Dinh khong ton tai trong do thi!" << endl;
        return;
    }

    cout << "Thong tin cua dinh " << vertexName << ":" << endl;
    cout << "Cac dinh ke voi " << vertexName << ": ";
    for (int i = 0; i < n; i++) {
        if (a[vertexIndex][i] == 1) {
            cout << vertex[i] << ", ";
        }
    }
    cout << endl;
}
void changeWeight(int a[][100], int n) 
{
    char vertexName1, vertexName2;
    int weight;

    cout << "Nhap ten dinh dau cua canh: ";
    cin >> vertexName1;
    cout << "Nhap ten dinh cuoi cua canh: ";
    cin >> vertexName2;
    cout << "Nhap gia tri moi cua trong so: ";
    cin >> weight;

    int vertexIndex1 = -1;
    int vertexIndex2 = -1;
    for (int i = 0; i < n; i++) {
        if (vertex[i] == vertexName1) {
            vertexIndex1 = i;
        }
        if (vertex[i] == vertexName2) {
            vertexIndex2 = i;
        }
    }

    if (vertexIndex1 == -1 || vertexIndex2 == -1) {
        cout << "Mot trong hai dinh khong ton tai trong do thi!" << endl;
        return;
    }

    a[vertexIndex1][vertexIndex2] = weight;
    a[vertexIndex2][vertexIndex1] = weight;

    cout << "Da thay doi trong so cua canh " << vertexName1 << "-" << vertexName2 << " thanh " << weight << endl;
}
void dfsTraversal(int a[][100], int n, int vertex, bool visited[])
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (a[vertex][i] != 0 && !visited[i])
        {
            dfsTraversal(a, n, i, visited);
        }
    }
}

void dfsTraversalWrapper(int a[][100], int n, int startVertex)
{	
    bool visited[100] = {false};
    cout << "DFS Traversal: ";
    dfsTraversal(a, n, startVertex, visited);
    cout << endl;
}

void bfsTraversal(int a[][100], int n, int startVertex)
{
    bool visited[100] = {false};
    queue<int> q;

    cout << "BFS Traversal: ";

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (a[vertex][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

void output(int a[][100],int n) 
{
	for(int i=0;i<n;i++) cout << "----------";
	cout << endl;
	cout << "|";
	cout << "\t";
	for(int i=0;i<n;i++) {
		cout << "|" << vertex[i] << "\t";
	}
	cout << "|" << endl;
	for(int i=0;i<n;i++) {
		cout << "|" << vertex[i] << "\t";
		for(int j=0;j<n;j++) {
			cout << "|" << a[i][j] << "\t";
		}
		cout << "|" << endl;
	}
	for(int i=0;i<n;i++) cout << "----------";
}
