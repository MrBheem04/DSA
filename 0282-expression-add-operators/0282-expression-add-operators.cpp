class Solution {
    void dfs(string & num, int target, int start,
             long long current_value, long long last_oprends, string expression,
             vector<string>& result) {
        if (start == num.size()) {
            if (current_value == target) {
                result.push_back(expression);
                return;
            }
        }
        for (int i = start; i < num.size(); i++) {

            if (i > start && num[start] == '0')
                break;
            string current_num = num.substr(start, i - start + 1);
            long long current_num_value = stoll(current_num);

            if (start == 0) {
                dfs(num, target, i + 1, current_num_value, current_num_value,
                    current_num, result);
            } else {
                dfs(num, target, i + 1, current_value + current_num_value,
                    current_num_value, expression + "+" + current_num, result);

                dfs(num, target, i + 1, current_value - current_num_value,
                    -current_num_value, expression + "-" + current_num, result);

                dfs(num, target, i + 1,
                    current_value - last_oprends +
                        last_oprends * current_num_value,
                    last_oprends * current_num_value,
                    expression + "*" + current_num, result);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;

        dfs(num, target, 0, 0, 0, "", result);
        return result;
    }
};