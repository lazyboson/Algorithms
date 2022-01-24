class Solution {
    public boolean isValid(String s) {
        Stack<Character> verifier = new Stack<Character>();
        for (var c:s.toCharArray()) {
            if (c == '(' || c== '{' || c=='[') {
                verifier.add(c);
            }
            else {
                if(verifier.empty()) {
                    return false;
                }
                if (c == ')') {
                    if (verifier.peek() != '(') {
                        //System.out.println("false");
                        return false;
                    }
                    verifier.pop();
                }
                if (c=='}'){
                    if (verifier.peek() != '{'){
                       // System.out.println("false");
                        return false;
                    }
                    verifier.pop();
                }
                if (c == ']'){
                    if (verifier.peek() != '['){
                        //System.out.println("false");
                        return false;
                    }
                    verifier.pop();
                }
            }
        }
        //System.out.println("true");
        if(verifier.empty())
        return true;
        return false;
    }
}
