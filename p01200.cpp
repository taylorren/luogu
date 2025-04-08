#include <iostream>
#include <string>
using namespace std;

int main() {
    string comet, team;
    cin >> comet >> team;
    
    // 计算彗星名字的乘积，同时取模
    int comet_product = 1;
    for(char c : comet) {
        comet_product = (comet_product * (c - 'A' + 1)) % 47;
    }
    
    // 计算队伍名字的乘积，同时取模
    int team_product = 1;
    for(char c : team) {
        team_product = (team_product * (c - 'A' + 1)) % 47;
    }
    
    // 直接比较结果
    if(comet_product == team_product) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    
    return 0;
}