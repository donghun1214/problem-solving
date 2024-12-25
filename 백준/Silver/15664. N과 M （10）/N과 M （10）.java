/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
import java.io.*;

public class Main
{
    public static int[] array, answer;
    public static boolean[] vis;
    public static int n, m;
    public static StringBuilder sb = new StringBuilder();
    
    public static void selection(int start, int size){
        if(size == m){
            for(int i = 0; i < m; i++){
                sb.append(answer[i]).append(" ");
            }
            sb.append("\n");
            
            return;
        }
        int prev = -1;
        for(int i = start; i < n; i++){
            if(array[i] == prev) continue;
            
            vis[i] = true;
            prev = array[i];
            answer[size] = array[i];
            selection(i + 1, size + 1);
            vis[i] = false;
        }
    }
    
	public static void main(String[] args) throws Exception {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] tokens = br.readLine().split(" ");
	    n = Integer.parseInt(tokens[0]);
	    m = Integer.parseInt(tokens[1]);
	    vis = new boolean[n];
	    array = new int[n];
	    answer = new int[n];
	    String[] nums = br.readLine().split(" ");
	    for(int i = 0; i < n; i++){
	        array[i] = Integer.parseInt(nums[i]);
	    }
	    Arrays.sort(array);
	    
	    selection(0,0);
	    System.out.println(sb.toString());
	}
}