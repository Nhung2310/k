#pragma once
#include"hamphu.h"


//=========khai bao nguyen mau cac ham can thiet cho load file
NODE_DMS* khoi_tao_nodedms(danhmucsach a);
void them_dms(list_danhmucsach& ds_dms, danhmucsach a);
//=======doc ghi file danh sach dau sach
void doc_file_ds_dau_sach(LIST_DS& lds);
void ghi_file_ds_dau_sach(LIST_DS l);

//==========doc file the doc gia ======

theDocGia* khoi_tao_node_doc_gia();

void them_1_tdg(tree& t, theDocGia* p);
void doc_file_tdg(DS_THE_DOC_GIA& ds_tdg);

//=============DAU SACH===============

//=======doc ghi file danh sach dau sach
void doc_file_ds_dau_sach(LIST_DS& lds)
{
	ifstream filein;
	string temp;
	filein.open("dsdausach.txt ", ios_base::in);

	filein >> lds.sl;  // sai cho nay nay lds.sl no bang 0
	getline(filein, temp);

	for (int i = 0; i < lds.sl; ++i) // nen cai vong lap nay no k chay
	{
		lds.ds_dausach[i] = new DAUSACH;

		getline(filein, lds.ds_dausach[i]->ISBN, ',');
		getline(filein, lds.ds_dausach[i]->tensach, ',');
		getline(filein, lds.ds_dausach[i]->tacgia, ',');
		getline(filein, lds.ds_dausach[i]->theloai, ',');
		filein >> lds.ds_dausach[i]->sotrang;
		getline(filein, temp, ',');
		filein >> lds.ds_dausach[i]->namxuatban;


		int n;
		filein >> n;
		getline(filein, temp);
		for (int j = 0; j < n; ++j)
		{
			danhmucsach a;
			getline(filein, a.masach, ',');
			getline(filein, a.vitri, ',');
			filein >> a.trangthai;
			getline(filein, temp);
			//them dms
			them_dms(lds.ds_dausach[i]->dms, a);


		}
	}
	filein.close();
}

void ghi_file_ds_dau_sach(LIST_DS l)
{
	ofstream fileOut("dsdausach.txt");

	fileOut << l.sl << '\n';

	for (int i = 0; i < l.sl; ++i)
	{
		fileOut << l.ds_dausach[i]->ISBN << ',' << l.ds_dausach[i]->tensach << ',' << l.ds_dausach[i]->tacgia << ',' << l.ds_dausach[i]->theloai << ',' << l.ds_dausach[i]->sotrang << ',' << l.ds_dausach[i]->namxuatban << '\n';
		fileOut << LaySoLuongDSMS(l.ds_dausach[i]->dms) << '\n';
		for (NODE_DMS* p = l.ds_dausach[i]->dms.pHead; p != NULL; p = p->pNext)
		{
			fileOut << p->data.masach << ',' << p->data.vitri << ',' << p->data.trangthai << '\n';
		}
	}
	fileOut.close();
}
//=================DOC GIA================
//======doc file the doc gia===========

void doc_file_tdg(DS_THE_DOC_GIA& ds_tdg)
{
	ifstream filein;
	filein.open("docgia.txt", ios_base::in);
	while (filein.eof() != true)
	{
		theDocGia* x = khoi_tao_node_doc_gia();
		filein >> x->maThe;
		filein.ignore();
		getline(filein, x->ho, ',');
		getline(filein, x->ten, ',');
		getline(filein, x->phai, ',');
		getline(filein, x->trangThai, '\n');
		them_1_tdg(ds_tdg.TREE, x);
		ds_tdg.sl++;
	}
	filein.close();
} 

void ghi_file_tdg(DS_THE_DOC_GIA ds_tdg)
{
	ofstream fileOut("docgia.txt");

	for (int i = 0; i < ds_tdg.sl; ++i)
	{
		fileOut << ds_tdg.TREE->maThe << ',' << ds_tdg.TREE->ho << ',' << ds_tdg.TREE->ten << ',' << ds_tdg.TREE->phai << ',' << ds_tdg.TREE->trangThai << '\n';
	
	}
	fileOut.close();
}