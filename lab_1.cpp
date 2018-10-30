#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Menu(int &punkt),
    conclusionFunc(vector<string> &list, int &i),
    AddToList(vector<string> &list, int &id),
	DeleteFromList(vector<string> &list),
	ShowList(vector<string> &list),
	SortByDate(vector<string> &list),
	FromDateToDate(vector<string> &list),
    FromDurToDur(vector<string> &list),
    SortOnFrom(vector<string> &list),
    SortOnTo(vector<string> &list);

int main(){
	int punkt, id=1;
	vector<string> list;

	setlocale(LC_ALL, "Russian");
	Menu(punkt);
	while (punkt >= 1 && punkt <= 8){
		switch (punkt){
		case 1:
			system("cls");
			cin.get();
			AddToList(list, id);
			Menu(punkt);
			break;
		case 2:
			system("cls");
			DeleteFromList(list);
			Menu(punkt);
			break;
		case 3:
			system("cls");
			cin.get();
			ShowList(list);
			Menu(punkt);
			break;
		case 4:
			system("cls");
			SortByDate(list);
			Menu(punkt);
			break;
		case 5:
			system("cls");
			FromDateToDate(list);
			Menu(punkt);
			break;
		case 6:
			system("cls");
			FromDurToDur(list);
			Menu(punkt);
			break;
		case 7:
			system("cls");
			SortOnFrom(list);
			Menu(punkt);
			break;
		case 8:
			system("cls");
			SortOnTo(list);
			Menu(punkt);
			break;
		}
	}
	system("pause");
	return 0;
}

void AddToList(vector<string> &list, int &id) {
	string from, to, date, time, dur;
	cout << "insert from: "; getline(cin, from);
	cout << "insert to: ";  getline(cin, to);
	cout << "insert date: ";  getline(cin, date);
	cout << "insert time: ";  getline(cin, time);
	cout << "insert duration: ";  getline(cin, dur);
	list.push_back(to_string(id));
	list.push_back(from);
	list.push_back(to);
	list.push_back(date);
	list.push_back(time);
	list.push_back(dur);
	id++;
}

void ShowList(vector<string> &list) {
	for(int i=0; i<list.size(); i++)
    {
            cout << list.at(i) << "\t";
            if((i+1)%6==0 && i!=0) cout<<endl;
    }
    system("pause");
}

void DeleteFromList(vector<string> &list) {
    int _id, it=0;
    cout<<"Введеите id вызова который хотите удалить: "; cin>>_id;
    try{
    for(int i=0; i<list.size(); i+=6)
    {
        if(list.at(i)==to_string(_id))
        {
            list.erase(list.begin()+i, list.begin()+(i+6));
        }
    }
    } catch (const std::out_of_range& oor){}

    system("pause");
}

void SortByDate(vector<string> &list){
    int data0, data, n, m;
    string temp[6];
    div_t d1, d2;
    istringstream ss(list.at(3));
    while (ss){
        ss >> data0;
    }
    for(int i=0; i<list.size(); i+=6)
    {
        for(int j=0; j<6; j++)
        {
            temp[j]=list.at(i+j);
        }
        istringstream iss(temp[3]);
        while (iss){
            iss >> data;
        }
        n = data%100;
        m = data0%100;
        if(n<m){
            d1=div(data,100);
            d2=div(data0,100);
            n=d1.quot%100;
            m=d2.quot%100;
            if(n<m){
                d1=div(data,10000);
                d2=div(data0,10000);
                n=d1.quot;
                m=d2.quot;
                if(n<m){
                    list.at(i)=list.at(i-6);
                    list.at(i+1)=list.at(i-5);
                    list.at(i+2)=list.at(i-4);
                    list.at(i+3)=list.at(i-3);
                    list.at(i+4)=list.at(i-2);
                    list.at(i+5)=list.at(i-1);

                    list.at(i-6)=temp[0];
                    list.at(i-5)=temp[1];
                    list.at(i-4)=temp[2];
                    list.at(i-3)=temp[3];
                    list.at(i-2)=temp[4];
                    list.at(i-1)=temp[5];
                }
            }
        }
    }
}

void FromDateToDate(vector<string> &list){
    int start, fin, n , m, temp, lis;
    div_t d1;
    cout<<"Insert from date: "; cin>>start;
    cout<<"Insert to date: "; cin>>fin;
    for(int i=0; i<list.size(); i+=6)
    {
        n = start%100;
        m = fin%100;
        istringstream ss(list.at(i+3));
        while (ss){
            ss >> temp;
        }
        lis=temp%100;
        if(lis>n && lis<m)
        {
            conclusionFunc(list, i);
        }
        else{
            d1=div(start,100);
            n=d1.quot%100;
            d1=div(fin,100);
            m=d1.quot%100;
            d1=div(temp,100);
            lis=d1.quot%100;
            if(lis>n && lis<m){
                conclusionFunc(list, i);
            }
            else{
                d1=div(start,10000);
                n=d1.quot%100;
                d1=div(fin,10000);
                m=d1.quot%100;
                d1=div(temp,10000);
                lis=d1.quot%100;
                if(lis>n && lis<m){
                    conclusionFunc(list, i);
                }
            }
            }
    }
    system("pause");
}

void FromDurToDur(vector<string> &list){
    int start, fin, lis;
    cout<<"Insert from duration: "; cin>>start;
    cout<<"Insert to duration: "; cin>>fin;
    for(int i=0; i<list.size(); i+=6)
    {
        istringstream ss(list.at(i+5));
        while (ss){
            ss >> lis;
        }
        if(lis>start && lis<fin){
            conclusionFunc(list, i);
        }
    }
    system("pause");
}

void SortOnFrom(vector<string> &list){
    string from;
    cout<<"Insert from: "; cin>>from;
    for(int i=0; i<list.size(); i+=6)
    {
        if(list.at(i+1)==from){
            conclusionFunc(list, i);
        }
    }
    system("pause");
}

void SortOnTo(vector<string> &list){
    string to;
    cout<<"Insert to: "; cin>>to;
    for(int i=0; i<list.size(); i+=6)
    {
        if(list.at(i+2)==to){
            conclusionFunc(list, i);
        }
    }
    system("pause");
}

void conclusionFunc(vector<string> &list, int &i){
    cout << list.at(i) << "\t";
    cout << list.at(i+1) << "\t";
    cout << list.at(i+2) << "\t";
    cout << list.at(i+3) << "\t";
    cout << list.at(i+4) << "\t";
    cout << list.at(i+5) << "\t";
    cout<<endl;
}

void Menu(int &punkt) {
	system("cls");
	cout << "1. add call" << endl;
	cout << "2. delete call by id" << endl;
	cout << "3. show list" << endl;
	cout << "4. sort list by date" << endl;
	cout << "5. show from date to date" << endl;
	cout << "6. show from duration to duration" << endl;
	cout << "7. sort by from" << endl;
	cout << "8. sort by to" << endl;
	cin >> punkt;
}
