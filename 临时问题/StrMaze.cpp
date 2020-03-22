////
////  StrMaze.cpp
////  test
////
////  Created by yourui on 2020/2/26.
////  Copyright © 2020 yourui. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int FindWord(vector<vector<char>> map, int m, int n, string word){
//    int ans = 0;
//    int N = (int)word.length();
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if(map[i][j] == word[0]){
//                bool flag;
//                int k;
//                //判断右
//                flag = true;
//                for (k = 1; k < N && j+k < n; k++) {
//                    if(map[i][j+k] != word[k]){
//                        flag = false;
//                        break;
//                    }
//                }
//                if(k == N && flag)
//                    ans++;
//                //判断右下
//                flag = true;
//                for (k = 1; k < N && j+k < n && i+k<m; k++) {
//                    if(map[i+k][j+k] != word[k]){
//                        flag = false;
//                        break;
//                    }
//                }
//                if(k == N && flag)
//                    ans++;
//                //判断下
//                flag = true;
//                for (k = 1; k < N && i+k < m; k++) {
//                    if(map[i+k][j] != word[k]){
//                        flag = false;
//                        break;
//                    }
//                }
//                if(k == N && flag)
//                    ans++;
//            }
//        }
//    }
//    
//    return ans;
//}
//int main(){
//    int T;
//    while(cin >> T){
//        vector<int> ans(T);
//        for(int i = 0; i < T; i++){
//            int m,n;
//            cin >> m >> n;
//            vector<vector<char>> map(m, vector<char>(n));
//            for(int j = 0; j < m; j++){
//                for(int k = 0; k < n; k++){
//                    cin >> map[j][k];
//                }
//            }
//            string word;
//            cin >> word;
//            ans[i] = FindWord(map, m, n, word);
//        }
//        for(int i = 0; i < T; i++){
//            cout<<ans[i]<<endl;
//        }
//    }
//}
