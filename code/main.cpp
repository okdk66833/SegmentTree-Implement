#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <conio.h>
#include <limits>

using namespace std;

vector<int> arr;
vector<int> segment;
int n,a,b,result,num;
string input;
char realTimeInput;

void printLogo(int stat){
    if(stat==0) system("cls");
    cout<<"����������������������������������\n��  SegmentTree  ��\n����������������������������������\n\n";
    
}

void changeColor(int stat){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), stat);
}

int buildSegmentTree(int start, int end,int now){
    int mid=(start+end)/2;
    if(start==end) return segment[now]=arr[start];
    return segment[now]=buildSegmentTree(start,mid,now*2)+buildSegmentTree(mid+1,end,now*2+1);
}

int sum(int start,int end, int now, int s,int e){
    if(s<=start&&e>=end) return segment[now];
    if(e<start||s>end) return 0;
    int mid=(start+end)/2;
    return sum(start,mid,now*2,s,e)+sum(mid+1,end,now*2+1,s,e);
}

int main(){    
begin:
    num=0,n=0,a=0,b=0,result=0;
    arr.clear();
    segment.clear();

    //1
    printLogo(0);
fst:
    cout<<"* ���� �̷���� �迭�� �Է��ϼ���: ";;
    getline(cin,input);
    istringstream iss(input);
    while(iss>>num) arr.push_back(num);
    n=arr.size();
    segment.resize(n*4);

    if(n==0){
        system("cls");
        printLogo(1);
        changeColor(12);
        cout<<"* �߸��� �Է��Դϴ�.\n";
        changeColor(7);
        goto fst;
    }

    //2
    printLogo(0);
snd:
    cout<<"* ������ �Է��ϼ���(1��° ������ 5��° �������� ������ ���: 1 5): ";
    cin>>a>>b;
    if(a<1||b>n){
        system("cls");
        printLogo(1);
        changeColor(12);
        cout<<"* ������ 1���� "<<n<<"�����Դϴ�.\n";
        changeColor(7);
        goto snd;
    }
    else if(a>b){
        system("cls");
        printLogo(1);
        changeColor(12);
        cout<<"* ���� ������ �� �������� Ŭ �� �����ϴ�.\n";
        changeColor(7);
        goto snd;
    }
    else if(a==b){
        system("cls");
        printLogo(1);
        changeColor(12);
        cout<<"* ������ ���� �� �����ϴ�.\n";
        changeColor(7);
        goto snd;
    }

    //3
    printLogo(0);
    changeColor(8);
    cout<<"* ���׸�Ʈ Ʈ�� ��� ��...\n";
    changeColor(7);
    buildSegmentTree(0,n-1,1);
    //for(int i=0;i<segment.size();i++) cout<<segment[i]<<" ";

    //4
    printLogo(0);
    changeColor(8);
    cout<<"* ���� ��...\n";
    changeColor(7);
    result=sum(1,n,1,a,b);

    //5
    printLogo(0);
    changeColor(7);
    cout<<"* ����� �Ϸ�Ǿ����ϴ�.\n  ����� ";
    changeColor(10);
    cout<<result;
    changeColor(7);
    cout<<"�Դϴ�.\n\n";

    changeColor(8);
    cout<<"* esc�� ���� �����ų� SPACE Ű�� ���� ����ϱ�";
    realTimeInput=0;
    for(;;){
        realTimeInput=_getch();
        if(realTimeInput==27) return 0;
        else if(realTimeInput==32){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            goto begin;
        }
    }
}