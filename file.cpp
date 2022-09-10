#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
using ii = pair<int, int>;
int kk;
struct node
{
    node *child[26];
    int prefix;
    vector<string> wend;
    node()
    {
        prefix = 0;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};
struct trie
{
    node* root;
    trie()
    {
        root = new node;
    }
    void insert(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            curr->prefix++;
            int x = s[i] - 'a';
            if (curr->child[x] == NULL)
            {
                curr->child[x] = new node;
            }
            curr = curr->child[x];
        }
        curr->wend.push_back(s);
    }
    void dfs(node* cur)
    {
        for (int i = 0; i < cur->wend.size() && kk > 0; i++)
        {
            kk--;
            cout << cur->wend[i] << " ";
        }
        if (kk == 0)
            return;
        for (int i = 0; i < 26; i++)
        {
            if (cur->child[i] != NULL)
                dfs(cur->child[i]);
        }

    }
};
void solve()
{
    int n, maxlen, q;
    cin >> n >> maxlen >> q;
    trie tr;
    for (int i = 0; i < n; i++)
    {
        int j;
        string s;
        cin >> j >> s;
        tr.insert(s);
    }
    while (q--)
    {
        string s1;
        int k, k2;
        cin >> k2 >> s1 >> k;
        for (int len = 1; len <= k2; len++)
        {
            kk = k;
            string pre = s1.substr(0, len);
            auto cur = tr.root;
            for (int i = 0; i < pre.size(); i++)
            {
                cur = cur->child[pre[i] - 'a'];
                if (cur == NULL)
                {
                    break;
                }
            }
            if (cur != NULL)
            {
                tr.dfs(cur);
            }
            cout << "\n";
        }

    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1; //cin>>_t;
    while (_t--)
        solve();
}