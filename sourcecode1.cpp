#include <iostream>
#include <fstream>
using namespace std;

void input(int a[][100],int &n);
void output(int a[][100],int n);
void inputFile(int a[][100],int &n);
void addvertex(int a[][100],int &n);
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
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "LUA CHON CUA BAN LA : ";
		cin >> chooseBegin;
	return chooseBegin;
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
