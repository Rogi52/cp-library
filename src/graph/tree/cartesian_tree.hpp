#pragma once

template < class T >
pair< vector<vector<int>>, int > cartesian_tree(vector< T > &a) {
    int n = a.size();
    vector<vector<int>> graph(n);
    vector<int> parent(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        int prev = -1;
        while(!st.empty() && a[i] < a[st.top()]) { prev = st.top(); st.pop(); }
        if(prev != -1) parent[prev] = i;
        if(!st.empty()) parent[i] = st.top();
        st.push(i);
    }

    int root = -1;
    for(int i = 0; i < n; i++) {
        if(parent[i] == -1) root = i;
        else graph[p[i]].push_back(i);
    }
    return {graph, root};
}
