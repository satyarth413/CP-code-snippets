long double l = -100100, r = 101000;
rep(_, 300) {
    long double tl = (l * 2 + r) / 3, tr = (l + r * 2) / 3;
    if(f(tl) < f(tr))
        r = tr;
    else
        l = tl;
}