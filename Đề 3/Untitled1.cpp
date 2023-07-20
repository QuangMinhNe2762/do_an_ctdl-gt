#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Lophoc
{
	char MALOP[10];
	char Tenlop[20];
	float Hocphi;
	int lichHoc;
};
struct nodeLH
{
	Lophoc infor;
	nodeLH* next;
};
struct listLH
{
	nodeLH* head;
	nodeLH* tail;
};
//========================
struct date
{
	int d, m, y;
};
struct HocVien
{
	char mhv[15], ho[30], ten[10];
	date NS;
	float diem;
	Lophoc malop;
};
struct nodeHV
{
	HocVien infor;
	nodeHV* next;
};
struct listHV
{
	nodeHV* head;
	nodeHV* tail;
};
//các hàm liên quan toi lop 
void createListLH(listLH& l)
{
	l.head = l.tail = NULL;
}
void NhapTTLop(Lophoc& x)
{
	printf("\nTen lop hoc: ");
	fflush(stdin);
	gets(x.Tenlop);
	printf("Hoc phi: ");
	scanf("%f", &x.Hocphi);
	do
	{
		printf("\nNhap lich hoc\n1:sang\n2:chieu\n3:toi\nNhap lua chon cua ban (so): ");
		scanf("%d", &x.lichHoc);
		if (x.lichHoc == 1)
		{
			printf("\nBan chon lich hoc sang\n");
		}
		else if (x.lichHoc == 2)
		{
			printf("\nBan chon lich hoc chieu\n");
		}
		else if (x.lichHoc == 3)
		{
			printf("\nBan chon lich hoc toi\n");
		}
		else
		{
			printf("\nkhong co lich hoc da nhap!!!!!\n");
		}
	} while (x.lichHoc != 1 && x.lichHoc != 2 && x.lichHoc != 3);
}
nodeLH* createLop(Lophoc x)
{
	nodeLH* p = new nodeLH;
	if (p == NULL)
	{
		printf("\nOver load\n");
		return NULL;
	}
	p->infor = x;
	p->next = NULL;
	return p;
}
void insertLop(listLH& l, Lophoc& x)
{
	nodeLH* p = createLop(x);
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//xuat lop 
void printfLop(Lophoc x)
{
	printf("================================================================================\n");
	printf("|%-15s|%-18s\t|%0.1f trieu/thang|\t", x.MALOP, x.Tenlop, x.Hocphi);
	if (x.lichHoc == 1)
	{
		printf("|sang  |\n");
	}
	if (x.lichHoc == 2)
	{
		printf("|chieu |\n");
	}
	if (x.lichHoc == 3)
	{
		printf("|toi   |\n");
	}
}
void printfListLop(listLH l)
{
	int i=1;
	printf("%s%18s%29s%19s\n", "MA LOP", "TEN LOP", "HOC PHI", "LICH HOC");
	for (nodeLH* p = l.head; p != NULL; p = p->next)
	{
		printf("%d.",i),i++;
		printfLop(p->infor);
	}
}
void nhapMaLop_LH(Lophoc &x,listLH l)
{
	int dem = 0;
	do
	{
		printf("\nHien tai co cac lop hoc nhu sau\n");
		printfListLop(l);
		if(l.head==NULL)
		{
			printf("\nNhap ma lop: ");
			fflush(stdin);
			gets(x.MALOP);
			return;
		}
		printf("\nNhap ma lop: ");
		fflush(stdin);
		gets(x.MALOP);
		for (nodeLH* p = l.head; p != NULL;p=p->next)
		{
			if (stricmp(x.MALOP, p->infor.MALOP) == 0)
			{
				dem=0;
				printf("\nMa lop da co vui long nhap ma lop khac");
				break;
			}
			else
			{
				dem++;
			}
		}
	} while (dem == 0);
}
//các hàm liên quan toi hoc viên
void createListHV(listHV& l)
{
	l.head = l.tail = NULL;
}
void nhapMaLop(HocVien& y, listLH l)
{
	int dem = 0;
	do
	{
		printf("\nHien tai co cac lop hoc nhu sau\n");
		printfListLop(l);
		printf("\nNhap ma lop: ");
		fflush(stdin);
		gets(y.malop.MALOP);
		for (nodeLH* p = l.head; p != NULL;p=p->next)
		{
			if (stricmp(y.malop.MALOP, p->infor.MALOP) == 0)
			{
				dem++;
				break;
			}
		}
		if (dem == 0)
		{
			printf("\nMa lop khong chinh xac vui long nhap lai\n");
		}
	} while (dem == 0);
}
void NhapTTHV(HocVien& y, listLH lh)
{
	nhapMaLop(y, lh);
	printf("Nhap ho dem: ");
	fflush(stdin);
	gets(y.ho);
	printf("Nhap ten: ");
	gets(y.ten);
	printf("Nhap ngay sinh: ");
	scanf("%d", &y.NS.d);
	printf("Nhap thang sinh: ");
	scanf("%d", &y.NS.m);
	printf("Nhap nam sinh: ");
	scanf("%d", &y.NS.y);
	printf("Nhap diem: ");
	scanf("%f", &y.diem);
}
nodeHV* createHV(HocVien y)
{
	nodeHV* p = new nodeHV;
	if (p == NULL)
	{
		printf("\nOver load\n");
		return NULL;
	}
	p->infor = y;
	p->next = NULL;
	return p;
}
void insertHV(listHV& l, HocVien y)
{
	nodeHV* p = createHV(y);
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}
//hàm xuat danh sách hoc viên
void printfHV(HocVien y)
{
	printf("%-16s%-16s%-8s%d/%d/%d\t%.2f\t\t%5s\n", y.mhv, y.ho, y.ten, y.NS.d, y.NS.m, y.NS.y, y.diem,y.malop.MALOP);
}
void NhapMHV(HocVien &y,listHV hv)
{
	if(hv.head==NULL)
	{
		return;
	}
	int dem = 0;
	do
	{
		printf("\nNhap ma hoc vien: ");
		fflush(stdin);
		gets(y.mhv);
		for (nodeHV* p = hv.head; p != NULL;p=p->next)
		{
			if (stricmp(y.mhv, p->infor.mhv) == 0)
			{
				dem=0;
				printf("\nma hoc vien ban vua nhap da co trong danh sach\n");
				printfHV(p->infor);
				break;
			}
			else
			{
				dem++;
			}
		}
	} while (dem == 0);
}
void printfListHV(listHV l)
{
	int i=1;
	for (nodeHV* p = l.head; p != NULL; p = p->next)
	{
		printf("%2d.",i),i++;
		printfHV(p->infor);
	}
}
void printfTT(listHV hv, listLH lh)
{
	for (nodeLH* p = lh.head; p != NULL; p = p->next)
	{
		printf("\n");
		printf("%s%16s%29s%19s\n", "MA LOP", "TEN LOP", "HOC PHI", "LICH HOC");
		printfLop(p->infor);
		printf("%s%11s%13s%14s%16s%14s\n", "Ma hoc vien", "Ho dem", "Ten", "Ngay sinh", "Diem mon hoc","Ma Lop");
		for (nodeHV* q = hv.head; q != NULL;)
		{
			if (stricmp(p->infor.MALOP, q->infor.malop.MALOP) != 0)
			{
				q = q->next;
			}
			else
			{
				printfHV(q->infor);
			
				q = q->next;
			}
		}
		printf("--------------------------------------------------------------------------------\n");
	}
}
//xuất danh sách các học viên cùng lớp
void hocVienCungLop(listHV hv,HocVien x)
{
	printf("%s%11s%13s%14s%16s%14s\n", "Ma hoc vien", "Ho dem", "Ten", "Ngay sinh", "Diem mon hoc","Ma Lop");
	for(nodeHV* p=hv.head;p!=NULL;p=p->next)
	{
		if(stricmp(p->infor.malop.MALOP,x.malop.MALOP)==0)
		{
			printfHV(p->infor);
		}
	}
}
//doc file lop hoc
void readFileLH(FILE* lh, Lophoc& x)
{
	fscanf(lh, "%[^\t]%*c%[^\t]%*c%d%f\n", &x.MALOP, &x.Tenlop, &x.lichHoc, &x.Hocphi);
}
void readFileListLH(char* filename, Lophoc& x, listLH& lh)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("\nFILE khong ton tai\n");
		return;
	}
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		readFileLH(f, x);
		insertLop(lh, x);
	}
	fclose(f);
}
//doc file hoc viên
void readfileHV(FILE* hv, HocVien& y)
{
	fscanf(hv, "%[^\t]%*c%[^\t]%*c%[^\t]%*c%d\t%d\t%d\t%[^\t]%*c%f\n", &y.mhv, &y.ho, &y.ten, &y.NS.d, &y.NS.m, &y.NS.y, &y.malop.MALOP, &y.diem);
}
void readFileListHV(char* filename, HocVien& y, listHV& hv)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		printf("\nFILE khong ton tai\n");
		return;
	}
	int n;
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		readfileHV(f, y);
		insertHV(hv, y);
	}
	fclose(f);
}
//tìm kiem hoc viên theo các tiêu chí năm sinh,tên lop,mã hoc viên
void menuSelectSearch(int& search)
{
		printf("\n================================================================================");
		printf("\nMoi ban chon tieu chi tim kiem hoc vien");
		printf("\n1. Tim theo ten lop hoc\n2. Tim theo ma hoc vien\n3. Tim theo ngay thang nam sinh");
		printf("\n0. Thoat khoi chuong trinh tim kiem");
		printf("\n================================================================================");
		printf("\nBan chon tieu chi: "); scanf("%d", &search);
}
void selectSearch(int& search, listHV hv, listLH lh, HocVien& x, Lophoc& y)
{
	int dem=0;
	do
	{
		menuSelectSearch(search);
		switch (search)
		{
		case 1:
			printfListLop(lh);
			printf("\nNhap ten lop hoc muon tim: ");
			fflush(stdin);
			gets(y.Tenlop);
			for (nodeLH* p = lh.head; p != NULL;p = p->next)
			{
				if (stricmp(y.Tenlop, p->infor.Tenlop) == 0)
				{
					printfLop(p->infor);
					for(nodeHV* q=hv.head;q!=NULL;q=q->next)
					{
						if (stricmp(p->infor.MALOP,q->infor.malop.MALOP) == 0)
						{
							printfHV(q->infor);
						}
					}
					dem++;
				}
			}
			if(dem==0)
			{
				printf("\n----------------------Khong co ten lop da nhap-------------------");
			}
			dem=0;
			break;
		case 2:
			printf("\nNhap ma hoc vien muon tim: ");
			fflush(stdin);
			gets(x.mhv);
			for (nodeHV* p = hv.head; p != NULL;p = p->next)
			{
				if (stricmp(x.mhv, p->infor.mhv) == 0)
				{
					printf("%s%11s%13s%14s%16s%14s\n", "Ma hoc vien", "Ho dem", "Ten", "Ngay sinh", "Diem mon hoc","Ma Lop");
					printfHV(p->infor);
					dem++;
					break;
				}
			}
			if(dem==0)
			{
					printf("\n----------------------Khong co hoc vien nay trong danh sach-------------------");
			}
			dem=0;
			break;
		case 3:
			printf("\nNhap ngay sinh: ");
			scanf("%d", &x.NS.d);
			printf("\nNhap thang sinh: ");
			scanf("%d", &x.NS.m);
			printf("\nNhap nam sinh: ");
			scanf("%d", &x.NS.y);
			for (nodeHV* p = hv.head; p != NULL;)
			{
				if (x.NS.d == p->infor.NS.d && x.NS.m == p->infor.NS.m && x.NS.y == p->infor.NS.y)
				{
					printfHV(p->infor);
					dem++;
				}
				p = p->next;
			}
			if(dem==0)
			{
				printf("\n-------------------Khong co ngay thang nam sinh da nhap trong ds tat ca hoc vien-------------------");
			}
			dem=0;
			break;
		case 0:
			break;
		default:
			printf("\nKhong co lua chon tim kiem cua ban:");
		}
		} while (search != 0);
}
//in các học viên có điểm cao nhất ở các lớp
void HocVienMaxDiemLop(listHV hv,listLH lh)
{
	int i=1,j=1;
	for(nodeLH* p=lh.head;p!=NULL;p=p->next)
	{
		printf("%d)",i),i++;
		printfLop(p->infor);
		printf("--------------------------------------------------------------------------------\n");
		nodeHV* max=NULL;
		for(nodeHV* q=hv.head;q!=NULL;q=q->next)
		{
			if(stricmp(p->infor.MALOP,q->infor.malop.MALOP)==0)
			{
				if(max==NULL)
				{
					max=q;
				}
				else
				{
					if(q->infor.diem>=max->infor.diem)
					{
						max=q;
					}
				}
			}
		}
		printf("%d.",j);
		printfHV(max->infor);
	}
}
// in các học viên thuộc lớp có học phí cao nhất
void lopCoHocPhiMax(listHV hv,listLH lh)
{
	nodeLH* p=lh.head;
	nodeLH* max=p;
	if(lh.head==NULL)
	{
		return;
	}
	for(;p!=NULL;p=p->next)
	{
		if(p->infor.Hocphi>=max->infor.Hocphi)
		{
			max=p;
		}
	}
	printfLop(max->infor);
	for(nodeHV* q=hv.head;q!=NULL;)
	{
		if(stricmp(max->infor.MALOP,q->infor.malop.MALOP)==0)
		{
			printfHV(q->infor);
		}
		q=q->next;
	}
}
//sắp xếp độ dài chuỗi ngắn đến dài theo mã lớp
void swapLop(Lophoc& a, Lophoc& b)
{
	Lophoc t = a;
	a = b;
	b = t;
}
void SapXepMaLop(listLH lh)
{
	for(nodeLH* p=lh.head;p!=NULL;p=p->next)
	{
		int a=strlen(p->infor.MALOP);
		for(nodeLH* q=p->next;q!=NULL;q=q->next)
		{
			int b=strlen(q->infor.MALOP);
			if(a>b)
			{
				swapLop(p->infor,q->infor);
			}
		}
	}
}
//các học viên cùng 1 lớp sắp xếp điểm giảm dần
void swapHV(HocVien &a,HocVien &b)
{
	HocVien t=a;
	a=b;
	b=t;
}
void SapXepDiemGiamDan(listLH lh,listHV hv)
{
	for(nodeLH* p=lh.head;p!=NULL;p=p->next)
	{
		printfLop(p->infor);
		nodeHV* max=NULL;
		for(nodeHV*q=hv.head;q!=NULL;q=q->next)
		{
			if(stricmp(p->infor.MALOP,q->infor.malop.MALOP)==0)
			{
				if(max==NULL)
				{
					max=q;
				}
				else
				{
					if(max->infor.diem<=q->infor.diem)
					{
						swapHV(max->infor,q->infor);
					}
				}
			}
		}
		hocVienCungLop(hv,max->infor);
	}
}
//xuất các học viên điểm chưa đạt <5
void HocVienChuaDat(listHV hv,listLH lh)
{
	for(nodeLH* q=lh.head;q!=NULL;q=q->next)
	{
		int dem=0;
		printfLop(q->infor);
		for(nodeHV* p=hv.head;p!=NULL;p=p->next)
		{
			if(stricmp(q->infor.MALOP,p->infor.malop.MALOP)==0)
			{
				if(p->infor.diem<5)
				{
					printfHV(p->infor);
					dem++;
				}
			}
		}
		if(dem==0)
		{
			printf("Lop hoc khong co hoc vien chua dat\n");
		}
	}
}
//sắp xếp giảm dần theo tên
void SapXepTenHocVien(listLH lh,listHV hv)
{
	for(nodeLH* p=lh.head;p!=NULL;p=p->next)
	{
		printfLop(p->infor);
		nodeHV* t=NULL;
		nodeHV* q=hv.head;
		for(;q!=NULL;q=q->next)
		{
			if(stricmp(p->infor.MALOP,q->infor.malop.MALOP)==0)
			{
				int max=strlen(q->infor.ten);
				t=q;
				for(nodeHV* l=q->next;l!=NULL;l=l->next)
				{
					if(stricmp(p->infor.MALOP,l->infor.malop.MALOP)==0)
					{
						int a=strlen(l->infor.ten);
						if(a>max)
						{
							max=a;
							t=l;
						}
					}
				}
				swapHV(q->infor,t->infor);
			}
		}
		hocVienCungLop(hv,t->infor);
	}
}
//in ra các học viên đạt học bổng (điểm>=8)
void HocVienDatHB(listHV hv,listLH lh)
{
	for(nodeLH* q=lh.head;q!=NULL;q=q->next)
	{
		int dem=0;
		printfLop(q->infor);
		for(nodeHV* p=hv.head;p!=NULL;p=p->next)
		{
			if(stricmp(q->infor.MALOP,p->infor.malop.MALOP)==0)
			{
				if(p->infor.diem>=8)
				{
					printfHV(p->infor);
					dem++;
				}
			}
		}
		if(dem==0)
		{
			printf("Lop hoc khong co hoc vien dat hoc bong\n");
		}
	}
}
//ghi các học viên đạt học bổng vào file dshocbong.txt
void writeFileHocVienDatHB(char* filename,listLH lh,listHV hv)
{
	FILE* f=fopen(filename,"w");
	if(f==NULL)
	{
		printf("\nFile khong ton tai");
		return ;
	}
	fprintf(f,"\ndanh sach cac hoc vien dat hoc bong cua cac lop\n");
	for(nodeLH* p=lh.head;p!=NULL;p=p->next)
	{
		int dem=0;
		fprintf(f,"%-15s%-18s\t%0.1f trieu/thang\t\t",p->infor.MALOP, p->infor.Tenlop,p->infor.Hocphi);
		if (p->infor.lichHoc == 1)
		{
			fprintf(f,"sang\n");
		}
		if (p->infor.lichHoc == 2)
		{
			fprintf(f,"chieu\n");
		}
		if (p->infor.lichHoc == 3)
		{
			fprintf(f,"toi\n");
		}
		for(nodeHV* q=hv.head;q!=NULL;q=q->next)
		{
			if(stricmp(q->infor.malop.MALOP,p->infor.MALOP)==0)
			{
				if(q->infor.diem>=8)
				{
					fprintf(f,"%s\t\t%-4s\t%s\t%d/%d/%d\t%.2f\t%s\n", q->infor.mhv, q->infor.ho, q->infor.ten, q->infor.NS.d, q->infor.NS.m, q->infor.NS.y, q->infor.diem,q->infor.malop.MALOP);
					dem++;
				}
			}
		}
		if(dem==0)
		{
			fprintf(f,"Lop hoc khong co hoc vien dat hoc bong\n");
		}
	}
	fclose(f);
}
//xóa các học viên bất kì
void deleteHeadHV(listHV& hv)
{
	if(hv.head==NULL)
	{
		return;
	}
	else
	{
		nodeHV* p=hv.head;
		hv.head=p->next;
		p->next=NULL;
		delete p;
	}
}
void deleteTailHV(listHV& hv)
{
	if(hv.head==NULL)
	{
		return;
	}
	else
	{
		nodeHV* p=hv.head;
		nodeHV* q=hv.tail;
		while(p->next!=q)
		{
			p=p->next;
		}
		hv.tail=p;
		hv.tail->next=NULL;
		delete q;
	}
}
void NhapHocVien(HocVien &x)
{
	printf("\nNhap ma hoc vien muon xoa:");
	fflush(stdin);
	gets(x.mhv);
}
void xoaHocVienBatKi_MHV(listHV &hv,HocVien x)
{
	if(hv.head==NULL)
	{
		printf("\nKhong co hoc vien de xoa");
		return;
	}
	if(stricmp(hv.head->infor.mhv,x.mhv)==0)
	{
		deleteHeadHV(hv);
		return;
	}
	else if(stricmp(hv.tail->infor.mhv,x.mhv)==0)
	{
		deleteTailHV(hv);
		return;
	}
	nodeHV* p;
	for(nodeHV* k=hv.head;k!=NULL;k=k->next)
	{
		if(stricmp(k->infor.mhv,x.mhv)==0)
		{
			p->next=k->next;
			delete k;
			return;
		}
		p=k;
	}
}
//xóa lớp bất kì và học viên của lớp đó
void deleteHeadLH(listLH& lh)
{
	if(lh.head==NULL)
	{
		return;
	}
	else
	{
		nodeLH* p=lh.head;
		lh.head=p->next;
		p->next=NULL;
		delete p;
	}
}
void deleteTailLH(listLH& lh)
{
	if(lh.head==NULL)
	{
		return;
	}
	else
	{
		nodeLH* p=lh.head;
		nodeLH* q=lh.tail;
		while(p->next!=q)
		{
			p=p->next;
		}
		lh.tail=p;
		lh.tail->next=NULL;
		delete q;
	}
}
void NhapMaLop_Delete(Lophoc &x)
{
	printf("\nNhap ma lop can xoa:");
	fflush(stdin);
	gets(x.MALOP);
}
void xoaLopBatKi(listLH &lh,Lophoc x)
{
	if(stricmp(x.MALOP,lh.head->infor.MALOP)==0)
	{
		deleteHeadLH(lh);
		return;
	}
	else if(stricmp(x.MALOP,lh.tail->infor.MALOP)==0)
	{
		deleteTailLH(lh);
		return;
	}
	nodeLH* p;
	for(nodeLH* k=lh.head;k!=NULL;k=k->next)
	{
		if(stricmp(k->infor.MALOP,x.MALOP)==0)
		{
			p->next=k->next;
			delete k;
			break;
		}
		p=k;
	}
}
void xoaHocVienBatKi_ML(listHV &hv,Lophoc x)
{
	if(hv.head==NULL)
	{
		printf("\nKhong co hoc vien de xoa\n");
		return;
	}
	if(stricmp(hv.head->infor.malop.MALOP,x.MALOP)==0)
	{
		deleteHeadHV(hv);
	}
	else if(stricmp(hv.tail->infor.malop.MALOP,x.MALOP)==0)
	{
		deleteTailHV(hv);
	}
	nodeHV* p;
	for(nodeHV* k=hv.head;k!=NULL;k=k->next)
	{
		if(stricmp(k->infor.malop.MALOP,x.MALOP)==0)
		{
			p->next=k->next;
			delete k;
			break;
		}
		p=k;
	}
}
void xoaHocVien(listHV &hv,Lophoc &x,listLH &lh)
{
	if(lh.head==NULL)
	{
		printf("\nKhong co lop de xoa\n");
		return;
	}
	NhapMaLop_Delete(x);
	xoaLopBatKi(lh,x);
	for(nodeHV* p=hv.head;p!=NULL;p=p->next)
	{
		if(stricmp(p->infor.malop.MALOP,x.MALOP)==0)
		{
			xoaHocVienBatKi_ML(hv,x);
			p=hv.head;
		}
	}
}
void MENU()
{
	printf("\n================================================================================");
	printf("\n\t\tCHUONG TRINH QUAN LY HOC VIEN");
	printf("\n\t\tMoi ban chon 1 trong cac yeu cau sau");
	printf("\n\t\t1. Doc file lophoc.txt,Doc file hocvien.txt\n\t\t2. Them 1 hoc vien");
	printf("\n\t\t3. Tim hoc vien thong qua (ten lop, ma hoc vien hoac ngay sinh)\n\t\t4. In danh sach hoc vien theo ten lop(tat ca lop)");
	printf("\n\t\t5. Tim cac hoc vien co diem cao nhat\n\t\t6. Tim cac hoc vien o lop co hoc phi cao nhat");
	printf("\n\t\t7. Sap xep danh sach hoc vien theo ma lop, cac hoc vien cung 1 lop sap xep theo diem giam dan\n\t\t8. In cac hoc vien co diem chua dat(<5), sap xep giam dan theo ten hoc vien");
	printf("\n\t\t9. In cac hoc vien dat hoc bong(diem>=8) va luu danh sach vao file: dshocbong.txt");
	printf("\n\t\tCac yeu cau ngoai le khac:\n\t\t10. Them 1 lop hoc bang cach nhap tu ban phim\n\t\t11. xoa 1 hoc vien trong danh sach\n\t\t12. xoa lop va cac hoc vien cua lop do\n\t\t13. xoa tat ca cac danh sach lop hoc,hoc vien");
}
int main()
{
	listLH lh;
	Lophoc x;
	listHV hv;
	HocVien y;
	nodeHV* p;
	int luachon,dem=0;
	createListLH(lh);
	createListHV(hv);
	do
	{
		MENU();
		printf("\n\t\tBan chon yeu cau: ");
		scanf("%d", &luachon);
		switch (luachon)
		{
		case 1:
			if(dem==0)
			{
			printf("\n\t\t\tDANH SACH CAC LOP\n");
			readFileListLH("lophoc.txt", x, lh);
			printfListLop(lh);
			printf("\n\t\t\tDANH SACH CAC HOC VIEN\n");
			readFileListHV("hocvien.txt", y, hv);
			printfListHV(hv);
			dem++;
			}
			else
			{
				printf("\n\n\t\t VI LY DO KHONG DUOC TRUNG MA LOP, MA HOC VIEN NEN KHONG DC PHEP CHAY LAI CHUONG TRINH NAY\n\t\t HAY XOA TAT CA NHUNG GI DA CHAY TRUOC DO CUA TRUONG TRINH NAY VA CO THE CHAY LAI\n");
			}
			break;
		case 2:
			if(dem!=0)
			{
				NhapTTHV(y, lh);
				NhapMHV(y,hv);
				insertHV(hv, y);
				printfListHV(hv);
			}
			else
			{
				printf("\nkhong co lop hoc vui long tao lop hoc\n");
			}
			break;
		case 3:
			int search;
			selectSearch(search, hv, lh, y, x);
			break;
		case 4:
			printfTT(hv, lh);
			break;
		case 5:
			HocVienMaxDiemLop(hv,lh);
			break;
		case 6:
			lopCoHocPhiMax(hv,lh);
			break;
		case 7:
			SapXepMaLop(lh);
			SapXepDiemGiamDan(lh,hv);
			break;
		case 8:
			printf("\n+++++++++++++++++++++++In thong tin cac hoc vien chua dat+++++++++++++++++++++++\n");
			HocVienChuaDat(hv,lh),printf("\n");
			printf("\n+++++++++++++++++++++++Sap xep giam dan theo ten hoc vien+++++++++++++++++++++++\n");
			SapXepTenHocVien(lh,hv);
			break;
		case 9:
			HocVienDatHB(hv,lh);
			writeFileHocVienDatHB("dshocbong.txt",lh,hv);
			break;
		case 10:
			NhapTTLop(x);
			nhapMaLop_LH(x,lh);
			insertLop(lh, x);
			printfListLop(lh);
			break;
		case 11:
			NhapHocVien(y);
			xoaHocVienBatKi_MHV(hv,y);
			printfListHV(hv);
			break;
		case 12:
			xoaHocVien(hv,x,lh);
			printfListLop(lh);
			printfListHV(hv);
			break;
		case 13:
			createListLH(lh);
			createListHV(hv);
			dem=0;
			break;
		case 0:
			exit(1);
		default:
			printf("\nVui long nhap lai\n");
			break;
		}
	} while (luachon!=0);
	_getch();
	return 0;
}

