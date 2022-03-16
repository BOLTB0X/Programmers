#include <string>
#include <vector>

using namespace std;

int one_cnt = 0, zero_cnt = 0;

//길이 반환
int get_length(string s) {
    int size = s.length(); //길이
    
    for(char& c : s) {
        if (c == '1')
            one_cnt++; //곧 길이
        else
            zero_cnt++;
    }
    
    return one_cnt;
}

string get_binary(int n) {
    string ret, tmp;
    
    while (n > 0) {
        int mod = n % 2;
        
        tmp += (char)(mod + '0');
        
        n /= 2;
    }
    
    int size = tmp.length();
    
    //뒤집어져있으니 다시 
    for (int i = size - 1; i>=0; --i) 
        ret += tmp[i];
    
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    
    while(1) {
        if (s == "1")
            break;
        s = get_binary(get_length(s));
        cnt++;
        one_cnt = 0;
    }
    
    answer.push_back(cnt);
    answer.push_back(zero_cnt);
    
    return answer;
}
