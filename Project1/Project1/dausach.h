#pragma once

#include"load_file.h"

using namespace std;

string chuan_hoa_chuoi(string s);

string viet_in_hoa(string s);

bool kt_trung_ma_sach(NODE_DMS* phead, string ma);
string masach(LIST_DMS ldms);
//===========Dau Sach=====================
void chuan_hoa_chu(string& a);

//=============== tao ma IBNS radom ============
int kt_trung_ISBN(string a, LIST_DS lds);
//string tao_ISBN(LIST_DS lds);

//===============nhap dau sach================
void them_dau_sach(LIST_DS& lds);

//============= xuat danh sach dau sach------
void xuat_ds_dau_sach(LIST_DS lds);

//========xoa dau sach ================
int kt_dausach(string a, LIST_DS lds);
void xoa(LIST_DS& lds);

//=============hieu chinh dau sach==========
void hieu_chinh_dau_sach(LIST_DS lds);
//=======danh muc sach=============

int  kt_trung_ma_dausach(LIST_DS lds, string a);

istream& operator>>(istream& is, danhmucsach& a);

NODE_DMS* khoi_tao_nodedms(danhmucsach a);
//==============them danh muc sach==============
void them_dms(list_danhmucsach& ds_dms, danhmucsach a);

ostream& operator<<(ostream& os, dausach a);
void xuat_ds_dms_1_ds(LIST_DMS ldms);
//================= xuat danh muc sach================
void xuat_ds_dms(LIST_DS lds);
//===========sap xep theo the loai
void sap_xep_ds_theo_ten(LIST_DS& dsDs);

//tìm sach
void tim_sach(LIST_DS& l_ds);

bool checkDegit(string& s)
{
	if (s[0] == '-')
		return false;
	while (s.length() > 1 && s[0] == '0')
	{
		s.erase(s.begin() + 0);
	}

	while (s.length() > 0 && s[0] == ' ')
	{
		s.erase(s.begin() + 0);
	}

	while (s.length() > 0 && s[s.length() - 1] == ' ')
	{
		s.erase(s.begin() + s.length() - 1);
	}

	for (int i = 0; i < s.length(); ++i)
		if (s[i] < '0' || s[i] > '9')
			return false;
	return true;
}

void hien_menu_sach()
{
	LIST_DS l_ds;

	bool kt_menu = true;
	//===============load file =========
	doc_file_ds_dau_sach(l_ds);
	//=========== xu ly menu=============
	while (kt_menu == true)

	{
		system("cls");
		cout << "\t\t\t\ ========= MENU SACH =================" << endl;

		cout << "\t\t\t\ 1. Cap nhat dau sach\n";
		cout << "\t\t\t\ 7. Xoa dau sach\n";
		cout << "\t\t\t\ 2. Hien thi cac dau sach\n";
		cout << "\t\t\t 3. Cap nhat danh muc sach\n";
		cout << "\t\t\t 4. Hien thi danh muc sach\n";
		cout << "\t\t\t 5. Tim thong tin sach\n";
		cout << "\t\t\t\ 6. Sap xep sach tang dan\n";
		cout << "\t\t\t\ 8. Chi sua dau sach\n";
		cout << "\t\t\t 0. Thoat\n";
		cout << "\t\t\t ==========================\n" << endl;
		cout << "Nhap lua chon: ";
		int lc;
		cin >> lc;
		switch (lc)
		{
		case 1:
		{
			if (l_ds.sl == MAX)
			{
				cout << "Them khong thanh cong ! datsa day! " << endl;
				system("pause");
			}
			else
			{
				int sl; cout << "nhap so luong dau sach can them: "; cin >> sl;
				for (int i = 1; i <= sl; i++)
				{
					cout << " Dau sach duoc them thu" << i << endl;
					them_dau_sach(l_ds);
				}
			}
			break;

		}
		case 2: {

			xuat_ds_dau_sach(l_ds);
			system("pause");
			break;
		}


		case 3: {
			string a;// luu ma ibns can nhap ds
			cin.ignore();
			cout << " Nhap  dau sach can them danh muc sach (nhap ISBN): "; getline(cin, a);
			a = viet_in_hoa(chuan_hoa_chuoi(a));
			int i = kt_trung_ISBN(a, l_ds);
			if (i == -1)
			{
				cout << " Ma dau sach khong ton tai!" << endl;
				system("pause");
			}
			else
			{
				// them danh muc sach cho dau sach thu i: 
				int sl;
				cout << " Nhap so luong sach can them: "; cin >> sl;
				cin.ignore();//chi xoa cho sv dau tien
				for (int j = 0; j < sl; j++)
				{

					cout << "-------Nhap danh muc sach " << j + 1 << "---------------" << endl;

					/*string masach;
					do {
						masach = l_ds.ds_dausach[i]->ISBN + to_string(j + 1);
					}
					while(kt_trung_ma_sach(l_ds.ds_dausach[i]->dms.pHead, masach) == true);*/

					danhmucsach a;
					a.masach = l_ds.ds_dausach[i]->ISBN + to_string(LaySoLuongDSMS(l_ds.ds_dausach[i]->dms));

					cout << "Ma sach " << j + 1 << ": " << l_ds.ds_dausach[i]->ISBN + to_string(+j + 1) << endl;

					//nhap 1 danh muc sach
					cin >> a;

					them_dms(l_ds.ds_dausach[i]->dms, a);
				}
			}
			break;
		}

		case 4:
		{
			xuat_ds_dms(l_ds);
			system("pause");

			break;
		}

		case 5:
		{
			tim_sach(l_ds);
			system("pause");
			break;
		}
		case 6:
		{
			sap_xep_ds_theo_ten(l_ds);
			system("pause");
			break;
		}
		case 7:
		{
			if (l_ds.sl == 0)
			{
				cout << " Khong thanh cong ! Data rong." << endl;
				system("pause");
			}
			else
			{
				xoa(l_ds);
			}
			break;
		}
		case 8: {
			if (l_ds.sl == 0)
			{
				cout << "Data rong!" << endl;
				system("pause");
			}
			else
			{
				hieu_chinh_dau_sach(l_ds);
			}
			break;

		}
		case 0:
		{
			kt_menu = false;
			break;
		}

		}


	}

}

