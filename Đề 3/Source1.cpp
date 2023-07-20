//#include <stdio.h>
//#include <conio.h>
//#define MAXSIZE 50
//#include<stdlib.h>
//#include<time.h>
//struct của danh sách đặc
//struct list
//{
//    int infor[MAXSIZE];//khai báo danh sách 
//    int last;//kiểu dữ liệu dùng để đếm số phần tử đang có trong danh sách
//};
//
//khai báo danh sách rỗng
//void createlist(list &l)
//{
//    l.last=0;//khai báo bằng 0 vì chưa có giá trị đc thêm vào
//}
//
//kiểm tra xem danh sách có rỗng hay không ???
//int Emptylist(list l)
//{
//    return (l.last==0);
//}
//
//thêm giá trị vào danh sách
//void Insertlist(int X,list &l)
//{
//    if(l.last==MAXSIZE)
//        printf("danh sach day roi!!\n");
//    else
//	{
//		int i=l.last;
//        for (;i>0;i--)//vòng lặp này dùng để lui các giá trị có trùng vị trí đã đc thêm vào trước đó
//		{
//			l.infor[i]=l.infor[i-1];
//		}
//		l.infor[i]=X;//thêm giá trị mới vào vị trí đã có giá trị cũ
//        l.last=l.last+1;//tăng số phần tử lên 1
//    }
//}
//tìm kiếm phần tử bằng vị trí
//int searchViTri(int x,list l)
//{
//	for(int i=0;i<l.last;i++)
//	{
//		if(l.infor[i]==x)
//		{
//			return i+1;
//		}
//	}
//	return -1;
//}
//xóa phần tử bất kì trong danh sách
//void deleteGiaTri(int x,list &l)
//{
//	int dem=0;
//	for(int i=0; i<l.last; i++) 
//	{
//		if(l.infor[i] == x) 
//		{
//			for(int j=i; j<l.last-1; j++) 
//			{
//				l.infor[j] = l.infor[j+1];
//            }
//            dem++;
//			l.last-=1;
//            i--;
//        }
//    }
//    if(dem == 0)
//	{
//		printf("\nKhong co phan tu %d trong danh sach",x);
//	}
//}
//void Printlist(list l)
//{
//    for(int i=0;i<l.last;i++)
//	{
//		printf("%d\t",l.infor[i]);
//	}
//}
//void randomGiaTri(list &l,int &n)
//{
//	srand(unsigned(time(NULL)));
//	printf("\nNhap so luong muon them vao danh sach:");
//	scanf_s("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		l.infor[i]=rand()%100;
//		Insertlist(l.infor[i],l);
//	}
//}
//void main()
//{
//	list l;
//	int x,luachon,kq,n;
//	createlist(l);
//	do
//	{
//		printf("\nNhap lua chon:");
//		scanf_s("%d",&luachon);
//		switch (luachon)
//		{
//		case 1:
//			printf("\nNhap gia tri :");
//			scanf_s("%d",&x);
//			Insertlist(x,l);
//			break;
//		case 2:
//			Printlist(l);
//			break;
//		case 3:
//			printf("\nNhap phan tu muon tim kiem:");
//			scanf_s("%d",&x);
//			kq=searchViTri(x,l);
//			if(kq>=0)
//			{
//				printf("\n phan tu '%d' nam tai vi tri: %d",x,kq);
//			}
//			else
//			{
//				printf("\nKhong tim thay vi tri cua phan tu %d",x);
//			}
//			break;
//		case 4:
//			printf("\nNhap phan tu muon xoa:");
//			scanf_s("%d",&x);
//			deleteGiaTri(x,l);
//			Printlist(l);
//			break;
//		case 5:
//			randomGiaTri(l,n);
//			break;
//		default:
//			break;
//		}
//	}while(luachon!=0);
//	_getch();
//}