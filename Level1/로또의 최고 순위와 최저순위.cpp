#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//0의 개수 반환
int get_zero_count(vector<int>& lottos) {
    int cnt = 0;
    for (int i = 0; i < lottos.size(); ++i)
        if (lottos[i] == 0)
            cnt++;
    return cnt;
}

//등수 반환 함수
int get_rank(int n) {
    //각 경우의 수가 몇 위에 해당하는 지 확인
    
    //1등인 경우
    if (n == 6) 
        return 1;
    //2등인 경우
    else if (n == 5) 
        return 2;
    //3등인 경우
    else if (n == 4) 
        return 3;
    //4등인 경우
    else if (n == 3) 
        return 4;
    //5등인 경우
    else if (n == 2) 
        return 5;
    //6등인 경우
    else 
        return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    //방문리스트
    vector<bool> visited(lottos.size(), false);
    
    //최악의 경우
    int min_cnt = 0;

    //이진탐색을 위한 오름차순정렬
    sort(lottos.begin(), lottos.end());
    
    //몇개 맞는 지 확인
    for (int i = 0; i < lottos.size(); ++i) {
        //현재 로또 번호가 당첨번호에 몇 개있는지 확인
        for (int j = 0; j < win_nums.size(); ++j) {
            if (!visited[i] && lottos[i] == win_nums[j]) {
                min_cnt++;
                //중복할 경우 대비
                visited[i] = true;
            }
        }
    }

    //가장 좋은 경우
    //즉 남아있는 것들도 맞고 지워진 갯수 또한 맞을 경우
    int max_cnt = min_cnt + get_zero_count(lottos);

    answer.push_back(get_rank(max_cnt));
    answer.push_back(get_rank(min_cnt));

    return answer;
}
