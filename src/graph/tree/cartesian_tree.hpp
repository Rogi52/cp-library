#pragma once

template < class T >
pair< vector<vector<int>>, int > cartesian_tree(vector< T > &a) {
    int n = a.size();
    vector<vector<int>> graph(n);
    vector<int> p(n, -1), st;
    st.reserve(n);
    for(int i = 0; i < n; i++) {
        int prev = -1;
        while(!st.empty() && a[i] < a[st.back()]) {
            prev = st.back();
            st.pop_back();
        }
        if(prev != -1) p[prev] = i;
        if(!st.empty()) p[i] = st.back();
        st.push_back(i);
    }

    int root = -1;
    for(int i = 0; i < n; i++) {
        if(p[i] == -1) root = i;
        else graph[p[i]].push_back(i);
    }
    return {graph, root};
}
