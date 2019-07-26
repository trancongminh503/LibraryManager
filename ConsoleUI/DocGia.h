#pragma once
#include "MuonTra.h"
#include "TextHandler.h"
#include "Displays.h"

enum GioiTinh
{
	Nam,
	Nu
};
enum TrangThaiTheDG
{
	TheBiKhoa = 0,
	DangHoatDong = 1
};
enum ExeptionMuonSach
{
	Accept,
	BiKhoaThe,
	SachBiMat,
	GiuQua7Ngay,
	MuonDuSach
};

struct DOCGIA
{
	// 0001 ... 9999
	int maDocGia;
	string ho;
	string ten;
	GioiTinh gioiTinh;
	TrangThaiTheDG trangThai;

	LIST_MUONTRA listMuonTra = LIST_MUONTRA();

	// in ra node
	void Print(MYPOINT location, Color backColor, Color textColor);
	// chen | vao giua field
	string ToString();
	// chuyen object dau sach thanh string luu file
	string ToStringFile();
	// kiem tra xem doc gia co duoc muon sach
	// 1> khong muon sach qua 7 ngay
	// 2> the doc gia dang hoat dong
	// 3> muon toi da 3 sach
	ExeptionMuonSach IsMuonSach();
	// ...
	string* ToStringQuaHan(LIST_DAUSACH listSach, int& count);
};

struct NODE_DOCGIA
{
	DOCGIA data;

	NODE_DOCGIA* pLeft;
	NODE_DOCGIA* pRight;

	NODE_DOCGIA(DOCGIA& data);
};

typedef NODE_DOCGIA* LIST_DOCGIA;

// Ghi du lieu ma doc gia ra file text
bool WriteMaDGToFile(string path, LIST_DOCGIA listDG);
// Ghi du lieu doc gia ra file text
bool WriteToFile(LIST_DOCGIA lstDG, string path);
// Remove ma doc gia from array khi them moi doc gia
void RemoveMaDG(LIST_DOCGIA listDG);
// Doc mang MADOCGIA tu file
bool ReadMaDGFromFile(string path);
// so node cua cay
int Size(LIST_DOCGIA listDG);
// Doc tu file txt
bool ReadFromFile(LIST_DOCGIA& listDG,string path);
// sinh madocgia ngau nhien tu dong
int GetRandomMaDG(LIST_DOCGIA listDG);
// ...
void SwapMaDG(int pos1, int pos2);
// Chuyen vector string thanh doc gia
DOCGIA ParseVectorString(string* data);
// ...
string* GetDGtoVector(DOCGIA docGia);
// Giai phong vung nho
void FreeMemory(NODE_DOCGIA* root);
// form nhap doc gia moi
DOCGIA InputDocGia(int maThe, RECTANGLE rect);
// khoi toa cay
void Init(LIST_DOCGIA& listDG);
// them node
void Insert(LIST_DOCGIA& listDG, DOCGIA docGia);
// duyet cay
void NLR(LIST_DOCGIA listDG);
// tim doc gia dua vao maDocGia
NODE_DOCGIA* Search(LIST_DOCGIA listDG, int maDocGia);
// ...
string* GetAllStringNode(LIST_DOCGIA listDG, int& count);
// ...
void TimPhanTuTheMangTraiNhatCayConPhai(LIST_DOCGIA& p, LIST_DOCGIA& q);
// ...
void TimpPhanTuTheMangPhaiNhatCayConTrai(LIST_DOCGIA& p, LIST_DOCGIA& q);
// xoa 1 doc gia
bool DeleteNode(LIST_DOCGIA& listDG, DOCGIA docGia);
// In ds doc gia: mode = 1 (Sort theo maDG)
//                mode = 2 (Sort theo hoTen)
string PrintAllDocGia(LIST_DOCGIA lstDG, MYPOINT location, int mode = 1, Menu_Mode m = Both);
// ...
DOCGIA InputFixDocGia(RECTANGLE rect, DOCGIA docGia);
// ...
void PrintStringDocGia(string data, MYPOINT location);
// ...
string PrintAllDGWithHL(LIST_DOCGIA listDG, MYPOINT location, int& page, Menu_Mode mode, int line = 0);
// luu list muon tra vo file
void DuyetLuuFile(LIST_DOCGIA lstDG, string defaultPath);
void DuyetDocFile(LIST_DOCGIA& lstDG, string path);
// Show ds qua han
void ShowListQuaHan(LIST_DAUSACH listDS, LIST_DOCGIA lstDG);