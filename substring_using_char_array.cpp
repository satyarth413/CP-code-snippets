void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<pair<int, string>> st;

    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            st.insert({tempindex, temp}); // length,string
        }
    }

    for (auto str : st )
        cout << str.ss << endl;
}