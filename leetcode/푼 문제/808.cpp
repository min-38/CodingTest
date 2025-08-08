class Solution {
public:
    vector<vector<double>> v;
    double soupServings(int n) {
        if (n >= 5000) return 1.0;

        int units = ceil(n / 25.0);

        v = vector<vector<double>>(units + 1, vector<double>(units + 1, -1.0));
        return dfs(units, units);
    }

    double dfs(int Asoup, int Bsoup)
    {
        if (Asoup <= 0 && Bsoup <= 0) return 0.5;
        if (Asoup <= 0) return 1.0;
        if (Bsoup <= 0) return 0.0;

        if (v[Asoup][Bsoup] != -1.0) return v[Asoup][Bsoup];

        v[Asoup][Bsoup] = 0.25 * (
            dfs(Asoup - 4, Bsoup) +
            dfs(Asoup - 3, Bsoup - 1) +
            dfs(Asoup - 2, Bsoup - 2) +
            dfs(Asoup - 1, Bsoup - 3)
        );

        return v[Asoup][Bsoup];
    }
};