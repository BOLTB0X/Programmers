#include <string>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
    int *tmp = a;
    a = b;
    b = tmp;
}

void select_sort(vector<int>& arr) {
    for (int i = 0; i <= arr.size(); i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

string solution(string s) {
    string answer = "";
    vector<int> tmp_arr;
    string tmp_str="";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            tmp_arr.push_back(atoi(tmp_str.c_str()));
            tmp_str = "";
        }
        else {
            tmp_str += s[i];
        }
    }
    //마지막 처리
    tmp_arr.push_back(atoi(tmp_str.c_str()));

    select_sort(tmp_arr);
    answer += to_string(tmp_arr[0]);
    answer += " ";
    answer += to_string(tmp_arr[tmp_arr.size() - 1]);
 
    return answer;
}
