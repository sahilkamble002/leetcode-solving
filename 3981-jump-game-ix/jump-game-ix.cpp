class Solution {
    vector<int> par, rnk, mx;

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        mx[a] = max(mx[a], mx[b]);
        if (rnk[a] == rnk[b]) rnk[a]++;
    }

    vector<int> seg;
    int N;

    void seg_init(int n) {
        N = n;
        seg.assign(4 * n, -1);
    }

    void seg_update(int node, int lo, int hi, int pos, int val) {
        if (lo == hi) { seg[node] = val; return; }
        int mid = (lo + hi) / 2;
        if (pos <= mid) seg_update(2*node,   lo,    mid, pos, val);
        else            seg_update(2*node+1, mid+1, hi,  pos, val);
        seg[node] = (seg[2*node] != -1) ? seg[2*node] : seg[2*node+1];
    }

    void seg_unite_range(int node, int lo, int hi, int l, int r,
                         int target, vector<int>& nums) {
        if (seg[node] == -1 || lo > r || hi < l) return;

        if (find(seg[node]) == find(target)) return;

        if (lo == hi) {
            if (nums[seg[node]] != nums[target])
                unite(seg[node], target);
            seg[node] = find(seg[node]);
            return;
        }

        int mid = (lo + hi) / 2;
        seg_unite_range(2*node,   lo,    mid, l, r, target, nums);
        seg_unite_range(2*node+1, mid+1, hi,  l, r, target, nums);

        int l_rep = seg[2*node],   l_root = (l_rep != -1) ? find(l_rep) : -1;
        int r_rep = seg[2*node+1], r_root = (r_rep != -1) ? find(r_rep) : -1;

        int t_root = find(target);
        if      (l_root != -1 && l_root != t_root) seg[node] = l_rep;
        else if (r_root != -1 && r_root != t_root) seg[node] = r_rep;
        else if (l_rep  != -1)                     seg[node] = l_rep;
        else                                        seg[node] = r_rep;
    }

public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        par.resize(n); rnk.assign(n, 0); mx.resize(n);
        iota(par.begin(), par.end(), 0);
        for (int i = 0; i < n; i++) mx[i] = nums[i];

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b){
            return nums[a] < nums[b];
        });
        seg_init(n);
        for (int g = 0; g < n; ) {
            int g2 = g;
            while (g2 < n && nums[idx[g2]] == nums[idx[g]]) g2++;
            // Query before inserting own group
            for (int k = g; k < g2; k++) {
                int i = idx[k];
                if (i + 1 < n)
                    seg_unite_range(1, 0, N-1, i+1, N-1, i, nums);
            }
            for (int k = g; k < g2; k++)
                seg_update(1, 0, N-1, idx[k], idx[k]);
            g = g2;
        }

        sort(idx.begin(), idx.end(), [&](int a, int b){
            return nums[a] > nums[b];
        });
        seg_init(n);
        for (int g = 0; g < n; ) {
            int g2 = g;
            while (g2 < n && nums[idx[g2]] == nums[idx[g]]) g2++;
            for (int k = g; k < g2; k++) {
                int i = idx[k];
                if (i - 1 >= 0)
                    seg_unite_range(1, 0, N-1, 0, i-1, i, nums);
            }
            for (int k = g; k < g2; k++)
                seg_update(1, 0, N-1, idx[k], idx[k]);
            g = g2;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = mx[find(i)];
        return ans;
    }
};