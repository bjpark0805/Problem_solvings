using namespace std;

/*
Long Long casting

w * h 가 long long 범위인데 w, h가 각각 int일 경우 long long 캐스팅을 해야한다. 잊지말자.
*/

long long solution(int w,int h) {
    long long answer = 1;
    answer = (long long) w * h;
    int tmp = w + h;
    while(w != 0 && h != 0){
        if(w >= h) w = w % h;
        else h = h % w;
    }
    answer -= tmp - w - h;
    return answer;
}