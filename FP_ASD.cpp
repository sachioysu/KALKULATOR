/*	FINAL PROJECT ASD SEMESTER 1

  	NAMA KELOMPOK
  	
	AFIFAH HASNA AMALIA     22.02.0803
	HAFIDH MUHAMMAD YUSUF   22.02.0831
	SISKA ANWAR             22.02.0840
	FATIA NURUL AMINAH      22.02.0871
	RASYAD AL FAYYADH       22.02.0874 

	PROGRAM Aplikasi Uang Digital*/
	
#include <iostream>//Untuk fungsi keluaran dan inputan
#include <conio.h>//untuk getch
//#include <stdlib.h>
#include <iomanip>//untuk setw, setiosflag & setprecision
#include <windows.h>//untuk menjalankan gotoxy(mengatur kolom dan baris)

using namespace std;

void point (int x, int y) {
	COORD C;//menentukan posisi cursor
	C.X = x;//kolom
	C.Y = y;//baris
	SetConsoleCursorPosition/*menetapkan posisi kursor ke layar*/(GetStdHandle(STD_OUTPUT_HANDLE),C);
}

int id,pil,pilmenu;//type data integer untuk memasukkan id, pilihan menu, dan dan pil
int i,a;
int s=0;
int n=0;
bool passcode;//type data yang berfungsi untuk true or false 

struct signup {//struct untuk membuat akun
	int id; 
	int pin;
	char username[25];
}client[25];

struct data {//struct untuk qrist u digital dan riwayat transaksi
	double saldo=0;
	int qris,mix;
	int topup;
} menu[25];


void header() {
	system("color 8F");
	point(0,0);	cout<<"============================================================";
	point(0,1);	cout<<"|                      U-DATA E-MONEY                      |";
	point(0,2);	cout<<"|";	
	point(59,2); cout<<"|";
	point(0,3);	cout<<"============================================================";
}

void login() {
	point(0,4);	   cout<<"|                |";
	point(43,4);   cout<<"|               |";
	point(0,5);    cout<<"|   [1] Daftar   |";
	point(25,5);   cout<<"[0]Exit[0]";
	point(43,5);   cout<<"|   Login [2]   |";
	point(0,6);    cout<<"|                |";
	point(43,6);   cout<<"|               |";
	point(48,8);   cout<<"|======|   |";
	point(0,7);    cout<<"============================================================";
	point(0,9);    cout<<"============================================================";
	point(0,8);    cout<<"|   Silahkan Pilih Menu di Atas      |======| "; cin>>pil;
}

void beranda() {
		point(0,2);    cout<<"|User                        =="<<setw(28)<<client[i].username;
		point(0,4);    cout<<"|";
		point(59,4);   cout<<"|";
		point(0,5);    cout<<"|   [1] Top Up U-DIGITAL";
		point(37,5);   cout<<"Saldo Saya Saat Ini   |";
	
		point(0,6);    cout<<"|";
		point(37,6);   cout<<"===================   |";
	
		point(0,7);    cout<<"|   [2] QRIS U-DIGITAL";
		point(37,7);   cout<<"|                 |   |";
		
		point(0,8);    cout<<"|";
		point(37,8);   cout<<"|                 |   |";
		s=i;
		point(39,8);   cout<<"Rp. "<<setiosflags(ios::fixed)<<setprecision(2)<<menu[s].saldo;
		
		point(0,9);    cout<<"|   [3] Riwayat Transaksi U-DIGITAL";
		point(37,9);   cout<<"|                 |   |";
			
		point(0,10);   cout<<"|";
		point(37,10);  cout<<"===================   |";
	
		point(0,11);   cout<<"|   [4] Log out";
		point(59,11);  cout<<"|";
	
		point(0,12);   cout<<"============================================================";
		point(48,13);  cout<<"|======|   |";
		point(0,14);   cout<<"============================================================";
		
		point(0,13);   cout<<"|   Silahkan Pilih Menu di Atas      |======| "; cin>>pilmenu;
}

void loop() {
	for(i=0; i<n; i++) {
        if(id==(client[i].id)) {
        	s=i;
        	passcode=true;
        	break;
    	}
        else
        	passcode=false;
    }
}	