//==================dau sach============

//================tao mang  tu tang=====

string tao_ISBN(LIST_DS lds)
{
	string a = "ISBN000";
	do {
		for (int i = 4; i < a.length(); i++) {
			a[i] = rand() % (57 - 48 + 1) + 48;//(b-a+1)+a[a,b]
		}
	} while (kt_trung_ISBN(a, lds) >= 0);
	return a;
}

int kt_trung_ISBN(string a, LIST_DS lds)
{
	for (int i = 0; i < lds.sl; i++) {
		if (lds.ds_dausach[i]->ISBN == a) {
			cout << "ok";
			return i;
		}
	}
	return -1;
}
//================them dau sach====================
void them_dau_sach(LIST_DS& lds) {
	DAUSACH* p = new DAUSACH;
	//	p->ISBN = tao_ISBN(lds);
	cin.ignore();
	cout << "Nhap ten sach: "; getline(cin, p->tensach);
	cout << "Nhap tac gia: "; getline(cin, p->tacgia);
	cout << "Nhap the loai: "; getline(cin, p->theloai);
	cout << "Nhap ISBN:"; cin >> p->ISBN;
	cout << "Nhap so trang: "; cin >> p->sotrang;
	cout << "Nhap nam xuat ban: "; cin >> p->namxuatban;
	lds.ds_dausach[lds.sl] = p;
	lds.sl++;
	//===============chuan hoa===========
	p->tensach = viet_in_hoa(chuan_hoa_chuoi(p->tensach));
	p->tacgia = viet_in_hoa(chuan_hoa_chuoi(p->tacgia));
	p->theloai = viet_in_hoa(chuan_hoa_chuoi(p->theloai));

	//khoi danh muc sach
}

//MAX
bool themDauSach(LIST_DS& l, DAUSACH* ds)
{
	if (l.sl == MAX)
		return false;

	l.ds_dausach[l.sl] = ds;
	l.sl++;

	return true;
}

//============xuat danh sach dau sach==================
void xuat_ds_dau_sach(LIST_DS lds) {
	for (int i = 0; i < lds.sl; i++) {
		cout << "======================= Dau Sach" << i + 1 << " ==============" << endl;
		cout << " ISBN: " << lds.ds_dausach[i]->ISBN << endl;
		cout << " ten sach: " << lds.ds_dausach[i]->tensach << endl;;
		cout << " tac gia: " << lds.ds_dausach[i]->tacgia << endl;
		cout << " the loai: " << lds.ds_dausach[i]->theloai << endl;
		cout << " so trang: " << lds.ds_dausach[i]->sotrang << endl;
		cout << " nam xuat ban: " << lds.ds_dausach[i]->namxuatban << endl;


	}
}


// ===============Danh Muc Sach============



