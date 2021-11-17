#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int fifo_pf(vector<int>ref, int n, int frames){
	
	int i,pf=0;
	queue<int> q;
	unordered_set<int>s;
	
	for(i=0;i<n;i++){
		if(q.size()<frames){
			
			if(s.find(ref[i]) == s.end()){
				//not found
				pf+=1;
				
				s.insert(ref[i]);
				q.push(ref[i]);
			}	
		} else{
			
			if(s.find(ref[i])==s.end()){
				//not present
				
				s.erase(q.front());
				q.pop();
				
				pf+=1;
				
				s.insert(ref[i]);
				q.push(ref[i]);
			}
		}	
	}
	
	
	
	
	return pf;
}

int main(){
	
	int i,n,num,frames=0;
	string reference;
	
	cout<<"Enter reference string length";
	cin>>n;
	cout<<endl<<"Enter string:";

	vector<int> ref;
	
	for(i=0;i<n;i++){
		cin>>num;
		ref.push_back(num);
	}
	
	cout<<endl<<"Enter frames:";
	cin>>frames;
	
	
	cout<<endl<<"Number of page faults:"<<fifo_pf(ref,n,frames);
	
	
	
	

}