int main () {
	login:
	system ("cls");
	header();
	login();
		if (pil<3){
			if (pil==1){
				point(0,10);      cout<<"|";
				point(59,10);	  cout<<"|";
				point(0,11);      cout<<"|   ID [5 angka]";
				point(37,11);     cout<<":";
				point(59,11);     cout<<"|";
				point(0,12);      cout<<"|   Username";
				point(37,12);     cout<<":";
				point(59,12);     cout<<"|"; 
				point(0,13);      cout<<"|   Pin [5 angka]";
				point(37,13);     cout<<":";
				point(59,13);     cout<<"|";
				point(0,14);      cout<<"|";
				point(59,14);     cout<<"|";
				point(0,15);      cout<<"============================================================";	
				point (39,11);    cin>>id;
				if (id<99999) {
					loop();
					if (passcode==true) {
						point(0,17);
		        		cout<<"Id ini telah digunakan di akun lain [enter]";
		        		getch();
		        		goto login;	//kembali ke menu login
		        			        		
		        	}
		        	else {
        			point(39,12); cin.ignore(); cin.getline(client[n].username, 25);
        			point(39,13); cin>>client[n].pin;
        			}
        			n+=1;
        			client[i].id=id;
        			goto beranda;
				}
				else 
				point(0,17);
				cout<<"Max ID Number = 5 [enter]";
				getch();
				goto login;

			}
			else if (pil==2){
				point(0,10);	cout<<"|";
				point(59,10);	cout<<"|";
				point(0,11);	cout<<"|   Masukan ID Anda"; 
				point(37,11);	cout<<":";
				point(59,11);	cout<<"|";
				point(0,12);	cout<<"|";
				point(59,12);	cout<<"|";
				point(0,13);	cout<<"============================================================";
			
				point(39,11);	cin>>id;	
				loop();
				
		       		if(passcode==false) {
		       			point(4,12); cout<<"tidak ditemukan [enter]";
		       			getch();
			       		goto login;
		       		}
		       		else {
		       			n+=1;
	        			client[i].id=id;
						goto beranda;
		      		}
			}
			
			else if (pil==0){
			cout<<"\n\nAnda telah keluar dari aplikasi";
			return 0;
			}
		}
		
		else
		cout<<"\n\nmaaf anda salah input [enter]";
		getch();
		goto login;
	
	
	beranda:
	system ("cls");
	header();
		beranda();
		switch (pilmenu) {
			
			case 1:
			loop();
            if(passcode==true) {
            	point(59,15);
					cout<<"|";
					point(0,16);
					cout<<"============================================================";
					point(0,15);
	            	cout<<"|   Masukan Nominal Top Up      : Rp. "; cin>>menu[i].topup;
	            	menu[s].saldo+=menu[i].topup;		
	   		}	
			goto beranda;	
	        break;
  
	        case 2:
	        loop();
	        if(passcode==true) {
	        	point(59,15);
					cout<<"|";
				point(0,16);
					cout<<"============================================================";
				point(0,15);
	        		cout<<"|   Masukan Nominal Pembayaran  : Rp. "; cin>>menu[i].qris;
	        	
	        	if(menu[i].qris>(menu[s].saldo)){
	        		point(59,17);
						cout<<"|";
					point(59,18);
						cout<<"|";
					point(0,19);
						cout<<"============================================================";
					point(0,17);
	        			cout<<"|   saldo tidak mencukupi !\n";
	        			cout<<"|   Pembayaran mix              : Rp. "; cin>>menu[i].mix;
	        			menu[s].saldo+=menu[i].mix;
	        	
	        		if(menu[s].saldo>=menu[i].qris){
	        			menu[s].saldo-=menu[i].qris;
	       			}
	        	} else menu[s].saldo-=menu[i].qris;
			}
			goto beranda;
			break;
			
			case 3:
			cout<<endl;
			loop();
				point(59,15); cout<<"|";
	        	point(59,16); cout<<"|";
				point(0,17);  cout<<"============================================================";
				point(0,15);  cout<<"|   top up terakhir anda sebesar      : + Rp. "<<menu[i].topup;
				point(0,16);  cout<<"|   Pembayaran terakhir anda sebesar  : - Rp. "<<menu[i].qris;	
			getch();
			goto beranda;			
			break;

			case 4:
			goto login;
			system("cls");
			break;
			
			default: 
			point(0,16);  cout<<"pilihan menu tersebut tidak ada di halaman beranda anda [enter]";
			getch();
	 	 	goto beranda;
		} 
	getch();
	return 0;
}
