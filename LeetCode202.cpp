int get(int n) {
    int res = 0;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}
bool isHappy(int n){
    int p = n, q = n;
    while (q != 1) {
        p = get(p);
        q = get(get(q));
        if(p == q) break;
    }
    return q == 1;
}
