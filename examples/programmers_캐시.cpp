#include <string>
#include <vector>
using namespace std;

string to_lower_alphabet(string s){
    string new_s = "";
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= 'A' and s[i] <= 'Z'){
            new_s += s[i] + 32;
        }
        else{
            new_s += s[i];
        }
    }
    return new_s;
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0){
        int s = cities.size();
        return s * 5;
    }
    int answer = 5;
    string first_city = to_lower_alphabet(cities[0]);
    vector<string> cache;
    vector<string>::iterator iter;
    cache.push_back(first_city);
    for(int i = 1; i < cities.size(); ++i){
        string new_city = to_lower_alphabet(cities[i]);
        bool find = false;
        for(iter = cache.begin(); iter != cache.end(); ++iter){
            if(*iter == new_city){
                cache.erase(iter);
                cache.push_back(new_city);
                answer++;
                find = true;
                break;
            }
        }
        if(not find){
            if(cache.size() == cacheSize) cache.erase(cache.begin());
            cache.push_back(new_city);
            answer += 5;
        }
    }
    return answer;
}