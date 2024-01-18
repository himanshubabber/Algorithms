#include<iostream>
#include<vector>
using namespace std;
void findlps(string needle,int nl,vector<int>&lps){
    
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<nl){
        if(needle[i]==needle[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
           if(len>0){
               len=lps[len-1];
           }
           else{
               lps[i]=0;
               i++;
           }
        }
    }

}
    
int main(){ 
//kmp is the algorithm that is us efor the string matching
//it matches string in complexity less than n^2
//let's do it 
string haystack;
string needle;
cout<<"enter string 1 and s2"<<endl;
cin>>haystack>>needle;
//brute force approch 
/*
int i=0;
int j=0;
int l1=s1.length();
int l2=s2.length();
bool flag=0;
while(i<=l1 && j<=l2){
    if(j==l2){
        
        flag=1;
    }
    if(i==l1)break;
    if(s1[i]==s2[j]){
        i++;
        j++;
    }
    else{
        j=0;
    }

}
if(flag==0)cout<<"no matching found"<<endl;
else cout<<"matching string is found"<<endl;*/
 int hl=haystack.length();
        int nl=needle.length();
       
        // 0 based indexing
        vector<int>lps(nl,0);
        findlps(needle,nl,lps);
        int i=0;
        int j=0;
        vector<int>ans;
        while(i<hl){
        
        if(haystack[i]==needle[j]){
            
            i++;
            j++;
            if(j==nl){
            ans.push_back(i-nl);
            j=lps[j-1];
        }
        }
        else{
            if(j>0){
            j=lps[j-1];
             
            }
            else{
                i++;
            }

            
        }
        }
        
//printing the vector ans
cout<<"returning the vector of first occurances"<<endl;
for(int i=0;i<ans.size();i++){
 cout<<ans[i]<<" ";
}
 return 0;
}