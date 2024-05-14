#include <iostream>
#include "Tree.h"
using namespace std;
int main(){
    Tree<int> ds;
    ds.addRoot(5);
    ds.addChild(5,4);
    ds.addChild(5,6);
    ds.addChild(4,3);
    ds.addChild(4,8);
    ds.addChild(6,2);
    ds.addChild(2,9);
    ds.addChild(9,99);
    ds.addChild(6,7);
    ds.Duyet();
    cout<<endl;
    ds.InChild(3);cout<<endl;
    cout<<"So dinh: "<<ds.soDinh()<<endl<<"So la: "<<ds.SoLa()<<endl<<"So nut noi: "<<ds.SoNotNoi()<<endl;
    cout<<"Chieu cao cay: "<<ds.Height()<<endl;
    ds.Delete(4);
    ds.Duyet();

}