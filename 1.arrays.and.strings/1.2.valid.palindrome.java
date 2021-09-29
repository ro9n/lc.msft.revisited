class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();

        for (int l = 0, r = n - 1; l < r;) {
            if (!Character.isLetterOrDigit(s.charAt(l))) {
                ++l;
                continue;
            } else if (!Character.isLetterOrDigit(s.charAt(r))) {
                --r;
                continue;
            } else if (Character.toLowerCase(s.charAt(l)) != Character.toLowerCase(s.charAt(r)))
                return false;
            else {
                ++l;
                --r;
            }
        }
        return true;
    }
}