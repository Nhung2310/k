#pragma once

#include"load_file.h"

using namespace std;



void menu_the_doc_gia();
//=============nhap the doc gia=============
bool kt_ma_dg_trung(tree t, int ma);
int tao_ma_dg(tree t);
//theDocGia* khoi_tao_node_doc_gia();
void nhap_the_dg(DS_THE_DOC_GIA& ds_tdg);
//void them_1_tdg(tree &t, theDocGia* p);

//----------------in danh sach doc gia ra ---------------
void chuyen_cay_sang_mang(tree t, theDocGia* ds[], int& nds);
void in_ds_doc_gia(theDocGia* ds[], int& nds);

// -------------sap xep danh sah doc gia --------------
void hoan_vi_2_tdg(theDocGia* a, theDocGia* b);
void sap_xep_ds_tdg(theDocGia* ds[], int& nds);
void giai_phong_ds_the_doc_gia(theDocGia* ds[], int& nds);

//hàm xuất cây nhị phân theo LNR xuất ra tu be den lon 
//theo ma doc gia
void Duyet_LNR(tree& t);

//=============xoa the doc gia============
void xoa_the_doc_gia(DS_THE_DOC_GIA& ds_tdg);
void xoa_1_the_doc_gia(tree& t, int ma);
void node_the_mang(tree& t, theDocGia*& x);

//==============hieu chinh the doc gia =========
void hieu_chinh_tdg(DS_THE_DOC_GIA& ds_tdg);
void hieu_chinh_1_tdg(tree t, int ma);

