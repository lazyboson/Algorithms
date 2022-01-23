class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left_pointer = 0;
        int right_pointer = 0;
        int res = 0;
        int sz = s.length();
        HashMap<Character, Integer> mp = new HashMap();
        while(right_pointer < sz){
            if(mp.containsKey(s.charAt(right_pointer))){
                left_pointer = Math.max(mp.get(s.charAt(right_pointer)) + 1, left_pointer);
            }
            mp.put(s.charAt(right_pointer), right_pointer);
            res = Math.max(res, right_pointer - left_pointer +1);
            right_pointer++;
        }
        return res;
    }
}
