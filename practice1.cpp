// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int main(){

//     int n;
//     cin >> n;

//     vector<pair<int,int>>students;

//     for(int i = 1; i < n; i++){
//         int a, b, c, d;

//         cin  >> a  >> b >> c >> d;

//         int total = a + b + c + d;

//         students.push_back({-total, i});
//     }
//      sort(students.begin(),students.end());

//      for(int i = 0; i < n; i++){
//         if(students[i].second == 1){
//             cout << i + 1 << endl;

//             break;
//         }
//      }

//      return 0;

// }


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main (){

    int i,n;
    cin >> n;

    vector<pair<int, int>>students;

    for(int i = 1; i < n; i++){
        int a, b, c, d;

        cin >> a >> b >> c >> b;
        
        int  total = a + b + c + d;

        students.push_back({-total,i});

        sort(students.begin(),students.end());
        for(int i = 0; i < n; i++){
            if(students[i].second == 1){
                cout << i + 1 << endl;
                break;
            }
          
        }
        return 0;
    }
}