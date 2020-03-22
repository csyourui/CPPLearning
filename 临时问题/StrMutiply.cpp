//#include <iostream>
//#include <string>
//using namespace std;
//string add(string num1, string num2){
//    string ans = "";
//    int num1_size = (int)num1.size();
//    int num2_size = (int)num2.size();
//    int carry = 0;
//    while(num1_size > 0||num2_size > 0||carry){
//        int num1_digit = (num1_size > 0 ? num1[num1_size-1]-'0' : 0);
//        int num2_digit = (num2_size > 0 ? num2[num2_size-1]-'0' : 0);
//        int temp = num1_digit + num2_digit + carry;
//        if(temp > 9){
//             carry = 1;
//             temp -= 10;
//        }
//        else
//             carry = 0;
//        ans.insert(ans.begin(),temp + '0');
//        num1_size--;
//        num2_size--;
//    }
//    return ans;
//}
//
//string multiplyhelp(string num1, char num2, int n){
//    string ans = "";
//    int num1_size = (int)num1.size();
//    int carry = 0;
//    while(num1_size > 0||carry>0){
//        int num1_digit = (num1_size > 0 ? num1[num1_size-1]-'0' : 0);
//        int num2_digit = num2-'0';
//        int temp = num1_digit * num2_digit + carry;
//        if(temp> 9){
//             carry = temp / 10;
//             temp = temp % 10 ;
//        }
//        else
//             carry = 0;
//        ans.insert(ans.begin(),temp + '0');
//        num1_size--;
//    }
//    while(n-->0)
//        ans.push_back('0');
//    return ans;
//}
//int main(){
//    string num1, num2;
//    while (cin >> num1 >> num2){
//        string ans = "";
//        if((num1.size() == 1&&num1[0] == '0') || (num2.size() == 1&&num2[0] =='0'))
//        {
//            cout<<ans<<endl;
//            return 0;
//        }
//        int length = (int)num2.length();
//        for(int i = 0; i < length; i++){
//            ans = add(multiplyhelp(num1, num2[length-1-i], i),ans);
//        }
//        cout<<ans<<endl;
//    }
//}
