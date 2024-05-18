#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    // 체력이 0 이하로 떨어질 경우 -1 리턴
    // bandage = 시전시간, 초당 회복량, 추가 회복량
    // attacks = [공격시간, 피해량]
    // 공격을 받으면 붕대 감기 취소, 데미지 입고 재 시전
    // 몬스터 공격이 끝나면 남은 체력 리턴
    
    int contime = bandage[0];
    int maxhealth = health;
    int heal = bandage[1];
    int contiheal = bandage[2];
    int time = 0; // 현재 시간
    int conti = 0; // 연속 성공
    int i = 0; // 몬스터 공격 포인터
    while(i < attacks.size())
    {
        time++;
        conti++;
        if(attacks[i][0] == time) // 몬스터 공격이 있을 경우
        {
            health -= attacks[i][1];
            if(health <= 0) return -1; // 체력이 0 이하로 감소할 경우 -1 리턴
            i++; // 다음 공격 준비
            conti = 0; // 연속 성공 초기화
        }
        else // 몬스터 공격이 없을 경우
        {
            if(conti == contime) // 연속 회복 성공
            {
                health += contiheal;
                conti = 0;
            }
            health += heal;
            if(health > maxhealth) health = maxhealth; // 최대 체력을 초과할 경우 최대체력으로 변경
        }
    }
    
    answer = health;
    // 1초 증가할때 마다 몬스터 공격이 있는지 체크
    // 몬스터 공격이 있을 경우 연속 회복 초기화 및 체력 감소
    // 체력 감소 후, 남은 체력이 0 이하일 경우 -1 리턴
    // 몬스터 공격이 없을 경우 초당 회복량만큼 체력 회복
    
    return answer;
}