/*int  kt_trung_ma_dausach(LIST_DS lds, string a) {
	for (int i = 0; i < lds.sl; i++) {
		if (_stricmp(lds.ds_dausach[i]->ISBN.c_str(), a.c_str()) == 0) {
			return i;
		}
	}
	return -1;//khong ton tai
}
*/
// ================kiem tra rong=================
bool ListDMSIsEmpty(LIST_DMS l)
{
	return l.pHead == NULL;
}


//-------------Nhap 1 danh muc sach-----------

istream& operator>>(istream& is, danhmucsach& a)
{
	cout << "Trang thai sach (0: cho muon duoc - 1: da co doc gia muon - 2: sach da thanh ly): ";
	cin >> a.trangthai;
	while (a.trangthai != 0 && a.trangthai != 1 && a.trangthai != 2)
	{
		cout << "Nhap sai trang thai!\n";
		cout << "Nhap lai trang thai (0: cho muon duoc - 1: da co doc gia muon - 2: sach da thanh ly): ";
		cin >> a.trangthai;
	}
	cin.ignore();
	cout << "Nhap vi tri: "; getline(is, a.vitri);
	return is;
}

NODE_DMS* khoi_tao_nodedms(danhmucsach a)
{
	NODE_DMS* p = new NODE_DMS;
	p->data = a;
	p->pNext = NULL;
	return p;
}


//===================Ham them vao cuoi==============

void them_dms(LIST_DMS& ds_dms, danhmucsach a)
{
	NODE_DMS* p = khoi_tao_nodedms(a);
	if (ds_dms.pHead == NULL)
	{
		ds_dms.pHead = ds_dms.pTail = p;
	}
	else
	{
		ds_dms.pTail->pNext = p;//lien ket
		ds_dms.pTail = p;//cap nhat ptail
	}
	ds_dms.sl++;
}


//================= tim ma sach trung ===================
NODE_DMS* search_DMS1(dausach ds, string masach) {
	NODE_DMS* p;
	p = ds.dms.pHead;
	while (p != NULL && p->data.masach != masach)
		p = p->pNext;
	return (p);
}

void xoa_dms(LIST_DMS& ldms, string vt)
{
	NODE_DMS* h = NULL;
	for (NODE_DMS* k = ldms.pHead; k != NULL;)
	{
		if (_stricmp(k->data.masach.c_str(), vt.c_str()) == 0 && k == ldms.pHead)
		{
			// ---vt ở đầu => xóa đầu ------
			ldms.pHead = ldms.pHead->pNext;
			delete k;// k vô định
			k = ldms.pHead;//nhảy về đầu- neu lên bước lặp =>sot pt
			// không được nhảy bước==>sử dụng for khuyết
		}
		else//lkac vt===vt nhưng k phải đầu
		{
			if (_stricmp(k->data.masach.c_str(), vt.c_str()) == 0)//trùng
			{
				//----------xóa--------
				h->pNext = k->pNext;
				delete k;//vô định
				k = h;//nhảy lại
				if (h->pNext == NULL)// h đang là cuối => chúng ta vùa xóa cuối
					ldms.pTail = h;
				return;
			}
			h = k;//nhảy theo k ++  =pt+2
			k = k->pNext;
		}
	}

}

ostream& operator<<(ostream& os, danhmucsach  a)
{
	cout << "ma sach: " << a.masach << endl;
	cout << " trang thai:  " << a.trangthai << endl;
	cout << " vi tri:  " << a.vitri << endl;

	return os;
}

void xuat_ds_dms_1_ds(LIST_DMS ldms)
{
	int i = 1;
	for (NODE_DMS* k = ldms.pHead; k != NULL; k = k->pNext)
	{
		cout << "\t\t----------Danh muc sach: " << i++ << "--------" << endl;
		cout << k->data;

	}
}

void xuat_ds_dms(LIST_DS lds)
{
	for (int i = 0; i < lds.sl; i++)
	{
		cout << "\t\t======Danh sach danh muc sach:" << lds.ds_dausach[i]->tensach << "==========" << endl;
		cout << endl;
		/*NODE_DMS* k = lds.ds_dausach[i]->dms.pHead;
		cout << k;*/
		int j = 1;
		for (NODE_DMS* k = lds.ds_dausach[i]->dms.pHead; k != NULL; k = k->pNext)
		{
			cout << "\t\t-------------- Danh muc sach:" << j++ << "---------" << endl;
			cout << k->data;

		}
	}
	cout << endl;
}

