int binary_search(int key) {
    int ng = //
    int ok = //

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    
    return ok;
}