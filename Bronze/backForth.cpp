#include <bits/stdc++.h>

using namespace std;

set<int>  values;

void doTransfer(vector<int> sender, vector<int> recivers, int step, int barn1, int barn2){
    if(step > 4){
        values.insert(barn1);
        return;
    }
    set<int> done;
    for(int i = 0; i < sender.size();i++){
        if(!(done.count(sender[i]))){
            done.insert(sender[i]);
            if(step % 2 == 0){
                barn2 -= sender[i];
                barn1 += sender[i];
                recivers.push_back(sender[i]);
                sender.erase(sender.begin()+i);
                doTransfer(recivers, sender, step+1, barn1, barn2);
                sender.insert(sender.begin()+i, recivers.back());
                recivers.pop_back();
                barn2 += sender[i];
                barn1 -= sender[i];
            }else{
                barn1 -= sender[i];
                barn2 += sender[i];
                recivers.push_back(sender[i]);
                sender.erase(sender.begin()+i);
                doTransfer(recivers, sender, step+1, barn1, barn2);
                sender.insert(sender.begin()+i, recivers.back());
                recivers.pop_back();
                barn1 += sender[i];
                barn2 -= sender[i];
            } 
        }
    }

}


int main(){
    ifstream input("backForth.in");
    vector<int> barn1(10), barn2(10);
    for(int i = 0; i < 2; i++){
        input >> barn1[i];
    }
    for(int i = 0; i < 2;i++){
        input >> barn2[i];
    }
    doTransfer(barn1, barn2, 1, 1000, 1000);
    cout << values.size() << endl;
    
}