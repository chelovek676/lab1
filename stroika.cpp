#include <iostream>
#include <fstream>
#include <string>
#include "stroika.h"
using namespace::std;

Stroika::Stroika():name(""),price(0),whomade(""),color(""){}
Stroika::Stroika(const string& name, int price, const string& whomade, const string& color):name(name),price(price),whomade(whomade),color(color){}

ostream&operator<<(ostream& os, const Stroika& stroika){
    os<<"Name: "<<stroika.name<<" Price: "<<stroika.price<<" Made by: "<<stroika.whomade<<" Color: "<<stroika.color;
    return os;
}

istream&operator>>(istream& is, Stroika& stroika){
    is>>stroika.name>>stroika.price>>stroika.whomade>>stroika.color;
    return is;
}

void Stroika::edit(const string& newName, int newPrice, const string& newWhomade, const string& newColor){
    name = newName;
    price = newPrice;
    whomade = newWhomade;
    color = newColor;
}

string Stroika::getName()const{
    return name;
}

int Stroika::getPrice()const{
    return price;
}

string Stroika::getWhomade()const{
    return whomade;
}

string Stroika::getColor()const{
    return color;
}
void saveData(const Stroika* stroiki, int size){
    ofstream file("stroika.txt");
    if(!file.is_open())
        cerr<<"can't open file\n"<<endl;
    else{
        for (int i = 0; i < size; i++) {
            file<<stroiki[i].getName()<<" "<<stroiki[i].getPrice()<<"\\n";
            }
            file.close();
            cout<<"data saved\n"<<endl;
    }
}

void readData(Stroika* stroiki, int size) {
    ifstream file("stroika.txt");
    if(!file.is_open())
        cerr<<"can't open file.\n"<<endl;
    else{
        for(int i = 0; i < size; i++){
            file>>stroiki[i];
        }
        file.close();
        cout<<"data read\n"<<endl;
    }
}

void addElement(Stroika*& stroiki, int& size, const Stroika& newElement) {
    Stroika* temp = new Stroika[size + 1];
    for(int i = 0; i < size; i++){
        temp[i] = stroiki[i];
    }
    temp[size] = newElement;
    delete[] stroiki;
    stroiki = temp;
    size++;
}

void deleteElement(Stroika*& stroiki, int& size, const string& name){
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (stroiki[i].getName() == name) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        Stroika* temp = new Stroika[size - 1];
        for (int i = 0; i < index; ++i) {
            temp[i] = stroiki[i];
        }
        for (int i = index + 1; i < size; ++i) {
            temp[i - 1] = stroiki[i];
        }
        delete[] stroiki;
        stroiki = temp;
        size--;
        cout<<"element deleted\n"<<endl;
    }else{
        cerr<<"element not found\n"<<endl;
    }
}

void editElement(Stroika* stroiki, int size, const string& name, const string& newName, int newPrice, const string& newWhomade, const string&newColor){
    for(int i = 0; i < size; i++){
        if(stroiki[i].getName() != name)
            cerr<<"element not found\n"<<endl;
        else{
            stroiki[i].edit(newName, newPrice, newWhomade, newColor);
            cout<<"element edited\n"<<endl;
            return;
            }
       }
}

void searchElement(const Stroika* stroiki, int size, const string& name){
    for(int i = 0; i < size; ++i){
        if (stroiki[i].getName() == name){
            cout<<"element found: \n"<<stroiki[i]<<endl;
        return;
        }
    }
    cerr<<"element not found\n"<<endl;
}

void printArray(const Stroika* stroiki, int size){
                for (int i = 0; i < size; ++i){
                    cout<<stroiki[i]<<"\n"<<endl;
                }
            }
