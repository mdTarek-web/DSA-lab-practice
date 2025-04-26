#include <iostream>
#include <stack>
using namespace std;

void finalPrices(int prices[], int n, int answer[]) {
    stack<int> st; 

    for (int i = 0; i < n; ++i) {
  
        while (!st.empty() && prices[i] <= prices[st.top()]) {
            int idx = st.top(); st.pop();
            answer[idx] = prices[idx] - prices[i];
        }
        st.push(i);
    }

  
    while (!st.empty()) {
        int idx = st.top(); st.pop();
        answer[idx] = prices[idx];
    }
}

int main() {
    int prices[5] = {8, 4, 6, 2, 3};
    int n = 5;
    int answer[5];

    finalPrices(prices, n, answer);

   
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}