//==================nhap the doc gia ================
theDocGia* khoi_tao_node_doc_gia()
{
	theDocGia* p = new theDocGia;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

void nhap_the_dg(DS_THE_DOC_GIA& ds_tdg)
{
	theDocGia* p = khoi_tao_node_doc_gia();

	p->maThe = tao_ma_dg(ds_tdg.TREE);
	cout << "Ma the doc gia: " << p->maThe << endl;
	cin.ignore();
	cout << "Nhap ho:"; getline(cin, p->ho);
	p->ho = viet_in_hoa(chuan_hoa_chuoi(p->ho));

	cout << "Nhap ten:"; getline(cin, p->ten);
	p->ten = viet_in_hoa(chuan_hoa_chuoi(p->ten));

	cout << "Nhap gioi tinh (NAM - NU): "; getline(cin, p->phai);
	p->phai = viet_in_hoa(chuan_hoa_chuoi(p->phai));
	while (p->phai != "NAM" && p->phai != "NU")
	{
		cout << "Nhap sai gioi tinh!\n";
		cout << "Nhap lai gioi tinh: (NAM - NU) :";
		getline(cin, p->phai);
		p->phai = viet_in_hoa(chuan_hoa_chuoi(p->phai));
	}

	cout << " Trạng thái thẻ = 0 khi thẻ bị khóa, trạng thái thẻ = 1 khi thẻ  đang hoạt động  " << endl;
	cout << "Nhap trang thai:";
	getline(cin, p->trangThai);
	while (p->trangThai != "0" && p->trangThai != "1")
	{
		cout << "Nhap sai trang thai !\n";
		cout << "Nhap lai trang thai : (0 - 1) :";
		getline(cin, p->trangThai);

	}

	them_1_tdg(ds_tdg.TREE, p);
	ds_tdg.sl++;
}


int tao_ma_dg(tree t)
{
	int ma;//1000-9999
	do
	{
		ma = rand() % (9999 - 1000 + 1) + 1000;
	} while (kt_ma_dg_trung(t, ma) == true);
	return ma;
}

bool kt_ma_dg_trung(tree t, int ma)//dung de quy
{
	if (t == NULL)//het roi, k co trung 
	{
		return 0;
	}
	else
	{
		if (t->maThe == ma)
		{
			return 1;
		}
		else if (t->maThe < ma)//neu ma lon hon thi de quy sang phai 
		{
			kt_ma_dg_trung(t->pRight, ma);
		}
		else
		{
			kt_ma_dg_trung(t->pLeft, ma);
		}
	}
}

//===============in danh sach doc gia=============
// 
//------------chuyen cay sang mang------------------
void chuyen_cay_sang_mang(tree t, theDocGia* ds[], int& nds)
{
	//chung ta de quy
	if (t != NULL)
	{
		//data
		ds[nds] = new theDocGia;
		ds[nds]->maThe = t->maThe;
		ds[nds]->ho = t->ho;
		ds[nds]->ten = t->ten;
		ds[nds]->phai = t->phai;
		ds[nds]->trangThai = t->trangThai;
		nds++;
		chuyen_cay_sang_mang(t->pLeft, ds, nds);
		chuyen_cay_sang_mang(t->pRight, ds, nds);

	}
}
// -------------sap xep danh sah doc gia --------------
void hoan_vi_2_tdg(theDocGia* a, theDocGia* b)
{
	theDocGia* tam = new theDocGia;
	tam->maThe = a->maThe;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->phai = a->phai;
	tam->trangThai = a->trangThai;
	tam->dsm_t = a->dsm_t;
	//==================
	a->maThe = b->maThe;
	a->ho = b->ho;
	a->ten = b->ten;
	a->phai = b->phai;
	a->trangThai = b->trangThai;
	a->dsm_t = b->dsm_t;
	//=================
	b->maThe = tam->maThe;
	b->ho = tam->ho;
	b->ten = tam->ten;
	b->phai = tam->phai;
	b->trangThai = tam->trangThai;
	b->dsm_t = tam->dsm_t;
	delete tam;
}

void sap_xep_ds_tdg(theDocGia* ds[], int& nds)
{
	for (int i = 0; i < nds - 1; i++)
	{
		for (int j = i + 1; j < nds; j++)
		{
			if (ds[i]->ten > ds[j]->ten)
			{
				hoan_vi_2_tdg(ds[i], ds[j]);//hoan vi hai data
			}
			else if (ds[i]->ten == ds[j]->ten)
			{
				if (ds[i]->ho > ds[j]->ten)
				{
					hoan_vi_2_tdg(ds[i], ds[j]);
				}
			}
		}
	}
}

//----------------in danh sach doc gia ra ---------------
void in_ds_doc_gia(theDocGia* ds[], int& nds)
{
	for (int i = 0; i < nds; i++)
	{

		cout << "\t\t================ Doc gia " << i << "=========" << endl;
		cout << " Ma the doc gia: " << ds[i]->maThe << endl;
		cout << " Ho ten:" << ds[i]->ho << " " << ds[i]->ten << endl;
		cout << " Phai: " << ds[i]->phai << endl;
		cout << "Trang Thai: " << ds[i]->trangThai << endl;

	}
}
//-------------------giai phong--------------

void giai_phong_ds_the_doc_gia(theDocGia* ds[], int& nds)
{
	for (int i = 0; i < nds; i++)
	{
		delete ds[i];
	}
}

void hien_main_menu()
{
	int choice;
	do
	{
		system("cls");


		cout << "\t============== QUAN LY THU VIEN =============" << endl;
		cout << "\t\t\t1. Doc gia\n";
		cout << "\t\t\t2. Sach\n";
		cout << "\t\t\t3. Muon tra\n";
		cout << "\t\t\t4. Thong ke\n";
		cout << "\t\t\t5. Cap nhap ngay thang\n";
		cout << "\t\t\t0. Thoat\n";
		cout << "\t\t============== END =============" << endl;
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch (choice)
		{

		case 1:
			menu_the_doc_gia();
			break;

		case 0:
			return;
			break;
		default:
			cin.clear();
			cout << "Lua chon khong hop le!\n";
			break;
		}
	} while (choice != 0);
}


void menu_the_doc_gia()
{
	DS_THE_DOC_GIA ds_tdg;

	doc_file_tdg(ds_tdg);
	bool kt = true;
	while (kt == true)
	{
		system("cls");
		cout << "\t\t\t\ ==============MENU==================== " << endl;
		cout << "\t\t\t\ 1. Them the doc gia" << endl;
		cout << "\t\t\t\ 2. In danh sach tang dan theo  ten ho " << endl;
		cout << "\t\t\t\ 3.In danh sach tang dan theo ma the doc gia" << endl;
		cout << "\t\t\t\ 4. Xoa the doc gia " << endl;
		cout << "\t\t\t\ 5. Hieu chinh thong tin the doc gia" << endl;
		cout << "\t\t\t\ 0. Thoat" << endl;
		int luachon;
		cout << "nhap lua chon: "; cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			nhap_the_dg(ds_tdg);
			break;
		}
		case 2:
		{
			theDocGia* ds[1000];
			int nds = 0;
			chuyen_cay_sang_mang(ds_tdg.TREE, ds, nds);
			sap_xep_ds_tdg(ds, nds);
			in_ds_doc_gia(ds, nds);
			giai_phong_ds_the_doc_gia(ds, nds);
			system("pause");

			break;
		}
		case 3:
		{
			Duyet_LNR(ds_tdg.TREE);
			system("pause");
			break;
		}
		case 4:
		{
			xoa_the_doc_gia(ds_tdg);
			break;
		}
		case 5:
		{
			hieu_chinh_tdg(ds_tdg);
			break;
		}
		case 0:
		{
			kt = false;
			break;
		}
		}
	}

}

