#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i = 0; i < skill_trees.size(); ++i){
        string skill_tree = skill_trees[i];
        bool good = true;
        int index = -1;
        for(int s = 0; s < skill.size(); ++s){
            int new_index = 27;
            for(int j = 0; j < skill_tree.size(); ++j){
                if(skill[s] == skill_tree[j]) {new_index = j; break;}
            }
            if(new_index >= index) index = new_index;
            else{
                good = false; break;
            }
        }
        if(good) answer += 1;
    }
    return answer;
}