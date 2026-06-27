class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Handle 1 separately
        if (cnt.count(1))
            ans = max(ans, cnt[1] - (cnt[1] % 2 == 0));

        vector<long long> keys;
        for (auto &p : cnt)
            keys.push_back(p.first);

        for (long long start : keys) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                auto it = cnt.find(cur);
                if (it == cnt.end() || it->second < 2)
                    break;

                len++;

                if (cur > 1000000000LL / cur) {
                    cur = -1;
                    break;
                }

                cur *= cur;
            }

            if (cur != -1) {
                auto it = cnt.find(cur);
                if (it != cnt.end())
                    ans = max(ans, 2 * len + 1);
                else if (len > 0)
                    ans = max(ans, 2 * len - 1);
            } else if (len > 0) {
                ans = max(ans, 2 * len - 1);
            }
        }

        return ans;
    }
};