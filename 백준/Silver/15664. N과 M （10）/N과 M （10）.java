import java.util.*;
import java.io.*;
// 중복 확인 : 가변 Array 써서 이전 수열과 비교
public class Main
{
    public static int arr[];
    public static int n, m;
    public static ArrayList<Integer> dq_cur = new ArrayList<>();
    public static ArrayList<Integer> dq_prev = new ArrayList<>();
    public static StringBuilder sb = new StringBuilder();
    
    public static void selection(int start, int size){
        if(size == m){
            //수열 중복 고려
            if(!dq_prev.isEmpty() && dq_cur.equals(dq_prev)){
                return;
            }
            
            //이전 덱 초기화 & 갱신.
            dq_prev.clear();
            dq_prev.addAll(dq_cur); //3번
            for(int num : dq_cur){
                sb.append(num + " ");
            }
            sb.append("\n");
            return;
        }
        int prev = -1;
        for(int i = start; i < n; i++){
            if(prev == arr[i]) continue;
            dq_cur.add(arr[i]);
            prev = arr[i];
            selection(i+1, size+1);
            dq_cur.remove(dq_cur.size() - 1);
        }
    }
    
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] tokens = br.readLine().split(" ");
	    n = Integer.parseInt(tokens[0]);
	    m = Integer.parseInt(tokens[1]);
	    arr = new int[n];  //1번
	    
	    String[] arr_token = br.readLine().split(" ");
	    for(int i = 0; i < n; i++){
	        arr[i] = Integer.parseInt(arr_token[i]);
	    }
	    Arrays.sort(arr); //2번
	    
	   
	   selection(0, 0);
	    
	    
	    System.out.println(sb.toString());
	}
}