#include <string>
using namespace std;

// from r from c to r to c 
bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    //초기 위치
    int x = 5, y = 5;
	for (int i = 0; i < dirs.length(); i++) {
		if (dirs[i] == 'U') {
			if (y < 10) {
				if (!visited[x][y][x][y + 1]) {
					visited[x][y][x][y + 1] = true; //방문한 것으로 체크
					visited[x][y + 1][x][y] = true;
					answer++;
				}
				y++;
			}
		}
		else if (dirs[i] == 'D') {
			if (y > 0) {
				if (!visited[x][y][x][y - 1]) {
					visited[x][y][x][y - 1] = true;
					visited[x][y - 1][x][y] = true;
					answer++;
				}
				y--;
			}
		}
		else if (dirs[i] == 'L') {
			if (x > 0) {
				if (!visited[x][y][x - 1][y]) {
					visited[x][y][x - 1][y] = true;
					visited[x - 1][y][x][y] = true;
					answer++;
				}
				x--;
			}
		}
		else if (dirs[i] == 'R') {
			if (x < 10) {
				if (!visited[x][y][x + 1][y]) {
					visited[x][y][x + 1][y] = true;
					visited[x + 1][y][x][y] = true;
					answer++;
				}
				x++;
			}
		}
	}
	return answer;
}