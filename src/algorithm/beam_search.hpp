#include "../../src/cp-template.hpp"
#include "../../src/algorithm/selection.hpp"

template < class state, class F >
state beam_search(state first, int turn, int width, const F& trans) {
    vector<state> list = {first};
    for(int t : rep(turn)) {
        vector<state> next;
        for(state& s : list) {
            vector<state> ns = trans(s);
            next.insert(next.end(), ns.begin(), ns.end());
        }
        list = topk(next, width);
    }
    return kth(list, 1);
}