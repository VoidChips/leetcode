class Solution {
    public static String longestCommonPrefix(String[] strs) {
        String prefix = "";

        if (strs.length == 0) {
            return "";
        }

        // find the longest common prefix no longer than the shortest string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i); // character of the first string
            for (int j = 1; j < strs.length; j++) {
                if (i > strs[j].length() - 1 || strs[j].charAt(i) != c) {
                    return prefix;
                }
            }
            prefix += c;
        }

        return prefix;
    }

    public static void main(String[] args) {
        System.out.println(longestCommonPrefix(new String[] { "flower", "flow", "flight" }));
        System.out.println(longestCommonPrefix(new String[] { "dog", "racecar", "car" }));
        System.out.println(longestCommonPrefix(new String[] { "", "job", "juke" }));
        System.out.println(longestCommonPrefix(new String[] { "plane", "", "plant" }));
    }
}