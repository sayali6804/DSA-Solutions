class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        
        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;
            
            // Find how many words can fit in the current line
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }
            
            int numWords = j - i;
            int totalChars = 0;
            for (int k = i; k < j; k++) totalChars += words[k].size();
            
            string line;
            
            // Last line or single word in line → left justify
            if (j == n || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; k++) line += " " + words[k];
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - totalChars;
                int spaceBetween = totalSpaces / (numWords - 1);
                int extraSpaces = totalSpaces % (numWords - 1);
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = spaceBetween + (k - i < extraSpaces ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            
            res.push_back(line);
            i = j;
        }
        
        return res;
    }
};
