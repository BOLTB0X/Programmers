#include <string>
#include <vector>

using namespace std;

int count_out(vector<vector<int>> &table, int size, int a, int k) {
    int ret = 0;
    for (int i = 0; i < size; ++i) {
        int cnt = 0;
        if (table[a][i] == 1) {
            for (int j = 0; j < size; ++j) {
                if (table[j][i] == 1)
                    cnt++;
            }
            
            if (cnt >= k)
                ret++;
        }
    }
    
    //신고 한넘이 정지시킨 넘 갯수
    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int size = id_list.size();
    
    // size X size 표, 득점 생성
    vector<vector<int>> table(size, vector<int> (size, 0));
    vector<int> score(size, 0);
    
    //신고자와 받은자 찾기
    for (string& s: report) {
        int idx = s.find(' ');
        string atteck = s.substr(0,idx);
        string defence = s.substr(idx + 1);
        int row, col;
        
        //아이디 찾기
        for (int i = 0; i< size; ++i) {
            if (atteck == id_list[i]) 
                row = i;
            else if (defence == id_list[i])
                col = i;
        }
        
        //중복 허용 X
        if (table[row][col] == 0) {
            table[row][col] = 1;
            score[col]++;
        }
    }
    /*
    for (int i = 0; i < size; ++i) {
        int cnt = count_out(table, size, i , k);
        answer.push_back(cnt);
    }
    */
    
    //신고자 행, 받은자 열
    for (int i = 0; i < size; ++i) {
        int cnt = 0;
        for (int j = 0; j < size; ++j) {
            if (table[i][j] > 0 && score[j] >= k)
                   cnt++;
        }
        answer.push_back(cnt); 
    }
    
    return answer;
}
