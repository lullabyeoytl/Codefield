#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int t;  // 数据组数
    cin >> t;
    
    while (t--) {
        int n;  // 序列长度
        cin >> n;
        vector<int> sequence(n);
        
        for (int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        int last = 0;
        int ans =0;
        int max_num=0;int min_num=0;
        for (int i=0;i<n;i++){
            if (i==0){
                ans = 2*sequence[i]+1;
                max_num = sequence[i];
                min_num = sequence[i];
            
                continue;
            }
            else if (last+1<i){
                if(sequence[i]>max_num){
                    int temp1 = 2*sequence[i]+1;
                    int temp2 = ans-max_num+sequence[i]+1;
                    if(temp1<temp2){
                        max_num = sequence[i];
                        last=i;
                        ans = temp2;
                    }
                    else{
                        last=i;
                        ans = temp1;
                        max_num = sequence[i];
                        min_num = sequence[i];
                    }
                }

                else if(sequence[i]<min_num){
                    continue;
                }
                else{
                    last=i;
                    ans++;
                }
            }

            else{
                if(sequence[i]>max_num){
                    int temp1 = 2*sequence[i]+1;
                    int temp2 = ans-max_num+sequence[i];
                    if(temp1<temp2){
                        max_num = sequence[i];
                        last=i;
                        ans = temp2;    
                    }
                    else{
                        last=i;
                        ans = temp1;
                        max_num = sequence[i];
                        min_num = sequence[i];
                    }
                }
                else{
                    continue;
                }
            }
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}
