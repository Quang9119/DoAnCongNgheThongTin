#include <iostream>
#include <cstring>
#include <fstream>
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
int Begin();
void createGraph();


int a[100][100],n,chooseBegin,chooseGraph;
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
		cout << "8.Thay doi trong so cua canh";
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "LUA CHON CUA BAN LA : ";
		cin >> chooseBegin;
	return chooseBegin;
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
void output(int a[][100],int n) {
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
