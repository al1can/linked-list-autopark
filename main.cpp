#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
using namespace std;

class araba {
    public : string plaka;
    public : string aracTipi;
    public : int ucret;
};

struct node
{
	araba data;
	struct node* next;
};

struct node* basaEkle(struct node* head, araba araba)
{
	if (head == NULL)
	{
		struct node* temp = new node();
		temp->data = araba;
		temp->next = NULL;
		head = temp;
		cout << "Ilk araba eklendi." << endl;
	}
	else
	{
		struct node* temp = new node();
		temp->data = araba;
		temp->next = head;
		head = temp;
		cout << "Araba listenin basina basariyla eklendi" << endl;
	}
	return head;
}

struct node* sonaEkle(struct node* head, araba araba)
{
	if (head == NULL) {
		struct node* temp = new node();
		temp->data = araba;
		temp->next = NULL;
		head = temp;
		cout << "Ilk araba eklendi" << endl;
	}
	else {
		struct node* temp = new node();
		temp->data = araba;
		temp->next = NULL;
		
		struct node* temp2 = head;
		while (temp2->next != NULL)
			temp2 = temp2->next;

		temp2->next = temp;
		cout << "Araba listenin sonuna basariyla eklendi" << endl;
	}
	return head;
}

void verileriYazdir(struct node* head)
{
	system("cls");
	if (head == NULL)
		cout << "Otopark bos" << endl;
	else
	{ 
	struct node* temp = head;
	int i = 1;
	while (temp != NULL)
	{
	    cout << i << ". Arac: " << endl;
		cout << "Aracin plakasi: " << temp->data.plaka << endl;
		cout << "Aracin tipi: " << temp->data.aracTipi << endl;
		cout << "Aracin ucreti: " << temp->data.ucret << endl;
		cout << endl;
		temp = temp->next;
		i++;
	}
}}

int aracSayisi(struct node* head)
{
	int adet = 0;
	if (head==NULL)
	{
		cout << "Otopark bos" << endl;
		return 0;
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			adet++;
			temp = temp->next;
		}
		return adet;
	}
}

struct node* aracSil(struct node* head) {
    cout << head->data.plaka << " plakali arac otoparktan silindi";
    head = head->next;
    return head;
}

void verileriKaydet(struct node* head) {
    ofstream dosya("dosya.txt");
	
	if (head == NULL)
		cout << "liste bos" << endl;
	else
	{
		struct node* temp = head;
		int i = 1;
		while (temp != NULL)
		{
			dosya << "arac plakasi" << temp->data.plaka << endl;
            dosya << "arac tipi" << temp->data.aracTipi << endl;
	        dosya << "arac ucreti" << temp->data.ucret << endl;
			temp = temp->next;
			i++;
		}
	}
	
	dosya.close();
}

void verileriOku() {
    string veriler;
    ifstream dosya("dosya.txt");
    while(getline(dosya, veriler)) {
        cout << veriler << endl;
    }
    dosya.close();
}

int ucretToplami(struct node* head)
{
	int toplam = 0;
	if (head == NULL)
	{
		cout << "Otopark bos" << endl;
		return 0;
	}
	else
	{
		struct node* temp = head;
		while (temp != NULL)
		{
			toplam += temp->data.ucret;
			temp = temp->next;
		}
		return toplam;
	}
}

int main()
{
	struct node* head = NULL;
	int secim, n, sayi;
	araba araba;
	string plaka;
	string aracTipi;
	int ucret;
	while (1)
	{
		cout << endl;
		cout << "Otopark Takip Uygulamasi" << endl;
		cout << "1) Basa arac ekleme" << endl;
		cout << "2) Sona arac ekleme" << endl;
		cout << "3) Araclari yazdir" << endl;
		cout << "4) Arac sayisini yazdir" << endl;
		cout << "5) Ucret toplamini yazdir" << endl;
		cout << "6) Arac sil" << endl;
		cout << "7) Verileri kaydet" << endl;
		cout << "8) Verileri oku" << endl;
		cout << "9) Cikis" << endl;
		
		cin >> secim;
		
		switch (secim)
		{
		case 1: cout << "Basa eklenecek aracin bilgileri : " << endl;
			cout << "\tAracin plakasini giriniz: ";
			cin >> plaka;
			cout << endl;
			
			cout << "\tAracin tipini giriniz: ";
			cin >> aracTipi;
			cout << endl;
			
			cout << "\tAracin ucretini giriniz: ";
			cin >> ucret;
			cout << endl;
			
			araba.plaka = plaka;
			araba.aracTipi = aracTipi;
			araba.ucret = ucret;
			head = basaEkle(head, araba);
			break;
		case 2: cout << "Sona eklenecek aracin bilgileri : " << endl;
			cout << "\tAracin plakasini giriniz: ";
			cin >> plaka;
			cout << endl;
			
			cout << "\tAracin tipini giriniz: ";
			cin >> aracTipi;
			cout << endl;
			
			cout << "\tAracin ucretini giriniz: ";
			cin >> ucret;
			cout << endl;
			
			araba.plaka = plaka;
			araba.aracTipi = aracTipi;
			araba.ucret = ucret;
			head = sonaEkle(head, araba);
			break;
		case 3:
		    verileriYazdir(head);
			break;
		case 4:
		    n = aracSayisi(head);
			cout << "Otoparktaki arac sayisi: " << n << endl;
			break;
		case 5:
		    n = ucretToplami(head);
		    cout << "Toplam ucret: " << n << endl;
		    break;
		case 6:
		    head = aracSil(head);
		    break;
	    case 7:
		    verileriKaydet(head);
		    break;
		case 8:
		    verileriOku();
		    break;
		case 9: cout << "Programdan basariyla ciktiniz";
			return 0;
		default:
			cout << "Hatali secim yaptiniz";
			break;
		}
	}
	return 0;
}

		
	
