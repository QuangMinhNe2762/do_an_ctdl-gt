//#include <stdio.h>
//#include <conio.h>
//#define MAXSIZE 50
//#include<stdlib.h>
////struct của danh sách đặc
//struct list
//{
//    int a[MAXSIZE];//khai báo danh sách 
//    int last;//kiểu dữ liệu dùng để đếm số phần tử đang có trong danh sách
//};
//
////khai báo danh sách rỗng
//void createlist(list &l)
//{
//    l.last=0;//khai báo bằng 0 vì chưa có giá trị đc thêm vào
//}
//
////kiểm tra xem danh sách có rỗng hay không ???
//int Emptylist(list l)
//{
//    return (l.last==0);
//}
//
////thêm giá trị vào danh sách
//void Insertlist(int X,int P,list &l)
//{
//    if(l.last==MAXSIZE)
//        printf("danh sach day roi!!\n");
//    else if (P<1||P>l.last+1)//p là vị trí được thêm vào trong danh sách nếu vị trí này lớn hơn (số phần tử đang có trong danh sách +1 ) thì báo lỗi
//        printf("vi tri them k hop le!!\n");
//    else
//	{
//        for (int i=l.last;i>=P;i--)//vòng lặp này dùng để lui các giá trị có trùng vị trí đã đc thêm vào trước đó
//		{
//			l.a[i]=l.a[i-1];
//		}
//        l.a[P-1]=X;//thêm giá trị mới vào vị trí đã có giá trị cũ
//        l.last=l.last+1;//tăng số phần tử lên 1
//    }
//}
//void readFile(char* filename,list &l)
//{
//	FILE* f=fopen(filename,"r");
//	if(f==NULL)
//	{
//		printf("\nKhong doc duoc file");
//		return;
//	}
//	else
//	{
//		int n,x,p;
//		fscanf_s(f,"%d\n",&n);
//		for(int i=0;i<n;i++)
//		{
//			fscanf_s(f,"%d\t",&x);
//			fscanf_s(f,"%d\n",&p);
//			Insertlist(x,p,l);
//		}
//	}
//}
////xóa phần tử x tại vị trí bất kì
//void deletePosition(int P, list &l)
//{
//    if (P>=1 && P<=l.last && !Emptylist(l))
//	{
//        for(int i=P-1;i<l.last-1;i++)
//		{
//            l.a[i]=l.a[i+1];
//		}
//        l.last=l.last-1;
//    }
//}
////tìm kiếm phần tử bằng vị trí
//int searchPosition(int P, list l)
//{
//    return l.a[P-1];
//}
////tìm kiếm phần tử nằm trong danh sách
//int searchElement(int X, list l)
//{
//    for(int i=0;i<l.last;i++)
//	{
//        if (l.a[i]==X)
//            return i+1;
//    }
//    return -1;
//}
////xuất danh sách
//void Printlist(list l)
//{
//	printf("\n");
//	for(int j=1;j<=l.last;j++)
//	{
//		printf("%d.\t",j);
//	}
//	printf("\n");
//    for(int i=0;i<l.last;i++)
//	{
//        printf("%d\t",l.a[i]);
//	}
//}
////sắp xếp danh sách tăng dần
//void swap(int &a,int &b){
//    int t = a;
//    a = b;
//    b = t;
//}
//void sortListAscending(list &l)
//{
//    int n = l.last;
//    for (int i=0;i<n-1;i++)
//     for (int j=i+1;j<n;j++)
//        if (l.a[i]>l.a[j])
//            swap(l.a[i],l.a[j]);
//}
////xóa phần tử bất kì trong danh sách
//void deleteElement(int x,list &l)
//{
//	int dem=0;
//	for(int i=0; i<l.last; i++) 
//	{
//		if(l.a[i] == x) 
//		{
//			for(int j=i; j<l.last-1; j++) 
//			{
//                l.a[j] = l.a[j+1];
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
//void MENU()
//{
//	printf("\n*****************************************************");
//	printf("\n*                       MENU                        *");
//	printf("\n*****************************************************");
//	printf("\n* 1. them phan tu vao danh sach                     *");
//	printf("\n* 2. read file                                      *");
//	printf("\n* 3. xuat cac phan tu trong danh sach               *");
//	printf("\n* 4. tim kiem phan tu X trong danh sach             *");
//	printf("\n* 5. tim kiem phan tu X bang cach nhap vi tri       *");
//	printf("\n* 6. xoa phan tu X tai vi tri bat ki trong danh sach*");
//	printf("\n* 7. sap xep danh sach tang dan                     *");
//	printf("\n* 8. xoa phan tu bat ki trong danh sach             *");
//	printf("\n* 0. Thoat chuong trinh                             *");
//	printf("\n*****************************************************");
//}
//int main()
//{
//    list l;
//	int m,p,luachon,result;
//    createlist(l);
//	do
//	{
//		MENU();
//		printf("\nNhap lua chon cua ban:");
//		scanf_s("%d",&luachon);
//		switch (luachon)
//		{
//		case 1:
//			printf("\nNhap gia tri :");
//			scanf_s("%d",&m);
//			printf("\nNhap vi tri :");
//			scanf_s("%d",&p);
//			Insertlist(m,p,l);
//			break;
//		case 2:
//			readFile("dulieu.txt",l);
//			Printlist(l);
//			break;
//		case 3:
//			printf("\nXuat danh sach dac\n");
//			Printlist(l);
//			break;
//		case 4:
//			int x;
//			printf("\nNhap phan tu muon tim kiem trong danh sach:");
//			scanf_s("%d",&x);
//			result=searchElement(x,l);
//			if(result!=-1)
//			{
//			printf("da tim thay phan tu '%d' tai vi tri :%d\n",x,result);
//			}
//			else
//			{
//				printf("\nKhong tim thay phan tu '%d' trong danh sach\n",x);
//			}
//			break;
//		case 5:
//			printf("\nTim phan tu bang vi tri\n");
//			printf("\nNhap vi tri cua phan tu muon tim:");
//			scanf_s("%d",&x);
//			printf("tai vi tri '%d' =%d\n",x,searchPosition(x,l));
//			break;
//		case 6:
//			printf("\nNhap vi tri muon xoa:");
//			scanf_s("%d",&p);
//			deletePosition(p,l);
//			printf("Danh sach sau khi xoa phan tu o vi tri '%d':\n",p);
//			Printlist(l);
//			break;
//		case 7:
//			sortListAscending(l);
//			printf("Danh sach sau khi sap xep:\n");
//			Printlist(l);
//			break;
//		case 8:
//			printf("\nNhap phan tu muon xoa:");
//			scanf_s("%d",&x);
//			deleteElement(x,l);
//			printf("\nDanh sach sau khi xoa phan tu '%d':\n",x);
//			Printlist(l);
//			break;
//		case 0:
//			exit(1);
//		default:
//			break;
//		}
//	}while(luachon!=0);
//	_getch();
//    return 0;
//}