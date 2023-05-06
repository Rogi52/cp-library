vector<int> angle_argsort(const vector<pointll>& P) {
    vector<int> lower, origin, upper;
    pointll O(0, 0);
    for(int i : rep(P.size())) {
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

void angle_sort(vector<pointll>& P) {
    auto I = angle_argsort(P);
    vector<pointll> Q(P.size());
    for(int i : rep(P.size())) Q[i] = P[I[i]];
    swap(P, Q);
}
