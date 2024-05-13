#include <bits/stdc++.h>
using namespace std;
class Solution {
public:     
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        queue <snake> que;
        snake start;
        que.push(start);
        while(que.size()){
            snake s_front=que.front();
            que.pop();
            if(s_front.tail[0]==n-1&&s_front.tail[1]==n-2&&s_front.head[0]==n-1&&s_front.head[1]==n-1){
                return s_front.step_num;

            }
            else{
                if(s_front.head[0]<n-1&&can_down(s_front,grid)){
                    snake nxt=snake_new(s_front);
                    go_down(&nxt);
                    que.push(nxt);
                }
                if(s_front.head[1]<n-1&&can_right(s_front,grid)){
                    snake nxt=snake_new(s_front);
                    go_right(&nxt);
                    que.push(nxt);
                }
                if(can_rotate(s_front,grid)){
                    snake nxt=snake_new(s_front);
                    rotate(&nxt);
                    que.push(nxt);
                }
            }
        }
        return -1;
    }
private:
    struct snake{
        int tail[2]={0,0};
        int head[2]={0,1};
        int step_num=0;
    };
    snake snake_new(snake now){
        snake nxt;
        nxt.tail[0]=now.tail[0];
        nxt.tail[1]=now.tail[1];
        nxt.head[0]=now.tail[0];
        nxt.head[1]=now.tail[1];
        nxt.step_num=now.step_num;
        return nxt;
    }
    bool is_parallel(snake now){
        return (now.tail[0]==now.head[0]&&now.tail[1]+1==now.head[1]);
    }
    bool is_vertical(snake now){
        return (now.tail[0]+1==now.head[0]&&now.tail[1]==now.head[1]);
    }
    bool can_rotate(snake now,vector<vector<int>>& grid){
        int n=grid.size();
        if(is_parallel(now)){
            return (now.tail[0]+1<=n-1)&&(grid[now.tail[0]+1][now.tail[1]]==0&&grid[now.tail[0]+1][now.tail[1]+1]==0);
        }
        else{
            return (now.tail[1]+1<=n-1)&&(grid[now.tail[0]][now.tail[1]+1] == 0 && grid[now.head[0]][now.head[1]+1] == 0);
        }
    }
    bool can_right(snake now,vector<vector<int>>& grid){
        if(is_parallel(now)){
            return grid[now.head[0]][now.head[1]+1]==0;
        }
        if(is_vertical(now)){
            return grid[now.head[0]][now.head[1]+1]==0&&grid[now.tail[0]][now.tail[1]+1]==0;
        }
        else return false;
    }
    bool can_down(snake now,vector<vector<int>>& grid){
        if(is_parallel(now)){
            return grid[now.head[0]+1][now.head[1]]==0&&grid[now.tail[0]+1][now.tail[1]]==0;
        }
        if(is_vertical(now)){
            return grid[now.head[0]+1][now.head[1]]==0;
        }
        else return false;
    }
    void go_down(snake * now){
        now->tail[0]+=1;
        now->head[0]+=1;
        now->step_num+=1;
    }
    void go_right(snake * now){
        now->tail[1]+=1;
        now->head[1]+=1;
        now->step_num+=1;
    }

    void rotate(snake * now){
        if(is_parallel(* now)){
            now->head[0]=now->tail[0]+1;
            now->head[1]=now->tail[1];
        }
        if(is_vertical(*now)){
            now->head[0]=now->tail[0];
            now->head[1]=now->tail[1]+1;
        }
        now->step_num+=1;
    }
};
int main(){
    vector<vector<int>> grid;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    int x=Solution().minimumMoves(grid);
    cout<<x<<endl;
}