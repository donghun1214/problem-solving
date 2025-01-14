import java.util.*;
import java.io.*;

class Solution {
    public static int[] g_A, g_B;
    public static boolean[] b_used = new boolean[100002];
    public static int answer = 0;
    
    public static int upper_bound(int target){
        int low = 0;
        int high = g_B.length;
        
        while(low < high){
            int mid = (low + high) / 2;
            if (g_B[mid] > target) {
                high = mid;  
            } else {
                low = mid + 1;  
            }
        }
        return low;
    }
    
    
    public int solution(int[] A, int[] B) {
        g_A = A; g_B = B;
        Arrays.sort(g_A); Arrays.sort(g_B);
        
        for(int i : g_A){
            int idx = upper_bound(i);
            if(idx >= g_B.length) return answer; //범위에 벗어난 값
            else{
                //이전 idx 와 동일한 값 이면 계속 갱신하기
                while(b_used[idx]){
                    idx++;
                }
                if(idx >= g_B.length) return answer; //범위에 벗어난 값인지 체크
                answer++; //값 추가해
                b_used[idx] = true;
            }
        }
        
    
        
        return answer;
    }
}