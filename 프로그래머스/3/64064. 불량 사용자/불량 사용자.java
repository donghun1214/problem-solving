import java.util.*;
class Solution {
    //global 변수로 만듬
    public static int num = 0;
    public static int answer = 0;
    public static String[] g_user_id, g_banned_id;
    public static HashSet<List<Integer>> set = new HashSet<>();
    public static boolean[] vis = new boolean[8]; //Boolean 은 null 초기화. boolean 은 false 초기화.
    
    public boolean isEqual(String user, String ban){
        if(user.length() != ban.length()) return false; //String 은 length() 해야하네.
        for(int i = 0; i < user.length(); i++){
            if(user.charAt(i) != ban.charAt(i) && ban.charAt(i) != '*'){
                return false;
            }
        }
        return true;
    }
    
    public void select_evil(int step){
        if(step == num){
            List<Integer> temp_list = new ArrayList<>();
            for(int idx = 0; idx < g_user_id.length; idx++){
                if(vis[idx]) temp_list.add(idx);
            }
            
            if(!set.contains(temp_list)){
                set.add(temp_list);
                answer++;
            }
            return;
        }
        for(int idx = 0; idx < g_user_id.length; idx++){
            if(vis[idx]) continue; 
            if(isEqual(g_user_id[idx], g_banned_id[step])){
                vis[idx] = true;
                select_evil(step + 1);
                vis[idx] = false;
            }
        }
    }
    
    
    public int solution(String[] user_id, String[] banned_id) {
        num = banned_id.length;
        g_user_id = user_id; g_banned_id = banned_id;
        
        select_evil(0);
        
        
        return answer;
    }
}