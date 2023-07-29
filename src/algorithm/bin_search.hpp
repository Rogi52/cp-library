template < class T, class F >
T bin_search(T ok, T ng, F& f) {
    while(abs(ok - ng) > 1) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

template < class T, class F >
T bin_search_real(T ok, T ng, F& f, int step = 80) {
    while(step--) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}