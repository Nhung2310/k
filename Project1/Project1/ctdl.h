#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include<algorithm>
#include<iomanip>
#include <conio.h>
#include<cstdlib>//rand,srand
#include<ctime>

using namespace std;
#define MAX 1000 // tối đa 1000 đầu sách 

//==============danh muc sach================
struct danhmucsach
{
	string masach;
	int trangthai; // =0 cho mượn được =1 đã có độc giả mượn =2 sách đã thanh lí
	string vitri;
};

struct node_danhmucsach
{
	danhmucsach data;
	node_danhmucsach* pNext;
};
typedef struct node_danhmucsach NODE_DMS;

struct list_danhmucsach
{
	int sl = 0;
	NODE_DMS* pHead = NULL;
	NODE_DMS* pTail = NULL;
};
typedef struct list_danhmucsach LIST_DMS;

// =================Dau sach===================
struct dausach
{
	string ISBN; // mã sách theo chuẩn quốc tế
	string tensach;
	int sotrang;
	string tacgia;
	int namxuatban;
	string theloai;
	bool kt;//true: da duoc lap danh muc sach  false: chua duoc lap danh muc sach

	LIST_DMS dms; // con trỏ trỏ đến các sách thuộc đầu sách tương ứng
};
typedef struct dausach DAUSACH;

struct list_dausach
{
	int sl = 0;
	dausach* ds_dausach[MAX];
};
typedef struct list_dausach LIST_DS;
//==================Muon tra======================

//==================Muon tra======================
struct Date
{
	int ngay;
	int thang;
	int nam;
};

struct muontra
{
	string masach;
	Date ngaymuon;
	Date ngaytra;
	int trangthai; // =0 đang mượn =1 đã trả =2 làm mất sách
};

struct node_muontra
{
	muontra data;
	node_muontra* pNext;
	node_muontra* pPrev;
};
typedef struct node_muontra NODE_MT;

struct list_muontra
{
	NODE_MT* pHead;
	NODE_MT* pTail;
};
typedef struct list_muontra LIST_MT;
//======================= The Doc Gia=============

struct theDocGia
{
	//data 
	int maThe;
	string ho, ten, trangThai, phai; //  trang thai =0 KHOA =1 HOATDONG
	//phai: NAM HOAC NU
	//pointer
	theDocGia* pLeft = NULL;
	theDocGia* pRight = NULL;
	//*dsmt
	LIST_MT  dsm_t;
};
typedef struct theDocGia* tree;

struct ds_the_doc_gia
{
	tree TREE = NULL;
	int sl = 0;
};
typedef struct  ds_the_doc_gia DS_THE_DOC_GIA;

//================== qua han===============
struct quahan
{
	int ma_doc_gia;
	string ho;
	string ten;
	string phai;
	string ma_sach;
	int so_ngay_quahan;
};

struct node_quahan
{
	quahan data;
	node_quahan* pNext;
};
typedef struct node_quahan NODE_QH;

struct list_quahan
{
	NODE_QH* pHead = NULL;
	NODE_QH* pTail = NULL;
};
typedef struct list_quahan LIST_QH;






