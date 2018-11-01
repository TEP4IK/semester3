#include <iostream>
#include <vector>
using namespace std;

class Circle{
private:
    float x,y;
    float r;
    float alpha;
public:
    Circle(float r){
        this->r=r;
        x=0;
        y=0;
        alpha=0;
    }
    int Setter(float r){
        this->r=r;
    }
    int Rot(float alpha){
        this->alpha=alpha;
    }
    int SetMov(float x, float y){
        this->x=x;
        this->y=y;
    }
    void Getter(){
        cout<<"radius = "<<r<<" x = "<<x<<" y = "<<y<<" alpha = "<<alpha;
    }
    ~Circle(){}
};

class Recktangle{
private:
    float x,y;
    float a, b;
    float alpha;
public:
    Recktangle(float a, float b){
        this->a=a;
        this->b=b;
        x=0;
        y=0;
        alpha=0;
    }
    int Setter(float a, float b){
        this->a=a;
        this->b=b;
    }
    int Rot(float alpha){
        this->alpha=alpha;
    }
    int SetMov(float x, float y){
        this->x=x;
        this->y=y;
    }
    void Getter(){
        cout<<"side a = "<<a<<" side b = "<<b<<" x = "<<x<<" y = "<<y<<" alpha = "<<alpha;
    }
    ~Recktangle(){}
};

class Square{
private:
    float x,y;
    float c;
    float alpha;
public:
    Square(float c){
        this->c=c;
        x=0;
        y=0;
        alpha=0;
    }
    int Setter(float c){
        this->c=c;
    }
    int Rot(float alpha){
        this->alpha=alpha;
    }
    int SetMov(float x, float y){
        this->x=x;
        this->y=y;
    }
    void Getter(){
        cout<<"side = "<<c<<" x = "<<x<<" y = "<<y<<" alpha = "<<alpha;
    }
    ~Square(){}
};

void Menu(int &punkt){
    system("cls");
	cout << "1. create objects" << endl;
	cout << "2. information of objects" << endl;
	cout << "3. moving objects" << endl;
	cout << "4. change size" << endl;
	cout << "5. rotation objects" << endl;
	cin >> punkt;
}

void Create(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N),
    Info(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N),
    Moving(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N),
    ChangeSize(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N),
    Rotation(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N);

int main(){
    int punkt, N=0;
    vector<Circle> Vcirc;
    vector<Recktangle> Vrect;
    vector<Square> Vsq;

    Menu(punkt);
	while (punkt >= 1 && punkt <= 5){
		switch (punkt){
		case 1:
			system("cls");
			Create(Vcirc, Vrect, Vsq, N);
			N++;
			Menu(punkt);
			break;
		case 2:
			system("cls");
			Info(Vcirc, Vrect, Vsq, N);
			Menu(punkt);
			break;
		case 3:
			system("cls");
			Moving(Vcirc, Vrect, Vsq, N);
			Menu(punkt);
			break;
		case 4:
			system("cls");
			ChangeSize(Vcirc, Vrect, Vsq, N);
			Menu(punkt);
			break;
        case 5:
			system("cls");
			Rotation(Vcirc, Vrect, Vsq, N);
			Menu(punkt);
			break;
		}
	}
	system("pause");
	return 0;
}

void Create(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N){
    float r, a, b, c;
    cout<<"Insert radius: "; cin>>r;
    cout<<"Insert rectangle sides: "; cin>>a; cin>>b;
    cout<<"Insert square side: "; cin>>c;
    Vcirc.push_back(Circle(r));
    Vrect.push_back(Recktangle(a,b));
    Vsq.push_back(Square(c));
}

void Info(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N){
    for(int i=0; i<N; i++){
    cout<<"Circle: "; Vcirc.at(i).Getter(); cout<<endl;
    cout<<"Rectangle: "; Vrect.at(i).Getter(); cout<<endl;
    cout<<"Square: "; Vsq.at(i).Getter(); cout<<endl;
    cout<<endl;
    }
    system("pause");
}

void Moving(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N){
    float x=0, y=0;
    for(int i=0; i<N; i++){
    cout<<"Moving circle: "; x+=5;y+=8;
    Vcirc.at(i).SetMov(x,y);
    cout<<"Moving rectangle: "; x+=4;y+=6;
    Vrect.at(i).SetMov(x,y);
    cout<<"Moving square: "; x+=2;y+=3;
    Vsq.at(i).SetMov(x,y);
    }
}

void ChangeSize(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N){
    float r=0, a=0, b=0, c=0;
    for(int i=0; i<N; i++){
    cout<<"Insert radius: "; r+=6;
    cout<<"Insert rectangle sides: "; a+=4; b+=7;
    cout<<"Insert square side: "; c+=2;
    Vcirc.at(i).Setter(r);
    Vrect.at(i).Setter(a,b);
    Vsq.at(i).Setter(c);
    }
}

void Rotation(vector<Circle> &Vcirc, vector<Recktangle> &Vrect, vector<Square> &Vsq, int N){
    float alpha=0;
    for(int i=0; i<N; i++){
    cout<<"Insert angle for circle: "; alpha+=2;
    Vcirc.at(i).Rot(alpha);
    cout<<"Insert angle for rectangle: "; alpha+=4;
    Vrect.at(i).Rot(alpha);
    cout<<"Insert angle for square: "; alpha+=1;
    Vsq.at(i).Rot(alpha);
    }
}
