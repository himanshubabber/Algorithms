#include<bits/stdc++.h>
using namespace std;

// trie

class node{
  public:
  
   node*links[26];
  bool flag=false;
  int ew=0;// end with 
  int cp=0;// count prefix 
  
  bool contain_key(char ch){
    return links[ch-'a'];
  }
  
  // create a reference trie
  void put(char ch,node*nd){
    links[ch-'a']=nd;
  }
  
  node*get(char ch){
    return links[ch-'a'];
  }
  
  void set(){
    flag=true;
  }
  
  bool is_end(){
    return flag;
  }
  
  void incew(){
    ew++;
  }
  void inccp(){
    cp++;
  }
  void decew(){
    ew--;
  }
  void deccp(){
    cp--;
  }
};

class trie{
  private:
  node* root;
  public:
  
  trie(){
    root= new node();
  }
  
  
  void insert(string word){
    node*nd= root;
    for(auto i:word){
      if(!nd->contain_key(i)){
        nd->put(i,new node());
      }
      nd=nd->get(i);
      nd->inccp();
    }
    nd->incew();
    nd->set();
  }
  
  bool search(string word){
    
    node*nd= root;
    for(auto i: word){
      if(!nd->contain_key(i)){
        return false;
      }
      nd=nd->get(i);
    }
    return nd->is_end();
  }
  
  bool start_with(string word){
    node*nd= root;
    for(auto i:word){
      if(!nd->contain_key(i)){
        return false;
      }
      nd=nd->get(i);
    }
    return true;
  }
    
   int countWordsEqualTo(string word){
     node*nd= root;
     for(auto i:word){
       if(!nd->contain_key(i)){
         return 0;
       }
       nd=nd->get(i);
     }
     return nd->ew;
   }
    
  
  int countWordsStartingWith(string word){
     node*nd= root;
     for(auto i:word){
       if(!nd->contain_key(i)){
         return 0;
       }
       nd=nd->get(i);
     }
     return nd->cp;
  }
  
  void erase(string word){
    node*nd = root;
    for(auto i: word){
        nd=nd->get(i);
        nd->deccp();
    }
    nd->decew();
  }

};

int main() 
{
  
  trie* t = new trie();
  
  t->insert("himanshu");
  t->insert("himanshu");
  
  cout<<t->search("himanshu")<<endl;//1
  cout<<t->search("himanshusingh")<<endl;//0
  
  t->insert("himanshusingh");
  cout<<t->search("himanshusingh")<<endl;//1
  cout<<t->countWordsEqualTo("himanshu")<<endl;//2
  cout<<t->countWordsStartingWith("himanshu")<<endl;//3
  
  t->insert("himanshu");
  t->insert("himanshu");
  cout<<t->countWordsEqualTo("himanshu")<<endl;//4
  t->erase("himanshu");
  
  cout<<t->countWordsEqualTo("himanshu")<<endl;//3
  cout<<t->countWordsStartingWith("himanshu")<<endl;//4
  

  
    cout << "Hello, World!";
    return 0;
}
