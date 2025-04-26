#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int buyChoco(vector<int>&prices, int money){
    sort(prices.begin(),prices.end());

    int total = prices[0] + prices[1];

    if(total <= money){
        return money - total;
    }
    return money;
}

int main (){
    vector<int>prices = {1, 2, 3, 4};
    int money = 3;
    
    int leftover = buyChoco(prices, money);
    cout << "Leftover :" << leftover << endl;
    return 0 ;
    
    }
