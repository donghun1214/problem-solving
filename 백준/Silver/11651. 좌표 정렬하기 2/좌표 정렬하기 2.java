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
    static class Point implements Comparable<Point>{  //1번 : static class 로 선언해야 Main 에서 쓸 수 있음.
        int x, y;
        Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        
        @Override
        public int compareTo(Point p){  //2번 : compareTo 함수를 익혀놔.
            if(this.y != p.y) {
                return this.y - p.y;
            }
            else{
                return this.x - p.x;
            }
        }
    }
    
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Point> points = new ArrayList<>();
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++){
		    String[] tokens = br.readLine().split(" ");
		    int x = Integer.parseInt(tokens[0]);
		    int y = Integer.parseInt(tokens[1]);
		    
		    points.add(new Point(x,y));
		}
	    Collections.sort(points);  //3번. ArrayList 는 Collections.sort 이다.
	    
	    for(Point i : points){ //4번. 이렇게 순회할 수 있구나
	        System.out.println(i.x + " " + i.y); 
	    }
	}
}
