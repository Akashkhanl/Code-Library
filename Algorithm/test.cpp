
vector<pair<int,int>>factors // {prime,exponent}

vector<long long >divisors;

function<void(int,long long)> dfs = [&](int idx,long long cur) {

    if(idx==factors.size()) {
        divisors.push_back(cur);
        return;
    }

    int p = factors[idx].first;
    int exp = factors[idx].second;
    long long mul = 1;

    for(int i=0;i<=exp;i++) {
        dfs(idx+1,mul*cur);
        mul*=p;
    }
};

dfs(0,1);