//===========sap xep theo the loai
void sap_xep_ds_theo_ten(LIST_DS& dsDs) {


	//sort theo the loai (inter...) vì số lượng MAX == 1000 nên dùng inter..
	for (int i = 0; i < dsDs.sl - 1; ++i)
	{
		for (int j = i + 1; j < dsDs.sl; ++j)
		{
			if (dsDs.ds_dausach[i]->theloai > dsDs.ds_dausach[j]->theloai)
				swap(dsDs.ds_dausach[i], dsDs.ds_dausach[j]);
		}
	}
	//sort theo ten
	for (int i = 0; i < dsDs.sl - 1; ++i)
	{
		int soLuong = 1; //TÌM SỐ LƯỢNG SÁCH CÙNG 1 THỂ LOẠI
		for (int j = i + 1; j < dsDs.sl; ++j)
		{
			if (dsDs.ds_dausach[i]->theloai != dsDs.ds_dausach[j]->theloai)
				break;
			soLuong++;
		}

		//SẮP XẾP TỪ VỊ TRÍ LẠI THEO TÊN SÁCH
		for (int p = i; p < soLuong - 1; ++p)
		{
			for (int j = i + 1; j < soLuong; ++j)
			{
				if (dsDs.ds_dausach[p]->tensach > dsDs.ds_dausach[j]->tensach)
					swap(dsDs.ds_dausach[p], dsDs.ds_dausach[j]);
			}
		}
		i += soLuong;//TĂNG CHỈ SỐ I (DUYỆT TỚI THỂ SÁCH TI)
	}
	xuat_ds_dau_sach(dsDs);
}

/*
//===========sap xep theo the loai
void sap_xep_ds_theo_ten(LIST_DS& dsDs) {
	//sort theo the loai
	for (int i = 0; i < dsDs.sl - 1; i++)
	{
		string check = dsDs.ds_dausach[i]->theloai;
		if (dsDs.ds_dausach[i + 1]->theloai == check) {
			continue;
		}
		else {
			for (int j = i + 2; j < dsDs.sl; j++)
			{
				if (check == dsDs.ds_dausach[j]->theloai) {
					swap(dsDs.ds_dausach[i + 1], dsDs.ds_dausach[j]);
					break;
				}
			}
		}
	}
	for (int i = 0; i < dsDs.sl - 1; i++) {
		if (dsDs.ds_dausach[i]->theloai == dsDs.ds_dausach[i + 1]->theloai) {
			for (int j = i + 1; j < dsDs.sl; j++) {
				if (dsDs.ds_dausach[i]->theloai == dsDs.ds_dausach[j]->theloai) {
					string checkOne = dsDs.ds_dausach[i]->tensach;
					checkOne = viet_in_hoa(chuan_hoa_chuoi(checkOne));
					string checkTwo = dsDs.ds_dausach[j]->tensach;
					checkTwo = viet_in_hoa(chuan_hoa_chuoi(checkTwo));
					if ((int)checkOne[0] > (int)checkTwo[0]) {
						swap(dsDs.ds_dausach[i], dsDs.ds_dausach[j]);
					}
				}
				else {
					break;
				}
			}
		}
	}
	//sort theo ten
	cout << "Da sap xep" << endl;
}

*/

//=================tim kiem theo ten==========================
void tim_sach(LIST_DS& l_ds)
{

	string ten_sach_can_tim, ten_sach;
	bool tim_thay{ false };
	cout << "Nhap ten sach can tim: ";
	cin.ignore();
	getline(cin, ten_sach_can_tim);
	ten_sach_can_tim = viet_in_hoa(chuan_hoa_chuoi(ten_sach_can_tim));
	int so_thu_tu, k{ 0 };

	for (int i = 0; i < l_ds.sl; i++)
	{

		ten_sach = l_ds.ds_dausach[i]->tensach;
		if (ten_sach.find(ten_sach_can_tim) != string::npos)
		{
			tim_thay = true;
		}
	}
	if (tim_thay == true)
	{
	}
	else
	{
		cout << "Khong tim thay sach!" << endl;
		return;
	}

	cout << setw(29) << "ISBN" << setw(29) << "Ten sach" << setw(20) << "So trang" <<
		setw(20) << "Tac gia" << setw(20) << "Nam xuat ban" << setw(20) << "The loai" << endl;


	for (int i = 0; i < l_ds.sl; i++) {
		ten_sach = l_ds.ds_dausach[i]->tensach;
		if (ten_sach.find(ten_sach_can_tim) != string::npos)
		{
			cout << setw(29) << l_ds.ds_dausach[i]->ISBN << setw(29) << l_ds.ds_dausach[i]->tensach << setw(20) << l_ds.ds_dausach[i]->sotrang
				<< setw(20) << l_ds.ds_dausach[i]->tacgia << setw(20) << l_ds.ds_dausach[i]->namxuatban << setw(20) << l_ds.ds_dausach[i]->theloai << endl;

		}

	}



}


