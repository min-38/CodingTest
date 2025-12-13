class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        set<string> categories = { "electronics", "grocery", "pharmacy", "restaurant" };
        vector<pair<string, string>> coupons;

        int n = isActive.size();
        for (int i = 0; i < n; i++)
        {
            // 3번 조건
            if (!isActive[i])
                continue;

            // 2번 조건
            if (categories.find(businessLine[i]) == categories.end())
                continue;

            // 1번 조건
            if (code[i] == "")
                continue;
            
            bool validCode = true;
            for (char c : code[i])
            {
                if (!isalnum(c) && c != '_')
                {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;

            coupons.push_back({businessLine[i], code[i]});
        }

        sort(coupons.begin(), coupons.end());

        vector<string> result;
        for (const auto& item : coupons)
            result.push_back(item.second);
        
        return result;
    }
};