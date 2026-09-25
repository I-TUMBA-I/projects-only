#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char a = 'A';

void clearScreen() {
    std::cout << "\033[H\033[2J" << std::flush;
}

struct people {
    float age;
    string name;
    size_t id;
};
bool isAdmin(){
    char admin;
    cout<<"Are you an (A)dmin or a (G)uest? :\n";
    cin>> admin;
    if(admin == a){
        string password = "123";
        cout<<"Password:\n";
        string passwordM;
        cin >> passwordM;
        if(password == passwordM){
            cout<<"Access granted!\n\n";
            return true;
        }else{
            cout<<"Acces denied\n\n";
            return isAdmin();
        }
    }else{
        cout<<"";
        return false;
    }
}
void AddPerson (vector<people> &Add){
    people p;
    size_t id = Add.size() + 1;
    p.id = id;
    string name;
    cout << "Name:\n";
    cin >> name;
    p.name = name;
    cout << "\n";
    float age;
    cout << "Age:\n";
    cin >> age;
    p.age = age;
    cout<<'\n';
    Add.push_back(p);
}
void DeletePerson (vector<people> &Delete){
    size_t idDel;
    cout<< "Id:\n";
    cin >> idDel;
    cout << '\n';
    for(size_t i = 0; i < Delete.size(); i++) {
        if(idDel == Delete[i].id){Delete.erase(Delete.begin() + i);break;}
    }
}
void FindByID (vector<people> &Find){
    size_t idFind;
    cout<<"Id to find:\n";
    cin >> idFind;
    cout << '\n';
    for(size_t i = 0; i < Find.size(); i++) {
        if(idFind == Find[i].id){
            cout<<"===Person===" << '\n';
            cout << "Name: " << Find[i].name << '\n'
                 << "Id: " << Find[i].id<< '\n'
                 << "Age: "<< Find[i].age << '\n' << '\n';
        }
    }
}
void FindByName (vector<people> &Find){
    string NameFind;
    cout<<"Name to find:\n";
    cin >> NameFind;
    cout << '\n';
    for(size_t i = 0; i < Find.size(); i++) {
        if(NameFind == Find[i].name){
            cout<<"===Person===" << '\n';
            cout << "Name: " << Find[i].name << '\n'
                 << "Id: " << Find[i].id<< '\n'
                 << "Age: "<< Find[i].age << '\n' << '\n';
        }
    }
}
void FindByAge (vector<people> &Find){
    float AgeFind;
    cout<<"Name to find:\n";
    cin >> AgeFind;
    cout << '\n';
    for(size_t i = 0; i < Find.size(); i++) {
        if(AgeFind == Find[i].age){
            cout<<"===Person===" << '\n';
            cout << "Name: " << Find[i].name << '\n'
                 << "Id: " << Find[i].id<< '\n'
                 << "Age: "<< Find[i].age << '\n' << '\n';
        }
    }
}
void Find(vector<people> &Find){
    int choise;
    cout<<"===Find by===\n"
        <<"1.By id\n"
        <<"2.By name\n"
        <<"3.By age\n" << '\n';
    cin>>choise;
    switch (choise) {
       case 1:
          FindByID(Find);
          break;
       case 2:
           FindByName(Find);
           break;
       case 3:
           FindByAge(Find);
    }
}
void ShowAll (vector<people> &Show) {
    for(size_t i = 0; i < Show.size(); i++) {
        cout<<"===Person===" << '\n';
        cout << "Name: " << Show[i].name << '\n'
             << "Id: " << Show[i].id<< '\n'
             << "Age: "<< Show[i].age << '\n' << '\n';
    }
}
int main(){
    vector<people> base;
    int choise;
    if(isAdmin()){
        while(true){
            clearScreen();
            cout<<"===DATABASE===\n"
                <<"1.Add person\n"
                <<"2.Delete person\n"
                <<"3.Find\n"
                <<"4.Show All\n"
                <<"5.Log off\n" << '\n';
            cin >> choise;
            switch (choise) {
                case 1:
                    AddPerson(base);
                break;
                case 2:
                    DeletePerson(base);
                break;
                case 3:
                    Find(base);
                break;
                case 4:
                    ShowAll(base);
                break;
                case 5:
                    return main();
                    break;
            }
        }
    }else{
        while(true) {
            clearScreen();
            cout<<"===DATABASE===\n"
                <<"1.Add person\n"
                <<"2.Find by ID\n"
                <<"3.Show All\n"
                <<"4.Log off\n" << '\n';
            cin >> choise;
            switch (choise) {
                case 1:
                    AddPerson(base);
                break;
                case 2:
                    FindByID(base);
                break;
                case 3:
                    ShowAll(base);
                break;
                case 4:
                    return main();
                    break;
            }
        }
    }
}
