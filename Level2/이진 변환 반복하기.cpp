#include <string>
#include <vector>

using namespace std;

int t_cnt = 0, z_cnt = 0;

//길이 반환
int get_len(string s) {
    int o_cnt = 0, size = s.length();
    
    for (int i = 0; i<size; ++i) {
        if (s[i] == '1')
            o_cnt++;
        else
            z_cnt++;
    }
    
    return o_cnt;
}

//이진변환 결과 반환
string get_bin(int len) {
    string tmp = "";
    int number = len;
    
    while(number > 0) {
        int r = number % 2;
        tmp += ((char)r + '0');
        number /= 2;
    }
    
    //뒤집어진 결과로 완성되지만 1인 결과확인과 길이를 구할 것이므로
    //그냥 반환
    return tmp;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    string str = s;
    while (1) {
        if (str == "1")
            break;
        str = get_bin(get_len(str));
        t_cnt++;
    }
    answer.push_back(t_cnt);
    answer.push_back(z_cnt);
    return answer;
}
