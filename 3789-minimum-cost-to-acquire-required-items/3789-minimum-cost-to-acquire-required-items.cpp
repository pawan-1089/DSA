class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;

        // Strategy 1 Buy type 1 and type 2 items separately
        long long allIndividual = (n1 * c1) + (n2 * c2);

        // Strategy 2: Buy type 3 for the shared requirement, then buy the remainder individually
        long long common = min(n1, n2);
        long long mixed = (common * cb) + ((n1 - common) * c1) + ((n2 - common) * c2);

        // Strategy 3: Satisfy both requirements entirely with type 3 items
        long long allCombined = max(n1, n2) * cb;

        return min({allIndividual, mixed, allCombined});
    }
};