//hàm xuất cây nhị phân theo LNR xuất ra tu be den lon 
void Duyet_LNR(tree& t)
{
	//neu cay con phan tu thi tiep tuc duyet
	if (t != NULL)
	{
		Duyet_LNR(t->pLeft);//duyet qua trai
		cout << "\t\t================ Doc gia =========" << endl;
		cout << " Ma the doc gia: " << t->maThe << endl;
		cout << " Ho ten:" << t->ho << " " << t->ten << endl;
		cout << " Phai: " << t->phai << endl;
		cout << "Trang Thai: " << t->trangThai << endl;
		Duyet_LNR(t->pRight);//duyet qua phai 
	}
}


//=============xoa the doc gia============
void xoa_the_doc_gia(DS_THE_DOC_GIA& ds_tdg)
{
	int a;
	cout << "Nhap ma nhan vien: "; cin >> a;
	bool kt = kt_ma_dg_trung(ds_tdg.TREE, a);
	if (kt == true)
	{
		//xoa
		xoa_1_the_doc_gia(ds_tdg.TREE, a);
		ds_tdg.sl--;
		cout << "Xoa thanh cong!" << endl;
	}
	else
	{
		cout << "Ma nhan vien khong ton tai!" << endl;
	}

	system("pause");
}

void xoa_1_the_doc_gia(tree& t, int ma)
{
	if (t != NULL)
	{
		if (t->maThe == ma)
		{
			theDocGia* x = t;//x se luu node can giai phong
			//xoa node la
			if (t->pLeft == NULL)
			{
				t = t->pRight;//neu la node la lay null gan vao t , neu node 1 con thi lay la gan len
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else if (t->pLeft != NULL && t->pRight != NULL)
			{
				//  tim node the mang trái  cung cua cay con phai
				node_the_mang(t->pRight, x);
			}
			delete x;
		}
		else if (t->maThe < ma)
		{
			xoa_1_the_doc_gia(t->pRight, ma);
		}
		else if (t->maThe > ma)
		{
			xoa_1_the_doc_gia(t->pLeft, ma);
		}
	}

}

void node_the_mang(tree& t, theDocGia*& x)
{
	if (t->pLeft != NULL)
	{
		node_the_mang(t->pLeft, x);
	}
	else //trai cung
	{
		hoan_vi_2_tdg(t, x);
		x = t;//x se luu vi tri node nay de ty nua giai phong
		t = t->pRight;
	}
}

//==============hieu chinh the doc gia =========
void hieu_chinh_tdg(DS_THE_DOC_GIA& ds_tdg)
{
	int a;
	cout << "Nhap ma the doc gia can hieu chinh: "; cin >> a;
	bool kt = kt_ma_dg_trung(ds_tdg.TREE, a);
	if (kt == true)
	{
		hieu_chinh_1_tdg(ds_tdg.TREE, a);
	}
	else
	{
		cout << " Ma khong ton tai." << endl;
	}
	system("pause");
}

void hieu_chinh_1_tdg(tree t, int ma)
{
	if (t != NULL)
	{
		if (t->maThe == ma)
		{
			cin.ignore();
			cout << "Nhap ho: "; getline(cin, t->ho);
			cout << "Nhap ten: "; getline(cin, t->ten);

			cout << "da hieu chinh thong tin nhan vien" << endl;
		}
		else if (t->maThe > ma)
		{
			hieu_chinh_1_tdg(t->pLeft, ma);
		}
		else if (t->maThe < ma)
		{
			hieu_chinh_1_tdg(t->pRight, ma);
		}
	}
}

