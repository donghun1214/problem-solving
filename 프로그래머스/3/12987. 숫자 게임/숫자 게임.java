import java.util.Arrays;

class Solution {
    public int solution(int[] A, int[] B) {
        Arrays.sort(A);
        Arrays.sort(B);

        int answer = 0;
        int aIdx = 0;  // A팀 인덱스
        int bIdx = 0;  // B팀 인덱스

        while (aIdx < A.length && bIdx < B.length) {
            if (B[bIdx] > A[aIdx]) {
                // B팀이 승리하면 점수 추가
                answer++;
                aIdx++;
                bIdx++;
            } else {
                // B팀이 지면 더 큰 숫자를 찾기 위해 B팀 인덱스만 증가
                bIdx++;
            }
        }

        return answer;
    }
}
