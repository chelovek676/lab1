#include <iostream>
#include <fstream>
#include <string>
#include "stroika.h"
using namespace::std;

int main(){
    const int max_count = 10;
    Stroika* stroiki = new Stroika[max_count];
    int size = 0;
    char choice;
    do{
        cout<<"1-add, 2-delete, 3-change, 4-find\n"<<endl;
        cout<<"5-print, 6-save, 7-read, 8-exit\n"<<endl;
        cout<<"what do you want to do? (choose number):\n"<<endl;
        cin>>choice;
        switch(choice){
            case '1':{
                if(size == max_count){
                    cerr<<"you can't add more elements because array is full\n"<<endl;
                }else{
                    cout<<"enter name, price, maker and color: \n"<<endl;
                    Stroika newElement;
                    cin>>newElement;
                    addElement(stroiki, size, newElement);
                }
                break;
            }
            case '2':{
                if(size == 0){
                    cerr<<"array is empty\n"<<endl;
                }else{
                    string nameToDelete;
                    cout<<"write the name of the element that you want to delete: \n"<<endl;
                    cin>>nameToDelete;
                    deleteElement(stroiki, size, nameToDelete);
                }
                break;
            }
            case '3':{
                if(size == 0){
                    cerr<<"Array is empty\n"<<endl;
                }else{
                    string oldName, newName;
                    int newPrice;
                    string newWhomade;
                    string newColor;
                    cout<<"write the name of the element to edit: \n"<<endl;
                    cin>>oldName;
                    cout<<"write the new name, price, maker, color: \n"<<endl;
                    cin>>newName>>newPrice>>newWhomade>>newColor;
                    editElement(stroiki, size, oldName, newName, newPrice, newWhomade, newColor);
                }
                break;
            }
            case '4':{
                if(size == 0){
                    cerr<<"array is empty\n"<<endl;
                }else{
                    string nameToSearch;
                    cout<<"write the name of the element to search: \n"<<endl;
                    cin>>nameToSearch;
                    searchElement(stroiki, size, nameToSearch);
                }
                break;
            }
            case '5':{
                if(size == 0){
                    cerr<<"array is empty\n"<<endl;
                }else{
                    printArray(stroiki, size);
                }
                break;
            }
            case '6':{
                saveData(stroiki, size);
                break;
            }
            case '7':{
                readData(stroiki, size);
                break;
            }
            case '8':{
                break;
            }
            default:
                cerr<< "error\n"<<endl;
        }
    }while (choice != '8');
    delete[] stroiki;
    return 0;
}
