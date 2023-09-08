using ull = unsigned long long;

int count_bit(ull x) {
    ull count = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);
    count = (count & 0x3333333333333333) + ((count >> 2) & 0x3333333333333333);
    count = (count & 0x0f0f0f0f0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f0f0f0f0f);
    count = (count & 0x00ff00ff00ff00ff) + ((count >> 8) & 0x00ff00ff00ff00ff);
    count = (count & 0x0000ffff0000ffff) + ((count >> 16) & 0x0000ffff0000ffff);
    return (int)((count & 0x00000000ffffffff) + ((count >> 32) & 0x00000000ffffffff));
}

int msb(ull x) {
    if (x == 0) return -1;
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return count_bit(x) - 1;
}

int lsb(ull x) {
    if (x == 0) return -1;
    x |= (x << 1);
    x |= (x << 2);
    x |= (x << 4);
    x |= (x << 8);
    x |= (x << 16);
    x |= (x << 32);
    return 64 - count_bit(x);
}
