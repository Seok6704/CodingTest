#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // 멀리 있는 집을 적게 방문할수록 거리가 감소함
    // 배달을 끝내고 돌아올 때는 트럭이 비어있어야 최대한 많이 싣고 돌아올 수가 있음
    // 가장 멀리 있는 집에 최대한 많이 배달하고, 남는 택배를 거리가 먼 순서대로 분배하면서 옴
    // 이러면 가장 멀리 있는 집에 도착했을 때, 트럭이 비게 됨.
    // 트럭이 비었다면 가장 멀리 있는 집의 수거할 택배부터 트럭이 가득 찰 때까지 담으면서 복귀하면 됨
    // 수거가 끝난 곳은 탐색하지 않도록 해야 실행 시간을 줄일 수 있음
    
    // 가장 멀리 있는 집부터 탐색

    bool deliLeft = true;
    bool pickLeft = true;
    
    while(deliLeft || pickLeft) // 배송할 택배나 수거할 택배가 남지 않을때까지 반복
    {
        if(deliveries[deliveries.size() - 1] == 0) deliveries.pop_back();
        if(pickups[pickups.size() - 1] == 0) pickups.pop_back();
        int now = cap;
        int dis = 0;
        if(deliLeft) // 배달할 택배가 남았을 경우
        {
            // 택배 배달
            for(int i = deliveries.size() - 1; i >= 0; i--)
            {
                if(deliveries[i] == 0) continue;
                // 배달해야하는 택배가 남아 있을 경우
                if(deliveries[i] != 0 && now > 0)
                {
                    // 가장 멀리 배달한 포인트까지의 거리 저장
                    if(now == cap) dis = i + 1;
                    // 갖고 있는 택배 수 만큼 감소
                    if(deliveries[i] >= now) // 받을 택배가 갖고 있는 택배보다 많을 경우
                    {
                        deliveries[i] -= now;
                        now = 0;
                    }
                    else // 받을 택배가 갖고 있는 택배보다 적을 경우
                    {
                        now -= deliveries[i];
                        deliveries[i] = 0;
                    }
                }
                if(now == 0) break; // 갖고 있는 택배가 더이상 없을 경우 탐색 중지
            }
        }    
        //배달 완료 후, 택배가 남았을 경우, 더이상 배달할 곳이 없었다는 뜻
        if(now != 0) deliLeft = false;

        now = 0;

        if(pickLeft) // 수거할 택배가 남았을 경우
        {
            //상자 수거
            for(int i = pickups.size() - 1; i >= 0; i--)
            {
                if(pickups[i] == 0) continue;
                // 수거할 택배가 남아 있고, 현재 적재된 용량이 최대 용량보다 적을 경우
                if(pickups[i] != 0 && now < cap)
                {
                    // 가장 멀리 택배를 준 곳보다 먼 곳에서 수거할 경우 이동 거리 변경
                    if(dis <= i) dis = i + 1;
                    if(pickups[i] > cap - now) // 수거할 택배가 남은 용량보다 많을 경우
                    {
                        pickups[i] -= (cap - now); // 남은 용량만큼 수거
                        now = cap; // 트럭 꽉 참
                    }
                    else // 수거할 택배가 남은 용량보다 적을 경우
                    {
                        now += pickups[i]; // 트럭에 싣기;
                        pickups[i] = 0; // 남은 택배 X
                    }
                }
                if(now == cap) break; // 용량이 가득차면 탐색 중지
            }
        }
        // 트럭 용량이 남았을 경우, 더이상 수거할 택배가 없다는 뜻
        if(now != cap) pickLeft = false;

        answer += dis * 2; // 한 싸이클 당 최대 이동거리만큼 다시 돌아오므로 이동거리 * 2만큼 이동함
    }
    
    
    return answer;
}