/*void chuan_hoa_chu(string& a)
{
	//xu ly ky tu dau
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);
	}
	while (a[a.length() - 1]==' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	//xoa kt giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i+1] == ' ')
		{
			a.erase(a.begin() + i );
			i--;
		}
	}
	//chuan hoa ky tu
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] -= 32;
			}
}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}
		}
	}
}
*/

// ================xoa dau sach ==============
void xoa(LIST_DS& lds)
{
	cout << " Neu dau sach da duoc lap danh muc sach thi khong the xoa" << endl;
	string a;
	cout << " Nhap ma ISBN: "; cin >> a;
	a = viet_in_hoa(chuan_hoa_chuoi(a));
	//===============================
	int ds = kt_dausach(a, lds);
	//=============xoa==============
	//doi
	if (ds < 0)
	{
		cout << " Dau sach khong ton tai hoac da duoc lap danh muc sach" << endl;
		system("pause");
	}
	else
	{
		for (int i = ds; i < lds.sl - 1; i++)
		{
			lds.ds_dausach[i]->ISBN = lds.ds_dausach[i + 1]->ISBN;
			lds.ds_dausach[i]->tensach = lds.ds_dausach[i + 1]->tensach;
			lds.ds_dausach[i]->tacgia = lds.ds_dausach[i + 1]->tacgia;
			lds.ds_dausach[i]->theloai = lds.ds_dausach[i + 1]->theloai;
			lds.ds_dausach[i]->sotrang = lds.ds_dausach[i + 1]->sotrang;
			lds.ds_dausach[i]->namxuatban = lds.ds_dausach[i + 1]->namxuatban;
			lds.ds_dausach[i]->kt = lds.ds_dausach[i + 1]->kt;

		}
		//===============giai phong========(giam so luong)

		DAUSACH* tam = lds.ds_dausach[lds.sl - 1];
		lds.sl--;
		cout << "Da xoa thanh cong !" << endl;
		system("pause");
	}
}

int kt_dausach(string a, LIST_DS lds)
{
	for (int i = 0; i < lds.sl; i++)
	{
		//kt iSBN a ton tai
		if (lds.ds_dausach[i]->ISBN == a)
		{
			//kt chua lap danh muc sach
			if (lds.ds_dausach[i]->kt == false)
			{
				return i;
			}
		}
	}
	return -1;
}

//====================hieu chinh dau sach ===============
void hieu_chinh_dau_sach(LIST_DS lds) {
	string a;
	cout << " Nhap ISBN cua dau sach can hieu chinh: "; cin >> a;
	a = viet_in_hoa(chuan_hoa_chuoi(a));
	//===============kiem tra isbn========
	int ds = kt_trung_ISBN(a, lds);
	if (ds < 0) {
		cout << " Ma ISBN khong ton tai !" << endl;
		system("pause");
	}

	else
	{
		//======================hieu chinh=================
		cout << " Nhap ten sach: ";
		cin.ignore();
		getline(cin, lds.ds_dausach[ds]->tensach);
		cout << "Nhap tac gia: "; getline(cin, lds.ds_dausach[ds]->tacgia);
		cout << "Nhap the loai: "; getline(cin, lds.ds_dausach[ds]->theloai);
		cout << "Nhap so trang: "; cin >> lds.ds_dausach[ds]->sotrang;
		cout << "Nhap nam xuat ban: "; cin >> lds.ds_dausach[ds]->namxuatban;
		lds.ds_dausach[ds]->tensach = viet_in_hoa(chuan_hoa_chuoi(lds.ds_dausach[ds]->tensach));
		lds.ds_dausach[ds]->tacgia = viet_in_hoa(chuan_hoa_chuoi(lds.ds_dausach[ds]->tacgia));
		lds.ds_dausach[ds]->theloai = viet_in_hoa(chuan_hoa_chuoi(lds.ds_dausach[ds]->theloai));
		cout << " Da thay doi thong tin dau sach" << endl;
		system("pause");
	}
}


string  masach(LIST_DMS ldms) {

	string masach;
	do
	{
		for (int i = 0; i < ldms.sl; i++)
		{

			//masach = lds.ds_dausach[i]->ISBN + to_string(i + 1);
			//ldms.pHead->data.masach = masach;
		}
	} while (kt_trung_ma_sach(ldms.pHead, masach) == true);
	return masach;
}

bool kt_trung_ma_sach(NODE_DMS* phead, string ma)
{
	for (NODE_DMS* k = phead; k != NULL; k = k->pNext) {
		if (k->data.masach == ma) {
			return true;
		}
	}
	return false;
}


