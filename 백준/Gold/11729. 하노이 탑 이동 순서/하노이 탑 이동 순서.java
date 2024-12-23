/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.io.*;
import java.util.*;
public class Main
{
    public static  StringBuilder sb = new StringBuilder();
    public static int move(int n){
        if(n == 1) return 1;
        return 2*move(n-1) + 1;
    }
    
    public static void move_pos(int n, int start, int end){
        if(n == 1){
            sb.append(start).append(" ").append(end).append("\n");
            return;
        }
        
        move_pos(n-1, start, 6 - (start+end));
        sb.append(start).append(" ").append(end).append("\n");
        move_pos(n-1, 6-(start+end), end);
    }
    
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		//횟수
		int cnt = move(n);
		System.out.println(cnt);
		
		//경로 출력
		move_pos(n, 1, 3);
		System.out.println(sb.toString());
	}
}
