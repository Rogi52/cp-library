vector<int> angle_argsort(vector<pointll>& P) {
    vector<int> lower, origin, upper;
    pointll O(0, 0);
    rep(i,int(P.size())) {
        if(P[i] == O)
            origin.push_back(i);
        else if(P[i].y < 0 || (P[i].y == 0 && P[i].x > 0))
            lower .push_back(i);
        else
            upper .push_back(i);
    }
    sort(lower.begin(), lower.end(), [&](int i, int j) { return det(P[i], P[j]) > 0; });
    sort(upper.begin(), upper.end(), [&](int i, int j) { return det(P[i], P[j]) > 0; });
    vector<int> I;
    I.insert(I.end(), lower .begin(), lower .end());
    I.insert(I.end(), origin.begin(), origin.end());
    I.insert(I.end(), upper .begin(), upper .end());
    return I;
}
