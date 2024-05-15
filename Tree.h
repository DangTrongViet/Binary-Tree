#ifndef Tree_h
#define Tree_h
using namespace std;
#include "BNode.h"
#include <bits/stdc++.h>
#include <iostream>
template<class T>
class Tree{
    private:
    Bnode<T> *root;
    Bnode<T> * Search(Bnode<T> *p,T val){
            if(p==NULL) return NULL;
            else if(p->data==val){
                    return p;
            }
            else{
                if(Search(p->left,val)!=NULL){
                        return Search(p->left,val);
                }
                if(Search(p->right,val)!=NULL){
                        return Search(p->right,val);
                }
                return NULL;
            }
    }
    
    public:
    Tree(){
        root=NULL;
    }
    bool IsEmpty()const{
        if(root==NULL){
            return true;
        }
        return false;
    }
    void addRoot(T val){
        Bnode<T> *newnode=new Bnode<T>();
        if(root!=NULL){
            root->data=val;
        }
        else{
            newnode->data=val;
            root=newnode;
        }
    }
    Bnode<T> * Search(T val){
        Search(root,val);
    }
    void addChild(T val1,T val2){
       Bnode<T> *newnode=new Bnode<T>();
        newnode->data=val2;
        if(Search(root,val1)!=NULL){
            Bnode<T> *p=Search(root,val1);
            if(p->left!=NULL&&p->right!=NULL){
                return;
            }
            else if(p->left==NULL){
                p->left=newnode;
            }
            else if(p->right==NULL){
                p->right=newnode;
            }
        }
    }
    void Duyet(Bnode<T> *p){
        if(p!=NULL){
            cout<<p->data<<" ";
            Duyet(p->left);
            Duyet(p->right);
            
        }
    }
    void Duyet(){
        Duyet(root);
    }
    void InChild(Bnode<T> *p,T val){
        if(Search(p,val)!=NULL){
            Bnode<T> *tmp=Search(p,val);
            if(tmp->left!=NULL){
                cout<<tmp->left->data<<" ";
            }
            if(tmp->right!=NULL){
                cout<<tmp->right->data;
            }
        }
    }
    void InChild(T val){
        InChild(root,val);
    }
    void Reset(){
        delete root;
        root=NULL;
    }

    // void Delete(T value){
    //     Delete(root,value);
    // }
    T soDinh(Bnode<T> *p){
        int dem=0;
        if(p==NULL){
            return dem;
        }
        else{
            dem++;
            int sum=0;
            if(p->left!=NULL){
                sum+=soDinh(p->left);
            }
            if(p->right!=NULL){
                sum+=soDinh(p->right);
            }
            dem+=sum;
        }
        return dem;
    }
    T soDinh(){
        soDinh(root);
    }
    T SoLa(Bnode<T> *p){
        int dem=0;
        if(p==NULL) return dem;
        else{
            int sum=0;
            if(p->left!=NULL){
                dem++;
                sum=SoLa(p->left);
            }
            if(p->right!=NULL){
                dem++;
                sum=SoLa(p->right);
            }
            dem+=sum;
        }
        
        return dem;
    }
    T SoLa(){
        SoLa(root);
    }
    T SoNotNoi(){
        return soDinh()-SoLa();
    }
    T Height(Bnode<T> *p){
        if(p==NULL||p->left==NULL&&p->right==NULL){
            return 0;
        }
        else{
            int heightLeft=Height(p->left);
            int heightRight=Height(p->right);
            if(heightLeft>heightRight){
                return heightLeft+1;
            }
            else{
                return heightRight+1;
            }
        }

    }
    T Height(){
        Height(root);
    }
    Bnode<T> *findParent(Bnode<T> *Root,Bnode<T> *Child,T val){
        if(!Root||!Child) return NULL;
        if((Root->left&&Root->left->data==val)||(Root->right&&Root->right->data==val)) return Root;
        Bnode<T> *leftchild=findParent(Root->left,Child,val);
        if(leftchild) return leftchild;
        Bnode<T> *rightchild=findParent(Root->right,Child,val);
        if(rightchild) return rightchild;
    }
        void Delete(Bnode<T> *p,T val){
        if(!p) return; 
        Bnode<T> *Parent=findParent(root,root,val);;
        Bnode<T> *current=p;
        current=Search(val);
        if(current==NULL) return;
        // TH1: neu la nut la
        if(current->left==NULL&&current->right==NULL){
            cout<<"hi";
            if(current==root){
                root=NULL;
            }
            else if(Parent->left){
                Parent->right=NULL;
            }
            else if(Parent->right){
                Parent->left=NULL;
            }
            delete current;
        }
        // TH2: neu nut chi co 1 con
        if(current->left!=NULL&&current->right==NULL){
            if(current==root) root=current->left;
            else if(Parent->left){
                Parent->left=current->left;
            }
            else if(Parent->right){
                Parent->right=current->left;
            }
            delete current;
        }
        if(current->right!=NULL&&current->left==NULL){
            if(current==root) root=current->right;
            else if(Parent->left){
                Parent->left=Parent->right;
            }
            else if(Parent->right){
                Parent->right=Parent->right;
            }
            delete current;
        }
        // TH3: nut xoa co 2 con, se tim nut xa nhat cung phia cua nut xoa. 
        // chang han: neu nut xoa nam ben trai thi tim nut con trai xa nhat va nguoc lai
        if(current->left!=NULL&&current->right!=NULL){ 
            if(current->left){
                Bnode<T> *tmp=current->left;
                Bnode<T> *tam=current->left;
                while(tmp->left!=NULL){
                    tam=tmp;
                    tmp=tmp->left;
                }
                current->data=tmp->data;
                delete tmp;
                if(tmp!=tam){
                    tam->left=NULL;
                }
                else{
                    current->left=NULL;
                }    
                
               
            }
        }
    }
    void Delete(T val){
        Delete(root,val);
    }
    

    
    
   

};

#endif
