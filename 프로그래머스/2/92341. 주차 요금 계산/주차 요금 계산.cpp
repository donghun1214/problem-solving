#include <bits/stdc++.h>

using namespace std;
int std_time, std_fee, unit_time, unit_fee;
map<string, int> m, cost;

int time2min(string time){
    string str_hour = time.substr(0,2);
    string str_min = time.substr(3,5);
    int hour = stoi(str_hour);
    int min = stoi(str_min);
    
    return (hour*60) + min;
}


int calCost(int min){
    if(min > std_time) {
        min -= std_time;
        if(min % unit_time == 0)
            return (min/unit_time)*unit_fee + std_fee;
        else{
            return ((min/unit_time) + 1) * unit_fee + std_fee;
        }
    }
    else 
        return std_fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    std_time = fees[0]; std_fee = fees[1]; unit_time = fees[2]; unit_fee = fees[3];
    for(string s : records) {
        string time, car, status;
        stringstream ss(s);
        ss >> time >> car >> status;
        int min = time2min(time);
        if(status == "IN")
            m[car] = min;
        else {
            cost[car] += (min - m[car]);
            m[car] = -1;
        }
    }
    
    for(auto i : m) {
        if(i.second >= 0)
            cost[i.first] += (time2min("23:59") - i.second);
    }
    
    vector<int> answer;
    for(auto i : cost) {
        cout << i.first << " " << i.second << endl;
        answer.push_back(calCost(i.second));
    }
    
    return answer;
}