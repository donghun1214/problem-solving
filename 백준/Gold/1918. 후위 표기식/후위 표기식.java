/**
 * 1. 후위표기식 : 연산자 우선순위가 높은 순서대로 출력된다. 
 *          => 연산자 우선순위를 우리가 따로 정할 수는 없으니 우선순위 정하는 로직을 따로 정해야함
 * 2. 괄호를 고려 => 스택을 사용해야 함.
 * 3. ) 을 만나면 다 출력하기.
 */
import java.io.*;
import java.util.*;

public class Main
{
    static int weight(char op) {
        if (op == '(') return 0;
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return -1;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        Stack<Character> st = new Stack<>();
        StringBuilder answer = new StringBuilder();
        
        for(int i = 0; i < line.length(); i++){
            char temp = line.charAt(i);
            
            if(Character.isLetter(temp)){
                answer.append(temp);
            }else if(temp == '('){
                st.push(temp);
            } 
            else if(temp == ')'){
                while(st.peek() != '('){
                    answer.append(st.pop());
                }
                st.pop();
            } else {
                while(!st.empty() && weight(temp) <= weight(st.peek())){
                    answer.append(st.pop());
                }
                st.push(temp);
            }
        }
        
        while (!st.isEmpty()) {
            answer.append(st.pop());
        }
        
        System.out.println(answer);
    }
}




