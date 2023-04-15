/*
 * BOJ 13305: 주유소 (Greedy)
 *
 * - 이전 주유소의 가격이 더 저렴한 경우,
 *   이전 주유소에서 주유를 한 것이라 가정하고 계산해나아감
 * 
 * - 다음 주유소가 더 저렴한 경우,
 *   그 시점부터 더 저렴한 주유소에서 주유한다 가정하고 계산해나아감
 * 
 */

#include <stdio.h>
#define MAX 100000

int main()
{
    // 변수 선언
    long long vertex[MAX];
    long long edge[MAX];
    long long N; // vertex(주유소)의 개수
    int i;
    long long charge=0; // Optimul Cost (최적 가격; 정답) 
    long long min; // 여지껏 거쳐온 주유소 중, 가장 유가가 저렴한 주유소의 인덱스

    // 입력 처리
    scanf("%lld", &N);

    for(i=0; i<N-1; i++)
        scanf("%lld", &edge[i]);

    for(i=0; i<N; i++)
        scanf("%lld", &vertex[i]);

    // 최적값 계산 (Greedy Algorithm)
    min = 0;
    for(i=0; i<N-1; i++)
    {
        if(vertex[min] > vertex[i])
            vertex[min] = vertex[i];

        charge += vertex[min] * edge[i];
    }

    // 정답 출력
    printf("%lld\n", charge);

    // 프로그램 종료
    return 0;
}